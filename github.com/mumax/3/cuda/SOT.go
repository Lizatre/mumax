package cuda

import (
	"unsafe"
	"github.com/mumax/3/data"
)

// Add Slonczewski ST torque to torque (Tesla).
// see slonczewski.cu
func AddSpinOrbitTorque(torque, m, J, sigma *data.Slice, Msat LUTPtr, alpha LUTPtr, tSL LUTPtr, tFL LUTPtr, regions *Bytes, mesh *data.Mesh) {
	N := torque.Len()
	cfg := make1DConf(N)
	thickness := float32(mesh.WorldSize()[Z])
	jc := J.DevPtr(X)

	k_addspinorbittorque_async(torque.DevPtr(X), torque.DevPtr(Y), torque.DevPtr(Z),
		m.DevPtr(X), m.DevPtr(Y), m.DevPtr(Z), unsafe.Pointer(jc),
		sigma.DevPtr(X), sigma.DevPtr(Y), sigma.DevPtr(Z),
		unsafe.Pointer(Msat), unsafe.Pointer(alpha),
		thickness, unsafe.Pointer(tSL), unsafe.Pointer(tFL),
		regions.Ptr, N, cfg)
}
