
module lsu(
    input         clk,
    input         rst_n,

    output        hs_ls4sram_val,
    output [ 3:0] o_sram_wen,
    input  [31:0] i_sram_rdat,

    output        hs_ls4axim_val,
    input         hs_axim4ls_rdy,
    output [ 3:0] o_axim_wen,
    input  [31:0] i_axim_rdat,
    
    output [31:0] o_adr,
    output [31:0] o_wdat,

    input         hs_rd4ls_val,
    output        hs_ls4rd_rdy,
    input  [31:0] i_pc,

    input         hs_ag4ls_val,
    output        hs_ls4ag_rdy,
    input  [31:0] i_ag_adr,
    input  [31:0] i_ag_wdat,
    input  [ 3:0] i_ag_wen,
    input         i_ag_ren,

    input         hs_axis4ls_val,
    output        hs_ls4axis_rdy,
    input  [31:0] i_axis_adr,
    input  [31:0] i_axis_wdat,
    input  [ 3:0] i_axis_wen,
    input         i_axis_ren,

    output [31:0] o_rdat
);
    wire hs_ram4ls_rdy;
    wire sel_sram = (ls_adr[31:16] == 16'h8000);
    wire out_rdy = sel_sram_r ? hs_ram4ls_rdy : hs_axim4ls_rdy;
    wire hs_axis4ls_val_r, hs_rd4ls_val_r, hs_ag4ls_val_r;
    
    assign hs_ls4sram_val = (hs_rd4ls_val | hs_ag4ls_val | hs_axis4ls_val)
                          & sel_sram;
    assign hs_ls4axim_val = (hs_rd4ls_val | hs_ag4ls_val | hs_axis4ls_val)
                          & ~sel_sram;

    assign hs_ls4axis_rdy = out_rdy & hs_axis4ls_val_r;
    assign hs_ls4ag_rdy   = out_rdy & (~hs_axis4ls_val_r) & hs_ag4ls_val_r;
    assign hs_ls4rd_rdy   = out_rdy & (~hs_axis4ls_val_r) & (~hs_ag4ls_val_r) & hs_rd4ls_val_r;

    wire [31:0] ls_adr  = hs_axis4ls_val ? i_axis_adr
                        : hs_ag4ls_val   ? i_ag_adr
                        :                  i_pc;

    assign o_wdat = hs_axis4ls_val ? i_axis_wdat
                  : hs_ag4ls_val   ? i_ag_wdat
                  :                  32'b0;

    wire [ 3:0] ls_wen  = hs_axis4ls_val ? i_axis_wen
                        : hs_ag4ls_val   ? i_ag_wen
                        :                  4'b0;

    assign o_adr = ls_adr;
    assign o_sram_wen = {4{ sel_sram}} & ls_wen;
    assign o_axim_wen = {4{~sel_sram}} & ls_wen;
    wire   sel_sram_r;
    assign o_rdat = sel_sram_r ? i_sram_rdat : i_axim_rdat;
    dffl #(1)       radtsd (1'b1, sel_sram, sel_sram_r, clk);
    dffr #(1, 1'b0) ramrdyd(hs_ls4sram_val, hs_ram4ls_rdy, clk, rst_n);
    dffr #(1, 1'b0) axid (hs_axis4ls_val, hs_axis4ls_val_r, clk, rst_n);
    dffr #(1, 1'b0) rdd  (hs_rd4ls_val  , hs_rd4ls_val_r  , clk, rst_n);
    dffr #(1, 1'b0) agd  (hs_ag4ls_val  , hs_ag4ls_val_r  , clk, rst_n);
endmodule