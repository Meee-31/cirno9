 /*                                                                      
 Copyright 2020 Blue Liang, liangkangnan@163.com
                                                                         
 Licensed under the Apache License, Version 2.0 (the "License");         
 you may not use this file except in compliance with the License.        
 You may obtain a copy of the License at                                 
                                                                         
     http://www.apache.org/licenses/LICENSE-2.0                          
                                                                         
 Unless required by applicable law or agreed to in writing, software    
 distributed under the License is distributed on an "AS IS" BASIS,       
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and     
 limitations under the License.                                          
 */

`timescale 1 ns / 100 ps

`define JTAG_CLK  500   // 1MHz. This value do not less than 100


module jtagtb;

    reg clk;
    reg rst_n;

    reg TCK;
    reg TMS;
    reg TDI;
    wire TDO;

    reg[39:0] shift_reg;
    reg in;
    reg[39:0] resp_data;


    always #10 clk = ~clk;     // core clock = 50MHz


    integer i;
    integer j;


    task tap_reset;
        begin
            for (i = 0; i < 8; i = i + 1) begin
                TMS = 1;
                TCK = 0;
                #`JTAG_CLK
                TCK = 1;
                #`JTAG_CLK
                TCK = 0;
            end
        end
    endtask

    task select_ir;
        input[39:0] ir;

        begin
            // IR
            shift_reg = ir;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // SELECT-DR
            TMS = 1;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // SELECT-IR
            TMS = 1;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // CAPTURE-IR
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // SHIFT-IR
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // SHIFT-IR & EXIT1-IR
            for (i = 5; i > 0; i = i - 1) begin
                if (shift_reg[0] == 1'b1)
                    TDI = 1'b1;
                else
                    TDI = 1'b0;

                if (i == 1)
                    TMS = 1;

                TCK = 0;
                #`JTAG_CLK
                in = TDO;
                TCK = 1;
                #`JTAG_CLK
                TCK = 0;

                shift_reg = {{(35){1'b0}}, in, shift_reg[4:1]};
            end

            // PAUSE-IR
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // EXIT2-IR
            TMS = 1;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // UPDATE-IR
            TMS = 1;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;
        end
    endtask

    task dmi_write;
        input[5:0] addr;
        input[31:0] data;
        output[39:0] out;

        begin
            // op write
            shift_reg = {addr, data, 2'b10};

            // SELECT-DR
            TMS = 1;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // CAPTURE-DR
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // SHIFT-DR
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // SHIFT-DR & EXIT1-DR
            for (i = 40; i > 0; i = i - 1) begin
                if (shift_reg[0] == 1'b1)
                    TDI = 1'b1;
                else
                    TDI = 1'b0;

                if (i == 1)
                    TMS = 1;

                TCK = 0;
                #`JTAG_CLK
                in = TDO;
                TCK = 1;
                #`JTAG_CLK
                TCK = 0;

                shift_reg = {in, shift_reg[39:1]};
            end

            // PAUSE-DR
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // EXIT2-DR
            TMS = 1;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // UPDATE-DR
            TMS = 1;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // op nop
            shift_reg = {addr, {(32){1'b0}}, 2'b00};

            // SELECT-DR
            TMS = 1;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // CAPTURE-DR
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // SHIFT-DR
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // SHIFT-DR & EXIT1-DR
            for (i = 40; i > 0; i = i - 1) begin
                if (shift_reg[0] == 1'b1)
                    TDI = 1'b1;
                else
                    TDI = 1'b0;

                if (i == 1)
                    TMS = 1;

                TCK = 0;
                #`JTAG_CLK
                in = TDO;
                TCK = 1;
                #`JTAG_CLK
                TCK = 0;

                shift_reg = {in, shift_reg[39:1]};
            end

            // PAUSE-DR
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // EXIT2-DR
            TMS = 1;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // UPDATE-DR
            TMS = 1;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            out = shift_reg;
        end
    endtask

    task dmi_read;
        input[5:0] addr;
        output[39:0] out;

        begin
            // op read
            shift_reg = {addr, {(32){1'b0}}, 2'b01};

            // SELECT-DR
            TMS = 1;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // CAPTURE-DR
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // SHIFT-DR
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // SHIFT-DR & EXIT1-DR
            for (i = 40; i > 0; i = i - 1) begin
                if (shift_reg[0] == 1'b1)
                    TDI = 1'b1;
                else
                    TDI = 1'b0;

                if (i == 1)
                    TMS = 1;

                TCK = 0;
                #`JTAG_CLK
                in = TDO;
                TCK = 1;
                #`JTAG_CLK
                TCK = 0;

                shift_reg = {in, shift_reg[39:1]};
            end

            // PAUSE-DR
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // EXIT2-DR
            TMS = 1;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // UPDATE-DR
            TMS = 1;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // op nop
            shift_reg = {addr, {(32){1'b0}}, 2'b00};

            // SELECT-DR
            TMS = 1;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // CAPTURE-DR
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // SHIFT-DR
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // SHIFT-DR & EXIT1-DR
            for (i = 40; i > 0; i = i - 1) begin
                if (shift_reg[0] == 1'b1)
                    TDI = 1'b1;
                else
                    TDI = 1'b0;

                if (i == 1)
                    TMS = 1;

                TCK = 0;
                #`JTAG_CLK
                in = TDO;
                TCK = 1;
                #`JTAG_CLK
                TCK = 0;

                shift_reg = {in, shift_reg[39:1]};
            end

            // PAUSE-DR
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // EXIT2-DR
            TMS = 1;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // UPDATE-DR
            TMS = 1;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            // IDLE
            TMS = 0;
            TCK = 0;
            #`JTAG_CLK
            TCK = 1;
            #`JTAG_CLK
            TCK = 0;

            out = shift_reg;
        end
    endtask


    initial begin
        clk = 0;
        rst_n = 1'b1;

        TCK = 1;
        TMS = 1;
        TDI = 1;
        shift_reg = 40'h0;
        resp_data = 40'h0;
        in = 1'b0;

        $display("test running...");
        #100
        rst_n = 1'b0;
        #100
        rst_n = 1'b1;
        #200

        /*************************** start test ***************************/
        // reset TAP state machine
        tap_reset();
        // select dm regs
        select_ir(40'b10001);
        // reset dm module
        dmi_write(6'h10, 32'h0, resp_data);

        // read dmstatus reg
        dmi_read(6'h11, resp_data);
        $display("dmstatus = 0x%x", resp_data[33:2]);

        // write data to memory
        dmi_write(6'h38, 32'h20050404, resp_data);      // write sbcs
        dmi_write(6'h39, 32'h0, resp_data);             // write sbaddress0
        for (j = 0; j < 5; j = j + 1) begin
            $display("write: addr = 0x%x, data = 0x%x", j * 4, 32'h0 + j);
            dmi_write(6'h3c, 32'h0 + j, resp_data);     // write sbdata0
        end

        // read data from memory
        dmi_write(6'h38, 32'h20158404, resp_data);      // write sbcs
        dmi_write(6'h39, 32'h0, resp_data);             // write sbaddress0
        for (j = 0; j < 5; j = j + 1) begin
            dmi_read(6'h3c, resp_data);                 // read sbdata0
            $display("read: addr = 0x%x, data = 0x%x", j * 4, resp_data[33:2]);
        end

        ///////////////////////////////////////////////////////////
        // Check whether the data read is equal to the data written.
        ///////////////////////////////////////////////////////////

        $finish;
    end


    // sim timeout
    initial begin
        #10000000
        $display("Time Out.");
        $finish;
    end

    // generate wave file, used by gtkwave
    initial begin
        $dumpfile("jtagtb.vcd");
        $dumpvars(0, jtagtb);
    end

    cirno9_cpu_top cpu0(
        .clk(clk),
        .outside_rst_n(rst_n),
        .jtag_TCK(TCK),
        .jtag_TMS(TMS),
        .jtag_TDI(TDI),
        .jtag_TDO(TDO)
    );

endmodule
