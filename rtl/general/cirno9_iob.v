module cirno9_iob(
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
endmodule