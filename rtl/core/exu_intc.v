module exu_intc(
    output        hs_in4ex_rdy,
    input  [ 1:0] i_ecabr,
    input         i_ilg,
    output        o_int_ena,
    output [31:0] o_mcause
);
    assign hs_in4ex_rdy = 1'b1;
    assign o_int_ena = ((| i_ecabr) | i_ilg);
    assign o_mcause[31] = (| i_ecabr) ? 1'b0
                        :               1'b1;
    assign o_mcause[30:0] = i_ecabr[1] ? 31'hb
                          :           31'h0;
endmodule