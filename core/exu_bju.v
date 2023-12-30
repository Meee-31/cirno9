`include "cirno9_define.v"

module exu_bju(
    input              hs_ex4bj_val,
    output wire        hs_bj4ex_rdy,

    input [`CIRNO_DEC_OPB_SIZE-1:0] i_opb,

    input       [31:0] i_opn1,
    input       [31:0] i_opn2,
    input       [31:0] i_imm,
    input       [31:0] i_pc,
    output wire [31:0] o_res,
    output wire        o_setpc,
    output wire [31:0] o_newpc,

    output wire        hs_al4cal_val,
    input              hs_cal4al_rdy,
    output wire [`CIRNO_CAL_OPB_SIZE-1:0] o_cal_opb,
    input       [31:0] i_cal_res
);
    wire opn_u = i_opb[`CIRNO_DEC_BJU_BLTU]
                |i_opb[`CIRNO_DEC_BJU_BGEU];

    wire [32:0] e_opn1 = opn_u ? {1'b0, i_opn1}
                                 : {i_opn1[31], i_opn1};
    wire [32:0] e_opn2 = opn_u ? {1'b0, i_opn2}
                                 : {i_opn2[31], i_opn2};
endmodule