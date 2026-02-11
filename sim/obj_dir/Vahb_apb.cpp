// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vahb_apb__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Vahb_apb::Vahb_apb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vahb_apb__Syms(contextp(), _vcname__, this)}
    , H_CLK{vlSymsp->TOP.H_CLK}
    , H_RESET_n{vlSymsp->TOP.H_RESET_n}
    , H_WRITE{vlSymsp->TOP.H_WRITE}
    , H_SEL_APB{vlSymsp->TOP.H_SEL_APB}
    , H_READY_IN{vlSymsp->TOP.H_READY_IN}
    , H_TRANS{vlSymsp->TOP.H_TRANS}
    , H_RESP{vlSymsp->TOP.H_RESP}
    , H_READY_OUT{vlSymsp->TOP.H_READY_OUT}
    , P_ENABLE{vlSymsp->TOP.P_ENABLE}
    , P_WRITE{vlSymsp->TOP.P_WRITE}
    , P_SELx{vlSymsp->TOP.P_SELx}
    , H_WDATA{vlSymsp->TOP.H_WDATA}
    , H_ADDR{vlSymsp->TOP.H_ADDR}
    , P_RDATA{vlSymsp->TOP.P_RDATA}
    , P_WDATA{vlSymsp->TOP.P_WDATA}
    , P_ADDR{vlSymsp->TOP.P_ADDR}
    , H_RDATA{vlSymsp->TOP.H_RDATA}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vahb_apb::Vahb_apb(const char* _vcname__)
    : Vahb_apb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vahb_apb::~Vahb_apb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vahb_apb___024root___eval_debug_assertions(Vahb_apb___024root* vlSelf);
#endif  // VL_DEBUG
void Vahb_apb___024root___eval_static(Vahb_apb___024root* vlSelf);
void Vahb_apb___024root___eval_initial(Vahb_apb___024root* vlSelf);
void Vahb_apb___024root___eval_settle(Vahb_apb___024root* vlSelf);
void Vahb_apb___024root___eval(Vahb_apb___024root* vlSelf);

void Vahb_apb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vahb_apb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vahb_apb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vahb_apb___024root___eval_static(&(vlSymsp->TOP));
        Vahb_apb___024root___eval_initial(&(vlSymsp->TOP));
        Vahb_apb___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vahb_apb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vahb_apb::eventsPending() { return false; }

uint64_t Vahb_apb::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vahb_apb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vahb_apb___024root___eval_final(Vahb_apb___024root* vlSelf);

VL_ATTR_COLD void Vahb_apb::final() {
    Vahb_apb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vahb_apb::hierName() const { return vlSymsp->name(); }
const char* Vahb_apb::modelName() const { return "Vahb_apb"; }
unsigned Vahb_apb::threads() const { return 1; }
void Vahb_apb::prepareClone() const { contextp()->prepareClone(); }
void Vahb_apb::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vahb_apb::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vahb_apb___024root__trace_decl_types(VerilatedFst* tracep);

void Vahb_apb___024root__trace_init_top(Vahb_apb___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vahb_apb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vahb_apb___024root*>(voidSelf);
    Vahb_apb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vahb_apb___024root__trace_decl_types(tracep);
    Vahb_apb___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vahb_apb___024root__trace_register(Vahb_apb___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vahb_apb::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vahb_apb::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vahb_apb___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
