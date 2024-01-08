`include "cirno9_define.v"

module exu_cal(
    input              hs_ex4cal_val,
    output wire        hs_cal4ex_rdy,

    input [`CIRNO_CAL_OPB_SIZE-1:0] i_opb,

    output wire [31:0] res
);
    assign hs_cal4ex_rdy = 1'b1;

    wire opadd = i_opb[`CIRNO_CAL_ADD] & hs_ex4cal_val;
    wire opsub = i_opb[`CIRNO_CAL_SUB] & hs_ex4cal_val;
    wire opsl  = i_opb[`CIRNO_CAL_SLL] & hs_ex4cal_val;
    wire opsr  = (i_opb[`CIRNO_CAL_SRL]
               | i_opb[`CIRNO_CAL_SRA]) & hs_ex4cal_val;
    wire opxor = i_opb[`CIRNO_CAL_XOR] & hs_ex4cal_val;
    wire opcmp = i_opb[`CIRNO_CAL_CMP] & hs_ex4cal_val;                            
    wire [32:0] opn1 = i_opb[`CIRNO_CAL_OPN1];
    wire [32:0] opn2 = i_opb[`CIRNO_CAL_OPN2];
    wire [32:0] opn2_n = ~opn2 + 1;

    wire [32:0] addopn1 = {33{(opadd|opsub|opcmp)}} & opn1;
    wire [32:0] addopn2 = ({33{opadd}} & opn2)
                        | ({33{(opsub|opcmp)}} & opn2_n);
    
    wire [32:0] slopn = {1'b0,
                         opn1[ 0], opn1[ 1], opn1[ 2], opn1[ 3],
                         opn1[ 4], opn1[ 5], opn1[ 6], opn1[ 7], 
                         opn1[ 8], opn1[ 9], opn1[10], opn1[11],
                         opn1[12], opn1[13], opn1[14], opn1[15],
                         opn1[16], opn1[17], opn1[18], opn1[19],
                         opn1[20], opn1[21], opn1[22], opn1[23],
                         opn1[24], opn1[25], opn1[26], opn1[27],
                         opn1[28], opn1[29], opn1[30], opn1[31]};
    wire [32:0] sropn1 = ({33{opsr}} & opn1)
                       | ({33{opsl}} & slopn);
    wire [ 4:0] sropn2 = {5{(opsr | opsl)}} & opn2[4:0];

    wire [32:0] xoropn1 = {33{opxor}} & opn1;
    wire [32:0] xoropn2 = {33{opxor}} & opn2;

    wire [32:0] addsub_res = addopn1 + addopn2;
    wire [32:0] sr_res = sropn1 >>> sropn2;
    wire [32:0] sl_res = {            sr_res[ 1], sr_res[ 2], sr_res[ 3],
                          sr_res[ 4], sr_res[ 5], sr_res[ 6], sr_res[ 7],
                          sr_res[ 8], sr_res[ 9], sr_res[10], sr_res[11],
                          sr_res[12], sr_res[13], sr_res[14], sr_res[15],
                          sr_res[16], sr_res[17], sr_res[18], sr_res[19],
                          sr_res[20], sr_res[21], sr_res[22], sr_res[23],
                          sr_res[24], sr_res[25], sr_res[26], sr_res[27],
                          sr_res[28], sr_res[29], sr_res[30], sr_res[31],
                          sr_res[32], 1'b0};
    wire [32:0] xor_res = xoropn1 ^ xoropn2;
    wire [32:0] cmp_res = {32'b0, addsub_res[32]};

    assign res = ({32{(opadd|opsub)}} & addsub_res[31:0])
               | ({32{opsr         }} & sr_res[31:0]    )
               | ({32{opsl         }} & sl_res[31:0]    )
               | ({32{opxor        }} & xor_res[31:0]   )
               | ({32{opcmp        }} & cmp_res[31:0]   );
endmodule