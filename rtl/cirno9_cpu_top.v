
module cirno9_cpu_top(
    input outside_rst_n,
    input clk,
    
    input  uart_rx,
    output uart_tx,

    input  jtag_TCK,
    input  jtag_TMS,
    input  jtag_TDI,
    output jtag_TDO

//    output [31:0]   m_axi_awaddr, 
//    output [7:0]              m_axi_awlen,  
//    output [2:0]              m_axi_awsize, 
//    output [1:0]              m_axi_awburst,
//    output                    m_axi_awlock, 
//    output [3:0]              m_axi_awcache,
//    output [2:0]              m_axi_awprot, 
//    output [3:0]              m_axi_awqos,  
//    output                    m_axi_awvalid,
//    input                     m_axi_awready,
//    /*write*/
//    output [31:0]   m_axi_wdata,  
//    output [3:0]    m_axi_wstrb,  
//    output                    m_axi_wlast,  
//    output                    m_axi_wvalid, 
//    input                     m_axi_wready, 
//    /*write response*/ 
//    input  [1:0]              m_axi_bresp,  
//    input                     m_axi_bvalid, 
//    output                    m_axi_bready, 
//    /*address read*/ 
//    output [31:0]   m_axi_araddr, 
//    output [7:0]              m_axi_arlen,  
//    output [2:0]              m_axi_arsize, 
//    output [1:0]              m_axi_arburst,
//    output                    m_axi_arlock, 
//    output [3:0]              m_axi_arcache,
//    output [2:0]              m_axi_arprot, 
//    output [3:0]              m_axi_arqos,  
//    output                    m_axi_arvalid,
//    input                     m_axi_arready,
//    /*read*/ 
//    input  [31:0]   m_axi_rdata,  
//    input  [1:0]              m_axi_rresp,  
//    input                     m_axi_rlast,  
//    input                     m_axi_rvalid, 
//    output                    m_axi_rready
);
    wire        hs_ls4ram_val;
    wire [ 3:0] sram_wen;
    wire [31:0] sram_rdat;
    wire        hs_ls4iob_val;
    wire        hs_iob4ls_rdy;
    wire [ 3:0] iob_wen;
    wire [31:0] iob_rdat;
    wire [31:0] adr;
    wire [31:0] wdat;

    wire        hs_iobs4ls_val;
    wire        hs_ls4iobs_rdy;
    wire [31:0] iob_s_adr;
    wire [31:0] iob_s_wdat;
    wire [ 3:0] iob_s_wen;
    wire        iob_s_ren;
    wire [31:0] iob_s_rdat;
    wire        jtag_reset_req;
    wire        rst_n = outside_rst_n & (~jtag_reset_req);
    cirno9_core  u_cirno9_core (
        .rst_n                   ( rst_n         ),
        .clk                     ( clk           ),
        .o_hs_ls4sram_val        ( hs_ls4ram_val ),
        .o_sram_wen              ( sram_wen      ),
        .i_sram_rdat             ( sram_rdat     ),
        .o_hs_ls4iob_val         ( hs_ls4iob_val ),
        .i_hs_iob4ls_rdy         ( hs_iob4ls_rdy ),
        .o_iob_wen               ( iob_wen       ),
        .i_iob_rdat              ( iob_rdat      ),
        .o_adr                   ( adr           ),
        .o_wdat                  ( wdat          ),
        .hs_iobs4ls_val          ( hs_iobs4ls_val),
        .hs_ls4iobs_rdy          ( hs_ls4iobs_rdy),
        .i_iob_s_adr             ( iob_s_adr      ),
        .i_iob_s_wdat            ( iob_s_wdat     ),
        .i_iob_s_wen             ( iob_s_wen      ),
        .i_iob_s_ren             ( iob_s_ren      ),
        .o_iob_s_rdat            ( iob_s_rdat     ),
        .i_jtag_halt_req         ( jtag_halt_req_o)
    );
    
    sram32  u_sram32 (
        .clk                     ( clk           ),
        .en                      ( hs_ls4ram_val ),
        .we                      ( sram_wen      ),
        .adr                     ( adr           ),
        .din                     ( wdat          ),
        .dout                    ( sram_rdat     )
    );


    jtag_top #(
        .DMI_ADDR_BITS(6),
        .DMI_DATA_BITS(32),
        .DMI_OP_BITS(2)
    ) u_jtag_top(
        .clk(clk),
        .jtag_rst_n(outside_rst_n),
        .jtag_pin_TCK(jtag_TCK),
        .jtag_pin_TMS(jtag_TMS),
        .jtag_pin_TDI(jtag_TDI),
        .jtag_pin_TDO(jtag_TDO),
        .reg_we_o(),
        .reg_addr_o(),
        .reg_wdata_o(),
        .reg_rdata_i(0),
        .mem_wen_o      (iob_s_wen),
        .mem_addr_o     (iob_s_adr),
        .mem_wdata_o    (iob_s_wdat),
        .mem_rdata_i    (iob_s_rdat),
        .req_valid_o    (hs_iobs4ls_val),
        .halt_req_o     (jtag_halt_req_o),
        .reset_req_o    (jtag_reset_req)
    );

    wire          o0_iob_val;
    wire          o0_iob_rdy;
    wire  [31:0]  o0_iob_rdat;

    wire          o1_iob_val;
    wire          o1_iob_rdy;
    wire  [31:0]  o1_iob_rdat;

    wire  [31:0]  o_iob_adr;
    wire  [ 3:0]  o_iob_wen;
    wire  [31:0]  o_iob_wdat;
    cirno9_iob  u_cirno9_iob (
        .clk                     ( clk       ),
        .rst_n                   ( rst_n     ),

        .iob_val                 ( hs_ls4iob_val ),
        .iob_rdy                 ( hs_iob4ls_rdy ),
        .iob_adr                 ( adr           ),
        .iob_wen                 ( iob_wen       ),
        .iob_wdat                ( wdat          ),
        .iob_rdat                ( iob_rdat      ),

        .o0_iob_val              ( o0_iob_val    ),
        .o0_iob_rdy              ( o0_iob_rdy    ),
        .o0_iob_rdat             ( o0_iob_rdat   ),

        .o1_iob_val              ( o1_iob_val    ),
        .o1_iob_rdy              ( o1_iob_rdy    ),
        .o1_iob_rdat             ( o1_iob_rdat   ),
        
        .o_iob_adr               ( o_iob_adr     ),
        .o_iob_wen               ( o_iob_wen     ),
        .o_iob_wdat              ( o_iob_wdat    )
    );

    uart u_uart (
        .clk                     ( clk       ),
        .rst                     ( rst_n     ),
        .iob_val                 ( o0_iob_val    ),
        .iob_rdy                 ( o0_iob_rdy    ),
        .iob_adr                 ( o_iob_adr     ),
        .iob_wen                 ( o_iob_wen     ),
        .iob_wdat                ( o_iob_wdat    ),
        .iob_rdat                ( o0_iob_rdat   ),
        .rx_pin                    ( rx_i      ),
        .tx_pin                    ( tx_o      )
    );
    //wire  [11:0]  paddr;
    //wire          psel;
    //wire          penable;
    //wire          pwrite;
    //wire  [31:0]  pwdata;
    //wire          pready;
    //wire  [31:0]  prdata;
    //wire          pslverr;
    //o0_apb  u_iob2apb (
    //    .clk                     ( clk       ),
    //    .rst_n                   ( rst_n     ),
    //    .paddr                   ( o0_paddr     ),
    //    .psel                    ( o0_psel      ),
    //    .penable                 ( o0_penable   ),
    //    .pwrite                  ( o0_pwrite    ),
    //    .pwdata                  ( o0_pwdata    ),
    //    .pready                  ( o0_pready    ),
    //    .prdata                  ( o0_prdata    ),
    //    .pslverr                 ( o0_pslverr   ),
    //
    //    .ibval                   ( o0_iob_val    ),
    //    .ibrdy                   ( o0_iob_rdy    ),
    //    .ibadr                   ( o_iob_adr     ),
    //    .ibwen                   ( o_iob_wen     ),
    //    .ibwdat                  ( o_iob_wdat    ),
    //    .ibrdat                  ( o0_iob_rdat   )
    //);

    //apb_uart_sv u_apb_uart_sv (
    //    .CLK                     ( clk       ),
    //    .RSTN                    ( rst_n     ),
    //    .PADDR                   ( PADDR_12  ),
    //    .PWDATA                  ( o0_pwdata    ),
    //    .PWRITE                  ( o0_pwrite    ),
    //    .PSEL                    ( o0_psel      ),
    //    .PENABLE                 ( o0_penable   ),
    //    .PRDATA                  ( o0_prdata    ),
    //    .PREADY                  ( o0_pready    ),
    //    .PSLVERR                 ( o0_pslverr   ),
    //    .rx_i                    ( rx_i      ),
    //    .tx_o                    ( tx_o      ),
    //    .event_o                 ( event_o   )
    //);
endmodule
