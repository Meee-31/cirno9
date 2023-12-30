`include "cirno9_define.v"

module exu_alu(
    input              hs_ex4al_val,
    output wire        hs_al4ex_rdy,

    input [`CIRNO_DEC_OPB_SIZE-1:0] i_opb,

    input       [31:0] i_rs1,
    input       [31:0] i_rs2,
    input       [31:0] i_rs2_n,
    output wire [31:0] o_rd,

    output wire [31:0] o_add_rs1,
    output wire [31:0] o_add_rs2,
    input       [31:0] i_add_rd,
    output wire [31:0] o_sft_rs1,
    output wire [31:0] o_sft_rs2,
    input       [31:0] i_sft_rd,
    output wire [31:0] o_cmp_rs1,
    output wire [31:0] o_cmp_rs2,
    input              i_cmp_rd
);
    
endmodule