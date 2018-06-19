package engine

import (
	"github.com/mumax/3/cuda"
	"github.com/mumax/3/data"
	"github.com/mumax/3/util"
)

var (
	Alpha        = NewScalarParam("alpha", "", "Landau-Lifshitz damping constant", &temp_red)
	Xi           = NewScalarParam("xi", "", "Non-adiabaticity of spin-transfer-torque")
	Pol          = NewScalarParam("Pol", "", "Electrical current polarization")
	Lambda       = NewScalarParam("Lambda", "", "Slonczewski Λ parameter")
	EpsilonPrime = NewScalarParam("EpsilonPrime", "", "Slonczewski secondairy STT term ε'")
	FrozenSpins  = NewScalarParam("frozenspins", "", "Defines spins that should be fixed") // 1 - frozen, 0 - free. TODO: check if it only contains 0/1 values

	FixedLayer                       = NewExcitation("FixedLayer", "", "Slonczewski fixed layer polarization")
	SpinPol							 = NewExcitation("SpinPol", "", "SOT spin polarization direction")
	Torque                           = NewVectorField("torque", "T", "Total torque/γ0", SetTorque)
	LLTorque                         = NewVectorField("LLtorque", "T", "Landau-Lifshitz torque/γ0", SetLLTorque)
	STTorque                         = NewVectorField("STTorque", "T", "Spin-transfer torque/γ0", AddSTTorque)
	SOTorque						 = NewVectorField("SOTorque", "T", "Spin-orbit torque/γ0", AddSOTorque)
	J                                = NewExcitation("J", "A/m2", "Electrical current density")
	MaxTorque                        = NewScalarValue("maxTorque", "T", "Maximum torque/γ0, over all cells", GetMaxTorque)
	GammaLL                  float64 = 1.7595e11 // Gyromagnetic ratio of spins, in rad/Ts
	Precess                          = true
	DisableZhangLiTorque             = false
	DisableSlonczewskiTorque         = false
	DisableSpinOrbitTorque           = false
	thetaSL      = NewScalarParam("thetaSL", "", "SOT Damping term efficiency")
	thetaFL      = NewScalarParam("thetaFL", "", "SOT Field term efficiency")
	// thetaSL float32                  = 0.14
	// thetaFL float32                  = 0.34
)

func init() {
	Pol.setUniform([]float64{1}) // default spin polarization
	Lambda.Set(1)                // sensible default value (?). TODO: should not be zero
	DeclVar("GammaLL", &GammaLL, "Gyromagnetic ratio in rad/Ts")
	DeclVar("DisableZhangLiTorque", &DisableZhangLiTorque, "Disables Zhang-Li torque (default=false)")
	DeclVar("DisableSlonczewskiTorque", &DisableSlonczewskiTorque, "Disables Slonczewski torque (default=false)")
	DeclVar("DisableSpinOrbitTorque", &DisableSpinOrbitTorque, "Disables SOT (default=false)")	
	DeclVar("DoPrecess", &Precess, "Enables LL precession (default=true)")
}

// Sets dst to the current total torque
// TODO: extensible
func SetTorque(dst *data.Slice) {
	SetLLTorque(dst)
	AddSTTorque(dst)
	AddSOTorque(dst)
	FreezeSpins(dst)
}

// Sets dst to the current Landau-Lifshitz torque
func SetLLTorque(dst *data.Slice) {
	SetEffectiveField(dst) // calc and store B_eff
	if Precess {
		cuda.LLTorque(dst, M.Buffer(), dst, Alpha.gpuLUT1(), regions.Gpu()) // overwrite dst with torque
	} else {
		cuda.LLNoPrecess(dst, M.Buffer(), dst)
	}
}

// Adds the current spin transfer torque to dst
func AddSTTorque(dst *data.Slice) {
	if J.isZero() {
		return
	}
	util.AssertMsg(!Pol.isZero(), "spin polarization should not be 0")
	jspin, rec := J.Slice()
	if rec {
		defer cuda.Recycle(jspin)
	}
	fl, rec := FixedLayer.Slice()
	if rec {
		defer cuda.Recycle(fl)
	}
	if !DisableZhangLiTorque {
		cuda.AddZhangLiTorque(dst, M.Buffer(), jspin, Bsat.gpuLUT1(),
			Alpha.gpuLUT1(), Xi.gpuLUT1(), Pol.gpuLUT1(), regions.Gpu(), Mesh())
	}
	if !DisableSlonczewskiTorque && !FixedLayer.isZero() {
		cuda.AddSlonczewskiTorque(dst, M.Buffer(), jspin, fl, Msat.gpuLUT1(),
			Alpha.gpuLUT1(), Pol.gpuLUT1(), Lambda.gpuLUT1(), EpsilonPrime.gpuLUT1(), regions.Gpu(), Mesh())
	}
}

//ADDED TORQUE TERM: Adds the spin orbit torque to dst
func AddSOTorque(dst *data.Slice) {
	if J.isZero() {
		return
	}
	//util.AssertMsg(!Pol.isZero(), "spin polarization should not be 0")
	jspin, rec := J.Slice()
	if rec {
		defer cuda.Recycle(jspin)
	}
	sp, rec := SpinPol.Slice()
	if rec {
		defer cuda.Recycle(sp)
	}
	//SOT efficiency parameters (change to be externally defined as material parameters)

	if !DisableSpinOrbitTorque && !SpinPol.isZero() {
		cuda.AddSpinOrbitTorque(dst, M.Buffer(), jspin, sp, Msat.gpuLUT1(),
			Alpha.gpuLUT1(), thetaSL.gpuLUT1(), thetaFL.gpuLUT1(), regions.Gpu(), Mesh())
	}
}


func FreezeSpins(dst *data.Slice) {
	if !FrozenSpins.isZero() {
		cuda.ZeroMask(dst, FrozenSpins.gpuLUT1(), regions.Gpu())
	}
}

// Gets
func GetMaxTorque() float64 {
	torque, recycle := Torque.Slice()
	if recycle {
		defer cuda.Recycle(torque)
	}
	return cuda.MaxVecNorm(torque)
}

