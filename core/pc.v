module pc(
    input       [31:0] i_pc_r,
    input              i_setpc,
    input       [31:0] i_pc,
    input       [31:0] i_pcadd,

    output      [31:0] o_pc_nx
);
    wire [31:0] pc_add1 = i_setpc ? i_pc :
                                    i_pc_r ;
    wire [31:0] pc_add2 = i_setpc ? i_pcadd :
                                    32'd4;
    assign o_pc_nx = pc_add1 + pc_add2;
endmodule
