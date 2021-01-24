#include <RxODE_model_shared.h>
#define __MAX_PROD__ 0
#define _CMT CMT
#define _SYNC_simeps_ for (int _svari=_solveData->neps; _svari--;){  if (_solveData->svar[_svari] == 0) {V = _PP[0];};   if (_solveData->svar[_svari] == 1) {KA = _PP[1];};   if (_solveData->svar[_svari] == 2) {KE = _PP[2];}; }
#define _SYNC_simeta_ for (int _ovari=_solveData->neta; _ovari--;){  if (_solveData->ovar[_ovari] == 0) {V = _PP[0];};   if (_solveData->ovar[_ovari] == 1) {KA = _PP[1];};   if (_solveData->ovar[_ovari] == 2) {KE = _PP[2];}; }
#include "extraC.h"
#include <RxODE_model_shared.c>
extern void  m2__ode_solver_solvedata (rx_solve *solve){
  _solveData = solve;
}
extern rx_solve *m2__ode_solver_get_solvedata(){
  return _solveData;
}
SEXP m2__model_vars();


// prj-specific differential eqns
void m2__dydt(int *_neq, double __t, double *__zzStateVar__, double *__DDtStateVar__)
{
  int _itwhile = 0;
  (void)_itwhile;
  int _cSub = _neq[1];
  double t = __t + _solveData->subjects[_neq[1]].curShift;
  (void)t;
    double C2;
  double centr;
  double V;
  double depot;
  double KA;
  double KE;

  (void)t;
  (void)C2;
  (void)centr;
  (void)V;
  (void)depot;
  (void)KA;
  (void)KE;

  C2 = _PL[0];

  _update_par_ptr(__t, _cSub, _solveData, _idx);
  V = _PP[0];
  KA = _PP[1];
  KE = _PP[2];

  depot = __zzStateVar__[0]*((double)(_ON[0]));
  centr = __zzStateVar__[1]*((double)(_ON[1]));

  C2=centr/safe_zero(V);
  __DDtStateVar__[0] = ((double)(_ON[0]))*(_IR[0] -KA*depot);
  __DDtStateVar__[1] = ((double)(_ON[1]))*(_IR[1] + KA*depot-KE*centr);
  (&_solveData->subjects[_cSub])->dadt_counter[0]++;
}

// Jacobian derived vars
void m2__calc_jac(int *_neq, double __t, double *__zzStateVar__, double *__PDStateVar__, unsigned int __NROWPD__) {
  int _itwhile = 0;
  (void)_itwhile;
    int _cSub=_neq[1];
  double t = __t + _solveData->subjects[_neq[1]].curShift;
  (void)t;
    (&_solveData->subjects[_cSub])->jac_counter[0]++;
}
// Functional based initial conditions.
void m2__inis(int _cSub, double *__zzStateVar__){
  int _itwhile = 0;
  (void)_itwhile;
  
}
// prj-specific derived vars
void m2__calc_lhs(int _cSub, double __t, double *__zzStateVar__, double *_lhs) {
    int _itwhile = 0;
  (void)_itwhile;
  double t = __t + _solveData->subjects[_cSub].curShift;
  (void)t;
    double  __DDtStateVar_0__;
  double  __DDtStateVar_1__;
  double C2;
  double centr;
  double V;
  double depot;
  double KA;
  double KE;

  (void)t;
  (void)__DDtStateVar_0__;
  (void)__DDtStateVar_1__;
  (void)C2;
  (void)centr;
  (void)V;
  (void)depot;
  (void)KA;
  (void)KE;

  C2 = _PL[0];

  _update_par_ptr(__t, _cSub, _solveData, _idx);
  V = _PP[0];
  KA = _PP[1];
  KE = _PP[2];

  depot = __zzStateVar__[0]*((double)(_ON[0]));
  centr = __zzStateVar__[1]*((double)(_ON[1]));

  C2=centr/safe_zero(V);
  __DDtStateVar_0__ = ((double)(_ON[0]))*(_IR[0] -KA*depot);
  __DDtStateVar_1__ = ((double)(_ON[1]))*(_IR[1] + KA*depot-KE*centr);

  _lhs[0]=C2;
}
// Functional based bioavailability
double m2__F(int _cSub,  int _cmt, double _amt, double __t, double *__zzStateVar__){
 return _amt;
}
// Functional based absorption lag
double m2__Lag(int _cSub,  int _cmt, double __t, double *__zzStateVar__){
 return __t;
}
// Modeled zero-order rate
double m2__Rate(int _cSub,  int _cmt, double _amt, double __t, double *__zzStateVar__){
 return 0.0;
}
// Modeled zero-order duration
double m2__Dur(int _cSub,  int _cmt, double _amt, double __t){
 return 0.0;
}
// Model Times
void m2__mtime(int _cSub, double *_mtime){
}
// Matrix Exponential (0)
void m2__ME(int _cSub, double _t, double __t, double *_mat, const double *__zzStateVar__){
  int _itwhile = 0;
  (void)_itwhile;
  double t = __t + _solveData->subjects[_cSub].curShift;
  (void)t;
  }
