//`include "./core/cirno9_define.v"
`include "cirno9_define.v"

module cirno9_core(
    input         rst_n,
    input         clk,

    output        o_hs_ls4sram_val,
    output        o_sram_ren,
    output [ 3:0] o_sram_wen,
    input  [31:0] i_sram_rdat,
    output [31:0] o_adr,
    output [31:0] o_wdat,

    output [31:0]   m_axi_awaddr, 
    output [7:0]              m_axi_awlen,  
    output [2:0]              m_axi_awsize, 
    output [1:0]              m_axi_awburst,
    output                    m_axi_awlock, 
    output [3:0]              m_axi_awcache,
    output [2:0]              m_axi_awprot, 
    output [3:0]              m_axi_awqos,  
    output                    m_axi_awvalid,
    input                     m_axi_awready,
    /*write*/
    output [31:0]   m_axi_wdata,  
    output [3:0]    m_axi_wstrb,  
    output                    m_axi_wlast,  
    output                    m_axi_wvalid, 
    input                     m_axi_wready, 
    /*write response*/ 
    input  [1:0]              m_axi_bresp,  
    input                     m_axi_bvalid, 
    output                    m_axi_bready, 
    /*address read*/ 
    output [31:0]   m_axi_araddr, 
    output [7:0]              m_axi_arlen,  
    output [2:0]              m_axi_arsize, 
    output [1:0]              m_axi_arburst,
    output                    m_axi_arlock, 
    output [3:0]              m_axi_arcache,
    output [2:0]              m_axi_arprot, 
    output [3:0]              m_axi_arqos,  
    output                    m_axi_arvalid,
    input                     m_axi_arready,
    /*read*/ 
    input  [31:0]   m_axi_rdata,  
    input  [1:0]              m_axi_rresp,  
    input                     m_axi_rlast,  
    input                     m_axi_rvalid, 
    output                    m_axi_rready
);
    wire        hs_ex4rd_rdy;
    wire        hs_rd4ex_val;
    wire [31:0] pc_r;
    wire        setpc;
    wire [31:0] pc;
    wire [31:0] pcadd;
    wire [31:0] pc_nx;
    wire        hs_rd4ls_val;
    wire        hs_ls4rd_rdy;
    wire [31:0] valin;
    ifu  u_if (
        .clk                     ( clk         ),
        .rst_n                   ( rst_n       ),
        .rdy                     ( hs_ex4rd_rdy),
        .val                     ( hs_rd4ex_val),
        .hs_rd4ls_val            ( hs_rd4ls_val),
        .hs_ls4rd_rdy            ( hs_ls4rd_rdy),
        .o_pc_nx                 ( pc_nx   ),
        .i_in_r                  ( rdat        ),
        .o_in                    ( valin       ),
        .o_pc_r                  ( pc_r        ),
        .i_setpc                 ( setpc   ),
        .i_pc                    ( pc      ),
        .i_pcadd                 ( pcadd   )
    );
    
    wire [`CIRNO_DEC_OPB_SIZE-1:0]  opb;
    wire [`CIRNO_DEC_USELE   -1:0]  usele;
    wire        rs1_ren;
    wire        rs2_ren;
    wire        rd_wen;
    wire [ 4:0] rs1_idx;
    wire [ 4:0] rs2_idx;
    wire [ 4:0] rd_idx;
    wire [11:0] csr_idx;
    wire [31:0] im;
    wire        deilg;
    wire        deval;
    wire [ 1:0] ecabr;
    decode  u_decode (
        .i_val                   ( hs_rd4ex_val),
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
        .o_csr_idx               ( csr_idx   ),
        .o_im                    ( im        ),
        .o_ilgl                  ( deilg     ),
        .o_val                   ( deval     ),
        .o_ecallbreak            ( ecabr     )
    );
    
    wire [31:0] rs1;
    wire [31:0] rs2;
    wire ex_rd_wen = rd_wen & hs_ex4rd_rdy;
    regfile  u_regfile (
        .read_src1_idx           ( rs1_idx  ),
        .read_src2_idx           ( rs2_idx  ),
        .wbck_dest_wen           ( ex_rd_wen),
        .wbck_dest_idx           ( rd_idx   ),
        .wbck_dest_dat           ( rd       ),
        .clk                     ( clk      ),
        .rst_n                   ( rst_n    ),
        .read_src1_dat           ( rs1      ),
        .read_src2_dat           ( rs2      )
    );
    
    wire [31:0] rd;
    wire        hs_ls4ex_rdy;
    wire        hs_ex4ls_val;
    wire [31:0] agls_adr;
    wire [31:0] agls_wdat;
    wire [ 3:0] agls_wen;
    wire        agls_ren;
    exu  u_exu (
        .clk                     ( clk          ),
        .rst_n                   ( rst_n        ),
        .hs_ex4rd_rdy            ( hs_ex4rd_rdy ),
        .i_val                   ( deval        ),
        .i_deilg                 ( deilg        ),
        .i_ecabr                 ( ecabr        ),
        .i_opb                   ( opb          ),
        .i_usele                 ( usele        ),
        .i_rs2_ren               ( rs2_ren      ),
        .i_csr_idx               ( csr_idx      ),
        .i_rs1                   ( rs1          ),
        .i_rs2                   ( rs2          ),
        .i_im                    ( im           ),
        .i_pc                    ( pc_r         ),
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
        .o_ls_ren                ( agls_ren     )
    );
    
    wire        hs_ls4axim_val;
    wire        hs_axim4ls_rdy;
    wire [ 3:0] axim_wen;
    wire [31:0] axim_rdat;
    wire        hs_axis4ls_val;
    wire        hs_ls4axis_rdy;
    wire [31:0] axis_adr;
    wire [31:0] axis_wdat;
    wire [ 3:0] axis_wen;
    wire [31:0] rdat;
    lsu  u_lsu (
        .clk                     ( clk              ),
        .rst_n                   ( rst_n            ),
        .hs_ls4sram_val          ( o_hs_ls4sram_val ),
        .o_sram_wen              ( o_sram_wen       ),
        .i_sram_rdat             ( i_sram_rdat      ),
        .hs_ls4axim_val          ( hs_ls4axim_val   ),
        .hs_axim4ls_rdy          ( hs_axim4ls_rdy   ),
        .o_axim_wen              ( axim_wen         ),
        .i_axim_rdat             ( axim_rdat        ),
        .o_adr                   ( o_adr            ),
        .o_wdat                  ( o_wdat           ),
        .hs_rd4ls_val            ( hs_rd4ls_val     ),
        .hs_ls4rd_rdy            ( hs_ls4rd_rdy     ),
        .i_pc                    ( pc_nx            ),
        .hs_ag4ls_val            ( hs_ex4ls_val     ),
        .hs_ls4ag_rdy            ( hs_ls4ex_rdy     ),
        .i_ag_adr                ( agls_adr         ),
        .i_ag_wdat               ( agls_wdat        ),
        .i_ag_wen                ( agls_wen         ),
        .i_ag_ren                ( agls_ren         ),
        .hs_axis4ls_val          ( 1'b0  ),
        .hs_ls4axis_rdy          (   ),
        .i_axis_adr              ( 32'b0  ),
        .i_axis_wdat             ( 32'b0  ),
        .i_axis_wen              ( 4'b0  ),
        .i_axis_ren              ( 1'b0  ),
        .o_rdat                  ( rdat             )
    );

axi4m #(
    .AXI_ADDR_W ( 32 ),
    .AXI_DATA_W ( 32 ))
 u_axi4m (
    .clk                     ( clk             ),
    .rst_n                   ( rst_n           ),
    .m_axi_awready           ( m_axi_awready   ),
    .m_axi_wready            ( m_axi_wready    ),
    .m_axi_bresp             ( m_axi_bresp     ),
    .m_axi_bvalid            ( m_axi_bvalid    ),
    .m_axi_arready           ( m_axi_arready   ),
    .m_axi_rdata             ( m_axi_rdata     ),
    .m_axi_rresp             ( m_axi_rresp     ),
    .m_axi_rlast             ( m_axi_rlast     ),
    .m_axi_rvalid            ( m_axi_rvalid    ),

    .m_axi_awaddr            ( m_axi_awaddr    ),
    .m_axi_awlen             ( m_axi_awlen     ),
    .m_axi_awsize            ( m_axi_awsize    ),
    .m_axi_awburst           ( m_axi_awburst   ),
    .m_axi_awlock            ( m_axi_awlock    ),
    .m_axi_awcache           ( m_axi_awcache   ),
    .m_axi_awprot            ( m_axi_awprot    ),
    .m_axi_awqos             ( m_axi_awqos     ),
    .m_axi_awvalid           ( m_axi_awvalid   ),
    .m_axi_wdata             ( m_axi_wdata     ),
    .m_axi_wstrb             ( m_axi_wstrb     ),
    .m_axi_wlast             ( m_axi_wlast     ),
    .m_axi_wvalid            ( m_axi_wvalid    ),
    .m_axi_bready            ( m_axi_bready    ),
    .m_axi_araddr            ( m_axi_araddr    ),
    .m_axi_arlen             ( m_axi_arlen     ),
    .m_axi_arsize            ( m_axi_arsize    ),
    .m_axi_arburst           ( m_axi_arburst   ),
    .m_axi_arlock            ( m_axi_arlock    ),
    .m_axi_arcache           ( m_axi_arcache   ),
    .m_axi_arprot            ( m_axi_arprot    ),
    .m_axi_arqos             ( m_axi_arqos     ),
    .m_axi_arvalid           ( m_axi_arvalid   ),
    .m_axi_rready            ( m_axi_rready    ),
    .val                     ( hs_ls4axim_val  ),
    .rdy                     ( hs_axim4ls_rdy  ),
    .wen                     ( axim_wen        ),
    .adr                     ( o_adr           ),
    .wdat                    ( o_wdat          ),
    .rdat                    ( axim_rdat       )
);
endmodule