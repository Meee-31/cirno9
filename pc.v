module pc(
    input       [31:0] i_pc_r,
    input              i_setpc,
    input       [31:0] i_newpc,

    output      [31:0] o_pc_nx
);
    assign o_pc_nx = i_setpc ? i_newpc    :
                               i_pc_r + 4;
endmodule