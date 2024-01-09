`include "cirno9_cpu_top.v"

module tb_top();
  
    reg  clk;
    reg  rst_n;

    `define PC_TOHOST  32'h8000003c
  
    `define CORE    cpu0.u_cirno9_core
    `define REG     `CORE.u_regfile
    `define SRAM    cpu0.u_sram32.mem_r
  
    wire [31:0] x3 = `REG.rf_r[3];
    wire [31:0] pc = `CORE.pc_r;
  
    reg [31:0] cycle_count;
  
    always @(posedge clk or negedge rst_n)
    begin 
      if(rst_n == 1'b0) begin
          cycle_count <= 32'b0;
      end
      else begin
          cycle_count <= cycle_count + 1'b1;
      end
    end

    initial begin
        clk   <=0;
        rst_n <=0;
        #120 rst_n <=1;
        #100000
            $display("Time Out !!!");
         $finish;
    end

    reg [7:0] sram_mem [0:65535];
    integer i;
    initial begin
        $readmemh({"rv32ui-p-add.verilog"}, sram_mem);
        
        for (i=0; i<16383;i=i+1) begin
            `SRAM[i][00+7:00] = sram_mem[i*4+0];
            `SRAM[i][08+7:08] = sram_mem[i*4+1];
            `SRAM[i][16+7:16] = sram_mem[i*4+2];
            `SRAM[i][24+7:24] = sram_mem[i*4+3];
        end
        $display("RAM 0x00: %h", `SRAM[00]);
        $display("RAM 0x01: %h", `SRAM[01]);
        $display("RAM 0x02: %h", `SRAM[02]);
        $display("RAM 0x03: %h", `SRAM[03]);
        $display("RAM 0x10: %h", `SRAM[10]);
    end
    always
    begin 
       #20 clk <= ~clk;
    end

    cirno9_cpu_top cpu0(
        .rst_n (rst_n),
        .clk   (clk  )
    );
    
    initial
    begin            
        $dumpfile("tb_top.vcd");        //生成的vcd文件名称
        $dumpvars(0, tb_top);    //tb模块名称
    end

endmodule


