`include "dffs.v"

module rd(
    input              clk,
    input              rst_n,

    input              rdy,//没有val，PC单周期必定准备好的。

    input       [31:0] i_pc_nx,
    output wire [31:0] o_pc_r
);
    dfflr #(32, 32'b0) pc (rdy, i_pc_nx, o_pc_r, clk, rst_n);
endmodule