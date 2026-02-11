import esdl.base.core: Entity;
import esdl.data.bvec: ubvec;
import esdl.intf.verilator.verilated: VerilatedContext, VerilatedModel;
import esdl.intf.verilator.verilated: VlInExport, VlOutExport, VlExport, VlInOutExport;
import esdl.intf.verilator.trace.base: VerilatedTraceBaseC;
import esdl.intf.verilator.trace.vcd: VerilatedVcdC, VerilatedVcdD;
import esdl.intf.verilator.trace.fst: VerilatedFstC, VerilatedFstD;
import esdl.intf.verilator.trace.saif: VerilatedSaifC, VerilatedSaifD;

//DESCRIPTION: Dlang code to link D classes and functions with the C++ classes


extern(C++) {
  align(8) class Vahb_apb: VerilatedModel {
    //Symbol table, currently unimplemented, using void pointer
    void* vlSymsp;

    //PORTS 
    ubvec!(1)* H_CLK;
    ubvec!(1)* H_RESET_n;
    ubvec!(1)* H_WRITE;
    ubvec!(1)* H_SEL_APB;
    ubvec!(1)* H_READY_IN;
    ubvec!(3)* H_TRANS;
    ubvec!(1)* H_RESP;
    ubvec!(1)* H_READY_OUT;
    ubvec!(1)* P_ENABLE;
    ubvec!(1)* P_WRITE;
    ubvec!(1)* P_SELx;
    ubvec!(32)* H_WDATA;
    ubvec!(32)* H_ADDR;
    ubvec!(32)* P_RDATA;
    ubvec!(32)* P_WDATA;
    ubvec!(32)* P_ADDR;
    ubvec!(32)* H_RDATA;

    // CELLS
    //Currently unimplemented, using void pointers 

    // Root instance pointer, currently unimplemented, using void pointers 
    void* rootp;
    this(VerilatedContext* contextp, const char* name = "TOP".ptr);
    ~this();
    final void eval();
    final void eval_step();
    final void eval_end_step();
    final bool eventsPending();
    final ulong nextTimeSlot();
    final void trace(VerilatedTraceBaseC tfp, int levels, int options = 0) {
        contextp().trace(tfp, levels, options);
    }
    final void trace(VerilatedVcdD tfp, int levels, int options = 0) {
        contextp().trace(tfp.getTraceBase(), levels, options);
    }
    final void trace(VerilatedFstD tfp, int levels, int options = 0) {
        contextp().trace(tfp.getTraceBase(), levels, options);
    }
    final void trace(VerilatedSaifD tfp, int levels, int options = 0) {
        contextp().trace(tfp.getTraceBase(), levels, options);
    }
    final const(char*) name();
    final override char* hierName() const;
    final override char* modelName() const;
    final override uint threads() const;
    final void prepareClone() const;
    final void atClone() const;
  }
  Vahb_apb create_Vahb_apb();
  void finalize(Vahb_apb obj);

}
class DVahb_apb: Entity {
  Vahb_apb _dut;

  this () {
    _dut = create_Vahb_apb();
  }
  override void doConnect() {
    H_CLK(_dut.H_CLK);
    H_RESET_n(_dut.H_RESET_n);
    H_WRITE(_dut.H_WRITE);
    H_SEL_APB(_dut.H_SEL_APB);
    H_READY_IN(_dut.H_READY_IN);
    H_TRANS(_dut.H_TRANS);
    H_RESP(_dut.H_RESP);
    H_READY_OUT(_dut.H_READY_OUT);
    P_ENABLE(_dut.P_ENABLE);
    P_WRITE(_dut.P_WRITE);
    P_SELx(_dut.P_SELx);
    H_WDATA(_dut.H_WDATA);
    H_ADDR(_dut.H_ADDR);
    P_RDATA(_dut.P_RDATA);
    P_WDATA(_dut.P_WDATA);
    P_ADDR(_dut.P_ADDR);
    H_RDATA(_dut.H_RDATA);
  }

  //Functions for Ports 
  VlInExport!(1) H_CLK;
  VlInExport!(1) H_RESET_n;
  VlInExport!(1) H_WRITE;
  VlInExport!(1) H_SEL_APB;
  VlInExport!(1) H_READY_IN;
  VlInExport!(3) H_TRANS;
  VlOutExport!(1) H_RESP;
  VlOutExport!(1) H_READY_OUT;
  VlOutExport!(1) P_ENABLE;
  VlOutExport!(1) P_WRITE;
  VlOutExport!(1) P_SELx;
  VlInExport!(32) H_WDATA;
  VlInExport!(32) H_ADDR;
  VlInExport!(32) P_RDATA;
  VlOutExport!(32) P_WDATA;
  VlOutExport!(32) P_ADDR;
  VlOutExport!(32) H_RDATA;
  final void eval() {
    _dut.eval();
  }
  final void finish() {
    finalize(_dut);
  }
  final void trace(VerilatedVcdD tfp, int levels, int options = 0) {
    _dut.trace(tfp, levels, options);
  }
  final void trace(VerilatedFstD tfp, int levels, int options = 0) {
    _dut.trace(tfp, levels, options);
  }
  final void trace(VerilatedSaifD tfp, int levels, int options = 0) {
    _dut.trace(tfp, levels, options);
  }
  final void trace(VerilatedTraceBaseC tfp, int levels, int options = 0) {
    _dut.trace(tfp, levels, options);
  }
}
