import esdl;
import uvm;
import ahb_apb_env: ahb_apb_env;
import ahb_apb_agent: ahb_apb_agent;
import ahb_apb_intf: ahb_apb_intf;
import ahb_apb_slave: ahb_apb_slave;

// AHB_APB DIRECTED TEST

class directed_test: uvm_test
{
    mixin uvm_component_utils;

        @UVM_BUILD ahb_apb_env env;
    

    this(string name = "directed_test", uvm_component parent = null) {
        super(name, parent);
    }

    override void build_phase(uvm_phase phase) {
    	     super.build_phase(phase);
	     env = ahb_apb_env.type_id.create("env", this);

    }
    
    override void run_phase(uvm_phase phase) {
        uvm_info("AHB_APB TEST", "Starting AHB directed Test...", UVM_LOW);

        phase.raise_objection(this);
        phase.get_objection().set_drain_time(this, 100.nsec);

        phase.drop_objection(this);
        uvm_info("AHB_APB_TEST", "AHB directed Test completed.", UVM_LOW);
    }
}


class ahb_apb_tb_top : Entity
{
    import Vahb_apb_euvm;
    import esdl.intf.verilator.verilated;
    import esdl.intf.verilator.trace;

   // ahb_apb_intf apbSlave;   
   // ahb_apb_intf ahbSlave;
      ahb_apb_intf bus_if;
    VerilatedFstD _trace;

    Signal!(ubvec!1) H_CLK;
    Signal!(ubvec!1) H_RESET_n;

    DVahb_apb dut;

    // trace setup
    void opentrace(string fstname) {
        if (_trace is null) {
            _trace = new VerilatedFstD();
            dut.trace(_trace, 99);
            _trace.open(fstname);
        }
    }

    void closetrace() {
        if (_trace !is null) {
            _trace.close();
            _trace = null;
        }
    }

    override void doBuild() {
        dut = new DVahb_apb();
        traceEverOn(true);
        opentrace("ahb_apb.fst");
    }

    override void doConnect() {
        bus_if.H_CLK(H_CLK);
        bus_if.H_RESET_n(H_RESET_n);

        bus_if.H_WDATA(dut.H_WDATA);
	bus_if.H_ADDR(dut.H_ADDR);
	bus_if.P_RDATA(dut.P_RDATA);
	bus_if.H_WRITE(dut.H_WRITE);
	bus_if.H_TRANS(dut.H_TRANS);
	bus_if.H_SEL_APB(dut.H_SEL_APB);
	bus_if.H_READY_IN(dut.H_READY_IN);

	bus_if.P_WDATA(dut.P_WDATA);
	bus_if.H_RDATA(dut.H_RDATA);
	bus_if.P_ADDR(dut.P_ADDR);
	bus_if.P_ENABLE(dut.P_ENABLE);
	bus_if.P_WRITE(dut.P_WRITE);
	bus_if.H_RESP(dut.H_RESP);
	bus_if.P_SELx(dut.P_SELx);
	bus_if.H_READY_OUT(dut.H_READY_OUT);
    }

    // Clock + Reset tasks
    
    Task!stimulateClk stimulateClkTask;
    Task!stimulateRst stimulateRstTask;

    void stimulateClk() {
        H_CLK = false;
        for (size_t i = 0; i != 100; ++i) {
            H_CLK = false;
            dut.H_CLK = false;
            wait(5.nsec);
            dut.eval();
            if (_trace !is null) _trace.dump(getSimTime().getVal());

            H_CLK = true;
            dut.H_CLK = true;
            wait(5.nsec);
            dut.eval();
            if (_trace !is null) {
                _trace.dump(getSimTime().getVal());
                _trace.flush();
            }
        }
    }

    void stimulateRst() {
        H_RESET_n = false;
        dut.H_RESET_n = false;
        wait(100.nsec);
        H_RESET_n = true;
        dut.H_RESET_n = true;
    }
}

// UVM + DUT world)

class ahb_apb_tb : uvm_context
{
    ahb_apb_tb_top top;
    import ahb_apb_test;
    override void initial() {
        // Pass interface to driver using config DB
        uvm_config_db!(ahb_apb_intf).set(null,
            "uvm_test_top.env.agent.*", "ahb_if", top.bus_if);
 	uvm_config_db!(ahb_apb_intf).set(null,
            "uvm_test_top.env.slave", "apb_if", top.bus_if);
    }
}


// MAIN ENTRY POINT

void main(string[] args) {
    import std.stdio;
    uint random_seed;
    CommandLine cmdl = new CommandLine(args);

    if (cmdl.plusArgs("random_seed=" ~ "%d", random_seed))
        writeln("Using random_seed: ", random_seed);
    else
        random_seed = 1;

    auto tb = new ahb_apb_tb;
    tb.multicore(0, 1);
    tb.elaborate("tb", args);
    tb.set_seed(random_seed);
    tb.start();
}
