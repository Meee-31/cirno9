`include "cirno9_define.v"

module exu_alu(
    input              hs_ex4al_val,
    output wire        hs_al4ex_rdy,

    input [`CIRNO_DEC_OPB_SIZE-1:0] i_opb,

    input       [31:0] i_opn1,
    input       [31:0] i_opn2,
    output wire [31:0] o_res,

    output wire        hs_al4cal_val,
    input              hs_cal4al_rdy,
    output wire [`CIRNO_CAL_OPB_SIZE-1:0] o_cal_opb,
    input       [31:0] i_cal_res
);
    assign hs_al4ex_rdy = hs_cal4al_rdy;
    assign hs_al4cal_val = cal_op;

    wire opn_u = i_opb[`CIRNO_DEC_ALU_SLTU]
               | i_opb[`CIRNO_DEC_ALU_SRL];

    wire cal_op = (| o_cal_opb);
    wire alu_op = (and_op | or_op);

    wire        and_op  = i_opb[`CIRNO_DEC_ALU_AND]; 
    wire        or_op   = i_opb[`CIRNO_DEC_ALU_OR];
    wire [31:0] alu_res = ({32{and_op}} & and_res)
                         |({32{or_op }} & or_res);

    wire [32:0] cal_opn1 = opn_u ? {1'b0, i_opn1}
                                 : {i_opn1[31], i_opn1};
    wire [32:0] cal_opn2 = opn_u ? {1'b0, i_opn2}
                                 : {i_opn2[31], i_opn2};

    assign o_cal_opb[`CIRNO_CAL_ADD] = hs_ex4al_val & i_opb[`CIRNO_DEC_ALU_ADD];
    assign o_cal_opb[`CIRNO_CAL_SUB] = hs_ex4al_val & i_opb[`CIRNO_DEC_ALU_SUB];
    assign o_cal_opb[`CIRNO_CAL_SLL] = hs_ex4al_val & i_opb[`CIRNO_DEC_ALU_SLL];
    assign o_cal_opb[`CIRNO_CAL_SRL] = hs_ex4al_val & i_opb[`CIRNO_DEC_ALU_SRL];
    assign o_cal_opb[`CIRNO_CAL_SRA] = hs_ex4al_val & i_opb[`CIRNO_DEC_ALU_SRA];
    assign o_cal_opb[`CIRNO_CAL_XOR] = hs_ex4al_val & i_opb[`CIRNO_DEC_ALU_XOR];
    assign o_cal_opb[`CIRNO_CAL_CMP] = hs_ex4al_val & (i_opb[`CIRNO_DEC_ALU_SLT]
                                                      |i_opb[`CIRNO_DEC_ALU_SLTU]);
    assign o_cal_opb[`CIRNO_CAL_OPN1] = {33{hs_ex4al_val}} & cal_opn1;
    assign o_cal_opb[`CIRNO_CAL_OPN2] = {33{hs_ex4al_val}} & cal_opn2;
//将需要“计算中心（cal）“计算的数据与信息传送过去。
    
    wire [31:0] and_res = i_opn1 & i_opn2;
    wire [31:0] or_res  = i_opn1 | i_opn2;
//AND和OR指令在alu内进行计算。
    
    assign o_res = ({32{cal_op}} & i_cal_res)
                  |({32{alu_op}} & alu_res);
endmodule