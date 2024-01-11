module exu_csr(
    input         rst_n,
    input         clk,

    input         csr_wen,
    input         csr_ren,
    input  [11:0] csr_idx,
    input  [31:0] csr_wdat,
    output [31:0] csr_rdat,

    input         mret_ena,
    input         trap_ena,
    input         epc_en,
    input  [31:0] epc_pc,

    output [31:0] cmepc,

    input         ext_ip,
    input         tmr_ip,
    input         sft_ip,

    input         in_retr
);
    wire sel_misa = (csr_idx == 12'h301);
    wire rd_misa = sel_misa & csr_ren;
    wire [31:0] cmisa = {2'b1 //32bit
                      , 4'b0
                      , 1'b0 //z
                      , 1'b0 //y
                      , 1'b0 //x
                      , 1'b0 //w
                      , 1'b0 //v
                      , 1'b0 //u
                      , 1'b0 //t
                      , 1'b0 //s
                      , 1'b0 //r
                      , 1'b0 //q
                      , 1'b0 //p
                      , 1'b0 //o
                      , 1'b0 //n
                      , 1'b0 //m
                      , 1'b0 //l
                      , 1'b0 //k
                      , 1'b0 //j
                      , 1'b1 //i
                      , 1'b0 //h
                      , 1'b0 //g
                      , 1'b0 //f
                      , 1'b0 //e
                      , 1'b0 //d
                      , 1'b0 //c
                      , 1'b0 //b
                      , 1'b0 //a
                      };
    
    wire rd_mvendorid = csr_ren & (csr_idx == 12'hF11);
    wire [31:0] cmvendorid = 32'b0;
    wire rd_marchid   = csr_ren & (csr_idx == 12'hF12);
    wire [31:0] cmarchid   = 32'b0;
    wire rd_mimpid    = csr_ren & (csr_idx == 12'hF13);
    wire [31:0] cmimpid    = 32'hc109;
    wire rd_mhartid   = csr_ren & (csr_idx == 12'hF14);
    wire [31:0] cmhartid   = 32'b0;
    wire rd_mconfigptr = csr_ren & (csr_idx == 12'hF15);
    wire [31:0] cmconfigptr = 32'b0;

    wire sel_mstatus = (csr_idx == 12'h300);
    wire rd_mstatus = sel_mstatus & csr_ren; 
    wire wr_mstatus = sel_mstatus & csr_wen;
    wire [1:0] status_fs_r = 2'b0;
    wire [1:0] status_xs_r = 2'b0;
    wire status_sd_r = (status_fs_r == 2'b11) 
                     | (status_xs_r == 2'b11);
    wire status_tsr_r  = 1'b0;
    wire status_tw_r   = 1'b0;
    wire status_tvm_r  = 1'b0;
    wire status_mxr_r  = 1'b0;
    wire status_sum_r  = 1'b0;
    wire status_mprv_r = 1'b0;
    wire [1:0] status_mpp_r  = 2'b11;
    wire [1:0] status_vs_r   = 2'b00;
    wire status_spp_r  = 1'b0;
    wire status_mpie_r;
    wire status_ube_r  = 1'b0;
    wire status_spie_r = 1'b0;
    wire status_mie_r;
    wire status_sie_r  = 1'b0;
    wire [31:0] status_r;
    assign status_r[31]    = status_sd_r  ;
    assign status_r[30:23] = 8'b0         ;
    assign status_r[22]    = status_tsr_r ;
    assign status_r[21]    = status_tw_r  ;
    assign status_r[20]    = status_tvm_r ;
    assign status_r[19]    = status_mxr_r ;
    assign status_r[18]    = status_sum_r ;
    assign status_r[17]    = status_mprv_r;
    assign status_r[16:15] = status_xs_r  ;
    assign status_r[14:13] = status_fs_r  ;
    assign status_r[12:11] = status_mpp_r ;
    assign status_r[10:9]  = status_vs_r  ;
    assign status_r[8]     = status_spp_r ;
    assign status_r[7]     = status_mpie_r;
    assign status_r[6]     = status_ube_r ;
    assign status_r[5]     = status_spie_r;
    assign status_r[4]     = 1'b0         ;
    assign status_r[3]     = status_mie_r ;
    assign status_r[2]     = 1'b0         ;
    assign status_r[1]     = status_sie_r ;
    assign status_r[0]     = 1'b0         ;
    wire [31:0] status_nxt = csr_wdat;
    wire status_sd_nxt   = status_nxt[31]; 
    wire status_tsr_nxt  = status_nxt[22];    
    wire status_tw_nxt   = status_nxt[21];    
    wire status_tvm_nxt  = status_nxt[20];    
    wire status_mxr_nxt  = status_nxt[19];    
    wire status_sum_nxt  = status_nxt[18];    
    wire status_mprv_nxt = status_nxt[17];    
    wire [1:0] status_xs_nxt   = status_nxt[16:15]; 
    wire [1:0] status_fs_nxt   = status_nxt[14:13];
    wire [1:0] status_mpp_nxt  = status_nxt[12:11]; 
    wire [1:0] status_vs_nxt   = status_nxt[10:9];
    wire status_spp_nxt  = status_nxt[8];  
    wire status_mpie_nxt = trap_ena   ? status_mie_r
                         : mret_ena   ? 1'b1
                         : wr_mstatus ? status_nxt[7]
                         :              status_mpie_r;
    wire status_ube_nxt  = status_nxt[6];  
    wire status_spie_nxt = status_nxt[5];
    wire status_mie_nxt  = trap_ena   ? 1'b0
                         : mret_ena   ? status_mpie_r
                         : wr_mstatus ? status_nxt[3]
                         :              status_mie_r;
    wire status_sie_nxt  = status_nxt[1];
    dffr #(1, 1'b0) status_miped (status_mpie_nxt, status_mpie_r, clk, rst_n);
    dffr #(1, 1'b0) status_mied (status_mie_nxt,  status_mie_r,  clk, rst_n);
    wire [31:0] cmstatus = status_r;

    wire sel_mtvec = (csr_idx == 12'h305);
    wire rd_mtvec  = csr_ren & sel_mtvec;
    wire wr_mtvec  = sel_mtvec & csr_wen;
    wire [31:0] mtvec_r;
    wire [31:0] mtvec_nxt = csr_wdat;
    dfflr #(32, 32'b0) mtvecd (wr_mtvec, mtvec_nxt, mtvec_r, clk, rst_n);
    wire [31:0] cmtvec = mtvec_r;

    wire sel_mip = (csr_idx == 12'h344);
    wire rd_mip = sel_mip & csr_ren;
    wire wr_mip = sel_mip & csr_wen;
    wire [31:0] mip_r;
    wire [31:0] mip_nxt;
    wire meip_r;
    wire msip_r;
    wire mtip_r;
    dffr #(1, 1'b0) meipd (ext_ip, meip_r, clk, rst_n);
    dffr #(1, 1'b0) mtipd (tmr_ip, mtip_r, clk, rst_n);
    dffr #(1, 1'b0) msipd (sft_ip, msip_r, clk, rst_n);
    assign mip_r[31:12] = 20'b0;
    assign mip_r[11] = meip_r;
    assign mip_r[10:8] = 3'b0;
    assign mip_r[ 7] = mtip_r;
    assign mip_r[6:4] = 3'b0;
    assign mip_r[ 3] = msip_r;
    assign mip_r[2:0] = 3'b0;
    wire [31:0] cmip = mip_r;

    wire sel_mie = (csr_idx == 12'h304);
    wire rd_mie = sel_mie & csr_ren;
    wire wr_mie = sel_mie & csr_wen;
    wire meie_r;
    wire msie_r;
    wire mtie_r;
    wire meie_nxt = csr_wdat[11];
    wire msie_nxt = csr_wdat[7];
    wire mtie_nxt = csr_wdat[3];
    dfflr #(1,1'b0) meied (wr_mie, meie_nxt, meie_r, clk, rst_n);
    dfflr #(1,1'b0) mtied (wr_mie, mtie_nxt, mtie_r, clk, rst_n);
    dfflr #(1,1'b0) msied (wr_mie, msie_nxt, msie_r, clk, rst_n);
    wire [31:0] mie_r;
    assign mie_r[31:12] = 20'b0;
    assign mie_r[11] = meie_r;
    assign mie_r[10:8] = 3'b0;
    assign mie_r[ 7] = mtie_r;
    assign mie_r[6:4] = 3'b0;
    assign mie_r[ 3] = msie_r;
    assign mie_r[2:0] = 3'b0;
    wire [31:0] cmie = mie_r;
    
    wire sel_mcyclel   = (csr_idx == 12'hB00);
    wire sel_mcycleh   = (csr_idx == 12'hB80);
    wire sel_minstretl = (csr_idx == 12'hB02);
    wire sel_minstreth = (csr_idx == 12'hB82);
    wire rd_mcyclel    = csr_ren & sel_mcyclel  ;
    wire rd_mcycleh    = csr_ren & sel_mcycleh  ;
    wire rd_minstretl  = csr_ren & sel_minstretl;
    wire rd_minstreth  = csr_ren & sel_minstreth;
    wire wr_mcyclel    = csr_wen & sel_mcyclel  ;
    wire wr_mcycleh    = csr_wen & sel_mcycleh  ;
    wire wr_minstretl  = csr_wen & sel_minstretl;
    wire wr_minstreth  = csr_wen & sel_minstreth;
    wire [31:0] mcyclel_r  ;
    wire [31:0] mcycleh_r  ;
    wire [31:0] minstretl_r;
    wire [31:0] minstreth_r;
    wire mcycleh_gon = (mcyclel_r == 32'b1);
    wire minstretl_gon = in_retr;
    wire minstreth_gon = in_retr & (minstretl_r == 32'b1);
    wire [31:0] mcyclel_nxt   = wr_mcyclel ? csr_wdat
                              :              (mcyclel_r + 1'b1);
    wire [31:0] mcycleh_nxt   = wr_mcycleh  ? csr_wdat
                              : mcycleh_gon ? (mcycleh_r + 1'b1)
                              :               minstreth_r;
    wire [31:0] minstretl_nxt = wr_minstretl  ? csr_wdat
                              : minstretl_gon ? (minstretl_r + 1'b1)
                              :                 minstretl_r;
    wire [31:0] minstreth_nxt = wr_minstreth  ? csr_wdat
                              : minstreth_gon ? (minstreth_r + 1'b1)
                              :                 minstreth_r;
    dffr #(32, 32'b0) mcycleld   (mcyclel_nxt,   mcyclel_r,   clk, rst_n);
    dffr #(32, 32'b0) mcyclehd   (mcycleh_nxt,   mcycleh_r,   clk, rst_n);
    dffr #(32, 32'b0) minstretld (minstretl_nxt, minstretl_r, clk, rst_n);
    dffr #(32, 32'b0) minstrethd (minstreth_nxt, minstreth_r, clk, rst_n);
    wire [31:0] cmcyclel   = mcyclel_r  ;
    wire [31:0] cmcycleh   = mcycleh_r  ;
    wire [31:0] cminstretl = minstretl_r;
    wire [31:0] cminstreth = minstreth_r;

    wire sel_mscratch = (csr_idx == 12'h340);
    wire rd_mscratch  = csr_ren & sel_mscratch;
    wire wr_mscratch  = sel_mscratch & csr_wen;
    wire [31:0] mscratch_r;
    wire [31:0] mscratch_nxt = csr_wdat;
    dfflr #(32, 32'b0) mscratchd (wr_mscratch, mscratch_nxt, mscratch_r, clk, rst_n);
    wire [31:0] cmscratch = mscratch_r;

    wire sel_mepc = (csr_idx == 12'h341);
    wire rd_mepc  = csr_ren & sel_mepc;
    wire wr_mepc  = sel_mepc & csr_wen;
    wire [30:0] mepc_r;
    wire [30:0] mepc_nxt = wr_mepc  ? csr_wdat[31:1]
                         : epc_en   ? epc_pc[31:1]
                         :            mepc_r;
    dffr #(31, 31'b0) mepcd (mepc_nxt, mepc_r, clk, rst_n);
    assign cmepc = {mepc_r,1'b0};

    wire sel_mcause = (csr_idx == 12'h342);
    wire rd_mcause = sel_mcause & csr_ren;
    wire [31:0] cmcause = 32'b0;

    wire sel_mtval = (csr_idx == 12'h343);
    wire rd_mtval = sel_mtval & csr_ren;
    wire [31:0] cmtval = 32'b0;

    assign csr_rdat = 32'b0 
                    | ({32{rd_mstatus  }} & cmstatus  )
                    | ({32{rd_mie      }} & cmie      )
                    | ({32{rd_mtvec    }} & cmtvec    )
                    | ({32{rd_mepc     }} & cmepc     )
                    | ({32{rd_mscratch }} & cmscratch )
                    | ({32{rd_mcause   }} & cmcause   )
                    | ({32{rd_mtval    }} & cmtval    )
                    | ({32{rd_mip      }} & cmip      )
                    | ({32{rd_misa     }} & cmisa     )
                    | ({32{rd_mvendorid}} & cmvendorid)
                    | ({32{rd_marchid  }} & cmarchid  )
                    | ({32{rd_mimpid   }} & cmimpid   )
                    | ({32{rd_mhartid  }} & cmhartid  )
                    | ({32{rd_mcyclel  }} & cmcyclel  )
                    | ({32{rd_mcycleh  }} & cmcycleh  )
                    | ({32{rd_minstretl}} & cminstretl)
                    | ({32{rd_minstreth}} & cminstreth);
endmodule