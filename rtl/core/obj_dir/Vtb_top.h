// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTB_TOP_H_
#define _VTB_TOP_H_  // guard

#include "verilated_heavy.h"

//==========

class Vtb_top__Syms;

//----------

VL_MODULE(Vtb_top) {
  public:
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_top__DOT__clk;
        CData/*0:0*/ tb_top__DOT__rst_n;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__hs_ram4ls_rdy;
        CData/*3:0*/ tb_top__DOT__cpu0__DOT__sram_wen;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__hs_ls4rd_rdy;
        CData/*2:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__usele;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__deval;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__hs_ex4rd_rdy;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__hs_ls4ex_rdy;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_rd__DOT__ready__DOT__qout_r;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv32_slli;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv32_srli;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv32_srai;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4al_val;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4bj_val;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_bj4ex_rdy;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjex_pc_setpc;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4ag_val;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__opsr;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_bju__DOT__opn_u;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_bju__DOT__justb;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_agu__DOT__lslb;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_agu__DOT__lslh;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_agu__DOT__val__DOT__qout_r;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__out_rdy;
        CData/*3:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__ls_wen;
        CData/*0:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__ls_ren;
        SData/*9:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb;
        SData/*9:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus;
        SData/*9:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus;
        SData/*9:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_lsubus;
        IData/*31:0*/ tb_top__DOT__i;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__adr;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__wdat;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs1;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs2;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rdat;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_pc__DOT__pc_add1;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_rd__DOT__inl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_rd__DOT__pc__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv32_jim;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv_im;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__1__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__2__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__3__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__4__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__5__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__6__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__7__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__8__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__9__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__10__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__11__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__12__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__13__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__14__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__15__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__16__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__17__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__18__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    };
    struct {
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__19__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__20__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__21__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__22__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__23__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__24__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__25__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__26__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__27__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__28__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__29__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__30__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__31__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
        WData/*72:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[3];
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_res;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__exal_opn2;
        WData/*72:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[3];
        WData/*72:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[3];
        WData/*72:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[3];
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_agu__DOT__adr__DOT__qout_r;
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__ls_adr;
        QData/*32:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__slopn;
        QData/*32:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__addsub_res;
        QData/*32:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res;
        QData/*32:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sl_res;
        CData/*7:0*/ tb_top__DOT__sram_mem[16384];
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[32];
        IData/*31:0*/ tb_top__DOT__cpu0__DOT__u_sram32__DOT__mem_r[16384];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__tb_top__DOT__clk;
    CData/*0:0*/ __Vclklast__TOP__tb_top__DOT__rst_n;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtb_top__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtb_top);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtb_top(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtb_top();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtb_top__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtb_top__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtb_top__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtb_top__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtb_top__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtb_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtb_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vtb_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__3(Vtb_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vtb_top__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vtb_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
