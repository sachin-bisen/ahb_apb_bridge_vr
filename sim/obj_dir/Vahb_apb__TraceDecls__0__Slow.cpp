// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing declarations

#include "verilated_fst_c.h"


void Vahb_apb___024root__traceDeclTypesSub0(VerilatedFst* tracep) {
    {
        const char* __VenumItemNames[]
        = {"IDLE", "READ", "W_WAIT", "WRITE", "WRITEP", 
                                "WENABLE", "WENABLEP", 
                                "RENABLE"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100", "101", "110", 
                                "111"};
        tracep->declDTypeEnum(1, "AHP_to_APB_Bridge.state", 8, 3, __VenumItemNames, __VenumItemValues);
    }
}

void Vahb_apb___024root__trace_decl_types(VerilatedFst* tracep) {
    Vahb_apb___024root__traceDeclTypesSub0(tracep);
}
