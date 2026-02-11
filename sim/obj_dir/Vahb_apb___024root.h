// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vahb_apb.h for the primary calling header

#ifndef VERILATED_VAHB_APB___024ROOT_H_
#define VERILATED_VAHB_APB___024ROOT_H_  // guard

#include "verilated.h"


class Vahb_apb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vahb_apb___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(H_CLK,0,0);
    VL_IN8(H_RESET_n,0,0);
    VL_IN8(H_WRITE,0,0);
    VL_IN8(H_SEL_APB,0,0);
    VL_IN8(H_READY_IN,0,0);
    VL_IN8(H_TRANS,2,0);
    VL_OUT8(H_RESP,0,0);
    VL_OUT8(H_READY_OUT,0,0);
    VL_OUT8(P_ENABLE,0,0);
    VL_OUT8(P_WRITE,0,0);
    VL_OUT8(P_SELx,0,0);
    CData/*2:0*/ AHP_to_APB_Bridge__DOT__current_state;
    CData/*2:0*/ AHP_to_APB_Bridge__DOT__next_state;
    CData/*0:0*/ AHP_to_APB_Bridge__DOT__H_Write_Reg;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__H_CLK__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__H_RESET_n__0;
    VL_IN(H_WDATA,31,0);
    VL_IN(H_ADDR,31,0);
    VL_IN(P_RDATA,31,0);
    VL_OUT(P_WDATA,31,0);
    VL_OUT(P_ADDR,31,0);
    VL_OUT(H_RDATA,31,0);
    IData/*31:0*/ AHP_to_APB_Bridge__DOT__ADDR_REG;
    IData/*31:0*/ AHP_to_APB_Bridge__DOT__DATA_REG;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vahb_apb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vahb_apb___024root(Vahb_apb__Syms* symsp, const char* namep);
    ~Vahb_apb___024root();
    VL_UNCOPYABLE(Vahb_apb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
