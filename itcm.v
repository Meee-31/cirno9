module itcm(
    input       [32:0] i_pc,
    output wire [32:0] o_in
);
    rom32 itcmm (i_pc, o_in);
endmodule