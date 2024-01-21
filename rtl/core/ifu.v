module ifu(
    input         clk,
    input         rst_n,

    input         rdy,
    output        val,

    output        hs_rd4ls_val,
    input         hs_ls4rd_rdy,
    output [31:0] o_pc_nx,
    input  [31:0] i_in_r,
    
    output [31:0] o_in,
    output [31:0] o_pc_r,

    input         i_setpc,
    input  [31:0] i_pc,
    input  [31:0] i_pcadd
);
    wire        rdyl;
    assign      val = hs_ls4rd_rdy | (~rdyl);
    wire [31:0] in_l;
    assign      o_in = rdyl ? i_in_r : in_l;
    assign      hs_rd4ls_val = rdy;

    dffr  #(1, 1'b1)          ready(rdy ,   rdyl , clk , rst_n);
    dffl  #(32)               inl  (hs_ls4rd_rdy, i_in_r, in_l, clk);
    dfflr #(32, 32'h80000000) pc   (rdy, o_pc_nx, o_pc_r, clk , rst_n);

    assign o_pc_nx = rdyl ? pc_nx_nx : pc_nx_r;

    wire [31:0] pc_nx_nx;
    wire [31:0] pc_nx_r;
    dffl #(32) pcnx (hs_ls4rd_rdy, pc_nx_nx, pc_nx_r, clk);

    wire [31:0] pc_add1 = i_setpc ? i_pc
                        :          o_pc_r ;
    wire [31:0] pc_add2 = i_setpc      ? i_pcadd
                        : hs_ls4rd_rdy ? 32'd4
                        :                32'b0;
    assign pc_nx_nx = pc_add1 + pc_add2;
endmodule