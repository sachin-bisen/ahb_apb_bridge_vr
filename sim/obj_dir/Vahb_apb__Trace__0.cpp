// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "Vahb_apb__Syms.h"


void Vahb_apb___024root__trace_chg_0_sub_0(Vahb_apb___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vahb_apb___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root__trace_chg_0\n"); );
    // Body
    Vahb_apb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vahb_apb___024root*>(voidSelf);
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vahb_apb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vahb_apb___024root__trace_chg_0_sub_0(Vahb_apb___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root__trace_chg_0_sub_0\n"); );
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgCData(oldp+0,(vlSelfRef.AHP_to_APB_Bridge__DOT__current_state),3);
        bufp->chgBit(oldp+1,(vlSelfRef.AHP_to_APB_Bridge__DOT__H_Write_Reg));
        bufp->chgIData(oldp+2,(vlSelfRef.AHP_to_APB_Bridge__DOT__ADDR_REG),32);
    }
    bufp->chgBit(oldp+3,(vlSelfRef.H_CLK));
    bufp->chgBit(oldp+4,(vlSelfRef.H_RESET_n));
    bufp->chgBit(oldp+5,(vlSelfRef.H_WRITE));
    bufp->chgBit(oldp+6,(vlSelfRef.H_SEL_APB));
    bufp->chgBit(oldp+7,(vlSelfRef.H_READY_IN));
    bufp->chgCData(oldp+8,(vlSelfRef.H_TRANS),3);
    bufp->chgIData(oldp+9,(vlSelfRef.H_WDATA),32);
    bufp->chgIData(oldp+10,(vlSelfRef.H_ADDR),32);
    bufp->chgIData(oldp+11,(vlSelfRef.P_RDATA),32);
    bufp->chgBit(oldp+12,(vlSelfRef.H_RESP));
    bufp->chgBit(oldp+13,(vlSelfRef.H_READY_OUT));
    bufp->chgBit(oldp+14,(vlSelfRef.P_ENABLE));
    bufp->chgBit(oldp+15,(vlSelfRef.P_WRITE));
    bufp->chgBit(oldp+16,(vlSelfRef.P_SELx));
    bufp->chgIData(oldp+17,(vlSelfRef.P_WDATA),32);
    bufp->chgIData(oldp+18,(vlSelfRef.P_ADDR),32);
    bufp->chgIData(oldp+19,(vlSelfRef.H_RDATA),32);
    bufp->chgCData(oldp+20,(vlSelfRef.AHP_to_APB_Bridge__DOT__next_state),3);
    bufp->chgBit(oldp+21,(((IData)(vlSelfRef.H_SEL_APB) 
                           & ((1U == (IData)(vlSelfRef.H_TRANS)) 
                              | (3U == (IData)(vlSelfRef.H_TRANS))))));
}

void Vahb_apb___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vahb_apb___024root__trace_cleanup\n"); );
    // Body
    Vahb_apb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vahb_apb___024root*>(voidSelf);
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
