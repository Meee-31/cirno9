`define CIRNO_DEC_ALU_ADD   0
`define CIRNO_DEC_ALU_SUB   1
`define CIRNO_DEC_ALU_SLL   2
`define CIRNO_DEC_ALU_SLT   3
`define CIRNO_DEC_ALU_SLTU  4
`define CIRNO_DEC_ALU_XOR   5
`define CIRNO_DEC_ALU_SRL   6
`define CIRNO_DEC_ALU_SRA   7
`define CIRNO_DEC_ALU_OR    8
`define CIRNO_DEC_ALU_AND   9
`define CIRNO_DEC_ALU_SIZE  10

`define CIRNO_DEC_BJU_BEQ   0
`define CIRNO_DEC_BJU_BNE   1
`define CIRNO_DEC_BJU_BLT   2
`define CIRNO_DEC_BJU_BGE   3
`define CIRNO_DEC_BJU_BLTU  4
`define CIRNO_DEC_BJU_BGEU  5
`define CIRNO_DEC_BJU_JAL   6
`define CIRNO_DEC_BJU_JALR  7
`define CIRNO_DEC_BJU_AUIP  8
`define CIRNO_DEC_BJU_MRET  9
`define CIRNO_DEC_BJU_SIZE  10

`define CIRNO_DEC_AGU_LB    0
`define CIRNO_DEC_AGU_LH    1
`define CIRNO_DEC_AGU_LW    2
`define CIRNO_DEC_AGU_LBU   3
`define CIRNO_DEC_AGU_LHU   4
`define CIRNO_DEC_AGU_SB    5
`define CIRNO_DEC_AGU_SH    6
`define CIRNO_DEC_AGU_SW    7
`define CIRNO_DEC_AGU_SIZE  8

`define CIRNO_DEC_CSU_CSRRW 0
`define CIRNO_DEC_CSU_CSRRS 1
`define CIRNO_DEC_CSU_CSRRC 2
`define CIRNO_DEC_CSU_SIZE  3

`define CIRNO_DEC_SELE_ALU  0
`define CIRNO_DEC_SELE_AGU  1
`define CIRNO_DEC_SELE_BJU  2
`define CIRNO_DEC_SELE_CSU  3

`define CIRNO_DEC_OPB_SIZE 10
`define CIRNO_DEC_USELE     4
//译码信息总线，由于同一条指令只会使用一个模块。

`define CIRNO_CAL_OPN1 32:0
`define CIRNO_CAL_OPN2 65:33
`define CIRNO_CAL_ADD 66
`define CIRNO_CAL_SUB 67
`define CIRNO_CAL_SLL 68
`define CIRNO_CAL_SRL 69
`define CIRNO_CAL_SRA 70
`define CIRNO_CAL_XOR 71
`define CIRNO_CAL_CMP 72

`define CIRNO_CAL_OPB_SIZE 73
//位于EXU内部的操作信息总线。