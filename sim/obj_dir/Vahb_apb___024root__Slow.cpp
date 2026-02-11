// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vahb_apb.h for the primary calling header

#include "Vahb_apb__pch.h"

void Vahb_apb___024root___ctor_var_reset(Vahb_apb___024root* vlSelf);

Vahb_apb___024root::Vahb_apb___024root(Vahb_apb__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vahb_apb___024root___ctor_var_reset(this);
}

void Vahb_apb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vahb_apb___024root::~Vahb_apb___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
