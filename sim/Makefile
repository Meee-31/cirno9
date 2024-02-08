ISAVERILOG_FILE = rv32ui-p-sw.verilog
NOMALVERILOG_FILE = coremark.verilog

ini:
	mkdir -p ./simdir
	cp -r ../rtl/* ./simdir
	cp ../tb/* ./simdir
	cp ../rtl/core/cirno9_define.v ./simdir

isasim:
	cp ../riscv-tests/isa/gen/$(ISAVERILOG_FILE) ./simdir/a.verilog
	cd ./simdir && iverilog -o wave -y ./core -y ./debug -y ./general -y ./perips -y ./rams isatb.v cirno9_cpu_top.v
	cd ./simdir && vvp -n wave -lxt2

nomalsim:
	cp ../riscv-tests/isa/gen/$(NOMALVERILOG_FILE) ./simdir/a.verilog
	cd ./simdir && iverilog -o wave -y ./core -y ./debug -y ./general -y ./perips -y ./rams nomaltb.v cirno9_cpu_top.v
	cd ./simdir && vvp -n wave -lxt2

jtagsim:
	cd ./simdir && iverilog -o wave -y ./core -y ./debug -y ./general -y ./perips -y ./rams jtagtb.v cirno9_cpu_top.v
	cd ./simdir && vvp -n wave -lxt2

wave:
	gtkwave ./simdir/*.vcd

clean:
	rm -rf ./simdir