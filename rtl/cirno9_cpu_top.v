`include "./core/cirno9_core.v"
`include "./rams/sram32.v"

module cirno9_cpu_top(
    input rst_n,
    input clk
);
    wire        hs_ls4ram_val;
    wire        sram_ren;
    wire [ 3:0] sram_wen;
    wire [31:0] sram_rdat;
    wire [31:0] adr;
    wire [31:0] wdat;
    cirno9_core  u_cirno9_core (
        .rst_n                   ( rst_n         ),
        .clk                     ( clk           ),
        .o_hs_ls4sram_val        ( hs_ls4ram_val ),
        .o_sram_ren              ( sram_ren      ),
        .o_sram_wen              ( sram_wen      ),
        .i_sram_rdat             ( sram_rdat     ),
        .o_adr                   ( adr           ),
        .o_wdat                  ( wdat          )
    );
    
    sram32  u_sram32 (
        .clk                     ( clk           ),
        .en                      ( hs_ls4ram_val ),
        .we                      ( sram_wen      ),
        .adr                     ( adr           ),
        .din                     ( wdat          ),
        .dout                    ( sram_rdat     )
);
endmodule
