//`include "./core/cirno9_define.v"
`include "cirno9_define.v"

module exu_bju(
    input              hs_ex4bj_val,
    output wire        hs_bj4ex_rdy,

    input [`CIRNO_DEC_OPB_SIZE-1:0] i_opb,

    input       [31:0] i_opn1,
    input       [31:0] i_opn2,
    input       [31:0] i_im,
    input       [31:0] i_pc,
    output wire [31:0] o_res,
    output wire        o_setpc,
    output wire [31:0] o_pc,
    output wire [31:0] o_pcadd,

    output wire        hs_bj4cal_val,
    input              hs_cal4bj_rdy,
    output wire [`CIRNO_CAL_OPB_SIZE-1:0] o_cal_opb,
    input       [31:0] i_cal_res,

    input       [31:0] i_mepc,
    output             o_mret,
    input       [31:0] i_mtvec,
    input              i_int_ena
);
    assign hs_bj4cal_val = hs_ex4bj_val;
    assign hs_bj4ex_rdy  = hs_cal4bj_rdy;
    
    wire opn_u = i_opb[`CIRNO_DEC_BJU_BLTU]
                |i_opb[`CIRNO_DEC_BJU_BGEU];

    wire [32:0] e_opn1 = opn_u ? {1'b0, i_opn1}
                               : {i_opn1[31], i_opn1};
    wire [32:0] e_opn2 = opn_u ? {1'b0, i_opn2}
                               : {i_opn2[31], i_opn2};
    wire [32:0] cal_opn1 = (justb | auipc) ? {1'b0,i_pc} : e_opn1;
    wire [32:0] cal_opn2 = justb ? 33'd4
                         : auipc ? {1'b0,i_im}
                                 : e_opn2;

    assign o_cal_opb[`CIRNO_CAL_XOR] = hs_ex4bj_val & (i_opb[`CIRNO_DEC_BJU_BEQ]
                                                          | i_opb[`CIRNO_DEC_BJU_BNE]);
    assign o_cal_opb[`CIRNO_CAL_CMP] = hs_ex4bj_val & (i_opb[`CIRNO_DEC_BJU_BLT]
                                                          | i_opb[`CIRNO_DEC_BJU_BGE]
                                                          | i_opb[`CIRNO_DEC_BJU_BLTU]
                                                          | i_opb[`CIRNO_DEC_BJU_BGEU]);
    assign o_cal_opb[`CIRNO_CAL_ADD] = hs_ex4bj_val & (i_opb[`CIRNO_DEC_BJU_AUIP]
                                                          | i_opb[`CIRNO_DEC_BJU_JALR]
                                                          | i_opb[`CIRNO_DEC_BJU_JAL ]);
    assign o_cal_opb[`CIRNO_CAL_SUB] = 1'b0;
    assign o_cal_opb[`CIRNO_CAL_SLL] = 1'b0;
    assign o_cal_opb[`CIRNO_CAL_SRL] = 1'b0;
    assign o_cal_opb[`CIRNO_CAL_SRA] = 1'b0;

    assign o_cal_opb[`CIRNO_CAL_OPN1] = {33{hs_ex4bj_val}} & cal_opn1;
    assign o_cal_opb[`CIRNO_CAL_OPN2] = {33{hs_ex4bj_val}} & cal_opn2;

    wire bif1  = (i_opb[`CIRNO_DEC_BJU_BNE ]
                   | i_opb[`CIRNO_DEC_BJU_BLT ] 
                   | i_opb[`CIRNO_DEC_BJU_BLTU]) & hs_ex4bj_val;
    wire bif0  = (i_opb[`CIRNO_DEC_BJU_BEQ ]
                   | i_opb[`CIRNO_DEC_BJU_BGE ]
                   | i_opb[`CIRNO_DEC_BJU_BGEU]) & hs_ex4bj_val;
    wire justb = ((i_opb[`CIRNO_DEC_BJU_JAL ]
                   | i_opb[`CIRNO_DEC_BJU_JALR]
                   | i_opb[`CIRNO_DEC_BJU_MRET]) 
               & hs_ex4bj_val);
    wire auipc = (i_opb[`CIRNO_DEC_BJU_AUIP]) & hs_ex4bj_val;

    wire b_res = (| i_cal_res);

    assign o_setpc = (bif1 & b_res   )
                   | (bif0 & (~b_res))
                   | (justb)
                   | i_int_ena;

    assign o_pc    = i_opb[`CIRNO_DEC_BJU_JALR] ? i_opn1
                   : i_int_ena                  ? i_mtvec
                   : i_opb[`CIRNO_DEC_BJU_MRET] ? i_mepc
                   :                              i_pc;
    assign o_pcadd = i_opb[`CIRNO_DEC_BJU_MRET] ? 32'b0 
                   : i_int_ena                  ? 32'b0 
                   :                              i_im;

    assign o_res = i_cal_res;

    assign o_mret = i_opb[`CIRNO_DEC_BJU_MRET] & hs_ex4bj_val;
endmodule