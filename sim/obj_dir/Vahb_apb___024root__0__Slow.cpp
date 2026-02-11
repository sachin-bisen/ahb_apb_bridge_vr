// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vahb_apb.h for the primary calling header

#include "Vahb_apb__pch.h"

VL_ATTR_COLD void Vahb_apb___024root___eval_static(Vahb_apb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___eval_static\n"); );
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__H_CLK__0 = vlSelfRef.H_CLK;
    vlSelfRef.__Vtrigprevexpr___TOP__H_RESET_n__0 = vlSelfRef.H_RESET_n;
}

VL_ATTR_COLD void Vahb_apb___024root___eval_initial(Vahb_apb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___eval_initial\n"); );
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vahb_apb___024root___eval_final(Vahb_apb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___eval_final\n"); );
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vahb_apb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vahb_apb___024root___eval_phase__stl(Vahb_apb___024root* vlSelf);

VL_ATTR_COLD void Vahb_apb___024root___eval_settle(Vahb_apb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___eval_settle\n"); );
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vahb_apb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("../rtl/ahb_apb.v", 1, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vahb_apb___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vahb_apb___024root___eval_triggers__stl(Vahb_apb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___eval_triggers__stl\n"); );
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vahb_apb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vahb_apb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vahb_apb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vahb_apb___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vahb_apb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___trigger_anySet__stl\n"); );
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

void Vahb_apb___024root___ico_sequent__TOP__0(Vahb_apb___024root* vlSelf);

VL_ATTR_COLD void Vahb_apb___024root___eval_stl(Vahb_apb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___eval_stl\n"); );
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vahb_apb___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vahb_apb___024root___eval_phase__stl(Vahb_apb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___eval_phase__stl\n"); );
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vahb_apb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vahb_apb___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vahb_apb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vahb_apb___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vahb_apb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vahb_apb___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vahb_apb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vahb_apb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vahb_apb___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge H_CLK)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge H_RESET_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vahb_apb___024root___ctor_var_reset(Vahb_apb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root___ctor_var_reset\n"); );
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->H_CLK = 0;
    vlSelf->H_RESET_n = 0;
    vlSelf->H_WRITE = 0;
    vlSelf->H_SEL_APB = 0;
    vlSelf->H_READY_IN = 0;
    vlSelf->H_TRANS = 0;
    vlSelf->H_WDATA = 0;
    vlSelf->H_ADDR = 0;
    vlSelf->P_RDATA = 0;
    vlSelf->H_RESP = 0;
    vlSelf->H_READY_OUT = 0;
    vlSelf->P_ENABLE = 0;
    vlSelf->P_WRITE = 0;
    vlSelf->P_SELx = 0;
    vlSelf->P_WDATA = 0;
    vlSelf->P_ADDR = 0;
    vlSelf->H_RDATA = 0;
    vlSelf->AHP_to_APB_Bridge__DOT__current_state = 0;
    vlSelf->AHP_to_APB_Bridge__DOT__next_state = 0;
    vlSelf->AHP_to_APB_Bridge__DOT__H_Write_Reg = 0;
    vlSelf->AHP_to_APB_Bridge__DOT__ADDR_REG = 0;
    vlSelf->AHP_to_APB_Bridge__DOT__DATA_REG = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__H_CLK__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__H_RESET_n__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
