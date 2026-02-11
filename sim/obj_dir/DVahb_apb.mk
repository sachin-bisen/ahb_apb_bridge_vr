include Vahb_apb.mk

EUVMBINDIR = $(dir $(shell which ldc2))

DVahb_apb.a: verilated.o verilated_d.o verilated_threads.o \
	verilated_fst_c.o verilated_fst_d.o \
	verilated_vcd_c.o verilated_vcd_d.o \
	verilated_saif_c.o verilated_saif_d.o \
	Vahb_apb_euvm_funcs.o Vahb_apb_euvm.o Vahb_apb__ALL.a

Vahb_apb_euvm.o: ../euvm_dir/Vahb_apb_euvm.d
	ldc2 -c -O3 -w $^ -of$@

Vahb_apb_euvm_funcs.o: ../euvm_dir/Vahb_apb_euvm_funcs.cpp
	g++ $(CPPFLAGS) -c -I . -I $(VERILATOR_ROOT)/include $^

