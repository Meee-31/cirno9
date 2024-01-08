`include "dffs.v"

module rd(
    input         clk,
    input         rst_n,

    input         rdy,

    output        hs_rd4ls_val,
    input  [31:0] i_pc_nx,
    output [31:0] o_pc_r,
    input  [31:0] i_in_r,
    output [31:0] o_in
);
    wire        rdyl;
    wire [31:0] in_l;
    assign o_in = rdyl ? i_in_r : in_l;
    assign hs_rd4ls_val = rdyl;

    dffl  #(1)         ready(1'b1, rdy    , rdyl  , clk);
    dffl  #(32)        inl  (rdyl, i_in_r , in_l  , clk);
    dfflr #(32, 32'b0) pc   (rdy,  i_pc_nx, o_pc_r, clk, rst_n);
endmodule