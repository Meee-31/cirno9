`include "dffs.v"

module regfile(

  input       [ 4:0] read_src1_idx,
  input       [ 4:0] read_src2_idx,
  output wire [31:0] read_src1_dat,
  output wire [31:0] read_src2_dat,

  input  wbck_dest_wen,

  input  [ 4:0] wbck_dest_idx,
  input  [31:0] wbck_dest_dat,

  input  clk,
  input  rst_n
  );

  // 寄存器组 & 写使能信号
  wire [31:0] rf_r [31:0];
  wire [31:0] rf_wen;

  //使用dff需要将数据存一拍
  genvar i;
  generate //{
  
      for (i=0; i<32; i=i+1) begin:regfile//{
  
        if(i==0) begin: rf0
            assign rf_wen[i] = 1'b0;
            assign rf_r[i] = 32'b0;
        end
        else begin: rfno0
          assign rf_wen[i] = wbck_dest_wen & (wbck_dest_idx == i) ;
          dffl #(32) rf_dffl (rf_wen[i], wbck_dest_dat, rf_r[i], clk);
        end
  
      end
  endgenerate

  assign read_src1_dat = rf_r[read_src1_idx];
  assign read_src2_dat = rf_r[read_src2_idx];
      
endmodule