// Inductive linearization Matf
void m2__IndF(int _cSub, double _t, double __t, double *_matf){
 int _itwhile = 0;
  (void)_itwhile;
  double t = __t + _solveData->subjects[_cSub].curShift;
  (void)t;
  }
extern SEXP m2__model_vars(){
  int pro=0;
  SEXP _mv = PROTECT(_rxGetModelLib("m2__model_vars"));pro++;
  if (!_rxIsCurrentC(_mv)){
    SEXP hash    = PROTECT(allocVector(STRSXP, 1));pro++;
#define __doBuf__  sprintf(buf, "un]\"BAAA@QBtHACAAAAAAABtsAAAv7#aT)RTI}KAxh%%(<W{FnAA.X,~jASyBH#&MMG10Zhb$jDVdH5a%%q}2r|Y!&=grBgi3(:iq)[%%1i1wQ<oe4a!F1A%%tTv2A2C0Uy:|Jz0[*]Dzs#7CN*^^b\"Ra~XX\".9w5VQDr0ifm~1Bf%%Q|P2{$F&9Y@%%43sjU^kI_N4$b]s>GlxPqsix0>.sn+&EW;n:v7HPc[f4X3qUB)nT0~CPVy$9@4,G]*Z36Kqw\"\"KyzI2:ZKi[<`;J\?530bl>jMW}!pZwjk_L3vi(kBIIeXpc@*M>Moz8W{\"}7&uZa9K^l<Ndt04};YK)T=t`4.B/a9jg*c/\?D|JNl)_~*6:53~9}{Dw6d;3R*&t]Q[R9dZE~2e7<Mn(\?8)x3O_N490(;<&V:,Ya>I6Kzn_oD\"uW^Hx}o*XP%%BKNuYQPSe^d1nMSr6;dSlWdwnm#c]e2Aus0)djM_aVe5D.W>MLa7vpxoL@FFQyUTy%%a@f$r2LtUh%%ebCjMQ0}csk&yI~nwQVm=}m=.ODiLXa<Y)TXs4uC4$LG9H)Et=4hO1{usb7DG^\"90aD3kCt6I{GF=Q{7<rYP~~;ey<c|LgG,bDm{3O<T:6==;5Q8=d4;m.DWRS_ut.y1Znq#2ymr^jj:cW_(Lg[icn/(;$qkDh%%tljxR(\?BEjX/M\?,WRIBB2d),tKuRAjHi9wBXrBYsPGu@W!MlnGWSz6}:/AEdcG5sWP1@3AK$!IthZ{cg5\"FN=APE&Wp{0X7M,Xuvi<+^vdBft3P(!XrhsO%%a8Z3nLp/jvLbwc;gE8|&(>Q3tlK!V$\"%%{/nXN:C3)7zs$a|}y:|B%%@KOEI{M3+q]5Ie/L<7Y|rV(4,inV%%yWYwTu3HP.^>KC|%%sN,`Cp`6x(tSFtE<D");
    char buf[919];
    __doBuf__
#undef __doBuf__
    SET_STRING_ELT(hash, 0, mkChar(buf));
    SEXP lst      = PROTECT(_rxQr(hash));pro++;
    _assign_ptr(lst);
    UNPROTECT(pro);
    return lst;
  } else {
    UNPROTECT(pro);
    return _mv;
  }
}
extern void m2__dydt_lsoda(int *neq, double *t, double *A, double *DADT)
{
  m2__dydt(neq, *t, A, DADT);
}
extern int m2__dydt_liblsoda(double __t, double *y, double *ydot, void *data)
{
  int *neq = (int*)(data);
  m2__dydt(neq, __t, y, ydot);
  return(0);
}
extern void m2__calc_jac_lsoda(int *neq, double *t, double *A,int *ml, int *mu, double *JAC, int *nrowpd){
  // Update all covariate parameters
  m2__calc_jac(neq, *t, A, JAC, *nrowpd);
}

