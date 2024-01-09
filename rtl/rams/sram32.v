module sram32(
    input         clk,
    input         en,
    input  [ 3:0] we,
    input  [31:0] adr,
    input  [31:0] din,
    output [31:0] dout
);
    reg  [31:0] mem_r [0:16383];
    wire [31:0] mem_d;
    wire [13:0] adr_w = adr[15:2];

    always @(posedge clk) begin
        if (en & we[0]) mem_r[adr_w][ 7: 0] <= din[ 7: 0];
        if (en & we[1]) mem_r[adr_w][15: 8] <= din[15: 8];
        if (en & we[2]) mem_r[adr_w][23:16] <= din[23:16];
        if (en & we[3]) mem_r[adr_w][31:24] <= din[31:24];
    end

    assign dout = mem_r[adr_w];
endmodule