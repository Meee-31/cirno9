module rom32(
    input       [32:0] adr,
    output wire [32:0] dout
);
    reg  [32:0] mem_r [0:1023];
    wire [32:0] mem_d;

    
    assign dout = mem_r[adr];
endmodule