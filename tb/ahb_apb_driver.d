import esdl;
import uvm;
import ahb_apb_intf: ahb_apb_intf;
import std.format;

class ahb_apb_driver: uvm_component {
      mixin uvm_component_utils;
      ahb_apb_intf ahb_if;

      this(string name, uvm_component parent = null) {
      super(name, parent);
      uvm_config_db!ahb_apb_intf.get(this, "", "ahb_if", ahb_if);
      assert(ahb_if !is null);
}

	override void run_phase(uvm_phase phase) {
	//super.run_phase(phase);
	phase.raise_objection(this);

	uint rdata;

	drive_idle();

	wait_for_reset_release();

	ahb_write(0x1000_0000, 0xDEADBEEF);

	uvm_info("DRIVER", "AHB WRITE completed, now starting READ", UVM_MEDIUM);

	rdata = ahb_read(0x1000_0000);

	 uvm_info("DRIVER", format("AHB READ returned data = 0x%08x", rdata), UVM_MEDIUM);

	phase.drop_objection(this);
}

	void drive_idle() {
	
	ahb_if.H_SEL_APB = ubvec!1(0);
	ahb_if.H_TRANS = ubvec!3(0); //IDLE RAKHA HAI
	ahb_if.H_WRITE = ubvec!1(0);
	ahb_if.H_ADDR = ubvec!32(0);
	ahb_if.H_WDATA = ubvec!32(0);
	ahb_if.H_READY_IN = ubvec!1(0);
}

	void wait_for_reset_release() {
	while(ahb_if.H_RESET_n == ubvec!1(0))
	       wait(ahb_if.H_CLK.posedge());

	       wait(ahb_if.H_CLK.posedge()); //ek cycle jyada after reset
}

	void ahb_write(uint addr, uint data) {

	wait(ahb_if.H_CLK.posedge()); //Address Phase

	ahb_if.H_SEL_APB = ubvec!1(1);
	//ahb_if.H_TRANS = ubvec!3(2); //IDLE RAKHA HAI
	ahb_if.H_WRITE = ubvec!1(1);
	ahb_if.H_ADDR = addr;
	ahb_if.H_WDATA = data;	


	while(ahb_if.H_READY_OUT == ubvec!1(0))
	     wait(ahb_if.H_CLK.posedge());


	     wait(ahb_if.H_CLK.posedge());
	     drive_idle();
}

	uint ahb_read(uint addr) {
	uint rdata;

	wait(ahb_if.H_CLK.posedge());

	ahb_if.H_SEL_APB = ubvec!1(1);
	//ahb_if.H_TRANS = ubvec!3(2); //NONSEQ
	ahb_if.H_WRITE = ubvec!1(0);
	ahb_if.H_ADDR = addr;	

	while(ahb_if.H_READY_OUT == ubvec!1(0))
	     wait(ahb_if.H_CLK.posedge());

	     rdata = ahb_if.H_RDATA;

	     wait(ahb_if.H_CLK.posedge());
	     drive_idle();

	     return rdata;
}
}