//Create function to call from R's main thread that assigns the required functions. Sometimes they don't get assigned.
extern void m2__assignFuns(){
  _assignFuns();
}

//Initialize the dll to match RxODE's calls
void R_init0_m2_(){
  // Get C callables on load; Otherwise it isn't thread safe
  _assignFuns();
  R_RegisterCCallable("m2_","m2__assignFuns", (DL_FUNC) m2__assignFuns);
  R_RegisterCCallable("m2_","m2__inis",(DL_FUNC) m2__inis);
  R_RegisterCCallable("m2_","m2__dydt",(DL_FUNC) m2__dydt);
  R_RegisterCCallable("m2_","m2__calc_lhs",(DL_FUNC) m2__calc_lhs);
  R_RegisterCCallable("m2_","m2__calc_jac",(DL_FUNC) m2__calc_jac);
  R_RegisterCCallable("m2_","m2__dydt_lsoda", (DL_FUNC) m2__dydt_lsoda);
  R_RegisterCCallable("m2_","m2__calc_jac_lsoda", (DL_FUNC) m2__calc_jac_lsoda);
  R_RegisterCCallable("m2_","m2__ode_solver_solvedata", (DL_FUNC) m2__ode_solver_solvedata);
  R_RegisterCCallable("m2_","m2__ode_solver_get_solvedata", (DL_FUNC) m2__ode_solver_get_solvedata);
  R_RegisterCCallable("m2_","m2__F", (DL_FUNC) m2__F);
  R_RegisterCCallable("m2_","m2__Lag", (DL_FUNC) m2__Lag);
  R_RegisterCCallable("m2_","m2__Rate", (DL_FUNC) m2__Rate);
  R_RegisterCCallable("m2_","m2__Dur", (DL_FUNC) m2__Dur);
  R_RegisterCCallable("m2_","m2__mtime", (DL_FUNC) m2__mtime);
  R_RegisterCCallable("m2_","m2__ME", (DL_FUNC) m2__ME);
  R_RegisterCCallable("m2_","m2__IndF", (DL_FUNC) m2__IndF);
  R_RegisterCCallable("m2_","m2__dydt_liblsoda", (DL_FUNC) m2__dydt_liblsoda);
}
//Initialize the dll to match RxODE's calls
void R_init_m2_(DllInfo *info){
  // Get C callables on load; Otherwise it isn't thread safe
  R_init0_m2_();
  static const R_CallMethodDef callMethods[]  = {
    {"m2__model_vars", (DL_FUNC) &m2__model_vars, 0},
    {NULL, NULL, 0}
  };

  R_registerRoutines(info, NULL, callMethods, NULL, NULL);
  R_useDynamicSymbols(info,FALSE);
}

void R_unload_m2_ (DllInfo *info){
  // Free resources required for single subject solve.
  SEXP _mv = PROTECT(_rxGetModelLib("m2__model_vars"));
  if (!isNull(_mv)){
    _rxRmModelLib("m2__model_vars");
  }
  UNPROTECT(1);
}