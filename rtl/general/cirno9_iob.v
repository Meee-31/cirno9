`define O0_BASE_ADR 32'h3000_0000
`define O0_SIZE     12  // 2=  4B   4= 16B   8=256B  12=  4KB
                        //16= 64KB 20=  1MB 24= 16MB 28=256MB
                        //30=  1GB
`define O1_BASE_ADR 32'h1000_0000
`define O1_SIZE     12

module cirno9_iob(
    input         clk,
    input         rst_n,

    input         iob_val,
    output        iob_rdy,
    input  [31:0] iob_adr,
    input  [ 3:0] iob_wen,
    input  [31:0] iob_wdat,
    output [31:0] iob_rdat,

    output        o0_iob_val,
    input         o0_iob_rdy,
    input  [31:0] o0_iob_rdat,

    output        o1_iob_val,
    input         o1_iob_rdy,
    input  [31:0] o1_iob_rdat,

    output [31:0] o_iob_adr,
    output [ 3:0] o_iob_wen,
    output [31:0] o_iob_wdat
);
    wire [31:0] o0_check_adr = `O0_BASE_ADR;
    wire sel_o0 = (iob_adr[31:`O0_SIZE] == o0_check_adr[31:`O0_SIZE]);
    wire sel_o0_r;
    wire [31:0] o1_check_adr = `O1_BASE_ADR;
    wire sel_o1 = (iob_adr[31:`O1_SIZE] == o1_check_adr[31:`O1_SIZE]);
    wire sel_o1_r;

    assign o0_iob_val = sel_o0 & iob_val;
    assign o1_iob_val = sel_o1 & iob_val;

    assign iob_rdy  = (sel_o0_r & o0_iob_rdy)
                    | (sel_o1_r & o1_iob_rdy);
    assign iob_rdat = ({32{sel_o0_r}} & o0_iob_rdat)
                    | ({32{sel_o1_r}} & o1_iob_rdat);

    assign o_iob_adr  = iob_adr;
    assign o_iob_wen  = iob_wen;
    assign o_iob_wdat = iob_wdat;
    dffr #(1, 1'b0) selo0d(sel_o0, sel_o0_r, clk, rst_n);
    dffr #(1, 1'b0) selo1d(sel_o1, sel_o1_r, clk, rst_n);
endmodule