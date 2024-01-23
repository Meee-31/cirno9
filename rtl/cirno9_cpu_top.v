`include "./core/cirno9_core.v"
`include "./rams/sram32.v"

module cirno9_cpu_top(
    input rst_n,
    input clk,

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
    wire        hs_ls4ram_val;
    wire [ 3:0] sram_wen;
    wire [31:0] sram_rdat;
    wire [31:0] adr;
    wire [31:0] wdat;
    cirno9_core  u_cirno9_core (
        .rst_n                   ( rst_n         ),
        .clk                     ( clk           ),
        .o_hs_ls4sram_val        ( hs_ls4ram_val ),
        .o_sram_wen              ( sram_wen      ),
        .i_sram_rdat             ( sram_rdat     ),
        .o_adr                   ( adr           ),
        .o_wdat                  ( wdat          ),
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
        .m_axi_rready            ( m_axi_rready    )
    );
    
    sram32  u_sram32 (
        .clk                     ( clk           ),
        .en                      ( hs_ls4ram_val ),
        .we                      ( sram_wen      ),
        .adr                     ( adr           ),
        .din                     ( wdat          ),
        .dout                    ( sram_rdat     )
);
endmodule
