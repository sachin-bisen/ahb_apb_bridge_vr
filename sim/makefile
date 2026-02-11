CC              = gcc
CFLAGS		= -Wall -O3 -fPIC
SEED            = 1
DUMPFST         = 1
VEROPTS         = -Wno-fatal -O3 --euvm --no-timing --x-assign fast --x-initial fast --threads 1

 ifeq ($(DUMPFST),1)
 	VEROPTS += --trace-fst
 endif

 DFLAGS = -relocation-model=pic -w -O3 
 


ifeq ($(DUMPFST),1)
     DFLAGS += --d-version=DUMPFST
 endif

LDC2BINDIR = $(dir $(shell which ldc2))
VLBINDIR = $(dir $(shell which verilator))
VERBOSITY = NONE
VEROPTS += -Wno-SELRANGE -Wno-WIDTHTRUNC

TBSRC = ../tb/ahb_apb_driver.d \
	../tb/ahb_apb_monitor.d \
	../tb/ahb_apb_scoreboard.d \
	../tb/ahb_apb_slave.d \
	../tb/ahb_apb_intf.d \
	../tb/ahb_apb_agent.d \
	../tb/ahb_apb_env.d \
	../tb/ahb_apb_test.d 

DUTLIB = obj_dir/DVahb_apb.a

.PHONY: all clean

all: ahb_apb

$(DUTLIB): link_verilator
	(cd obj_dir; make -f DVahb_apb.mk DVahb_apb.a)

clean:
	rm -rf ahb_apb* euvm_dir obj_dir link_verilator

link_verilator: ../rtl/ahb_apb.v
	verilator $(VEROPTS) $^
	touch link_verilator

ahb_apb: link_verilator $(DUTLIB) $(TBSRC)
	ldc2 $(DFLAGS) -Ieuvm_dir $(TBSRC) $(DUTLIB) -of$@ -L-luvm-ldc-shared -L-lesdl-ldc-shared \
		-L-lphobos2-ldc-shared -L-ldruntime-ldc-shared -L-ldl -L-lstdc++

run: ahb_apb
	./ahb_apb +UVM_TESTNAME=ahb_apb.directed_test +UVM_VERBOSITY=$(VERBOSITY) # +UVM_OBJECTION_TRACE
