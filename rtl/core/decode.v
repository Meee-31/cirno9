`include "cirno9_define.v"

module decode(   
    input       [31:0] i_in,
    input       [31:0] i_pc,

    output wire [`CIRNO_DEC_OPB_SIZE-1:0] o_opb,
    output wire [`CIRNO_DEC_USELE   -1:0] o_usele,
    
    output wire        o_rs1_ren,
    output wire        o_rs2_ren,
    output wire        o_rd_wen,
    
    output wire [ 4:0] o_rs1_idx,
    output wire [ 4:0] o_rs2_idx,
    output wire [ 4:0] o_rd_idx,
    output wire [31:0] o_im,

    output wire        o_ilgl,
    output wire        o_val
);

    wire [ 6: 0] rv32_opcode = i_in[ 6: 0];
    wire [ 4: 0] rv32_rd     = i_in[11: 7];
    wire [ 4: 0] rv32_rs1    = i_in[19:15];
    wire [ 4: 0] rv32_rs2    = i_in[24:20];
    wire [ 2: 0] rv32_fun3   = i_in[14:12];
    wire [ 6: 0] rv32_fun7   = i_in[31:25];

    wire rv32_rs1_x0 = (rv32_rs1 == 5'b00000);
    wire rv32_rs2_x0 = (rv32_rs2 == 5'b00000);
    wire rv32_rd_x0  = (rv32_rd  == 5'b00000);
    wire rv32_rd_x2  = (rv32_rd  == 5'b00010);

    wire rv32_rs1_x31 = (rv32_rs1 == 5'b11111);
    wire rv32_rs2_x31 = (rv32_rs2 == 5'b11111);
    wire rv32_rd_x31  = (rv32_rd  == 5'b11111);
    
    wire [31: 0] rv32_iim    = {{20{i_in[31]}}
                               ,i_in[31:20]};
    wire [31: 0] rv32_sim    = {{20{i_in[31]}}
                               ,i_in[31:25]
                               ,i_in[11: 7]};
    wire [31: 0] rv32_bim    = {{19{i_in[31]}}
                               ,i_in[31]
                               ,i_in[7]
                               ,i_in[30:25]
                               ,i_in[11: 8]
                               ,1'b0};
    wire [31: 0] rv32_uim    = {i_in[31:12] 
                                ,12'b0};
    wire [31: 0] rv32_jim    = {{11{i_in[31]}} 
                             , i_in[31] 
                             , i_in[19:12] 
                             , i_in[20] 
                             , i_in[30:21]
                             , 1'b0};

    wire rv32_rtype = (rv32_opcode == 7'b0110011);
    wire rv32_itype = (rv32_opcode == 7'b0010011);
    wire rv32_iload = (rv32_opcode == 7'b0000011);
    wire rv32_stype = (rv32_opcode == 7'b0100011);
    wire rv32_btype = (rv32_opcode == 7'b1100011);
    wire rv32_j     = (rv32_opcode == 7'b1101111);
    wire rv32_jr    = (rv32_opcode == 7'b1100011);
    wire rv32_lui   = (rv32_opcode == 7'b0110111);
    wire rv32_auipc = (rv32_opcode == 7'b0010111);
    wire rv32_envir = (rv32_opcode == 7'b1110011);

    wire rv32_fun3_000 = (rv32_fun3 == 3'b000);
    wire rv32_fun3_001 = (rv32_fun3 == 3'b001);
    wire rv32_fun3_010 = (rv32_fun3 == 3'b010);
    wire rv32_fun3_011 = (rv32_fun3 == 3'b011);
    wire rv32_fun3_100 = (rv32_fun3 == 3'b100);
    wire rv32_fun3_101 = (rv32_fun3 == 3'b101);
    wire rv32_fun3_110 = (rv32_fun3 == 3'b110);
    wire rv32_fun3_111 = (rv32_fun3 == 3'b111);

    wire rv32_fun7_0000000 = (rv32_fun7 == 7'b0000000);
    wire rv32_fun7_0100000 = (rv32_fun7 == 7'b0100000);
    wire rv32_fun7_0000001 = (rv32_fun7 == 7'b0000001);
    wire rv32_fun7_0000101 = (rv32_fun7 == 7'b0000101);
    wire rv32_fun7_0001001 = (rv32_fun7 == 7'b0001001);
    wire rv32_fun7_0001101 = (rv32_fun7 == 7'b0001101);
    wire rv32_fun7_0010101 = (rv32_fun7 == 7'b0010101);
    wire rv32_fun7_0100001 = (rv32_fun7 == 7'b0100001);
    wire rv32_fun7_0010001 = (rv32_fun7 == 7'b0010001);
    wire rv32_fun7_0101101 = (rv32_fun7 == 7'b0101101);
    wire rv32_fun7_1111111 = (rv32_fun7 == 7'b1111111);
    wire rv32_fun7_0000100 = (rv32_fun7 == 7'b0000100); 
    wire rv32_fun7_0001000 = (rv32_fun7 == 7'b0001000); 
    wire rv32_fun7_0001100 = (rv32_fun7 == 7'b0001100); 
    wire rv32_fun7_0101100 = (rv32_fun7 == 7'b0101100); 
    wire rv32_fun7_0010000 = (rv32_fun7 == 7'b0010000); 
    wire rv32_fun7_0010100 = (rv32_fun7 == 7'b0010100); 
    wire rv32_fun7_1100000 = (rv32_fun7 == 7'b1100000); 
    wire rv32_fun7_1110000 = (rv32_fun7 == 7'b1110000); 
    wire rv32_fun7_1010000 = (rv32_fun7 == 7'b1010000); 
    wire rv32_fun7_1101000 = (rv32_fun7 == 7'b1101000); 
    wire rv32_fun7_1111000 = (rv32_fun7 == 7'b1111000); 
    wire rv32_fun7_1010001 = (rv32_fun7 == 7'b1010001);  
    wire rv32_fun7_1110001 = (rv32_fun7 == 7'b1110001);  
    wire rv32_fun7_1100001 = (rv32_fun7 == 7'b1100001);  
    wire rv32_fun7_1101001 = (rv32_fun7 == 7'b1101001);  


    wire rv32_add  = rv32_rtype & rv32_fun3_000 & rv32_fun7_0000000;
    wire rv32_sub  = rv32_rtype & rv32_fun3_000 & rv32_fun7_0100000;
    wire rv32_sll  = rv32_rtype & rv32_fun3_001 & rv32_fun7_0000000;
    wire rv32_slt  = rv32_rtype & rv32_fun3_010 & rv32_fun7_0000000;
    wire rv32_sltu = rv32_rtype & rv32_fun3_011 & rv32_fun7_0000000;
    wire rv32_xor  = rv32_rtype & rv32_fun3_100 & rv32_fun7_0000000;
    wire rv32_srl  = rv32_rtype & rv32_fun3_101 & rv32_fun7_0000000;
    wire rv32_sra  = rv32_rtype & rv32_fun3_101 & rv32_fun7_0100000;
    wire rv32_or   = rv32_rtype & rv32_fun3_110 & rv32_fun7_0000000;
    wire rv32_and  = rv32_rtype & rv32_fun3_111 & rv32_fun7_0000000;

    wire rv32_addi = rv32_itype & rv32_fun3_000;
    wire rv32_slti = rv32_itype & rv32_fun3_010;
    wire rv32_sltiu= rv32_itype & rv32_fun3_011;
    wire rv32_xori = rv32_itype & rv32_fun3_100;
    wire rv32_ori  = rv32_itype & rv32_fun3_110;
    wire rv32_andi = rv32_itype & rv32_fun3_111;
    wire rv32_slli = rv32_itype & rv32_fun3_001 & (i_in[31:26] == 6'b000000);
    wire rv32_srli = rv32_itype & rv32_fun3_101 & (i_in[31:26] == 6'b000000);
    wire rv32_srai = rv32_itype & rv32_fun3_101 & (i_in[31:26] == 6'b010000);

    wire rv32_lb  = rv32_iload & rv32_fun3_000;
    wire rv32_lh  = rv32_iload & rv32_fun3_001;
    wire rv32_lw  = rv32_iload & rv32_fun3_010;
    wire rv32_lbu = rv32_iload & rv32_fun3_100;
    wire rv32_lhu = rv32_iload & rv32_fun3_101;

    wire rv32_sb  = rv32_stype & rv32_fun3_000;
    wire rv32_sh  = rv32_stype & rv32_fun3_001;
    wire rv32_sw  = rv32_stype & rv32_fun3_010;

    wire rv32_beq = rv32_btype & rv32_fun3_000;
    wire rv32_bne = rv32_btype & rv32_fun3_001;
    wire rv32_blt = rv32_btype & rv32_fun3_100;
    wire rv32_bge = rv32_btype & rv32_fun3_101;
    wire rv32_bltu= rv32_btype & rv32_fun3_110;
    wire rv32_bgeu= rv32_btype & rv32_fun3_111;

    wire rv32_jal = rv32_j                    ;
    wire rv32_jalr= rv32_jr    & rv32_fun3_000;

    wire rv32_csrrw = rv32_envir & rv32_fun3_001; 
    wire rv32_csrrs = rv32_envir & rv32_fun3_010; 
    wire rv32_csrrc = rv32_envir & rv32_fun3_011; 
    wire rv32_csrrwi= rv32_envir & rv32_fun3_101; 
    wire rv32_csrrsi= rv32_envir & rv32_fun3_110; 
    wire rv32_csrrci= rv32_envir & rv32_fun3_111;
    wire rv32_ecall = rv32_envir & rv32_fun3_000 & (i_in[31:20] == 12'b0000_0000_0000);
    wire rv32_ebreak= rv32_envir & rv32_fun3_000 & (i_in[31:20] == 12'b0000_0000_0001);
    wire rv32_mret  = rv32_envir & rv32_fun3_000 & (i_in[31:20] == 12'b0011_0000_0010);

    wire [`CIRNO_DEC_OPB_SIZE-1:0] dec_alubus;
    assign dec_alubus[`CIRNO_DEC_ALU_ADD ] = rv32_add  | rv32_addi | rv32_lui;
    assign dec_alubus[`CIRNO_DEC_ALU_SUB ] = rv32_sub;
    assign dec_alubus[`CIRNO_DEC_ALU_SLL ] = rv32_sll  | rv32_slli ;
    assign dec_alubus[`CIRNO_DEC_ALU_SLT ] = rv32_slt  | rv32_slti ;
    assign dec_alubus[`CIRNO_DEC_ALU_SLTU] = rv32_sltu | rv32_sltiu;
    assign dec_alubus[`CIRNO_DEC_ALU_XOR ] = rv32_xor  | rv32_xori ;
    assign dec_alubus[`CIRNO_DEC_ALU_SRL ] = rv32_srl  | rv32_srli ;
    assign dec_alubus[`CIRNO_DEC_ALU_SRA ] = rv32_sra  | rv32_srai ;
    assign dec_alubus[`CIRNO_DEC_ALU_OR  ] = rv32_or   | rv32_ori  ;
    assign dec_alubus[`CIRNO_DEC_ALU_AND ] = rv32_and  | rv32_andi ;

    wire [`CIRNO_DEC_OPB_SIZE-1:0] dec_bjubus;
    assign dec_bjubus[`CIRNO_DEC_BJU_BEQ ] = rv32_beq  ;
    assign dec_bjubus[`CIRNO_DEC_BJU_BNE ] = rv32_bne  ;
    assign dec_bjubus[`CIRNO_DEC_BJU_BLT ] = rv32_blt  ;
    assign dec_bjubus[`CIRNO_DEC_BJU_BGE ] = rv32_bge  ;
    assign dec_bjubus[`CIRNO_DEC_BJU_BLTU] = rv32_bltu ;
    assign dec_bjubus[`CIRNO_DEC_BJU_BGEU] = rv32_bgeu ;
    assign dec_bjubus[`CIRNO_DEC_BJU_JAL ] = rv32_jal  ;
    assign dec_bjubus[`CIRNO_DEC_BJU_JALR] = rv32_jalr ;
    assign dec_bjubus[`CIRNO_DEC_BJU_AUIP] = rv32_auipc;

    wire [`CIRNO_DEC_OPB_SIZE-1:0] dec_lsubus;
    assign dec_lsubus[`CIRNO_DEC_LSU_LB ]  = rv32_lb ;
    assign dec_lsubus[`CIRNO_DEC_LSU_LH ]  = rv32_lh ;
    assign dec_lsubus[`CIRNO_DEC_LSU_LW ]  = rv32_lw ;
    assign dec_lsubus[`CIRNO_DEC_LSU_LBU]  = rv32_lbu;
    assign dec_lsubus[`CIRNO_DEC_LSU_LHU]  = rv32_lhu;
    assign dec_lsubus[`CIRNO_DEC_LSU_SB ]  = rv32_sb ;
    assign dec_lsubus[`CIRNO_DEC_LSU_SH ]  = rv32_sh ;
    assign dec_lsubus[`CIRNO_DEC_LSU_SW ]  = rv32_sw ;

//    assign o_usele[`CIRNO_DEC_SELE_ALU] = (| dec_alubus);
//    assign o_usele[`CIRNO_DEC_SELE_BJU] = (| dec_bjubus);
//    assign o_usele[`CIRNO_DEC_SELE_LSU] = (| dec_lsubus);

    assign o_usele[`CIRNO_DEC_SELE_ALU] = rv32_rtype | rv32_itype | rv32_lui;
                                   
    assign o_usele[`CIRNO_DEC_SELE_BJU] = rv32_btype | rv32_j     | rv32_jr ;
    
    assign o_usele[`CIRNO_DEC_SELE_AGU] = rv32_iload | rv32_stype ;

    assign o_opb = dec_alubus |
                   dec_bjubus |
                   dec_lsubus |
                   {`CIRNO_DEC_OPB_SIZE{1'b0}};

    assign o_rs1_ren = rv32_rtype | rv32_itype | rv32_iload | rv32_btype |
                       rv32_jr;
    assign o_rs2_ren = rv32_rtype | rv32_stype | rv32_btype;
    assign o_rd_wen  = rv32_rtype | rv32_itype | rv32_iload |
                       rv32_jr    | rv32_lui   | rv32_auipc;

    assign o_rs1_idx = rv32_rs1;
    assign o_rs2_idx = rv32_rs2;
    assign o_rd_idx  = rv32_rd;

    wire [31:0] rv_im = ({32{rv32_itype}} & rv32_iim) |
                        ({32{rv32_stype}} & rv32_sim) |
                        ({32{rv32_btype}} & rv32_bim) |
                        ({32{rv32_lui  }} & rv32_uim) |
                        ({32{rv32_auipc}} & rv32_uim) |
                        ({32{rv32_j    }} & rv32_jim) |
                        ({32{rv32_jr   }} & rv32_jim);

    assign o_im = rv_im;

    wire rv32_all0s_ilgl = rv32_fun7_0000000           & 
                           rv32_rs2_x0                 &
                           rv32_rs1_x0                 &
                           rv32_fun3_000               &
                           rv32_rd_x0                  &
                           (rv32_opcode == 7'b0000000);
    wire rv32_all1s_ilgl = rv32_fun7_1111111           &
                           rv32_rs2_x31                &
                           rv32_rs1_x31                &
                           rv32_fun3_111               &
                           rv32_rd_x31                 &
                           (rv32_opcode == 7'b1111111);

    wire rv_all0s1s_ilgl = (rv32_all0s_ilgl | rv32_all1s_ilgl);

    wire rv32_sxxi_shamt_legl = (i_in[25] == 1'b0);
    wire rv32_sxxi_shamt_ilgl = (rv32_slli | rv32_srli | rv32_srai) & 
                                (~rv32_sxxi_shamt_legl);

    assign o_ilgl = (rv_all0s1s_ilgl     ) |
                    (rv32_sxxi_shamt_ilgl);

    wire rv32_nop = (rv32_itype | rv32_rtype  | 
                         rv32_itype | rv32_lui| 
                         rv32_auipc)           &
                         rv32_rd_x0           ;

    assign o_val = ~(rv32_nop) & (| o_usele);
endmodule