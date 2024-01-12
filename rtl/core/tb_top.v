`include "cirno9_cpu_top.v"

module tb_top();
  
    reg  clk;
    reg  rst_n;

    `define PC_TOHOST  32'h8000003c
  
    `define CORE    cpu0.u_cirno9_core
    `define REG     `CORE.u_regfile
    `define SRAM    cpu0.u_sram32.mem_r
    `define INSRT   `CORE.u_exu.in_retr
  
    wire [31:0] t3 = `REG.rf_r[28];
    wire [31:0] pc = `CORE.pc_r;
    wire pc_toho = pc == `PC_TOHOST;

    reg [31:0] pcho_cnt;
    reg [31:0] cycle_count;
    reg [31:0] inst_cnt;
  
    always @(posedge clk or negedge rst_n)
    begin 
      if(rst_n == 1'b0) begin
          cycle_count <= 32'b0;
          pcho_cnt    <= 0;
          inst_cnt    <= 0;
      end
      else begin
          cycle_count <= cycle_count + 1'b1;
      end
      if(pc_toho) pcho_cnt <= pcho_cnt + 1'b1;
      if(`INSRT)   inst_cnt <= inst_cnt + 1'b1;
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
        $readmemh({"rv32ui-p-fence_i.verilog"}, sram_mem);
        
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
        $display("RAM 0x50: %h", `SRAM[50]);

                $display("         ----------Running----------");

        wait(pcho_cnt == 3) 
            rst_n = 1'b0;
            $display("~~~~~~~~~~~~~~~~~~~Cycles %2d~~~~~~~~~~~~~~~~~~~~", cycle_count);
            $display("~~~~~~~~~~~~~~~~~~~Instrs %2d~~~~~~~~~~~~~~~~~~~~", inst_cnt);
            if (t3 == 1) begin
            $display("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            $display("~~~~~~~~~ #####     ##     ####    #### ~~~~~~~~~");
            $display("~~~~~~~~~ #    #   #  #   #       #     ~~~~~~~~~");
            $display("~~~~~~~~~ #    #  #    #   ####    #### ~~~~~~~~~");
            $display("~~~~~~~~~ #####   ######       #       #~~~~~~~~~");
            $display("~~~~~~~~~ #       #    #  #    #  #    #~~~~~~~~~");
            $display("~~~~~~~~~ #       #    #   ####    #### ~~~~~~~~~");
            $display("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        end else begin
            $display("~~~~~~~~~~~~~~~~~~ TEST_FAIL ~~~~~~~~~~~~~~~~~~~~~");
            $display("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            $display("~~~~~~~~~~######    ##       #    #     ~~~~~~~~~~");
            $display("~~~~~~~~~~#        #  #      #    #     ~~~~~~~~~~");
            $display("~~~~~~~~~~#####   #    #     #    #     ~~~~~~~~~~");
            $display("~~~~~~~~~~#       ######     #    #     ~~~~~~~~~~");
            $display("~~~~~~~~~~#       #    #     #    #     ~~~~~~~~~~");
            $display("~~~~~~~~~~#       #    #     #    ######~~~~~~~~~~");
            $display("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            $display("~~~~~~~~~~~~~CHECK YOUY BAKA DESIGN!~~~~~~~~~~~~~~");
            end
             $display("~~~~~~~~~~~~~~~~~~~~t3 %h~~~~~~~~~~~~~~~~~~~~~~~", t3);
            #10 $finish;
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


