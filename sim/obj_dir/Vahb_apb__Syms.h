// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VAHB_APB__SYMS_H_
#define VERILATED_VAHB_APB__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vahb_apb.h"

// INCLUDE MODULE CLASSES
#include "Vahb_apb___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vahb_apb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vahb_apb* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vahb_apb___024root             TOP;

    // CONSTRUCTORS
    Vahb_apb__Syms(VerilatedContext* contextp, const char* namep, Vahb_apb* modelp);
    ~Vahb_apb__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
