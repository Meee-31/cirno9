//`include "./core/cirno9_define.v"
`include "cirno9_define.v"

module exu(
    input  clk,
    input  rst_n,
    output hs_ex4rd_rdy,

    input i_val,
    input i_deilg,
    input [1:0]i_ecabr,
    input [`CIRNO_DEC_OPB_SIZE-1:0] i_opb,
    input [`CIRNO_DEC_USELE   -1:0] i_usele,

    input i_rs2_ren,

    input       [11:0] i_csr_idx,
    input       [31:0] i_rs1,
    input       [31:0] i_rs2,
    input       [31:0] i_im,
    input       [31:0] i_pc,

    output wire [31:0] o_rd,

    output wire        o_setpc,
    output wire [31:0] o_pc,
    output wire [31:0] o_pcadd,

    output wire        hs_ex4ls_val,
    input  wire        hs_ls4ex_rdy,
    output wire [31:0] o_ls_adr,
    output wire [31:0] o_ls_wdat,
    input       [31:0] i_ls_rdat,
    output wire [ 3:0] o_ls_wen,
    output wire        o_ls_ren
);
    assign hs_ex4rd_rdy = (hs_al4ex_rdy & i_usele[`CIRNO_DEC_SELE_ALU])
                        | (hs_bj4ex_rdy & i_usele[`CIRNO_DEC_SELE_BJU])
                        | (hs_ag4ex_rdy & i_usele[`CIRNO_DEC_SELE_AGU])
                        | (hs_cs4ex_rdy & i_usele[`CIRNO_DEC_SELE_CSU])
                        | ~i_val;

    assign o_rd = (alex_res & {32{i_usele[`CIRNO_DEC_SELE_ALU]}})
                | (bjex_res & {32{i_usele[`CIRNO_DEC_SELE_BJU]}})
                | (agex_res & {32{i_usele[`CIRNO_DEC_SELE_AGU]}})
                | (csex_res & {32{i_usele[`CIRNO_DEC_SELE_CSU]}});

    assign o_setpc = bjex_pc_setpc;
    assign o_pc = bjex_pc_pc;
    assign o_pcadd = bjex_pc_pcadd;

    assign hs_ex4ls_val = hs_ag4ls_val;
    assign hs_ls4ag_rdy = hs_ls4ex_rdy;
    assign o_ls_adr = agex_ls_adr;
    assign o_ls_wdat = agex_ls_wdat;
    assign o_ls_wen = agex_ls_wen;
    assign exag_ls_rdat = i_ls_rdat;
    assign o_ls_ren = agex_ls_ren;

    wire ilg = agex_misal | i_deilg;

    wire hs_ex4cal_val = hs_ag4cal_val | hs_bj4cal_val | hs_al4cal_val;
    wire hs_cal4ex_rdy;
    wire [`CIRNO_CAL_OPB_SIZE-1:0]  cal_opb = agcal_cal_opb | bjcal_cal_opb | alcal_cal_opb;
    wire [31:0]  cal_res;
    
    exu_cal  u_exu_cal (
        .hs_ex4cal_val           ( hs_ex4cal_val   ),
        .hs_cal4ex_rdy           ( hs_cal4ex_rdy   ),
        .i_opb                   ( cal_opb         ),
        .res                     ( cal_res         )
    );
  
    wire        hs_ex4al_val = i_usele[`CIRNO_DEC_SELE_ALU] & i_val;
    wire        hs_al4ex_rdy;
    wire [31:0] exal_opn2 = i_rs2_ren ? i_rs2 : i_im;
    wire [31:0] alex_res;
    wire        hs_al4cal_val;
    wire [`CIRNO_CAL_OPB_SIZE-1:0]  alcal_cal_opb;
    
    exu_alu  u_exu_alu (
        .hs_ex4al_val            ( hs_ex4al_val    ),
        .hs_al4ex_rdy            ( hs_al4ex_rdy    ),
        .i_opb                   ( i_opb           ),
        .i_opn1                  ( i_rs1           ),
        .i_opn2                  ( exal_opn2       ),
        .o_res                   ( alex_res        ),
        .hs_cal4al_rdy           ( hs_cal4ex_rdy   ),
        .hs_al4cal_val           ( hs_al4cal_val   ),
        .o_cal_opb               ( alcal_cal_opb   ),
        .i_cal_res               ( cal_res         )
    );

    wire        hs_ex4bj_val = i_usele[`CIRNO_DEC_SELE_BJU] & i_val;
    wire        hs_bj4ex_rdy;
    wire [31:0] bjex_res;
    wire        bjex_pc_setpc;
    wire [31:0] bjex_pc_pc;
    wire [31:0] bjex_pc_pcadd;
    wire        hs_bj4cal_val;
    wire [`CIRNO_CAL_OPB_SIZE-1:0]  bjcal_cal_opb;
    wire [31:0] mepc;
    wire        mret_ena;
    wire [31:0] mtvec;
    wire        int_ena;
    exu_bju  u_exu_bju (
        .hs_ex4bj_val            ( hs_ex4bj_val    ),
        .hs_bj4ex_rdy            ( hs_bj4ex_rdy    ),
        .i_opb                   ( i_opb           ),
        .i_opn1                  ( i_rs1           ),
        .i_opn2                  ( i_rs2           ),
        .i_im                    ( i_im            ),
        .i_pc                    ( i_pc            ),
        .o_res                   ( bjex_res        ),
        .o_setpc                 ( bjex_pc_setpc   ),
        .o_pc                    ( bjex_pc_pc      ),
        .o_pcadd                 ( bjex_pc_pcadd   ),
        .hs_bj4cal_val           ( hs_bj4cal_val   ),
        .hs_cal4bj_rdy           ( hs_cal4ex_rdy   ),
        .o_cal_opb               ( bjcal_cal_opb   ),
        .i_cal_res               ( cal_res         ),
        .i_mepc                  ( mepc            ),
        .o_mret                  ( mret_ena        ),
        .i_mtvec                 ( mtvec           ),
        .i_int_ena               ( int_ena         )
    );
        
    wire        hs_ex4ag_val = i_usele[`CIRNO_DEC_SELE_AGU] & i_val;
    wire        hs_ag4ex_rdy;
    wire [31:0] agex_res;
    wire        hs_ag4cal_val;
    wire [`CIRNO_CAL_OPB_SIZE-1:0]  agcal_cal_opb;
    wire        hs_ag4ls_val;
    wire        hs_ls4ag_rdy;
    wire [31:0] agex_ls_adr;
    wire [31:0] agex_ls_wdat;
    wire [ 3:0] agex_ls_wen;
    wire [31:0] exag_ls_rdat;
    wire        agex_ls_ren;
    wire        agex_misal;
    
    exu_agu  u_exu_agu (
        .clk                     ( clk             ),
        .rst_n                   ( rst_n           ),
        .hs_ex4ag_val            ( hs_ex4ag_val    ),
        .hs_ag4ex_rdy            ( hs_ag4ex_rdy    ),
        .i_opb                   ( i_opb           ),
        .i_opn1                  ( i_rs1           ),
        .i_opn2                  ( i_rs2           ),
        .i_im                    ( i_im            ),
        .o_res                   ( agex_res        ),
        .hs_ag4cal_val           ( hs_ag4cal_val   ),
        .hs_cal4ag_rdy           ( hs_cal4ex_rdy   ),
        .o_cal_opb               ( agcal_cal_opb   ),
        .i_cal_res               ( cal_res         ),
        .hs_ag4ls_val            ( hs_ag4ls_val    ),
        .hs_ls4ag_rdy            ( hs_ls4ag_rdy    ),
        .o_ls_adr                ( agex_ls_adr     ),
        .o_ls_wdat               ( agex_ls_wdat    ),
        .i_ls_rdat               ( exag_ls_rdat    ),
        .o_ls_wen                ( agex_ls_wen     ),
        .o_ls_ren                ( agex_ls_ren     ),
        .o_misal                 ( agex_misal      )
    );

    wire        hs_ex4cs_val = i_usele[`CIRNO_DEC_SELE_CSU] & i_val;
    wire        hs_cs4ex_rdy;
    wire [31:0] csex_res;
    wire        csr_wen;
    wire        csr_ren;
    wire [11:0] csr_idx;
    wire [31:0] csr_wdat;
    wire [31:0] csr_rdat;
    exu_csrctr  u_exu_csrctr (
        .hs_ex4cs_val            ( hs_ex4cs_val   ),
        .hs_cs4ex_rdy            ( hs_cs4ex_rdy   ),
        .i_opb                   ( i_opb          ),
        .i_opn1                  ( i_rs1         ),
        .i_csr_idx               ( i_csr_idx      ),
        .o_res                   ( csex_res       ),
        .csr_wen                 ( csr_wen        ),
        .csr_ren                 ( csr_ren        ),
        .csr_idx                 ( csr_idx        ),
        .csr_wdat                ( csr_wdat       ),
        .csr_rdat                ( csr_rdat       )
    );

    wire        epc_en   = 1'b0;
    wire [31:0] epc_pc = 32'b0;
    wire        ext_ip = 1'b0;
    wire        tmr_ip = 1'b0;
    wire        sft_ip = 1'b0;
    wire        in_retr = hs_ex4rd_rdy & i_val & ~ilg;
    exu_csr  u_exu_csr (
        .rst_n                   ( rst_n      ),
        .clk                     ( clk        ),
        .csr_wen                 ( csr_wen    ),
        .csr_ren                 ( csr_ren    ),
        .csr_idx                 ( csr_idx    ),
        .csr_wdat                ( csr_wdat   ),
        .csr_rdat                ( csr_rdat   ),
        .cmepc                   ( mepc       ),
        .mret_ena                ( mret_ena   ),
        .cmtvec                  ( mtvec      ),
        .int_ena                 ( int_ena    ),
        .i_mcause                ( mcause     ),
        .epc_pc                  ( i_pc       ),
        .ext_ip                  ( ext_ip     ),
        .tmr_ip                  ( tmr_ip     ),
        .sft_ip                  ( sft_ip     ),
        .in_retr                 ( in_retr    )
    );

    wire        hs_in4ex_rdy;
    wire [31:0] mcause;
    exu_intc  u_exu_intc (
        .hs_in4ex_rdy            (  ),
        .i_ecabr                 ( i_ecabr        ),
        .i_ilg                   ( ilg            ),
        .o_int_ena               ( int_ena        ),
        .o_mcause                ( mcause         )
    );
endmodule