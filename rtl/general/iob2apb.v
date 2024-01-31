module iob2apb (
    input         clk,
    input         rst_n,

    output [11:0] paddr,
    output        psel,
    output        penable,
    output        pwrite,
    output [31:0] pwdata,
    input         pready,
    input  [31:0] prdata,
    input         pslverr,

    input         ibval,
    output        ibrdy,
    input  [31:0] ibadr,
    input  [3:0]  ibwen,
    input  [31:0] ibwdat,
    output [31:0] ibrdat
    );
    localparam IDLE=1'h0, SETUP=1'h1;

    wire state_r;
    wire isidle = (state_r == IDLE);
    wire state_nx = (state_r == IDLE) ? SETUP : IDLE;

    wire state_en = ((state_r == IDLE)  & ibval )
                  | ((state_r == SETUP) & pready);
    dfflr #(1, 1'b0) stated (state_en, state_nx,    state_r, clk, rst_n);
    dffl  #(12)      adrd   (isidle,   ibadr[11:0], paddr,   clk);
    dffl  #(1)       wend   (isidle,   (| ibwen),   pwrite,  clk);
    dffl  #(32)      wdatd  (isidle,   ibwdat,      pwdata,  clk);

    assign psel    = (state_r == IDLE) ? ibval : 1'b1;
    assign penable = (state_r == IDLE) ? 1'b0 : 1'b1;
    assign ibrdy   = ((state_r == SETUP) & pready);
    assign ibrdat  = prdata;
endmodule