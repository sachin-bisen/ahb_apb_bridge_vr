import esdl;
import uvm;
import ahb_apb_monitor: ahb_apb_monitor;
import ahb_apb_driver: ahb_apb_driver;

class ahb_apb_agent: uvm_agent
{

	@UVM_BUILD ahb_apb_driver driver;
        @UVM_BUILD ahb_apb_monitor monitor;

	mixin uvm_component_utils;

	this(string name, uvm_component parent = null) {
		    super(name, parent);
}
	override void connect_phase(uvm_phase phase) {
	      super.connect_phase(phase);


}
}