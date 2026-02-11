import esdl;
import uvm;
import ahb_apb_intf: ahb_apb_intf;
import ahb_apb_driver: ahb_apb_driver;


class ahb_apb_monitor: uvm_component
{
	mixin uvm_component_utils;

	ahb_apb_intf ahb_if;

	this(string name, uvm_component parent = null) {
	super(name, parent);
       uvm_config_db!ahb_apb_intf.get(this, "", "ahb_if", ahb_if);
	assert(ahb_if !is null);
}

	override void run_phase(uvm_phase phase) {

	while(true) {

	wait(ahb_if.H_CLK.posedge());

	if(ahb_if.P_SELx == 1 && ahb_if.P_ENABLE == 0) {
		monitor_setup_phase();

}
}
}

	void monitor_setup_phase() {
	uint addr;
	uint data;
	bool is_write;
	import std.format;
	
	addr = ahb_if.P_ADDR;
	is_write = (ahb_if.P_WRITE == 1);

	 uvm_info("APB_MON", format("APB SETUP  | addr=0x%08x write=%0d", addr, is_write), UVM_MEDIUM);

	 wait(ahb_if.H_CLK.posedge());

	 if(ahb_if.P_SELx == 1 && ahb_if.P_ENABLE == 1) {    // wait for access phase 

	if (is_write) {

	data = ahb_if.P_WDATA;

	 uvm_info("APB_MON", format("APB WRITE | addr=0x%08x data=0x%08x", addr, data),  UVM_MEDIUM);
	
} else {
        data = ahb_if.P_RDATA;

      uvm_info("APB_MON", format("APB READ  | addr=0x%08x data=0x%08x", addr, data), UVM_MEDIUM);
}
} /*  else {
    uvm_warning("APB_MON", "ACCESS phase not detected correctly");
} */
}
}
