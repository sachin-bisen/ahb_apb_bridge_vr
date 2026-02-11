import esdl;
import uvm;
import std.format;
import ahb_apb_intf : ahb_apb_intf;

class ahb_apb_slave : uvm_component
{
    mixin uvm_component_utils;

    ahb_apb_intf apb_if;

    
    uint [uint]mem;  //simple memory

    this(string name, uvm_component parent = null)
    {
    super(name, parent);
    uvm_config_db!ahb_apb_intf.get(this, "", "apb_if", apb_if);
    assert(apb_if !is null);
}


    override void run_phase(uvm_phase phase)
    {
    while (true)
    {
    wait(apb_if.H_CLK.posedge());

    if (apb_if.H_RESET_n == 0)
    {
    apb_if.P_RDATA = 0;
    continue;
    }

    if (apb_if.P_SELx == 1 && apb_if.P_ENABLE == 1)
    {
    if (apb_if.P_WRITE == 1)
    {
    mem[apb_if.P_ADDR] = apb_if.P_WDATA;

     uvm_info("APB_SLAVE", format("WRITE mem[0x%08x] = 0x%08x",
                      apb_if.P_ADDR, apb_if.P_WDATA), UVM_MEDIUM);
     } else {
       	     if (apb_if.P_ADDR in mem)    //Read 
                        apb_if.P_RDATA = mem[apb_if.P_ADDR];
     else
         apb_if.P_RDATA = 0;

     uvm_info("APB_SLAVE",format("READ  mem[0x%08x]
     0x%08x", apb_if.P_ADDR, apb_if.P_RDATA), UVM_MEDIUM);
                }
            }
        }
    }
}
