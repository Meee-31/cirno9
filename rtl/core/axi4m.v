module axi4m #(
    parameter AXI_ADDR_W = 32,
    parameter AXI_DATA_W = 32
)
(
    input                     clk,
    input                     rst_n,

    output [AXI_ADDR_W-1:0]   m_axi_awaddr,  /*Address write channel address*/ 
    output [7:0]              m_axi_awlen,   /*Address write channel burst length*/ 
    output [2:0]              m_axi_awsize,  /*Address write channel burst size. This signal indicates the size of each transfer in the burst*/ 
    output [1:0]              m_axi_awburst, /*Address write channel burst type*/ 
    output                    m_axi_awlock,  /*Address write channel lock type*/ 
    output [3:0]              m_axi_awcache, /*Address write channel memory type. Transactions set with Normal Non-cacheable Modifiable and Bufferable (0011).*/ 
    output [2:0]              m_axi_awprot,  /*Address write channel protection type. Transactions set with Normal, Secure, and Data attributes (000).*/ 
    output [3:0]              m_axi_awqos,   /*Address write channel quality of service*/ 
    output                    m_axi_awvalid, /*Address write channel valid*/ 
    input                     m_axi_awready, /*Address write channel ready*/ 
    /*write*/
    output [AXI_DATA_W-1:0]   m_axi_wdata,   /*Write channel data*/ 
    output [AXI_DATA_W/8-1:0] m_axi_wstrb,   /*Write channel write strobe*/  
    output                    m_axi_wlast,   /*Write channel last word flag*/ 
    output                    m_axi_wvalid,  /*Write channel valid*/ 
    input                     m_axi_wready,  /*Write channel ready*/ 
    /*write response*/ 
    input  [1:0]              m_axi_bresp,   /*Write response channel response*/ 
    input                     m_axi_bvalid,  /*Write response channel valid*/ 
    output                    m_axi_bready,  /*Write response channel ready*/ 
    /*address read*/ 
    output [AXI_ADDR_W-1:0]   m_axi_araddr,  /*Address read channel address*/ 
    output [7:0]              m_axi_arlen,   /*Address read channel burst length*/ 
    output [2:0]              m_axi_arsize,  /*Address read channel burst size. This signal indicates the size of each transfer in the burst*/ 
    output [1:0]              m_axi_arburst, /*Address read channel burst type*/ 
    output                    m_axi_arlock,  /*Address read channel lock type*/ 
    output [3:0]              m_axi_arcache, /*Address read channel memory type. Transactions set with Normal Non-cacheable Modifiable and Bufferable (0011).*/ 
    output [2:0]              m_axi_arprot,  /*Address read channel protection type. Transactions set with Normal, Secure, and Data attributes (000).*/ 
    output [3:0]              m_axi_arqos,   /*Address read channel quality of service*/ 
    output                    m_axi_arvalid, /*Address read channel valid*/ 
    input                     m_axi_arready, /*Address read channel ready*/ 
    /*read*/ 
    input  [AXI_DATA_W-1:0]   m_axi_rdata,   /*Read channel data*/ 
    input  [1:0]              m_axi_rresp,   /*Read channel response*/ 
    input                     m_axi_rlast,   /*Read channel last word*/ 
    input                     m_axi_rvalid,  /*Read channel valid*/ 
    output                    m_axi_rready,  /*Read channel ready*/

    /*native*/
    input                     val,
    output                    rdy,
    input  [31:0]             adr,
    input  [3:0]              wen,
    input  [31:0]             wdat,
    output [31:0]             rdat
    );
    localparam IDLE=2'h0, WRITE=2'h1, READ=2'h2, WRESPONSE=2'h3;

    wire [1:0] state_r;
    wire [1:0] state_nx;

    assign state_nx = (state_r == IDLE)  ? ((| wen) ? WRITE
                                          :           READ )
                    : (state_r == WRITE) ? WRESPONSE
                    :                      IDLE;

    wire aw_hs = m_axi_awvalid & m_axi_awready;
    wire w_hs  = m_axi_wvalid  & m_axi_wready;
    wire b_hs  = m_axi_bvalid  & m_axi_bready;
    wire ar_hs = m_axi_arvalid & m_axi_arready;
    wire r_hs  = m_axi_rvalid  & m_axi_rready;
    wire state_en = ((state_r == IDLE ) & (aw_hs | ar_hs))
                  | ((state_r == WRITE) & w_hs)
                  | ((state_r == READ ) & r_hs)
                  | ((state_r == WRESPONSE) & b_hs);

    dfflr #(2, 2'b0) stated (state_en, state_nx, state_r, clk, rst_n);
    
    assign m_axi_awlen   = 8'b0;
    assign m_axi_awsize  = 3'b010;
    assign m_axi_awburst = 2'b01;
    assign m_axi_awlock  = 1'b0;
    assign m_axi_awcache = 4'b0010;
    assign m_axi_awprot  = 3'b0;
    assign m_axi_awqos   = 4'b0;
    assign m_axi_awaddr  = adr;
    assign m_axi_awvalid = (| wen) & val & (state_r == IDLE);

    assign m_axi_wlast   = 1'b1;
    assign m_axi_wdata   = wdat;
    assign m_axi_wstrb   = wen;
    assign m_axi_wvalid  = (state_r == WRITE);

    assign m_axi_bready  = state_r == WRESPONSE;

    assign m_axi_arlen   = 8'b0;
    assign m_axi_arsize  = 3'b010;
    assign m_axi_arburst = 2'b01;
    assign m_axi_arlock  = 1'b0;
    assign m_axi_arcache = 4'b0010;
    assign m_axi_arprot  = 3'b0;
    assign m_axi_arqos   = 4'b0;
    assign m_axi_araddr  = adr;
    assign m_axi_arvalid = (~(| wen)) & val & (state_r == IDLE);
    
    assign m_axi_rready  = state_r == READ;

    assign rdy = r_hs | b_hs;
    assign rdat = m_axi_rdata;
endmodule
