//`include "./core/cirno9_define.v"
`include "cirno9_define.v"

module exu_csrctr(
    input         hs_ex4cs_val,
    output        hs_cs4ex_rdy,

    input [`CIRNO_DEC_OPB_SIZE-1:0] i_opb,

    input  [31:0] i_opn1,
    input  [11:0] i_csr_idx,
    output [31:0] o_res,

    output        csr_wen,
    output        csr_ren,
    output [11:0] csr_idx,
    output [31:0] csr_wdat,
    input  [31:0] csr_rdat
);
    assign hs_cs4ex_rdy = 1'b1;
    wire csrrw = i_opb[`CIRNO_DEC_CSU_CSRRW ];
    wire csrrs = i_opb[`CIRNO_DEC_CSU_CSRRS ];
    wire csrrc = i_opb[`CIRNO_DEC_CSU_CSRRC ];
  
    assign csr_ren = hs_ex4cs_val;
    assign csr_wen = hs_ex4cs_val;                                                                           
                                                                                           
    assign csr_idx = i_csr_idx;
  
    assign csr_wdat = ({32{csrrw}} & i_opn1)
                    | ({32{csrrs}} & (  i_opn1  | csr_rdat))
                    | ({32{csrrc}} & ((~i_opn1) & csr_rdat));

    assign o_res = csr_rdat;
endmodule