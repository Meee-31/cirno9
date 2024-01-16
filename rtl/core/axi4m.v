module axi4m #(
    parameter AXI_ADDR_W = 32,
    parameter AXI_DATA_W = 32
)
(
    output                    axi_awid,    /*Address write channel ID*/ \
    output [AXI_ADDR_W-1:0]   axi_awaddr,  /*Address write channel address*/ \
    output [1:0]   axi_awlen,   /*Address write channel burst length*/ \
    output [`AXI_SIZE_W-1:0]  axi_awsize,  /*Address write channel burst size. This signal indicates the size of each transfer in the burst*/ \
    output [`AXI_BURST_W-1:0] axi_awburst, /*Address write channel burst type*/ \
    output [`AXI_LOCK_W-1:0]  axi_awlock,  /*Address write channel lock type*/ \
    output [`AXI_CACHE_W-1:0] axi_awcache, /*Address write channel memory type. Transactions set with Normal Non-cacheable Modifiable and Bufferable (0011).*/ \
    output [`AXI_PROT_W-1:0]  axi_awprot,  /*Address write channel protection type. Transactions set with Normal, Secure, and Data attributes (000).*/ \
    output [`AXI_QOS_W-1:0]   axi_awqos,   /*Address write channel quality of service*/ \
    output                    axi_awvalid, /*Address write channel valid*/ \
    input                     axi_awready, /*Address write channel ready*/ \
    /*write*/ \
    output [`AXI_ID_W-1:0]    axi_wid,     /*Write channel ID*/ \
    output [AXI_DATA_W-1:0]   axi_wdata,   /*Write channel data*/ \
    output [AXI_DATA_W/8-1:0] axi_wstrb,   /*Write channel write strobe*/ \
    output                    axi_wlast,   /*Write channel last word flag*/ \
    output                    axi_wvalid,  /*Write channel valid*/ \
    input                     axi_wready,  /*Write channel ready*/ \
    /*write response*/ \
    input [`AXI_ID_W-1:0]     axi_bid,     /*Write response channel ID*/ \
    input [`AXI_RESP_W-1:0]   axi_bresp,   /*Write response channel response*/ \
    input                     axi_bvalid,  /*Write response channel valid*/ \
    output                    axi_bready,  /*Write response channel ready*/ \
    /*address read*/ \
    output [`AXI_ID_W-1:0]    axi_arid,    /*Address read channel ID*/ \
    output [AXI_ADDR_W-1:0]   axi_araddr,  /*Address read channel address*/ \
    output [`AXI_LEN_W-1:0]   axi_arlen,   /*Address read channel burst length*/ \
    output [`AXI_SIZE_W-1:0]  axi_arsize,  /*Address read channel burst size. This signal indicates the size of each transfer in the burst*/ \
    output [`AXI_BURST_W-1:0] axi_arburst, /*Address read channel burst type*/ \
    output [`AXI_LOCK_W-1:0]  axi_arlock,  /*Address read channel lock type*/ \
    output [`AXI_CACHE_W-1:0] axi_arcache, /*Address read channel memory type. Transactions set with Normal Non-cacheable Modifiable and Bufferable (0011).*/ \
    output [`AXI_PROT_W-1:0]  axi_arprot,  /*Address read channel protection type. Transactions set with Normal, Secure, and Data attributes (000).*/ \
    output [`AXI_QOS_W-1:0]   axi_arqos,   /*Address read channel quality of service*/ \
    output                    axi_arvalid, /*Address read channel valid*/ \
    input                     axi_arready, /*Address read channel ready*/ \
    /*read*/ \
    input [`AXI_ID_W-1:0]     axi_rid,     /*Read channel ID*/ \
    input [AXI_DATA_W-1:0]    axi_rdata,   /*Read channel data*/ \
    input [`AXI_RESP_W-1:0]   axi_rresp,   /*Read channel response*/ \
    input                     axi_rlast,   /*Read channel last word*/ \
    input                     axi_rvalid,  /*Read channel valid*/ \
    output                    axi_rready   /*Read channel ready*/
);