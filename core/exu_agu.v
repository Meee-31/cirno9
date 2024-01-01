`include "cirno9_define.v"

module exu_agu(
    input              hs_ex4ag_val,
    output wire        hs_ag4ex_rdy,

    input [`CIRNO_DEC_OPB_SIZE-1:0] i_opb,

    input       [31:0] i_opn1,
    input       [31:0] i_opn2,
    input       [31:0] i_im,
    output wire [31:0] o_res,

    output wire        hs_ag4cal_val,
    input              hs_cal4ag_rdy,
    output wire [`CIRNO_CAL_OPB_SIZE-1:0] o_cal_opb,
    input       [31:0] i_cal_res,

    output wire        hs_ag4ls_val,
    input  wire        hs_ls4ag_rdy,
    output wire [31:0] o_ls_adr,
    output wire [31:0] o_ls_wdat,
    output wire [ 3:0] o_ls_wen,
    input       [31:0] i_ls_rdat,
    output wire        o_ls_ren,
    
    output wire        o_misal
);
    assign hs_ag4ex_rdy = hs_cal4ag_rdy & hs_ls4ag_rdy;
    wire lslb  = i_opb[`CIRNO_DEC_LSU_LB ]
               | i_opb[`CIRNO_DEC_LSU_LBU];
    wire lslh  = i_opb[`CIRNO_DEC_LSU_LH ]
               | i_opb[`CIRNO_DEC_LSU_LHU];
    wire lslw  = i_opb[`CIRNO_DEC_LSU_LW ];

    wire lssb  = i_opb[`CIRNO_DEC_LSU_SB ];
    wire lssh  = i_opb[`CIRNO_DEC_LSU_SH ];
    wire lssw  = i_opb[`CIRNO_DEC_LSU_SW ];

    wire res_u = i_opb[`CIRNO_DEC_LSU_LBU ]
               | i_opb[`CIRNO_DEC_LSU_LHU];

    assign o_cal_opb[`CIRNO_CAL_ADD] = hs_ex4ag_val & (lslb | lslh 
                                                         | lslw | lssb
                                                         | lssh | lssw);
    assign o_cal_opb[`CIRNO_CAL_SUB] = 1'b0;
    assign o_cal_opb[`CIRNO_CAL_SLL] = 1'b0;
    assign o_cal_opb[`CIRNO_CAL_SRL] = 1'b0;
    assign o_cal_opb[`CIRNO_CAL_SRA] = 1'b0;
    assign o_cal_opb[`CIRNO_CAL_XOR] = 1'b0;
    assign o_cal_opb[`CIRNO_CAL_CMP] = 1'b0;

    assign o_cal_opb[`CIRNO_CAL_OPN1] = {33{hs_ex4ag_val}} & {1'b0, i_opn1};
    assign o_cal_opb[`CIRNO_CAL_OPN2] = {33{hs_ex4ag_val}} & {1'b0, i_im};

    assign hs_ag4cal_val = o_cal_opb[`CIRNO_CAL_ADD];

    wire misal = ((lslh | lssh) & i_cal_res[0])
               | ((lslw | lssw) & (| i_cal_res[1:0]));
    assign o_misal = misal & hs_ex4ag_val;

    assign o_ls_adr = i_cal_res;
    assign o_ls_ren = lslb | lslh | lslw;

    wire [3:0] swen = 4'b1111;
    wire [3:0] shen = i_cal_res[1] ? 4'b1100
                                   : 4'b0011;
    wire [3:0] sben = i_cal_res[1] ? (i_cal_res[0] ? 4'b1000 : 4'b0100)
                                   : (i_cal_res[0] ? 4'b0010 : 4'b0001);
    assign o_ls_wen = ({4{lssw}} & swen)
                    | ({4{lssh}} & shen)
                    | ({4{lssb}} & sben);
    assign o_ls_wdat = i_opn2;
    assign o_res = i_ls_rdat;

    assign hs_ag4ls_val = hs_ex4ag_val & ~misal;
endmodule