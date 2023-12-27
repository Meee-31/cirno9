module ram32(
    input             clk,
    input             en,
    input             we,
    input       [32:0] adr,
    input       [32:0] din,
    output wire [32:0] dout
);
    reg  [32:0] mem_r [0:1023];
    wire [32:0] mem_d;

    genvar i;
    generate 
        for (i = 0; i<1023; i = i + 1) begin :DI
            always @(posedge clk) begin
                if (en & we)
                    if (adr == i) mem_r <= din;
            end
        end
    endgenerate

    assign dout = mem_r[adr];
endmodule