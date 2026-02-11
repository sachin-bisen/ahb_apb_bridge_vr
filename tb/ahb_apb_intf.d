import esdl;
import uvm;
import esdl.intf.verilator.verilated;
import esdl.intf.verilator.trace;

class ahb_apb_intf: VlInterface
{
	Port!(Signal!(ubvec!1)) H_CLK;
	Port!(Signal!(ubvec!1)) H_RESET_n;
	VlPort!(32) H_WDATA;
	VlPort!(32) H_ADDR;
	VlPort!(32) P_RDATA;
	VlPort!(1) H_WRITE;
	VlPort!(3) H_TRANS;
	VlPort!(1) H_SEL_APB;
	VlPort!(1) H_READY_IN;

	
	VlPort!(32) P_WDATA;
	VlPort!(32) H_RDATA;
	VlPort!(32) P_ADDR;
	VlPort!(1) P_ENABLE;
	VlPort!(1) P_WRITE;
	VlPort!(1) H_RESP;
	VlPort!(1) P_SELx;
	VlPort!(1) H_READY_OUT;

	
}







