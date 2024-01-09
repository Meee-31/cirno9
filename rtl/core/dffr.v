module dffr # (
  parameter DW = 32,
  parameter RDT = 0
) (
  input      [DW-1:0] dnxt,
  output     [DW-1:0] qout,
  input               clk,
  input               rst_n
);
reg [DW-1:0] qout_r;
always @(posedge clk or negedge rst_n)
begin : DFFR_PROC
  if (rst_n == 1'b0)
    qout_r <= RDT;
  else                  
    qout_r <= #1 dnxt;
end
assign qout = qout_r;
endmodule