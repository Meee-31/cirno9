`include "cirno9_define.v"

module exu(
    output o_ex4rd_rdy,

    input [`CIRNO_DEC_OPB_SIZE-1:0] i_opb,
    input [`CIRNO_DEC_USELE   -1:0] i_usele,

    input i_rs1_ren,
    input i_rs2_ren,

    input       [31:0] i_rs1,
    input       [31:0] i_rs2,
    input       [31:0] i_im,
    input       [31:0] i_pc,
    input       [ 4:0] i_rd_idx,

    input              i_val,
    input              i_deilg,

    output wire        o_rd_wen,
    output wire [31:0] o_rd,
    output wire        o_setpc,
    output wire [31:0] o_newpc,

    input              hs_mem4ex_rdy,
    output wire        hs_ex4mem_val,
    output wire [31:0] o_mem_adr,
    output wire [31:0] o_mem_d,
    output wire        o_mem_ren,
    output wire        o_mem_wen
);
    
endmodule