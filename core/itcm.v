

module itcm(
    input       [31:0] i_pc,
    output wire [31:0] o_in
);
    rom32 itcmm (i_pc, o_in);
endmodule