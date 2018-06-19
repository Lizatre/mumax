#define SIMD_HEADER "simd-sse2.h"
/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Tue Mar  4 13:47:54 EST 2014 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_twiddle.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -twiddle-log3 -precompute-twiddles -n 16 -name t2sv_16 -include ts.h */

/*
 * This function contains 196 FP additions, 134 FP multiplications,
 * (or, 104 additions, 42 multiplications, 92 fused multiply/add),
 * 120 stack variables, 3 constants, and 64 memory accesses
 */
#include "ts.h"

static void t2sv_16(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP923879532, +0.923879532511286756128183189396788286822416626);
     DVK(KP414213562, +0.414213562373095048801688724209698078569671875);
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT m;
	  for (m = mb, W = W + (mb * 8); m < me; m = m + (2 * VL), ri = ri + ((2 * VL) * ms), ii = ii + ((2 * VL) * ms), W = W + ((2 * VL) * 8), MAKE_VOLATILE_STRIDE(32, rs)) {
	       V T34, T30, T2N, T2v, T2M, T2g, T3V, T3X, T32, T2U, T33, T2X, T2O, T2K, T3P;
	       V T3R;
	       {
		    V T2, Tf, TM, TO, T3, T6, T5, Th;
		    T2 = LDW(&(W[0]));
		    Tf = LDW(&(W[TWVL * 2]));
		    TM = LDW(&(W[TWVL * 6]));
		    TO = LDW(&(W[TWVL * 7]));
		    T3 = LDW(&(W[TWVL * 4]));
		    T6 = LDW(&(W[TWVL * 5]));
		    T5 = LDW(&(W[TWVL * 1]));
		    Th = LDW(&(W[TWVL * 3]));
		    {
			 V TW, TZ, Te, T1U, T3A, T3L, T2D, T1G, T3h, T2A, T2B, T1R, T3i, T2I, Tx;
			 V T3M, T1Z, T3w, TL, T26, T25, T37, T1l, T2q, T1d, T2o, T2l, T3c, T1r, T2s;
			 V TX, T10, TV, T2a;
			 {
			      V Tz, TP, TT, Tq, TF, Tu, TI, Tm, TC, T1j, T1p, T1m, T1f, T1O, T1M;
			      V T1K, T2F, Tj, Tn, T1Q, T2G, Tk, T1V, Tr, Tv;
			      {
				   V T1, Ti, Tb, T3z, T8, Tc, T1u, T1D, T1L, T1z, T9, T3x, T1v, T1w, T1A;
				   V T1E;
				   {
					V T7, T1i, T1e, T1C, T1y;
					T1 = LD(&(ri[0]), ms, &(ri[0]));
					{
					     V Tg, TN, TS, Tp;
					     Tg = VMUL(T2, Tf);
					     TN = VMUL(T2, TM);
					     TS = VMUL(T2, TO);
					     Tp = VMUL(Tf, T3);
					     {
						  V T4, Tt, Ta, Tl;
						  T4 = VMUL(T2, T3);
						  Tt = VMUL(Tf, T6);
						  Ta = VMUL(T2, T6);
						  Tl = VMUL(T2, Th);
						  Ti = VFNMS(T5, Th, Tg);
						  Tz = VFMA(T5, Th, Tg);
						  TP = VFMA(T5, TO, TN);
						  TT = VFNMS(T5, TM, TS);
						  TW = VFMA(Th, T6, Tp);
						  Tq = VFNMS(Th, T6, Tp);
						  TF = VFNMS(T5, T6, T4);
						  T7 = VFMA(T5, T6, T4);
						  Tu = VFMA(Th, T3, Tt);
						  TZ = VFNMS(Th, T3, Tt);
						  TI = VFMA(T5, T3, Ta);
						  Tb = VFNMS(T5, T3, Ta);
						  Tm = VFMA(T5, Tf, Tl);
						  TC = VFNMS(T5, Tf, Tl);
						  T1i = VMUL(Ti, T6);
						  T1e = VMUL(Ti, T3);
						  T1C = VMUL(Tz, T6);
						  T1y = VMUL(Tz, T3);
						  T3z = LD(&(ii[0]), ms, &(ii[0]));
					     }
					}
					T8 = LD(&(ri[WS(rs, 8)]), ms, &(ri[0]));
					Tc = LD(&(ii[WS(rs, 8)]), ms, &(ii[0]));
					T1u = LD(&(ri[WS(rs, 15)]), ms, &(ri[WS(rs, 1)]));
					T1j = VFNMS(Tm, T3, T1i);
					T1p = VFMA(Tm, T3, T1i);
					T1m = VFNMS(Tm, T6, T1e);
					T1f = VFMA(Tm, T6, T1e);
					T1D = VFNMS(TC, T3, T1C);
					T1O = VFMA(TC, T3, T1C);
					T1L = VFNMS(TC, T6, T1y);
					T1z = VFMA(TC, T6, T1y);
					T9 = VMUL(T7, T8);
					T3x = VMUL(T7, Tc);
					T1v = VMUL(TM, T1u);
					T1w = LD(&(ii[WS(rs, 15)]), ms, &(ii[WS(rs, 1)]));
					T1A = LD(&(ri[WS(rs, 7)]), ms, &(ri[WS(rs, 1)]));
					T1E = LD(&(ii[WS(rs, 7)]), ms, &(ii[WS(rs, 1)]));
				   }
				   {
					V T1x, T2x, T1F, T2z, T1N, T1P;
					{
					     V T1H, T1J, T1I, T2E;
					     {
						  V Td, T3y, T2w, T1B, T2y;
						  T1H = LD(&(ri[WS(rs, 3)]), ms, &(ri[WS(rs, 1)]));
						  T1J = LD(&(ii[WS(rs, 3)]), ms, &(ii[WS(rs, 1)]));
						  Td = VFMA(Tb, Tc, T9);
						  T3y = VFNMS(Tb, T8, T3x);
						  T1M = LD(&(ri[WS(rs, 11)]), ms, &(ri[WS(rs, 1)]));
						  T1x = VFMA(TO, T1w, T1v);
						  T2w = VMUL(TM, T1w);
						  T1B = VMUL(T1z, T1A);
						  T2y = VMUL(T1z, T1E);
						  T1I = VMUL(Tf, T1H);
						  T2E = VMUL(Tf, T1J);
						  Te = VADD(T1, Td);
						  T1U = VSUB(T1, Td);
						  T3A = VADD(T3y, T3z);
						  T3L = VSUB(T3z, T3y);
						  T2x = VFNMS(TO, T1u, T2w);
						  T1F = VFMA(T1D, T1E, T1B);
						  T2z = VFNMS(T1D, T1A, T2y);
						  T1N = VMUL(T1L, T1M);
						  T1P = LD(&(ii[WS(rs, 11)]), ms, &(ii[WS(rs, 1)]));
					     }
					     T1K = VFMA(Th, T1J, T1I);
					     T2F = VFNMS(Th, T1H, T2E);
					}
					Tj = LD(&(ri[WS(rs, 4)]), ms, &(ri[0]));
					Tn = LD(&(ii[WS(rs, 4)]), ms, &(ii[0]));
					T2D = VSUB(T1x, T1F);
					T1G = VADD(T1x, T1F);
					T3h = VADD(T2x, T2z);
					T2A = VSUB(T2x, T2z);
					T1Q = VFMA(T1O, T1P, T1N);
					T2G = VMUL(T1L, T1P);
					Tk = VMUL(Ti, Tj);
					T1V = VMUL(Ti, Tn);
					Tr = LD(&(ri[WS(rs, 12)]), ms, &(ri[0]));
					Tv = LD(&(ii[WS(rs, 12)]), ms, &(ii[0]));
				   }
			      }
			      {
				   V TE, T22, T15, T17, TK, T16, T2h, T24, T19, T1b;
				   {
					V To, T1W, TG, TJ, Tw, T1Y, TH, T23;
					{
					     V TA, TD, TB, T21, T2H, Ts, T1X;
					     TA = LD(&(ri[WS(rs, 2)]), ms, &(ri[0]));
					     TD = LD(&(ii[WS(rs, 2)]), ms, &(ii[0]));
					     T2B = VSUB(T1K, T1Q);
					     T1R = VADD(T1K, T1Q);
					     T2H = VFNMS(T1O, T1M, T2G);
					     To = VFMA(Tm, Tn, Tk);
					     T1W = VFNMS(Tm, Tj, T1V);
					     Ts = VMUL(Tq, Tr);
					     T1X = VMUL(Tq, Tv);
					     TB = VMUL(Tz, TA);
					     T21 = VMUL(Tz, TD);
					     TG = LD(&(ri[WS(rs, 10)]), ms, &(ri[0]));
					     T3i = VADD(T2F, T2H);
					     T2I = VSUB(T2F, T2H);
					     TJ = LD(&(ii[WS(rs, 10)]), ms, &(ii[0]));
					     Tw = VFMA(Tu, Tv, Ts);
					     T1Y = VFNMS(Tu, Tr, T1X);
					     TE = VFMA(TC, TD, TB);
					     T22 = VFNMS(TC, TA, T21);
					     TH = VMUL(TF, TG);
					}
					T15 = LD(&(ri[WS(rs, 1)]), ms, &(ri[WS(rs, 1)]));
					T17 = LD(&(ii[WS(rs, 1)]), ms, &(ii[WS(rs, 1)]));
					T23 = VMUL(TF, TJ);
					Tx = VADD(To, Tw);
					T3M = VSUB(To, Tw);
					T1Z = VSUB(T1W, T1Y);
					T3w = VADD(T1W, T1Y);
					TK = VFMA(TI, TJ, TH);
					T16 = VMUL(T2, T15);
					T2h = VMUL(T2, T17);
					T24 = VFNMS(TI, TG, T23);
					T19 = LD(&(ri[WS(rs, 9)]), ms, &(ri[WS(rs, 1)]));
					T1b = LD(&(ii[WS(rs, 9)]), ms, &(ii[WS(rs, 1)]));
				   }
				   {
					V T1g, T1k, T18, T2i, T1a, T2j, T1h, T2p, T1n, T1q;
					T1g = LD(&(ri[WS(rs, 5)]), ms, &(ri[WS(rs, 1)]));
					T1k = LD(&(ii[WS(rs, 5)]), ms, &(ii[WS(rs, 1)]));
					TL = VADD(TE, TK);
					T26 = VSUB(TE, TK);
					T18 = VFMA(T5, T17, T16);
					T2i = VFNMS(T5, T15, T2h);
					T25 = VSUB(T22, T24);
					T37 = VADD(T22, T24);
					T1a = VMUL(T3, T19);
					T2j = VMUL(T3, T1b);
					T1h = VMUL(T1f, T1g);
					T2p = VMUL(T1f, T1k);
					T1n = LD(&(ri[WS(rs, 13)]), ms, &(ri[WS(rs, 1)]));
					T1q = LD(&(ii[WS(rs, 13)]), ms, &(ii[WS(rs, 1)]));
					{
					     V TQ, TU, TR, T29;
					     {
						  V T1c, T2k, T1o, T2r;
						  TQ = LD(&(ri[WS(rs, 14)]), ms, &(ri[0]));
						  TU = LD(&(ii[WS(rs, 14)]), ms, &(ii[0]));
						  T1c = VFMA(T6, T1b, T1a);
						  T2k = VFNMS(T6, T19, T2j);
						  T1l = VFMA(T1j, T1k, T1h);
						  T2q = VFNMS(T1j, T1g, T2p);
						  T1o = VMUL(T1m, T1n);
						  T2r = VMUL(T1m, T1q);
						  TR = VMUL(TP, TQ);
						  T29 = VMUL(TP, TU);
						  T1d = VADD(T18, T1c);
						  T2o = VSUB(T18, T1c);
						  T2l = VSUB(T2i, T2k);
						  T3c = VADD(T2i, T2k);
						  T1r = VFMA(T1p, T1q, T1o);
						  T2s = VFNMS(T1p, T1n, T2r);
						  TX = LD(&(ri[WS(rs, 6)]), ms, &(ri[0]));
						  T10 = LD(&(ii[WS(rs, 6)]), ms, &(ii[0]));
					     }
					     TV = VFMA(TT, TU, TR);
					     T2a = VFNMS(TT, TQ, T29);
					}
				   }
			      }
			 }
			 {
			      V T36, Ty, T3B, T3G, T1s, T2m, T2t, T3d, TY, T2b, T3g, T1S, T3s, T3j;
			      T36 = VSUB(Te, Tx);
			      Ty = VADD(Te, Tx);
			      T3B = VADD(T3w, T3A);
			      T3G = VSUB(T3A, T3w);
			      T1s = VADD(T1l, T1r);
			      T2m = VSUB(T1l, T1r);
			      T2t = VSUB(T2q, T2s);
			      T3d = VADD(T2q, T2s);
			      TY = VMUL(TW, TX);
			      T2b = VMUL(TW, T10);
			      T3g = VSUB(T1G, T1R);
			      T1S = VADD(T1G, T1R);
			      T3s = VADD(T3h, T3i);
			      T3j = VSUB(T3h, T3i);
			      {
				   V T3D, T1T, T3u, T3t, T28, T12, T38, T2d, T3n, T3f;
				   {
					V T1t, T3b, T3e, T3r, T11, T2c;
					T1t = VADD(T1d, T1s);
					T3b = VSUB(T1d, T1s);
					T3e = VSUB(T3c, T3d);
					T3r = VADD(T3c, T3d);
					T11 = VFMA(TZ, T10, TY);
					T2c = VFNMS(TZ, TX, T2b);
					T3D = VSUB(T1S, T1t);
					T1T = VADD(T1t, T1S);
					T3u = VADD(T3r, T3s);
					T3t = VSUB(T3r, T3s);
					T28 = VSUB(TV, T11);
					T12 = VADD(TV, T11);
					T38 = VADD(T2a, T2c);
					T2d = VSUB(T2a, T2c);
					T3n = VSUB(T3e, T3b);
					T3f = VADD(T3b, T3e);
				   }
				   {
					V T2Q, T20, T3N, T3T, T2J, T2C, T2W, T2V, T3O, T2f, T3U, T2T;
					{
					     V T2R, T27, T2e, T2S, T13, T3F;
					     T2Q = VADD(T1U, T1Z);
					     T20 = VSUB(T1U, T1Z);
					     T3N = VSUB(T3L, T3M);
					     T3T = VADD(T3M, T3L);
					     T13 = VADD(TL, T12);
					     T3F = VSUB(T12, TL);
					     {
						  V T3v, T39, T3o, T3k;
						  T3v = VADD(T37, T38);
						  T39 = VSUB(T37, T38);
						  T3o = VADD(T3g, T3j);
						  T3k = VSUB(T3g, T3j);
						  {
						       V T3H, T3J, T14, T3q;
						       T3H = VADD(T3F, T3G);
						       T3J = VSUB(T3G, T3F);
						       T14 = VADD(Ty, T13);
						       T3q = VSUB(Ty, T13);
						       {
							    V T3a, T3m, T3C, T3E;
							    T3a = VADD(T36, T39);
							    T3m = VSUB(T36, T39);
							    T3C = VADD(T3v, T3B);
							    T3E = VSUB(T3B, T3v);
							    {
								 V T3I, T3p, T3l, T3K;
								 T3I = VADD(T3n, T3o);
								 T3p = VSUB(T3n, T3o);
								 T3l = VADD(T3f, T3k);
								 T3K = VSUB(T3k, T3f);
								 ST(&(ri[WS(rs, 4)]), VADD(T3q, T3t), ms, &(ri[0]));
								 ST(&(ri[WS(rs, 12)]), VSUB(T3q, T3t), ms, &(ri[0]));
								 ST(&(ri[0]), VADD(T14, T1T), ms, &(ri[0]));
								 ST(&(ri[WS(rs, 8)]), VSUB(T14, T1T), ms, &(ri[0]));
								 ST(&(ii[WS(rs, 4)]), VADD(T3D, T3E), ms, &(ii[0]));
								 ST(&(ii[WS(rs, 12)]), VSUB(T3E, T3D), ms, &(ii[0]));
								 ST(&(ii[0]), VADD(T3u, T3C), ms, &(ii[0]));
								 ST(&(ii[WS(rs, 8)]), VSUB(T3C, T3u), ms, &(ii[0]));
								 ST(&(ri[WS(rs, 6)]), VFMA(LDK(KP707106781), T3p, T3m), ms, &(ri[0]));
								 ST(&(ri[WS(rs, 14)]), VFNMS(LDK(KP707106781), T3p, T3m), ms, &(ri[0]));
								 ST(&(ii[WS(rs, 10)]), VFNMS(LDK(KP707106781), T3I, T3H), ms, &(ii[0]));
								 ST(&(ii[WS(rs, 2)]), VFMA(LDK(KP707106781), T3I, T3H), ms, &(ii[0]));
								 ST(&(ii[WS(rs, 14)]), VFNMS(LDK(KP707106781), T3K, T3J), ms, &(ii[0]));
								 ST(&(ii[WS(rs, 6)]), VFMA(LDK(KP707106781), T3K, T3J), ms, &(ii[0]));
								 ST(&(ri[WS(rs, 2)]), VFMA(LDK(KP707106781), T3l, T3a), ms, &(ri[0]));
								 ST(&(ri[WS(rs, 10)]), VFNMS(LDK(KP707106781), T3l, T3a), ms, &(ri[0]));
								 T2R = VADD(T26, T25);
								 T27 = VSUB(T25, T26);
								 T2e = VADD(T28, T2d);
								 T2S = VSUB(T28, T2d);
							    }
						       }
						  }
					     }
					     {
						  V T2Y, T2Z, T2n, T2u;
						  T2J = VSUB(T2D, T2I);
						  T2Y = VADD(T2D, T2I);
						  T2Z = VSUB(T2A, T2B);
						  T2C = VADD(T2A, T2B);
						  T2W = VSUB(T2l, T2m);
						  T2n = VADD(T2l, T2m);
						  T2u = VSUB(T2o, T2t);
						  T2V = VADD(T2o, T2t);
						  T3O = VADD(T27, T2e);
						  T2f = VSUB(T27, T2e);
						  T34 = VFMA(LDK(KP414213562), T2Y, T2Z);
						  T30 = VFNMS(LDK(KP414213562), T2Z, T2Y);
						  T3U = VSUB(T2S, T2R);
						  T2T = VADD(T2R, T2S);
						  T2N = VFNMS(LDK(KP414213562), T2n, T2u);
						  T2v = VFMA(LDK(KP414213562), T2u, T2n);
					     }
					}
					T2M = VFNMS(LDK(KP707106781), T2f, T20);
					T2g = VFMA(LDK(KP707106781), T2f, T20);
					T3V = VFMA(LDK(KP707106781), T3U, T3T);
					T3X = VFNMS(LDK(KP707106781), T3U, T3T);
					T32 = VFNMS(LDK(KP707106781), T2T, T2Q);
					T2U = VFMA(LDK(KP707106781), T2T, T2Q);
					T33 = VFNMS(LDK(KP414213562), T2V, T2W);
					T2X = VFMA(LDK(KP414213562), T2W, T2V);
					T2O = VFMA(LDK(KP414213562), T2C, T2J);
					T2K = VFNMS(LDK(KP414213562), T2J, T2C);
					T3P = VFMA(LDK(KP707106781), T3O, T3N);
					T3R = VFNMS(LDK(KP707106781), T3O, T3N);
				   }
			      }
			 }
		    }
	       }
	       {
		    V T3Q, T35, T31, T3S;
		    T3Q = VADD(T33, T34);
		    T35 = VSUB(T33, T34);
		    T31 = VADD(T2X, T30);
		    T3S = VSUB(T30, T2X);
		    {
			 V T3W, T2P, T2L, T3Y;
			 T3W = VSUB(T2O, T2N);
			 T2P = VADD(T2N, T2O);
			 T2L = VSUB(T2v, T2K);
			 T3Y = VADD(T2v, T2K);
			 ST(&(ri[WS(rs, 5)]), VFMA(LDK(KP923879532), T35, T32), ms, &(ri[WS(rs, 1)]));
			 ST(&(ri[WS(rs, 13)]), VFNMS(LDK(KP923879532), T35, T32), ms, &(ri[WS(rs, 1)]));
			 ST(&(ii[WS(rs, 9)]), VFNMS(LDK(KP923879532), T3Q, T3P), ms, &(ii[WS(rs, 1)]));
			 ST(&(ii[WS(rs, 1)]), VFMA(LDK(KP923879532), T3Q, T3P), ms, &(ii[WS(rs, 1)]));
			 ST(&(ii[WS(rs, 13)]), VFNMS(LDK(KP923879532), T3S, T3R), ms, &(ii[WS(rs, 1)]));
			 ST(&(ii[WS(rs, 5)]), VFMA(LDK(KP923879532), T3S, T3R), ms, &(ii[WS(rs, 1)]));
			 ST(&(ri[WS(rs, 1)]), VFMA(LDK(KP923879532), T31, T2U), ms, &(ri[WS(rs, 1)]));
			 ST(&(ri[WS(rs, 9)]), VFNMS(LDK(KP923879532), T31, T2U), ms, &(ri[WS(rs, 1)]));
			 ST(&(ri[WS(rs, 15)]), VFMA(LDK(KP923879532), T2P, T2M), ms, &(ri[WS(rs, 1)]));
			 ST(&(ri[WS(rs, 7)]), VFNMS(LDK(KP923879532), T2P, T2M), ms, &(ri[WS(rs, 1)]));
			 ST(&(ii[WS(rs, 11)]), VFNMS(LDK(KP923879532), T3W, T3V), ms, &(ii[WS(rs, 1)]));
			 ST(&(ii[WS(rs, 3)]), VFMA(LDK(KP923879532), T3W, T3V), ms, &(ii[WS(rs, 1)]));
			 ST(&(ii[WS(rs, 15)]), VFMA(LDK(KP923879532), T3Y, T3X), ms, &(ii[WS(rs, 1)]));
			 ST(&(ii[WS(rs, 7)]), VFNMS(LDK(KP923879532), T3Y, T3X), ms, &(ii[WS(rs, 1)]));
			 ST(&(ri[WS(rs, 3)]), VFMA(LDK(KP923879532), T2L, T2g), ms, &(ri[WS(rs, 1)]));
			 ST(&(ri[WS(rs, 11)]), VFNMS(LDK(KP923879532), T2L, T2g), ms, &(ri[WS(rs, 1)]));
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 3),
     VTW(0, 9),
     VTW(0, 15),
     {TW_NEXT, (2 * VL), 0}
};

static const ct_desc desc = { 16, XSIMD_STRING("t2sv_16"), twinstr, &GENUS, {104, 42, 92, 0}, 0, 0, 0 };

void XSIMD(codelet_t2sv_16) (planner *p) {
     X(kdft_dit_register) (p, t2sv_16, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_twiddle.native -simd -compact -variables 4 -pipeline-latency 8 -twiddle-log3 -precompute-twiddles -n 16 -name t2sv_16 -include ts.h */

/*
 * This function contains 196 FP additions, 108 FP multiplications,
 * (or, 156 additions, 68 multiplications, 40 fused multiply/add),
 * 82 stack variables, 3 constants, and 64 memory accesses
 */
#include "ts.h"

static void t2sv_16(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP382683432, +0.382683432365089771728459984030398866761344562);
     DVK(KP923879532, +0.923879532511286756128183189396788286822416626);
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT m;
	  for (m = mb, W = W + (mb * 8); m < me; m = m + (2 * VL), ri = ri + ((2 * VL) * ms), ii = ii + ((2 * VL) * ms), W = W + ((2 * VL) * 8), MAKE_VOLATILE_STRIDE(32, rs)) {
	       V T2, T5, Tg, Ti, Tk, To, TE, TC, T6, T3, T8, TW, TJ, Tt, TU;
	       V Tc, Tx, TH, TN, TO, TP, TR, T1f, T1k, T1b, T1i, T1y, T1H, T1u, T1F;
	       {
		    V T7, Tv, Ta, Ts, T4, Tw, Tb, Tr;
		    {
			 V Th, Tn, Tj, Tm;
			 T2 = LDW(&(W[0]));
			 T5 = LDW(&(W[TWVL * 1]));
			 Tg = LDW(&(W[TWVL * 2]));
			 Ti = LDW(&(W[TWVL * 3]));
			 Th = VMUL(T2, Tg);
			 Tn = VMUL(T5, Tg);
			 Tj = VMUL(T5, Ti);
			 Tm = VMUL(T2, Ti);
			 Tk = VSUB(Th, Tj);
			 To = VADD(Tm, Tn);
			 TE = VSUB(Tm, Tn);
			 TC = VADD(Th, Tj);
			 T6 = LDW(&(W[TWVL * 5]));
			 T7 = VMUL(T5, T6);
			 Tv = VMUL(Tg, T6);
			 Ta = VMUL(T2, T6);
			 Ts = VMUL(Ti, T6);
			 T3 = LDW(&(W[TWVL * 4]));
			 T4 = VMUL(T2, T3);
			 Tw = VMUL(Ti, T3);
			 Tb = VMUL(T5, T3);
			 Tr = VMUL(Tg, T3);
		    }
		    T8 = VADD(T4, T7);
		    TW = VSUB(Tv, Tw);
		    TJ = VADD(Ta, Tb);
		    Tt = VSUB(Tr, Ts);
		    TU = VADD(Tr, Ts);
		    Tc = VSUB(Ta, Tb);
		    Tx = VADD(Tv, Tw);
		    TH = VSUB(T4, T7);
		    TN = LDW(&(W[TWVL * 6]));
		    TO = LDW(&(W[TWVL * 7]));
		    TP = VFMA(T2, TN, VMUL(T5, TO));
		    TR = VFNMS(T5, TN, VMUL(T2, TO));
		    {
			 V T1d, T1e, T19, T1a;
			 T1d = VMUL(Tk, T6);
			 T1e = VMUL(To, T3);
			 T1f = VSUB(T1d, T1e);
			 T1k = VADD(T1d, T1e);
			 T19 = VMUL(Tk, T3);
			 T1a = VMUL(To, T6);
			 T1b = VADD(T19, T1a);
			 T1i = VSUB(T19, T1a);
		    }
		    {
			 V T1w, T1x, T1s, T1t;
			 T1w = VMUL(TC, T6);
			 T1x = VMUL(TE, T3);
			 T1y = VSUB(T1w, T1x);
			 T1H = VADD(T1w, T1x);
			 T1s = VMUL(TC, T3);
			 T1t = VMUL(TE, T6);
			 T1u = VADD(T1s, T1t);
			 T1F = VSUB(T1s, T1t);
		    }
	       }
	       {
		    V Tf, T3r, T1N, T3e, TA, T3s, T1Q, T3b, TM, T2M, T1W, T2w, TZ, T2N, T21;
		    V T2x, T1B, T1K, T2V, T2W, T2X, T2Y, T2j, T2D, T2o, T2E, T18, T1n, T2Q, T2R;
		    V T2S, T2T, T28, T2A, T2d, T2B;
		    {
			 V T1, T3d, Te, T3c, T9, Td;
			 T1 = LD(&(ri[0]), ms, &(ri[0]));
			 T3d = LD(&(ii[0]), ms, &(ii[0]));
			 T9 = LD(&(ri[WS(rs, 8)]), ms, &(ri[0]));
			 Td = LD(&(ii[WS(rs, 8)]), ms, &(ii[0]));
			 Te = VFMA(T8, T9, VMUL(Tc, Td));
			 T3c = VFNMS(Tc, T9, VMUL(T8, Td));
			 Tf = VADD(T1, Te);
			 T3r = VSUB(T3d, T3c);
			 T1N = VSUB(T1, Te);
			 T3e = VADD(T3c, T3d);
		    }
		    {
			 V Tq, T1O, Tz, T1P;
			 {
			      V Tl, Tp, Tu, Ty;
			      Tl = LD(&(ri[WS(rs, 4)]), ms, &(ri[0]));
			      Tp = LD(&(ii[WS(rs, 4)]), ms, &(ii[0]));
			      Tq = VFMA(Tk, Tl, VMUL(To, Tp));
			      T1O = VFNMS(To, Tl, VMUL(Tk, Tp));
			      Tu = LD(&(ri[WS(rs, 12)]), ms, &(ri[0]));
			      Ty = LD(&(ii[WS(rs, 12)]), ms, &(ii[0]));
			      Tz = VFMA(Tt, Tu, VMUL(Tx, Ty));
			      T1P = VFNMS(Tx, Tu, VMUL(Tt, Ty));
			 }
			 TA = VADD(Tq, Tz);
			 T3s = VSUB(Tq, Tz);
			 T1Q = VSUB(T1O, T1P);
			 T3b = VADD(T1O, T1P);
		    }
		    {
			 V TG, T1S, TL, T1T, T1U, T1V;
			 {
			      V TD, TF, TI, TK;
			      TD = LD(&(ri[WS(rs, 2)]), ms, &(ri[0]));
			      TF = LD(&(ii[WS(rs, 2)]), ms, &(ii[0]));
			      TG = VFMA(TC, TD, VMUL(TE, TF));
			      T1S = VFNMS(TE, TD, VMUL(TC, TF));
			      TI = LD(&(ri[WS(rs, 10)]), ms, &(ri[0]));
			      TK = LD(&(ii[WS(rs, 10)]), ms, &(ii[0]));
			      TL = VFMA(TH, TI, VMUL(TJ, TK));
			      T1T = VFNMS(TJ, TI, VMUL(TH, TK));
			 }
			 TM = VADD(TG, TL);
			 T2M = VADD(T1S, T1T);
			 T1U = VSUB(T1S, T1T);
			 T1V = VSUB(TG, TL);
			 T1W = VSUB(T1U, T1V);
			 T2w = VADD(T1V, T1U);
		    }
		    {
			 V TT, T1Y, TY, T1Z, T1X, T20;
			 {
			      V TQ, TS, TV, TX;
			      TQ = LD(&(ri[WS(rs, 14)]), ms, &(ri[0]));
			      TS = LD(&(ii[WS(rs, 14)]), ms, &(ii[0]));
			      TT = VFMA(TP, TQ, VMUL(TR, TS));
			      T1Y = VFNMS(TR, TQ, VMUL(TP, TS));
			      TV = LD(&(ri[WS(rs, 6)]), ms, &(ri[0]));
			      TX = LD(&(ii[WS(rs, 6)]), ms, &(ii[0]));
			      TY = VFMA(TU, TV, VMUL(TW, TX));
			      T1Z = VFNMS(TW, TV, VMUL(TU, TX));
			 }
			 TZ = VADD(TT, TY);
			 T2N = VADD(T1Y, T1Z);
			 T1X = VSUB(TT, TY);
			 T20 = VSUB(T1Y, T1Z);
			 T21 = VADD(T1X, T20);
			 T2x = VSUB(T1X, T20);
		    }
		    {
			 V T1r, T2k, T1J, T2h, T1A, T2l, T1E, T2g;
			 {
			      V T1p, T1q, T1G, T1I;
			      T1p = LD(&(ri[WS(rs, 15)]), ms, &(ri[WS(rs, 1)]));
			      T1q = LD(&(ii[WS(rs, 15)]), ms, &(ii[WS(rs, 1)]));
			      T1r = VFMA(TN, T1p, VMUL(TO, T1q));
			      T2k = VFNMS(TO, T1p, VMUL(TN, T1q));
			      T1G = LD(&(ri[WS(rs, 11)]), ms, &(ri[WS(rs, 1)]));
			      T1I = LD(&(ii[WS(rs, 11)]), ms, &(ii[WS(rs, 1)]));
			      T1J = VFMA(T1F, T1G, VMUL(T1H, T1I));
			      T2h = VFNMS(T1H, T1G, VMUL(T1F, T1I));
			 }
			 {
			      V T1v, T1z, T1C, T1D;
			      T1v = LD(&(ri[WS(rs, 7)]), ms, &(ri[WS(rs, 1)]));
			      T1z = LD(&(ii[WS(rs, 7)]), ms, &(ii[WS(rs, 1)]));
			      T1A = VFMA(T1u, T1v, VMUL(T1y, T1z));
			      T2l = VFNMS(T1y, T1v, VMUL(T1u, T1z));
			      T1C = LD(&(ri[WS(rs, 3)]), ms, &(ri[WS(rs, 1)]));
			      T1D = LD(&(ii[WS(rs, 3)]), ms, &(ii[WS(rs, 1)]));
			      T1E = VFMA(Tg, T1C, VMUL(Ti, T1D));
			      T2g = VFNMS(Ti, T1C, VMUL(Tg, T1D));
			 }
			 T1B = VADD(T1r, T1A);
			 T1K = VADD(T1E, T1J);
			 T2V = VSUB(T1B, T1K);
			 T2W = VADD(T2k, T2l);
			 T2X = VADD(T2g, T2h);
			 T2Y = VSUB(T2W, T2X);
			 {
			      V T2f, T2i, T2m, T2n;
			      T2f = VSUB(T1r, T1A);
			      T2i = VSUB(T2g, T2h);
			      T2j = VSUB(T2f, T2i);
			      T2D = VADD(T2f, T2i);
			      T2m = VSUB(T2k, T2l);
			      T2n = VSUB(T1E, T1J);
			      T2o = VADD(T2m, T2n);
			      T2E = VSUB(T2m, T2n);
			 }
		    }
		    {
			 V T14, T24, T1m, T2b, T17, T25, T1h, T2a;
			 {
			      V T12, T13, T1j, T1l;
			      T12 = LD(&(ri[WS(rs, 1)]), ms, &(ri[WS(rs, 1)]));
			      T13 = LD(&(ii[WS(rs, 1)]), ms, &(ii[WS(rs, 1)]));
			      T14 = VFMA(T2, T12, VMUL(T5, T13));
			      T24 = VFNMS(T5, T12, VMUL(T2, T13));
			      T1j = LD(&(ri[WS(rs, 13)]), ms, &(ri[WS(rs, 1)]));
			      T1l = LD(&(ii[WS(rs, 13)]), ms, &(ii[WS(rs, 1)]));
			      T1m = VFMA(T1i, T1j, VMUL(T1k, T1l));
			      T2b = VFNMS(T1k, T1j, VMUL(T1i, T1l));
			 }
			 {
			      V T15, T16, T1c, T1g;
			      T15 = LD(&(ri[WS(rs, 9)]), ms, &(ri[WS(rs, 1)]));
			      T16 = LD(&(ii[WS(rs, 9)]), ms, &(ii[WS(rs, 1)]));
			      T17 = VFMA(T3, T15, VMUL(T6, T16));
			      T25 = VFNMS(T6, T15, VMUL(T3, T16));
			      T1c = LD(&(ri[WS(rs, 5)]), ms, &(ri[WS(rs, 1)]));
			      T1g = LD(&(ii[WS(rs, 5)]), ms, &(ii[WS(rs, 1)]));
			      T1h = VFMA(T1b, T1c, VMUL(T1f, T1g));
			      T2a = VFNMS(T1f, T1c, VMUL(T1b, T1g));
			 }
			 T18 = VADD(T14, T17);
			 T1n = VADD(T1h, T1m);
			 T2Q = VSUB(T18, T1n);
			 T2R = VADD(T24, T25);
			 T2S = VADD(T2a, T2b);
			 T2T = VSUB(T2R, T2S);
			 {
			      V T26, T27, T29, T2c;
			      T26 = VSUB(T24, T25);
			      T27 = VSUB(T1h, T1m);
			      T28 = VADD(T26, T27);
			      T2A = VSUB(T26, T27);
			      T29 = VSUB(T14, T17);
			      T2c = VSUB(T2a, T2b);
			      T2d = VSUB(T29, T2c);
			      T2B = VADD(T29, T2c);
			 }
		    }
		    {
			 V T23, T2r, T3A, T3C, T2q, T3B, T2u, T3x;
			 {
			      V T1R, T22, T3y, T3z;
			      T1R = VSUB(T1N, T1Q);
			      T22 = VMUL(LDK(KP707106781), VSUB(T1W, T21));
			      T23 = VADD(T1R, T22);
			      T2r = VSUB(T1R, T22);
			      T3y = VMUL(LDK(KP707106781), VSUB(T2x, T2w));
			      T3z = VADD(T3s, T3r);
			      T3A = VADD(T3y, T3z);
			      T3C = VSUB(T3z, T3y);
			 }
			 {
			      V T2e, T2p, T2s, T2t;
			      T2e = VFMA(LDK(KP923879532), T28, VMUL(LDK(KP382683432), T2d));
			      T2p = VFNMS(LDK(KP923879532), T2o, VMUL(LDK(KP382683432), T2j));
			      T2q = VADD(T2e, T2p);
			      T3B = VSUB(T2p, T2e);
			      T2s = VFNMS(LDK(KP923879532), T2d, VMUL(LDK(KP382683432), T28));
			      T2t = VFMA(LDK(KP382683432), T2o, VMUL(LDK(KP923879532), T2j));
			      T2u = VSUB(T2s, T2t);
			      T3x = VADD(T2s, T2t);
			 }
			 ST(&(ri[WS(rs, 11)]), VSUB(T23, T2q), ms, &(ri[WS(rs, 1)]));
			 ST(&(ii[WS(rs, 11)]), VSUB(T3A, T3x), ms, &(ii[WS(rs, 1)]));
			 ST(&(ri[WS(rs, 3)]), VADD(T23, T2q), ms, &(ri[WS(rs, 1)]));
			 ST(&(ii[WS(rs, 3)]), VADD(T3x, T3A), ms, &(ii[WS(rs, 1)]));
			 ST(&(ri[WS(rs, 15)]), VSUB(T2r, T2u), ms, &(ri[WS(rs, 1)]));
			 ST(&(ii[WS(rs, 15)]), VSUB(T3C, T3B), ms, &(ii[WS(rs, 1)]));
			 ST(&(ri[WS(rs, 7)]), VADD(T2r, T2u), ms, &(ri[WS(rs, 1)]));
			 ST(&(ii[WS(rs, 7)]), VADD(T3B, T3C), ms, &(ii[WS(rs, 1)]));
		    }
		    {
			 V T2P, T31, T3m, T3o, T30, T3n, T34, T3j;
			 {
			      V T2L, T2O, T3k, T3l;
			      T2L = VSUB(Tf, TA);
			      T2O = VSUB(T2M, T2N);
			      T2P = VADD(T2L, T2O);
			      T31 = VSUB(T2L, T2O);
			      T3k = VSUB(TZ, TM);
			      T3l = VSUB(T3e, T3b);
			      T3m = VADD(T3k, T3l);
			      T3o = VSUB(T3l, T3k);
			 }
			 {
			      V T2U, T2Z, T32, T33;
			      T2U = VADD(T2Q, T2T);
			      T2Z = VSUB(T2V, T2Y);
			      T30 = VMUL(LDK(KP707106781), VADD(T2U, T2Z));
			      T3n = VMUL(LDK(KP707106781), VSUB(T2Z, T2U));
			      T32 = VSUB(T2T, T2Q);
			      T33 = VADD(T2V, T2Y);
			      T34 = VMUL(LDK(KP707106781), VSUB(T32, T33));
			      T3j = VMUL(LDK(KP707106781), VADD(T32, T33));
			 }
			 ST(&(ri[WS(rs, 10)]), VSUB(T2P, T30), ms, &(ri[0]));
			 ST(&(ii[WS(rs, 10)]), VSUB(T3m, T3j), ms, &(ii[0]));
			 ST(&(ri[WS(rs, 2)]), VADD(T2P, T30), ms, &(ri[0]));
			 ST(&(ii[WS(rs, 2)]), VADD(T3j, T3m), ms, &(ii[0]));
			 ST(&(ri[WS(rs, 14)]), VSUB(T31, T34), ms, &(ri[0]));
			 ST(&(ii[WS(rs, 14)]), VSUB(T3o, T3n), ms, &(ii[0]));
			 ST(&(ri[WS(rs, 6)]), VADD(T31, T34), ms, &(ri[0]));
			 ST(&(ii[WS(rs, 6)]), VADD(T3n, T3o), ms, &(ii[0]));
		    }
		    {
			 V T2z, T2H, T3u, T3w, T2G, T3v, T2K, T3p;
			 {
			      V T2v, T2y, T3q, T3t;
			      T2v = VADD(T1N, T1Q);
			      T2y = VMUL(LDK(KP707106781), VADD(T2w, T2x));
			      T2z = VADD(T2v, T2y);
			      T2H = VSUB(T2v, T2y);
			      T3q = VMUL(LDK(KP707106781), VADD(T1W, T21));
			      T3t = VSUB(T3r, T3s);
			      T3u = VADD(T3q, T3t);
			      T3w = VSUB(T3t, T3q);
			 }
			 {
			      V T2C, T2F, T2I, T2J;
			      T2C = VFMA(LDK(KP382683432), T2A, VMUL(LDK(KP923879532), T2B));
			      T2F = VFNMS(LDK(KP382683432), T2E, VMUL(LDK(KP923879532), T2D));
			      T2G = VADD(T2C, T2F);
			      T3v = VSUB(T2F, T2C);
			      T2I = VFNMS(LDK(KP382683432), T2B, VMUL(LDK(KP923879532), T2A));
			      T2J = VFMA(LDK(KP923879532), T2E, VMUL(LDK(KP382683432), T2D));
			      T2K = VSUB(T2I, T2J);
			      T3p = VADD(T2I, T2J);
			 }
			 ST(&(ri[WS(rs, 9)]), VSUB(T2z, T2G), ms, &(ri[WS(rs, 1)]));
			 ST(&(ii[WS(rs, 9)]), VSUB(T3u, T3p), ms, &(ii[WS(rs, 1)]));
			 ST(&(ri[WS(rs, 1)]), VADD(T2z, T2G), ms, &(ri[WS(rs, 1)]));
			 ST(&(ii[WS(rs, 1)]), VADD(T3p, T3u), ms, &(ii[WS(rs, 1)]));
			 ST(&(ri[WS(rs, 13)]), VSUB(T2H, T2K), ms, &(ri[WS(rs, 1)]));
			 ST(&(ii[WS(rs, 13)]), VSUB(T3w, T3v), ms, &(ii[WS(rs, 1)]));
			 ST(&(ri[WS(rs, 5)]), VADD(T2H, T2K), ms, &(ri[WS(rs, 1)]));
			 ST(&(ii[WS(rs, 5)]), VADD(T3v, T3w), ms, &(ii[WS(rs, 1)]));
		    }
		    {
			 V T11, T35, T3g, T3i, T1M, T3h, T38, T39;
			 {
			      V TB, T10, T3a, T3f;
			      TB = VADD(Tf, TA);
			      T10 = VADD(TM, TZ);
			      T11 = VADD(TB, T10);
			      T35 = VSUB(TB, T10);
			      T3a = VADD(T2M, T2N);
			      T3f = VADD(T3b, T3e);
			      T3g = VADD(T3a, T3f);
			      T3i = VSUB(T3f, T3a);
			 }
			 {
			      V T1o, T1L, T36, T37;
			      T1o = VADD(T18, T1n);
			      T1L = VADD(T1B, T1K);
			      T1M = VADD(T1o, T1L);
			      T3h = VSUB(T1L, T1o);
			      T36 = VADD(T2R, T2S);
			      T37 = VADD(T2W, T2X);
			      T38 = VSUB(T36, T37);
			      T39 = VADD(T36, T37);
			 }
			 ST(&(ri[WS(rs, 8)]), VSUB(T11, T1M), ms, &(ri[0]));
			 ST(&(ii[WS(rs, 8)]), VSUB(T3g, T39), ms, &(ii[0]));
			 ST(&(ri[0]), VADD(T11, T1M), ms, &(ri[0]));
			 ST(&(ii[0]), VADD(T39, T3g), ms, &(ii[0]));
			 ST(&(ri[WS(rs, 12)]), VSUB(T35, T38), ms, &(ri[0]));
			 ST(&(ii[WS(rs, 12)]), VSUB(T3i, T3h), ms, &(ii[0]));
			 ST(&(ri[WS(rs, 4)]), VADD(T35, T38), ms, &(ri[0]));
			 ST(&(ii[WS(rs, 4)]), VADD(T3h, T3i), ms, &(ii[0]));
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 3),
     VTW(0, 9),
     VTW(0, 15),
     {TW_NEXT, (2 * VL), 0}
};

static const ct_desc desc = { 16, XSIMD_STRING("t2sv_16"), twinstr, &GENUS, {156, 68, 40, 0}, 0, 0, 0 };

void XSIMD(codelet_t2sv_16) (planner *p) {
     X(kdft_dit_register) (p, t2sv_16, &desc);
}
#endif				/* HAVE_FMA */
