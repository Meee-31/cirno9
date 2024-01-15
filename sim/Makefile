VERILOG_FILE = rv32ui-p-add.verilog

ini:
	mkdir -p ./simdir
	cp -r ../rtl/* ./simdir
	cp ../tb/* ./simdir

isasim:
	cp ../riscv-tests/isa/gen/$(VERILOG_FILE) ./simdir/a.verilog
	cd ./simdir && iverilog -o wave -y ./core isatb.v cirno9_cpu_top.v
	cd ./simdir && vvp -n wave -lxt2

wave:
	gtkwave ./simdir/*.vcd

clean:
	rm -rf ./simdir