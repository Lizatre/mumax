// Original implementation by Mykola Dvornik for mumax2
// Modified for mumax3 by Arne Vansteenkiste, 2013

#include <stdint.h>
#include "float3.h"
#include "constants.h"

extern "C" __global__ void
addspinorbittorque(float* __restrict__ tx, float* __restrict__ ty, float* __restrict__ tz,
                     float* __restrict__ mx, float* __restrict__ my, float* __restrict__ mz, float* __restrict__ jz,
                     float* __restrict__ sigx, float* __restrict__ sigy, float* __restrict__ sigz,
                     float* __restrict__ msatLUT, float* __restrict__ alphaLUT, float flt, 
                     float* __restrict__ tSL, float* __restrict__ tFL, 
                     uint8_t* __restrict__ regions, int N) {

	int I =  ( blockIdx.y*gridDim.x + blockIdx.x ) * blockDim.x + threadIdx.x;
	if (I < N) {
		//I=0;

		float3 m = make_float3(mx[I], my[I], mz[I]);
		float  J = jz[I];
		float3 sigma = normalized(make_float3(sigx[I], sigy[I], sigz[I]));

		// read parameters
		uint8_t region       = regions[I];

		float  Ms           = msatLUT[region];
		float  alpha 		= alphaLUT[region];
		float  thetaSL      = tSL[region];
		float  thetaFL      = tFL[region];



		if (J == 0.0f || Ms == 0.0f) {
			return;
		}

		float beta    = (HBAR / QE) * (J / (2*flt*Ms) );
		float gilb     = -1.0f / (1.0f + alpha * alpha);
		if (J < 0.0f) {
			J = -1.0f*J;		}
		float cnst     = gilb * beta;
		float tauS     = cnst * thetaSL;
		float tauF     = cnst * thetaFL;



		float3 mxsig   = cross(m, sigma);
		float3 mxmxsig = cross(m, mxsig);

		tx[I] += tauF * mxsig.x + tauS * mxmxsig.x;
		ty[I] += tauF * mxsig.y + tauS * mxmxsig.y;
		tz[I] += tauF * mxsig.z + tauS * mxmxsig.z;





	}
}

