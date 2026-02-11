// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vahb_apb.h for the primary calling header

#include "Vahb_apb__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vahb_apb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vahb_apb___024root___eval_triggers__ico(Vahb_apb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___eval_triggers__ico\n"); );
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vahb_apb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool Vahb_apb___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlUnpacked<CData/*0:0*/, 64> Vahb_apb__ConstPool__TABLE_hb75832b7_0;
extern const VlUnpacked<CData/*2:0*/, 64> Vahb_apb__ConstPool__TABLE_h6908d3be_0;

void Vahb_apb___024root___ico_sequent__TOP__0(Vahb_apb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___ico_sequent__TOP__0\n"); );
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = (((IData)(vlSelfRef.AHP_to_APB_Bridge__DOT__H_Write_Reg) 
                     << 5U) | (((IData)(vlSelfRef.H_WRITE) 
                                << 4U) | ((((IData)(vlSelfRef.H_SEL_APB) 
                                            & ((1U 
                                                == (IData)(vlSelfRef.H_TRANS)) 
                                               | (3U 
                                                  == (IData)(vlSelfRef.H_TRANS)))) 
                                           << 3U) | (IData)(vlSelfRef.AHP_to_APB_Bridge__DOT__current_state))));
    if (Vahb_apb__ConstPool__TABLE_hb75832b7_0[__Vtableidx1]) {
        vlSelfRef.AHP_to_APB_Bridge__DOT__next_state 
            = Vahb_apb__ConstPool__TABLE_h6908d3be_0
            [__Vtableidx1];
    }
}

void Vahb_apb___024root___eval_ico(Vahb_apb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___eval_ico\n"); );
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vahb_apb___024root___ico_sequent__TOP__0(vlSelf);
    }
}

bool Vahb_apb___024root___eval_phase__ico(Vahb_apb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___eval_phase__ico\n"); );
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vahb_apb___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = Vahb_apb___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vahb_apb___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vahb_apb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vahb_apb___024root___eval_triggers__act(Vahb_apb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___eval_triggers__act\n"); );
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((~ (IData)(vlSelfRef.H_RESET_n)) 
                                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__H_RESET_n__0)) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.H_CLK) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__H_CLK__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__H_CLK__0 = vlSelfRef.H_CLK;
    vlSelfRef.__Vtrigprevexpr___TOP__H_RESET_n__0 = vlSelfRef.H_RESET_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vahb_apb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vahb_apb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vahb_apb___024root___nba_sequent__TOP__0(Vahb_apb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___nba_sequent__TOP__0\n"); );
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    if ((1U & (~ (IData)(vlSelfRef.H_RESET_n)))) {
        vlSelfRef.H_RESP = 0U;
    }
    vlSelfRef.H_READY_OUT = ((IData)(vlSelfRef.H_RESET_n) 
                             && ((4U & (IData)(vlSelfRef.AHP_to_APB_Bridge__DOT__current_state))
                                  ? ((1U & ((IData)(vlSelfRef.AHP_to_APB_Bridge__DOT__current_state) 
                                            >> 1U)) 
                                     || (1U & (IData)(vlSelfRef.AHP_to_APB_Bridge__DOT__current_state)))
                                  : ((1U & (~ ((IData)(vlSelfRef.AHP_to_APB_Bridge__DOT__current_state) 
                                               >> 1U))) 
                                     && (1U & (~ (IData)(vlSelfRef.AHP_to_APB_Bridge__DOT__current_state))))));
    if (vlSelfRef.H_RESET_n) {
        if ((4U & (IData)(vlSelfRef.AHP_to_APB_Bridge__DOT__current_state))) {
            if ((1U & (~ ((IData)(vlSelfRef.AHP_to_APB_Bridge__DOT__current_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.AHP_to_APB_Bridge__DOT__current_state)))) {
                    vlSelfRef.P_SELx = 1U;
                    vlSelfRef.P_WRITE = 1U;
                    vlSelfRef.P_WDATA = vlSelfRef.H_WDATA;
                    vlSelfRef.AHP_to_APB_Bridge__DOT__H_Write_Reg 
                        = vlSelfRef.H_WRITE;
                    vlSelfRef.P_ADDR = vlSelfRef.AHP_to_APB_Bridge__DOT__ADDR_REG;
                    vlSelfRef.AHP_to_APB_Bridge__DOT__ADDR_REG 
                        = vlSelfRef.H_ADDR;
                }
            }
            vlSelfRef.P_ENABLE = ((1U & ((IData)(vlSelfRef.AHP_to_APB_Bridge__DOT__current_state) 
                                         >> 1U)) || 
                                  (1U & (IData)(vlSelfRef.AHP_to_APB_Bridge__DOT__current_state)));
            if ((2U & (IData)(vlSelfRef.AHP_to_APB_Bridge__DOT__current_state))) {
                if ((1U & (IData)(vlSelfRef.AHP_to_APB_Bridge__DOT__current_state))) {
                    vlSelfRef.H_RDATA = vlSelfRef.P_RDATA;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.AHP_to_APB_Bridge__DOT__current_state))) {
            if ((1U & (IData)(vlSelfRef.AHP_to_APB_Bridge__DOT__current_state))) {
                vlSelfRef.P_SELx = 1U;
                vlSelfRef.P_ENABLE = 0U;
                vlSelfRef.P_WRITE = 1U;
                vlSelfRef.P_WDATA = vlSelfRef.H_WDATA;
                vlSelfRef.P_ADDR = vlSelfRef.AHP_to_APB_Bridge__DOT__ADDR_REG;
            } else {
                vlSelfRef.P_ENABLE = 0U;
                vlSelfRef.P_ENABLE = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.AHP_to_APB_Bridge__DOT__current_state)))) {
                vlSelfRef.AHP_to_APB_Bridge__DOT__H_Write_Reg 
                    = vlSelfRef.H_WRITE;
                vlSelfRef.AHP_to_APB_Bridge__DOT__ADDR_REG 
                    = vlSelfRef.H_ADDR;
            }
        } else if ((1U & (IData)(vlSelfRef.AHP_to_APB_Bridge__DOT__current_state))) {
            vlSelfRef.P_SELx = 1U;
            vlSelfRef.P_ENABLE = 0U;
            vlSelfRef.P_WRITE = 0U;
            vlSelfRef.P_ADDR = vlSelfRef.H_ADDR;
        } else {
            vlSelfRef.P_SELx = 0U;
            vlSelfRef.P_ENABLE = 0U;
        }
        vlSelfRef.AHP_to_APB_Bridge__DOT__current_state 
            = vlSelfRef.AHP_to_APB_Bridge__DOT__next_state;
    } else {
        vlSelfRef.P_SELx = 0U;
        vlSelfRef.P_ENABLE = 0U;
        vlSelfRef.P_WRITE = 0U;
        vlSelfRef.P_WDATA = 0U;
        vlSelfRef.H_RDATA = 0U;
        vlSelfRef.P_ADDR = 0U;
        vlSelfRef.AHP_to_APB_Bridge__DOT__current_state = 0U;
    }
    __Vtableidx1 = (((IData)(vlSelfRef.AHP_to_APB_Bridge__DOT__H_Write_Reg) 
                     << 5U) | (((IData)(vlSelfRef.H_WRITE) 
                                << 4U) | ((((IData)(vlSelfRef.H_SEL_APB) 
                                            & ((1U 
                                                == (IData)(vlSelfRef.H_TRANS)) 
                                               | (3U 
                                                  == (IData)(vlSelfRef.H_TRANS)))) 
                                           << 3U) | (IData)(vlSelfRef.AHP_to_APB_Bridge__DOT__current_state))));
    if (Vahb_apb__ConstPool__TABLE_hb75832b7_0[__Vtableidx1]) {
        vlSelfRef.AHP_to_APB_Bridge__DOT__next_state 
            = Vahb_apb__ConstPool__TABLE_h6908d3be_0
            [__Vtableidx1];
    }
}

