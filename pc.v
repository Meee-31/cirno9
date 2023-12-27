module pc(
    input       [32:0] i_pc_r,
    input              i_setpc,
    input       [32:0] i_newpc,

    output      [32:0] o_pc_nx
);
    assign o_pc_nx = i_setpc ? i_newpc    :
                               i_pc_r + 4;
endmodule