`include "cirno9_define.v"

module lsu(
    input         hs_ram4ls_rdy,
    output        o_sram_ren,
    output [ 3:0] o_sram_wen,

    output        hs_ls4axim_val,
    input         hs_axim4ls_rdy,
    output [ 3:0] o_axim_wen,
    output        o_axim_ren,

    output [31:0] o_adr,
    output [31:0] o_wdat,
    input  [31:0] i_rdat,
    
    output        hs_ls4ex_rdy,
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
    wire sel_sram = (ls_adr[31:16] == 16'h8000);
    wire out_rdy = sel_sram ? hs_ram4ls_rdy : hs_axim4ls_rdy;

    assign hs_ls4ex_rdy = out_rdy
                        & ((~hs_ag4ls_val)
                             | (~hs_axis4ls_val));
    assign hs_ls4ag_rdy = out_rdy & (~hs_axis4ls_val);
    assign hs_ls4axis_rdy = 1'b1;

    wire [31:0] ls_adr  = hs_axis4ls_val ? i_axis_adr
                        : hs_ag4ls_val   ? i_ag_adr
                        :                  i_pc;
    assign o_wdat = hs_ls4ex_rdy ? 32'b0
                  : hs_ls4ag_rdy ? i_ag_wdat
                  :                i_axis_wdat;
    wire [ 3:0] ls_wen  = hs_ls4ex_rdy ? 4'b0
                        : hs_ls4ag_rdy ? i_ag_wen
                        :                i_axis_wen;
    wire        ls_ren  = hs_ls4ex_rdy ? 1'b1
                        : hs_ls4ag_rdy ? i_ag_ren
                        :                i_axis_ren;

    assign o_adr = {32{out_rdy}} & ls_adr;
    assign {o_sram_wen,o_sram_ren} = {5{ sel_sram}} & {ls_wen, ls_ren};
    assign {o_axim_wen,o_axim_ren} = {5{~sel_sram}} & {ls_wen, ls_ren};
    assign o_rdat = i_rdat;
endmodule