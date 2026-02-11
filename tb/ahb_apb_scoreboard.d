import esdl;
import uvm;
import std.format;
import ahb_apb_driver: ahb_apb_driver;
import ahb_apb_monitor: ahb_apb_monitor;

class ahb_apb_scoreboard: uvm_component
{
	mixin uvm_component_utils;

    	uint ahb_wr_addr;
    	uint ahb_wr_data;
    	bool ahb_wr_valid;

	uint apb_wr_addr;
    	uint apb_wr_data;
    	bool apb_wr_valid;

	uint ahb_rd_addr;
    	uint ahb_rd_data;
    	bool ahb_rd_valid;

    	uint apb_rd_addr;
    	uint apb_rd_data;
    	bool apb_rd_valid;

	this(string name, uvm_component parent = null)
    	{
        super(name, parent);
        ahb_wr_valid = false;
        apb_wr_valid = false;
	
        apb_rd_valid = false;
        apb_rd_valid = false;
}

	void write_ahb_write(uint addr, uint data)
    	{
        ahb_wr_addr  = addr;
        ahb_wr_data  = data;
        ahb_wr_valid = true;

  // uvm_info("SCOREBOARD", format("AHB WRITE received | addr=0x%08x data=0x%08x", addr, data), UVM_MEDIUM);

   	check_write();

}

	void write_apb_write(uint addr, uint data)
    	{
        apb_wr_addr  = addr;
        apb_wr_data  = data;
        apb_wr_valid = true;

        //uvm_info("SCOREBOARD", format("APB WRITE received | addr=0x%08x data=0x%08x", addr, data), UVM_MEDIUM);

        check_write();
}

	void check_write()
        {
        if (ahb_wr_valid && apb_wr_valid)
        {
            if (ahb_wr_addr == apb_wr_addr && ahb_wr_data == apb_wr_data)
            {
 uvm_info("SCOREBOARD", "PASS: AHB write matches APB write", UVM_LOW);
            }
            else
            {
 uvm_error("SCOREBOARD", format("FAIL: AHB(addr=0x%08x data=0x%08x) != APB(addr=0x%08x data=0x%08x)", UVM_LOW));
            }

            // Reset for next transaction
            ahb_wr_valid = false;
            apb_wr_valid = false;
        }
    }

    void write_apb_read(uint addr, uint data)
    {
        apb_rd_addr  = addr;
        apb_rd_data  = data;
        apb_rd_valid = true;

        check_read();
    }

   
    void write_ahb_read(uint addr, uint data)   //Ahb Read 
    {
        ahb_rd_addr  = addr;
        ahb_rd_data  = data;
        ahb_rd_valid = true;

        check_read();
    }

    void check_read()
    {
        if (ahb_rd_valid && apb_rd_valid)
        {
            if (ahb_rd_addr == apb_rd_addr && ahb_rd_data == apb_rd_data)
            {
                uvm_info("SCOREBOARD", "PASS: READ APB AHB matched", UVM_LOW);
            }
            else
            {
                uvm_error("SCOREBOARD", "FAIL: READ mismatch APB vs AHB");
            }

            ahb_rd_valid = false;
            apb_rd_valid = false;
        }
    }
}