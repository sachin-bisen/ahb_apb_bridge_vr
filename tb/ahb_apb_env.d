import esdl;
import uvm;
import ahb_apb_agent: ahb_apb_agent;
import ahb_apb_slave: ahb_apb_slave;


class ahb_apb_env: uvm_env
{
	mixin uvm_component_utils;

	@UVM_BUILD ahb_apb_agent agent;
	@UVM_BUILD ahb_apb_slave slave; 	


	this(string name, uvm_component parent) {
		    super(name, parent);

}
}