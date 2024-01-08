`include "cirno9_define.v"

module cirno9_core(
    input         rst_n,
    input         clk,

    output        o_hs_ram4ls_rdy,
    output        o_sram_ren,
    output [ 3:0] o_sram_wen,
    input  [31:0] i_sram_rdat,
    output [31:0] o_adr,
    output [31:0] o_wdat
);
wire [31:0] pc_r;
wire        setpc;
wire [31:0] pc;
wire [31:0] pcadd;
wire [31:0] pc_nx;
pc  u_pc (
    .i_pc_r                  ( pc_r    ),
    .i_setpc                 ( setpc   ),
    .i_pc                    ( pc      ),
    .i_pcadd                 ( pcadd   ),
    .o_pc_nx                 ( pc_nx   )
);

wire        hs_rd4ls_val;
wire [31:0] valin;
rd  u_rd (
    .clk                     ( clk         ),
    .rst_n                   ( rst_n       ),
    .rdy                     ( hs_ex4rd_rdy),
    .hs_rd4ls_val            ( hs_rd4ls_val),
    .i_pc_nx                 ( pc_nx       ),
    .o_pc_r                  ( pc_r        ),
    .i_in_r                  ( rdat        ),
    .o_in                    ( valin       )
);

wire [`CIRNO_DEC_OPB_SIZE-1:0]  opb;
wire [`CIRNO_DEC_USELE   -1:0]  usele;
wire        rs1_ren;
wire        rs2_ren;
wire        rd_wen;
wire [ 4:0] rs1_idx;
wire [ 4:0] rs2_idx;
wire [ 4:0] rd_idx;
wire [31:0] im;
wire        deilg;
wire        deval;
decode  u_decode (
    .i_in                    ( valin     ),
    .i_pc                    ( pc_r      ),
    .o_opb                   ( opb       ),
    .o_usele                 ( usele     ),
    .o_rs1_ren               ( rs1_ren   ),
    .o_rs2_ren               ( rs2_ren   ),
    .o_rd_wen                ( rd_wen    ),
    .o_rs1_idx               ( rs1_idx   ),
    .o_rs2_idx               ( rs2_idx   ),
    .o_rd_idx                ( rd_idx    ),
    .o_im                    ( im        ),
    .o_ilgl                  ( deilg     ),
    .o_val                   ( deval     )
);

wire [31:0] rs1;
wire [31:0] rs2;
regfile  u_regfile (
    .read_src1_idx           ( rs1_idx  ),
    .read_src2_idx           ( rs2_idx  ),
    .wbck_dest_wen           ( rd_wen   ),
    .wbck_dest_idx           ( rd_idx   ),
    .wbck_dest_dat           ( rd       ),
    .clk                     ( clk      ),
    .rst_n                   ( rst_n    ),
    .read_src1_dat           ( rs1      ),
    .read_src2_dat           ( rs2      )
);

wire        hs_ex4rd_rdy;
wire [31:0] rd;
wire        hs_ls4ex_rdy;
wire        hs_ex4ls_val;
wire [31:0] agls_adr;
wire [31:0] agls_wdat;
wire [ 3:0] agls_wen;
wire        agls_ren;
wire        ilg;

exu  u_exu (
    .hs_ex4rd_rdy            ( hs_ex4rd_rdy ),
    .i_val                   ( deval        ),
    .i_deilg                 ( deilg        ),
    .i_opb                   ( opb          ),
    .i_usele                 ( usele        ),
    .i_rs2_ren               ( rs2_ren      ),
    .i_rs1                   ( rs1          ),
    .i_rs2                   ( rs2          ),
    .i_im                    ( im           ),
    .i_pc                    ( pc_r           ),
    .o_rd                    ( rd           ),
    .o_setpc                 ( setpc        ),
    .o_pc                    ( pc           ),
    .o_pcadd                 ( pcadd        ),
    .hs_ls4ex_rdy            ( hs_ls4ex_rdy ),
    .hs_ex4ls_val            ( hs_ex4ls_val ),
    .o_ls_adr                ( agls_adr     ),
    .o_ls_wdat               ( agls_wdat    ),
    .i_ls_rdat               ( rdat         ),
    .o_ls_wen                ( agls_wen     ),
    .o_ls_ren                ( agls_ren     ),
    .o_ilg                   ( ilg          )
);

wire        hs_ls4axim_val;
wire        hs_axim4ls_rdy;
wire [ 3:0] axim_wen;
wire        axim_ren;
wire [31:0] o_axim_adr;
wire [31:0] o_axim_wdat;
wire [31:0] i_axim_rdat;
wire [31:0] agls_adr;
wire [31:0] agls_wdat;
wire [ 3:0] agls_wen;
wire        agls_ren;
wire        hs_axis4ls_val;
wire        hs_ls4axis_rdy;
wire [31:0] axis_adr;
wire [31:0] axis_wdat;
wire [ 3:0] axis_wen;
wire        axis_ren;
wire [31:0] rdat;
lsu  u_lsu (
    .hs_ram4ls_rdy           ( o_hs_ram4ls_rdy  ),
    .o_sram_ren              ( o_sram_ren       ),
    .o_sram_wen              ( o_sram_wen       ),
    .i_sram_rdat             ( i_sram_rdat      ),
    .hs_ls4axim_val          (   ),
    .hs_axim4ls_rdy          ( 0  ),
    .o_axim_wen              (   ),
    .o_axim_ren              (   ),
    .i_axim_rdat             ( 0  ),
    .o_adr                   ( o_adr            ),
    .o_wdat                  ( o_wdat           ),
    .hs_rd4ls_val            ( hs_rd4ls_val     ),
    .i_pc                    ( pc_r             ),
    .hs_ag4ls_val            ( hs_ex4ls_val     ),
    .hs_ls4ag_rdy            ( hs_ls4ex_rdy     ),
    .i_ag_adr                ( agls_adr         ),
    .i_ag_wdat               ( agls_wdat        ),
    .i_ag_wen                ( agls_wen         ),
    .i_ag_ren                ( agls_ren         ),
    .hs_axis4ls_val          ( 0  ),
    .hs_ls4axis_rdy          (   ),
    .i_axis_adr              ( 0  ),
    .i_axis_wdat             ( 0  ),
    .i_axis_wen              ( 0  ),
    .i_axis_ren              ( 0  ),
    .o_rdat                  ( rdat             )
);
endmodule