void Vahb_apb___024root___eval_nba(Vahb_apb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___eval_nba\n"); );
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vahb_apb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

void Vahb_apb___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vahb_apb___024root___eval_phase__act(Vahb_apb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___eval_phase__act\n"); );
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vahb_apb___024root___eval_triggers__act(vlSelf);
    Vahb_apb___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vahb_apb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vahb_apb___024root___eval_phase__nba(Vahb_apb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___eval_phase__nba\n"); );
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vahb_apb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vahb_apb___024root___eval_nba(vlSelf);
        Vahb_apb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vahb_apb___024root___eval(Vahb_apb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___eval\n"); );
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vahb_apb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("../rtl/ahb_apb.v", 1, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vahb_apb___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vahb_apb___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("../rtl/ahb_apb.v", 1, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vahb_apb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("../rtl/ahb_apb.v", 1, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vahb_apb___024root___eval_phase__act(vlSelf));
    } while (Vahb_apb___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vahb_apb___024root___eval_debug_assertions(Vahb_apb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___eval_debug_assertions\n"); );
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.H_CLK & 0xfeU)))) {
        Verilated::overWidthError("H_CLK");
    }
    if (VL_UNLIKELY(((vlSelfRef.H_RESET_n & 0xfeU)))) {
        Verilated::overWidthError("H_RESET_n");
    }
    if (VL_UNLIKELY(((vlSelfRef.H_WRITE & 0xfeU)))) {
        Verilated::overWidthError("H_WRITE");
    }
    if (VL_UNLIKELY(((vlSelfRef.H_SEL_APB & 0xfeU)))) {
        Verilated::overWidthError("H_SEL_APB");
    }
    if (VL_UNLIKELY(((vlSelfRef.H_READY_IN & 0xfeU)))) {
        Verilated::overWidthError("H_READY_IN");
    }
    if (VL_UNLIKELY(((vlSelfRef.H_TRANS & 0xf8U)))) {
        Verilated::overWidthError("H_TRANS");
    }
}
#endif  // VL_DEBUG
