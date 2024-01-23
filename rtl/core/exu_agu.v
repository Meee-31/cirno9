//`include "./core/cirno9_define.v"
`include "cirno9_define.v"
module exu_agu(
    input              clk,
    input              rst_n,

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
    input       [31:0] i_ls_rdat,
    output wire [ 3:0] o_ls_wen,
    output wire        o_ls_ren,
    
    output wire        o_misal
);
    assign hs_ag4ex_rdy = hs_cal4ag_rdy & hs_ls4ag_rdy;
    wire lslb  = i_opb[`CIRNO_DEC_AGU_LB ]
               | i_opb[`CIRNO_DEC_AGU_LBU];
    wire lslh  = i_opb[`CIRNO_DEC_AGU_LH ]
               | i_opb[`CIRNO_DEC_AGU_LHU];
    wire lslw  = i_opb[`CIRNO_DEC_AGU_LW ];

    wire lssb  = i_opb[`CIRNO_DEC_AGU_SB ];
    wire lssh  = i_opb[`CIRNO_DEC_AGU_SH ];
    wire lssw  = i_opb[`CIRNO_DEC_AGU_SW ];

    wire res_u = i_opb[`CIRNO_DEC_AGU_LBU ]
               | i_opb[`CIRNO_DEC_AGU_LHU];

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
    wire [31:0] w_wdat = i_opn2;
    wire [31:0] h_wdat00ff = i_opn2;
    wire [31:0] h_wdatff00 = {i_opn2[15:0], 16'b0};
    wire [31:0] b_wdat000f = i_opn2;
    wire [31:0] b_wdat00f0 = {i_opn2[23:0], 8'b0};
    wire [31:0] b_wdat0f00 = {i_opn2[15:0], 16'b0};
    wire [31:0] b_wdatf000 = {i_opn2[ 7:0], 24'b0};
    wire [31:0] h_wdat = i_cal_res[1] ? h_wdatff00 : h_wdat00ff;
    wire [31:0] b_wdat = i_cal_res[1] ? i_cal_res[0] ? b_wdatf000
                                                     : b_wdat0f00
                                      : i_cal_res[0] ? b_wdat00f0
                                                     : b_wdat000f;
    assign o_ls_wdat = ({32{lssw}} & w_wdat)
                     | ({32{lssh}} & h_wdat)
                     | ({32{lssb}} & b_wdat);
    wire [31:0] w_res  = i_ls_rdat;
    wire [31:0] h_res00ff  = res_u ? {{16'b0            },  i_ls_rdat[15:0]} 
                                   : {{16{i_ls_rdat[15]}},  i_ls_rdat[15:0]};
    wire [31:0] h_resff00  = res_u ? {{16'b0            },  i_ls_rdat[31:16]} 
                                   : {{16{i_ls_rdat[31]}},  i_ls_rdat[31:16]};
    wire [31:0] b_res000f  = res_u ? {{24'b0            },  i_ls_rdat[ 7:0]} 
                                   : {{24{i_ls_rdat[ 7]}},  i_ls_rdat[ 7:0]};
    wire [31:0] b_res00f0  = res_u ? {{24'b0            },  i_ls_rdat[15:8]} 
                                   : {{24{i_ls_rdat[15]}},  i_ls_rdat[15:8]};
    wire [31:0] b_res0f00  = res_u ? {{24'b0            },  i_ls_rdat[23:16]} 
                                   : {{24{i_ls_rdat[23]}},  i_ls_rdat[23:16]};
    wire [31:0] b_resf000  = res_u ? {{24'b0            },  i_ls_rdat[31:24]} 
                                   : {{24{i_ls_rdat[31]}},  i_ls_rdat[31:24]};
    wire [31:0] h_res = i_cal_res[1] ? h_resff00 : h_res00ff;
    wire [31:0] b_res = i_cal_res[1] ? i_cal_res[0] ? b_resf000
                                                    : b_res0f00
                                     : i_cal_res[0] ? b_res00f0
                                                    : b_res000f;
    assign o_res = ({32{lslw}} & w_res)
                 | ({32{lslh}} & h_res)
                 | ({32{lslb}} & b_res);

    assign hs_ag4ls_val = hs_ex4ag_val & (~misal);
    //dffr #(1) val(hs_ag4ls_val, hs_ag4ls_val_r, clk, rst_n);
    //dffr #(32)adr(o_ls_adr_r, o_ls_adr, clk, rst_n);
endmodule