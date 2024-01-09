// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_top.h for the primary calling header

#include "Vtb_top.h"
#include "Vtb_top__Syms.h"

//==========

VL_CTOR_IMP(Vtb_top) {
    Vtb_top__Syms* __restrict vlSymsp = __VlSymsp = new Vtb_top__Syms(this, name());
    Vtb_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtb_top::__Vconfigure(Vtb_top__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vtb_top::~Vtb_top() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vtb_top::_initial__TOP__1(Vtb_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top::_initial__TOP__1\n"); );
    Vtb_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*95:0*/ __Vtemp1[3];
    // Body
    VL_WRITEF("Time Out !!!\n");
    VL_FINISH_MT("tb_top.v", 32, "");
    __Vtemp1[0U] = 0x2e766364U;
    __Vtemp1[1U] = 0x5f746f70U;
    __Vtemp1[2U] = 0x7462U;
    vl_dumpctl_filenamep(true, VL_CVT_PACK_STR_NW(3, __Vtemp1));
    VL_PRINTF_MT("-Info: tb_top.v:61: $dumpvar ignored, as Verilated without --trace\n");
    VL_READMEM_N(true, 8, 16384, 0, std::string(".verilog")
                 , vlTOPp->tb_top__DOT__sram_mem, 0
                 , ~0ULL);
    vlTOPp->tb_top__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x3fffU, vlTOPp->tb_top__DOT__i)) {
        vlTOPp->tb_top__DOT__cpu0__DOT__u_sram32__DOT__mem_r[(0x3fffU 
                                                              & vlTOPp->tb_top__DOT__i)] 
            = ((0xffffff00U & vlTOPp->tb_top__DOT__cpu0__DOT__u_sram32__DOT__mem_r
                [(0x3fffU & vlTOPp->tb_top__DOT__i)]) 
               | vlTOPp->tb_top__DOT__sram_mem[(0x3fffU 
                                                & VL_MULS_III(14,32,32, (IData)(4U), vlTOPp->tb_top__DOT__i))]);
        vlTOPp->tb_top__DOT__cpu0__DOT__u_sram32__DOT__mem_r[(0x3fffU 
                                                              & vlTOPp->tb_top__DOT__i)] 
            = ((0xffff00ffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_sram32__DOT__mem_r
                [(0x3fffU & vlTOPp->tb_top__DOT__i)]) 
               | (vlTOPp->tb_top__DOT__sram_mem[(0x3fffU 
                                                 & ((IData)(1U) 
                                                    + 
                                                    VL_MULS_III(14,32,32, (IData)(4U), vlTOPp->tb_top__DOT__i)))] 
                  << 8U));
        vlTOPp->tb_top__DOT__cpu0__DOT__u_sram32__DOT__mem_r[(0x3fffU 
                                                              & vlTOPp->tb_top__DOT__i)] 
            = ((0xff00ffffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_sram32__DOT__mem_r
                [(0x3fffU & vlTOPp->tb_top__DOT__i)]) 
               | (vlTOPp->tb_top__DOT__sram_mem[(0x3fffU 
                                                 & ((IData)(2U) 
                                                    + 
                                                    VL_MULS_III(14,32,32, (IData)(4U), vlTOPp->tb_top__DOT__i)))] 
                  << 0x10U));
        vlTOPp->tb_top__DOT__cpu0__DOT__u_sram32__DOT__mem_r[(0x3fffU 
                                                              & vlTOPp->tb_top__DOT__i)] 
            = ((0xffffffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_sram32__DOT__mem_r
                [(0x3fffU & vlTOPp->tb_top__DOT__i)]) 
               | (vlTOPp->tb_top__DOT__sram_mem[(0x3fffU 
                                                 & ((IData)(3U) 
                                                    + 
                                                    VL_MULS_III(14,32,32, (IData)(4U), vlTOPp->tb_top__DOT__i)))] 
                  << 0x18U));
        vlTOPp->tb_top__DOT__i = ((IData)(1U) + vlTOPp->tb_top__DOT__i);
    }
    VL_WRITEF("RAM 0x00: %x\n",32,vlTOPp->tb_top__DOT__cpu0__DOT__u_sram32__DOT__mem_r
              [0U]);
    VL_WRITEF("RAM 0x01: %x\n",32,vlTOPp->tb_top__DOT__cpu0__DOT__u_sram32__DOT__mem_r
              [1U]);
    VL_WRITEF("RAM 0x02: %x\n",32,vlTOPp->tb_top__DOT__cpu0__DOT__u_sram32__DOT__mem_r
              [2U]);
    VL_WRITEF("RAM 0x03: %x\n",32,vlTOPp->tb_top__DOT__cpu0__DOT__u_sram32__DOT__mem_r
              [3U]);
    VL_WRITEF("RAM 0x10: %x\n",32,vlTOPp->tb_top__DOT__cpu0__DOT__u_sram32__DOT__mem_r
              [0xaU]);
}

void Vtb_top::_settle__TOP__2(Vtb_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top::_settle__TOP__2\n"); );
    Vtb_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[2U] 
        = (0x1fbU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[2U]);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[2U] 
        = (0x1f7U & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[2U]);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[2U] 
        = (0x1efU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[2U]);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[2U] 
        = (0x1dfU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[2U]);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[2U] 
        = (0x1bfU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[2U]);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[2U] 
        = (0x1f7U & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[2U]);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[2U] 
        = (0x1efU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[2U]);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[2U] 
        = (0x1dfU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[2U]);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[2U] 
        = (0x1bfU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[2U]);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[2U] 
        = (0x17fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[2U]);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[2U] 
        = (0xffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[2U]);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0U] = 0U;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = (0xfffffffeU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[1U] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__1__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[2U] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__2__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[3U] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__3__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[4U] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__4__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[5U] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__5__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[6U] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__6__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[7U] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__7__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[8U] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__8__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[9U] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__9__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0xaU] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__10__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0xbU] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__11__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0xcU] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__12__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0xdU] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__13__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0xeU] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__14__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0xfU] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__15__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0x10U] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__16__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0x11U] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__17__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0x12U] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__18__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0x13U] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__19__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0x14U] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__20__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0x15U] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__21__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0x16U] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__22__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0x17U] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__23__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0x18U] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__24__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0x19U] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__25__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0x1aU] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__26__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0x1bU] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__27__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0x1cU] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__28__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0x1dU] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__29__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0x1eU] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__30__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[0x1fU] 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__31__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r;
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__ls_adr 
        = ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_agu__DOT__val__DOT__qout_r)
            ? vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_agu__DOT__adr__DOT__qout_r
            : vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_rd__DOT__pc__DOT__qout_r);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__out_rdy 
        = ((0x8000U == (0xffffU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__ls_adr 
                                   >> 0x10U))) & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__hs_ram4ls_rdy));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__hs_ls4rd_rdy 
        = (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__out_rdy) 
            & (~ (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_agu__DOT__val__DOT__qout_r))) 
           & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_rd__DOT__ready__DOT__qout_r));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__hs_ls4ex_rdy 
        = ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__out_rdy) 
           & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_agu__DOT__val__DOT__qout_r));
    vlTOPp->tb_top__DOT__cpu0__DOT__adr = ((- (IData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__out_rdy))) 
                                           & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__ls_adr);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rdat 
        = ((0x8000U == (0xffffU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__ls_adr 
                                   >> 0x10U))) ? vlTOPp->tb_top__DOT__cpu0__DOT__u_sram32__DOT__mem_r
           [(0x3fffU & (vlTOPp->tb_top__DOT__cpu0__DOT__adr 
                        >> 2U))] : 0U);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
        = ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_rd__DOT__ready__DOT__qout_r)
            ? vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rdat
            : vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_rd__DOT__inl__DOT__qout_r);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen 
        = (((((((0x33U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
                | (0x13U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin))) 
               | (3U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin))) 
              | (0x6fU == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin))) 
             | (0x63U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin))) 
            | (0x37U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin))) 
           | (0x17U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs1 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r
        [(0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                   >> 0xfU))];
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs2 
        = vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r
        [(0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                   >> 0x14U))];
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv32_jim 
        = ((0xffe00000U & ((- (IData)((1U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                             >> 0x1fU)))) 
                           << 0x15U)) | ((0x100000U 
                                          & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                             >> 0xbU)) 
                                         | ((0xff000U 
                                             & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin) 
                                            | ((0x800U 
                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                   >> 9U)) 
                                               | (0x7feU 
                                                  & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                     >> 0x14U))))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_lsubus 
        = ((0x3feU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_lsubus)) 
           | ((3U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
              & (0U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                              >> 0xcU)))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_lsubus 
        = ((0x3fdU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_lsubus)) 
           | (((3U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
               & (1U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                               >> 0xcU)))) << 1U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_lsubus 
        = ((0x3fbU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_lsubus)) 
           | (((3U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
               & (2U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                               >> 0xcU)))) << 2U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_lsubus 
        = ((0x3f7U & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_lsubus)) 
           | (((3U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
               & (4U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                               >> 0xcU)))) << 3U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_lsubus 
        = ((0x3efU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_lsubus)) 
           | (((3U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
               & (5U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                               >> 0xcU)))) << 4U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_lsubus 
        = ((0x3dfU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_lsubus)) 
           | (((0x23U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
               & (0U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                               >> 0xcU)))) << 5U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_lsubus 
        = ((0x3bfU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_lsubus)) 
           | (((0x23U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
               & (1U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                               >> 0xcU)))) << 6U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_lsubus 
        = ((0x37fU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_lsubus)) 
           | (((0x23U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
               & (2U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                               >> 0xcU)))) << 7U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus 
        = ((0x3feU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus)) 
           | ((0x63U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
              & (0U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                              >> 0xcU)))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus 
        = ((0x3fdU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus)) 
           | (((0x63U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
               & (1U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                               >> 0xcU)))) << 1U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus 
        = ((0x3fbU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus)) 
           | (((0x63U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
               & (4U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                               >> 0xcU)))) << 2U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus 
        = ((0x3f7U & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus)) 
           | (((0x63U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
               & (5U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                               >> 0xcU)))) << 3U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus 
        = ((0x3efU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus)) 
           | (((0x63U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
               & (6U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                               >> 0xcU)))) << 4U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus 
        = ((0x3dfU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus)) 
           | (((0x63U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
               & (7U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                               >> 0xcU)))) << 5U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus 
        = ((0x3bfU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus)) 
           | ((0x6fU == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
              << 6U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus 
        = ((0x37fU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus)) 
           | (((0x63U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
               & (0U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                               >> 0xcU)))) << 7U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus 
        = ((0x2ffU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus)) 
           | ((0x17U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
              << 8U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus 
        = ((0x3feU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus)) 
           | (((((0x33U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
                 & (0U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                 >> 0xcU)))) & (0U 
                                                == 
                                                (0x7fU 
                                                 & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                    >> 0x19U)))) 
               | ((0x13U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
                  & (0U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                  >> 0xcU))))) | (0x37U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus 
        = ((0x3fdU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus)) 
           | ((((0x33U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
                & (0U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                >> 0xcU)))) & (0x20U 
                                               == (0x7fU 
                                                   & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                      >> 0x19U)))) 
              << 1U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus 
        = ((0x3f7U & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus)) 
           | (((((0x33U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
                 & (2U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                 >> 0xcU)))) & (0U 
                                                == 
                                                (0x7fU 
                                                 & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                    >> 0x19U)))) 
               | ((0x13U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
                  & (2U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                  >> 0xcU))))) << 3U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus 
        = ((0x3efU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus)) 
           | (((((0x33U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
                 & (3U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                 >> 0xcU)))) & (0U 
                                                == 
                                                (0x7fU 
                                                 & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                    >> 0x19U)))) 
               | ((0x13U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
                  & (3U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                  >> 0xcU))))) << 4U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus 
        = ((0x3dfU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus)) 
           | (((((0x33U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
                 & (4U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                 >> 0xcU)))) & (0U 
                                                == 
                                                (0x7fU 
                                                 & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                    >> 0x19U)))) 
               | ((0x13U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
                  & (4U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                  >> 0xcU))))) << 5U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus 
        = ((0x2ffU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus)) 
           | (((((0x33U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
                 & (6U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                 >> 0xcU)))) & (0U 
                                                == 
                                                (0x7fU 
                                                 & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                    >> 0x19U)))) 
               | ((0x13U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
                  & (6U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                  >> 0xcU))))) << 8U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus 
        = ((0x1ffU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus)) 
           | (((((0x33U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
                 & (7U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                 >> 0xcU)))) & (0U 
                                                == 
                                                (0x7fU 
                                                 & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                    >> 0x19U)))) 
               | ((0x13U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
                  & (7U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                  >> 0xcU))))) << 9U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__usele 
        = ((6U & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__usele)) 
           | (((0x33U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
               | (0x13U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin))) 
              | (0x37U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__usele 
        = ((1U & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__usele)) 
           | (((((0x63U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
                 | (0x6fU == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin))) 
                | (0x63U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin))) 
               << 2U) | (((3U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
                          | (0x23U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin))) 
                         << 1U)));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv32_slli 
        = (((0x13U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
            & (1U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                            >> 0xcU)))) & (0U == (0x3fU 
                                                  & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                     >> 0x1aU))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv32_srli 
        = (((0x13U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
            & (5U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                            >> 0xcU)))) & (0U == (0x3fU 
                                                  & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                     >> 0x1aU))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv32_srai 
        = (((0x13U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
            & (5U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                            >> 0xcU)))) & (0x10U == 
                                           (0x3fU & 
                                            (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                             >> 0x1aU))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xfffffffdU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (1U == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                  >> 7U)))) << 1U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xfffffffbU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (2U == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                  >> 7U)))) << 2U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xfffffff7U & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (3U == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                  >> 7U)))) << 3U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xffffffefU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (4U == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                  >> 7U)))) << 4U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xffffffdfU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (5U == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                  >> 7U)))) << 5U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xffffffbfU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (6U == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                  >> 7U)))) << 6U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xffffff7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (7U == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                  >> 7U)))) << 7U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xfffffeffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (8U == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                  >> 7U)))) << 8U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xfffffdffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (9U == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                  >> 7U)))) << 9U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xfffffbffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0xaU == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                    >> 7U)))) << 0xaU));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xfffff7ffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0xbU == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                    >> 7U)))) << 0xbU));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xffffefffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0xcU == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                    >> 7U)))) << 0xcU));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xffffdfffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0xdU == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                    >> 7U)))) << 0xdU));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xffffbfffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0xeU == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                    >> 7U)))) << 0xeU));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xffff7fffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0xfU == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                    >> 7U)))) << 0xfU));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xfffeffffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0x10U == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                     >> 7U)))) << 0x10U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xfffdffffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0x11U == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                     >> 7U)))) << 0x11U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xfffbffffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0x12U == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                     >> 7U)))) << 0x12U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xfff7ffffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0x13U == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                     >> 7U)))) << 0x13U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xffefffffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0x14U == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                     >> 7U)))) << 0x14U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xffdfffffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0x15U == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                     >> 7U)))) << 0x15U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xffbfffffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0x16U == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                     >> 7U)))) << 0x16U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xff7fffffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0x17U == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                     >> 7U)))) << 0x17U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xfeffffffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0x18U == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                     >> 7U)))) << 0x18U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xfdffffffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0x19U == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                     >> 7U)))) << 0x19U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xfbffffffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0x1aU == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                     >> 7U)))) << 0x1aU));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xf7ffffffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0x1bU == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                     >> 7U)))) << 0x1bU));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xefffffffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0x1cU == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                     >> 7U)))) << 0x1cU));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xdfffffffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0x1dU == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                     >> 7U)))) << 0x1dU));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0xbfffffffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0x1eU == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                     >> 7U)))) << 0x1eU));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen 
        = ((0x7fffffffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen) 
           | (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen) 
               & (0x1fU == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                     >> 7U)))) << 0x1fU));
    vlTOPp->tb_top__DOT__cpu0__DOT__wdat = ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__hs_ls4rd_rdy)
                                             ? 0U : 
                                            ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__hs_ls4ex_rdy)
                                              ? vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs2
                                              : 0U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv_im 
        = ((((((((- (IData)((0x13U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)))) 
                 & ((0xfffff000U & ((- (IData)((1U 
                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                   >> 0x1fU)))) 
                                    << 0xcU)) | (0xfffU 
                                                 & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                    >> 0x14U)))) 
                | ((- (IData)((0x23U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)))) 
                   & ((0xfffff000U & ((- (IData)((1U 
                                                  & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                     >> 0x1fU)))) 
                                      << 0xcU)) | (
                                                   (0xfe0U 
                                                    & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                         >> 7U)))))) 
               | ((- (IData)((0x63U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)))) 
                  & ((0xffffe000U & ((- (IData)((1U 
                                                 & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                    >> 0x1fU)))) 
                                     << 0xdU)) | ((0x1000U 
                                                   & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                      >> 0x13U)) 
                                                  | ((0x800U 
                                                      & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                         << 4U)) 
                                                     | ((0x7e0U 
                                                         & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                            >> 0x14U)) 
                                                        | (0x1eU 
                                                           & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                              >> 7U)))))))) 
              | (0xfffff000U & ((- (IData)((0x37U == 
                                            (0x7fU 
                                             & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)))) 
                                & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin))) 
             | (0xfffff000U & ((- (IData)((0x17U == 
                                           (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)))) 
                               & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin))) 
            | ((- (IData)((0x6fU == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)))) 
               & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv32_jim)) 
           | ((- (IData)((0x63U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)))) 
              & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv32_jim));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__deval 
        = ((~ ((((((0x13U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
                   | (0x33U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin))) 
                  | (0x13U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin))) 
                 | (0x37U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin))) 
                | (0x17U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin))) 
               & (0U == (0x1fU & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                  >> 7U))))) & (0U 
                                                != (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__usele)));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus 
        = ((0x3fbU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus)) 
           | (((((0x33U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
                 & (1U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                 >> 0xcU)))) & (0U 
                                                == 
                                                (0x7fU 
                                                 & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                    >> 0x19U)))) 
               | (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv32_slli)) 
              << 2U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus 
        = ((0x3bfU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus)) 
           | (((((0x33U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
                 & (5U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                 >> 0xcU)))) & (0U 
                                                == 
                                                (0x7fU 
                                                 & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                    >> 0x19U)))) 
               | (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv32_srli)) 
              << 6U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus 
        = ((0x37fU & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus)) 
           | (((((0x33U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
                 & (5U == (7U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                 >> 0xcU)))) & (0x20U 
                                                == 
                                                (0x7fU 
                                                 & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin 
                                                    >> 0x19U)))) 
               | (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv32_srai)) 
              << 7U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__exal_opn2 
        = ((((0x33U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)) 
             | (0x23U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin))) 
            | (0x63U == (0x7fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin)))
            ? vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs2
            : vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv_im);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__hs_ex4rd_rdy 
        = (1U & ((((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__usele) 
                   | ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_bj4ex_rdy) 
                      & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__usele) 
                         >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__hs_ls4ex_rdy) 
                                     & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__usele) 
                                        >> 1U))) | 
                 (~ (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__deval))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4ag_val 
        = (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__usele) 
            >> 1U) & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__deval));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4bj_val 
        = (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__usele) 
            >> 2U) & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__deval));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4al_val 
        = ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__usele) 
           & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__deval));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb 
        = (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus) 
            | (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus)) 
           | (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_lsubus));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[0U] 
        = (IData)(((- (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4ag_val))) 
                   & (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs1))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[1U] 
        = ((0xfffffffeU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[1U]) 
           | (IData)((((- (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4ag_val))) 
                       & (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs1))) 
                      >> 0x20U)));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[1U] 
        = ((1U & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[1U]) 
           | (0xfffffffeU & ((IData)(((- (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4ag_val))) 
                                      & (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv_im)))) 
                             << 1U)));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[2U] 
        = ((0x1fcU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[2U]) 
           | ((1U & ((IData)(((- (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4ag_val))) 
                              & (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv_im)))) 
                     >> 0x1fU)) | (0xfffffffeU & ((IData)(
                                                          (((- (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4ag_val))) 
                                                            & (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv_im))) 
                                                           >> 0x20U)) 
                                                  << 1U))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[2U] 
        = ((0x17fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[2U]) 
           | (0xffffff80U & (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4bj_val) 
                              << 7U) & (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                         << 7U) | (0xffffff80U 
                                                   & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                                      << 6U))))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[2U] 
        = ((0xffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[2U]) 
           | (0xffffff00U & (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4bj_val) 
                              << 8U) & (((((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                           << 6U) | 
                                          ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                           << 5U)) 
                                         | ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                            << 4U)) 
                                        | ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                           << 3U)))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[2U] 
        = ((0x1fbU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[2U]) 
           | (0xfffffffcU & (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4al_val) 
                              & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb)) 
                             << 2U)));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[2U] 
        = ((0x1f7U & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[2U]) 
           | (0xfffffff8U & (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4al_val) 
                              << 3U) & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                        << 2U))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[2U] 
        = ((0x1efU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[2U]) 
           | (0xfffffff0U & (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4al_val) 
                              << 4U) & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                        << 2U))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[2U] 
        = ((0x1dfU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[2U]) 
           | (0x7fffffe0U & (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4al_val) 
                              << 5U) & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                        >> 1U))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[2U] 
        = ((0x1bfU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[2U]) 
           | (0x7fffffc0U & (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4al_val) 
                              << 6U) & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                        >> 1U))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[2U] 
        = ((0x17fU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[2U]) 
           | (0xffffff80U & (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4al_val) 
                              << 7U) & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                        << 2U))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[2U] 
        = ((0xffU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[2U]) 
           | (0xffffff00U & (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4al_val) 
                              << 8U) & (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                         << 5U) | ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                                   << 4U)))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[0U] 
        = (IData)(((- (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4al_val))) 
                   & ((0x10U & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb))
                       ? (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs1))
                       : (((QData)((IData)((1U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs1 
                                                  >> 0x1fU)))) 
                           << 0x20U) | (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs1))))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[1U] 
        = ((0xfffffffeU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[1U]) 
           | (IData)((((- (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4al_val))) 
                       & ((0x10U & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb))
                           ? (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs1))
                           : (((QData)((IData)((1U 
                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs1 
                                                   >> 0x1fU)))) 
                               << 0x20U) | (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs1))))) 
                      >> 0x20U)));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[1U] 
        = ((1U & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[1U]) 
           | (0xfffffffeU & ((IData)(((- (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4al_val))) 
                                      & ((0x10U & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb))
                                          ? (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__exal_opn2))
                                          : (((QData)((IData)(
                                                              (1U 
                                                               & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__exal_opn2 
                                                                  >> 0x1fU)))) 
                                              << 0x20U) 
                                             | (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__exal_opn2)))))) 
                             << 1U)));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[2U] 
        = ((0x1fcU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[2U]) 
           | ((1U & ((IData)(((- (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4al_val))) 
                              & ((0x10U & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb))
                                  ? (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__exal_opn2))
                                  : (((QData)((IData)(
                                                      (1U 
                                                       & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__exal_opn2 
                                                          >> 0x1fU)))) 
                                      << 0x20U) | (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__exal_opn2)))))) 
                     >> 0x1fU)) | (0xfffffffeU & ((IData)(
                                                          (((- (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4al_val))) 
                                                            & ((0x10U 
                                                                & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb))
                                                                ? (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__exal_opn2))
                                                                : 
                                                               (((QData)((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__exal_opn2 
                                                                                >> 0x1fU)))) 
                                                                 << 0x20U) 
                                                                | (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__exal_opn2))))) 
                                                           >> 0x20U)) 
                                                  << 1U))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_agu__DOT__lslb 
        = (1U & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                 | ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                    >> 3U)));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_agu__DOT__lslh 
        = (1U & (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                  >> 1U) | ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                            >> 4U)));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_bju__DOT__opn_u 
        = (1U & (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                  >> 4U) | ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                            >> 5U)));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_bju__DOT__justb 
        = (1U & (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                  >> 6U) | ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                            >> 7U)));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__ls_ren 
        = ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__hs_ls4rd_rdy) 
           | ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__hs_ls4ex_rdy) 
              & (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_agu__DOT__lslb) 
                  | (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_agu__DOT__lslh)) 
                 | ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                    >> 2U))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[2U] 
        = ((0x1fbU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[2U]) 
           | (0xfffffffcU & (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4ag_val) 
                              << 2U) & (((((((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_agu__DOT__lslb) 
                                             | (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_agu__DOT__lslh)) 
                                            << 2U) 
                                           | (0xfffffffcU 
                                              & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb))) 
                                          | (0x1ffffffcU 
                                             & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                                >> 3U))) 
                                         | (0xffffffcU 
                                            & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                               >> 4U))) 
                                        | (0x7fffffcU 
                                           & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                              >> 5U))))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[0U] 
        = (IData)(((- (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4bj_val))) 
                   & ((1U & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_bju__DOT__justb) 
                             | ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                >> 8U))) ? (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_rd__DOT__pc__DOT__qout_r))
                       : ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_bju__DOT__opn_u)
                           ? (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs1))
                           : (((QData)((IData)((1U 
                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs1 
                                                   >> 0x1fU)))) 
                               << 0x20U) | (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs1)))))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[1U] 
        = ((0xfffffffeU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[1U]) 
           | (IData)((((- (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4bj_val))) 
                       & ((1U & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_bju__DOT__justb) 
                                 | ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                    >> 8U))) ? (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_rd__DOT__pc__DOT__qout_r))
                           : ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_bju__DOT__opn_u)
                               ? (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs1))
                               : (((QData)((IData)(
                                                   (1U 
                                                    & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs1 
                                                       >> 0x1fU)))) 
                                   << 0x20U) | (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs1)))))) 
                      >> 0x20U)));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[1U] 
        = ((1U & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[1U]) 
           | (0xfffffffeU & ((IData)(((- (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4bj_val))) 
                                      & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_bju__DOT__justb)
                                          ? 4ULL : 
                                         ((0x100U & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb))
                                           ? (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv_im))
                                           : ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_bju__DOT__opn_u)
                                               ? (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs2))
                                               : (((QData)((IData)(
                                                                   (1U 
                                                                    & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs2 
                                                                       >> 0x1fU)))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs2)))))))) 
                             << 1U)));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[2U] 
        = ((0x1fcU & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[2U]) 
           | ((1U & ((IData)(((- (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4bj_val))) 
                              & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_bju__DOT__justb)
                                  ? 4ULL : ((0x100U 
                                             & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb))
                                             ? (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv_im))
                                             : ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_bju__DOT__opn_u)
                                                 ? (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs2))
                                                 : 
                                                (((QData)((IData)(
                                                                  (1U 
                                                                   & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs2 
                                                                      >> 0x1fU)))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs2)))))))) 
                     >> 0x1fU)) | (0xfffffffeU & ((IData)(
                                                          (((- (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4bj_val))) 
                                                            & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_bju__DOT__justb)
                                                                ? 4ULL
                                                                : 
                                                               ((0x100U 
                                                                 & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb))
                                                                 ? (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv_im))
                                                                 : 
                                                                ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_bju__DOT__opn_u)
                                                                  ? (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs2))
                                                                  : 
                                                                 (((QData)((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs2 
                                                                                >> 0x1fU)))) 
                                                                   << 0x20U) 
                                                                  | (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs2))))))) 
                                                           >> 0x20U)) 
                                                  << 1U))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
        = ((vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[0U] 
            | vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[0U]) 
           | vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[0U]);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[1U] 
        = ((vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[1U] 
            | vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[1U]) 
           | vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[1U]);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U] 
        = ((vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb[2U] 
            | vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb[2U]) 
           | vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[2U]);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__addsub_res 
        = (0x1ffffffffULL & (((- (QData)((IData)((1U 
                                                  & (((vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U] 
                                                       >> 2U) 
                                                      | (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U] 
                                                         >> 3U)) 
                                                     | (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U] 
                                                        >> 8U)))))) 
                              & (((QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[1U])) 
                                  << 0x20U) | (QData)((IData)(
                                                              vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U])))) 
                             + (((- (QData)((IData)(
                                                    (1U 
                                                     & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U] 
                                                        >> 2U))))) 
                                 & (((QData)((IData)(
                                                     vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U])) 
                                     << 0x1fU) | ((QData)((IData)(
                                                                  vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[1U])) 
                                                  >> 1U))) 
                                | ((- (QData)((IData)(
                                                      (1U 
                                                       & ((vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U] 
                                                           >> 3U) 
                                                          | (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U] 
                                                             >> 8U)))))) 
                                   & (1ULL + (~ (((QData)((IData)(
                                                                  vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U])) 
                                                  << 0x1fU) 
                                                 | ((QData)((IData)(
                                                                    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[1U])) 
                                                    >> 1U))))))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__slopn 
        = (((QData)((IData)(((0x40000000U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                             << 0x1eU)) 
                             | ((0x20000000U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                << 0x1cU)) 
                                | ((0x10000000U & (
                                                   vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                   << 0x1aU)) 
                                   | ((0x8000000U & 
                                       (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                        << 0x18U)) 
                                      | ((0x4000000U 
                                          & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                             << 0x16U)) 
                                         | ((0x2000000U 
                                             & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                << 0x14U)) 
                                            | ((0x1000000U 
                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                   << 0x12U)) 
                                               | ((0x800000U 
                                                   & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                      << 0x10U)) 
                                                  | ((0x400000U 
                                                      & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                         << 0xeU)) 
                                                     | ((0x200000U 
                                                         & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                            << 0xcU)) 
                                                        | ((0x100000U 
                                                            & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                               << 0xaU)) 
                                                           | ((0x80000U 
                                                               & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                                  << 8U)) 
                                                              | ((0x40000U 
                                                                  & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                                     << 6U)) 
                                                                 | ((0x20000U 
                                                                     & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                                        << 4U)) 
                                                                    | ((0x10000U 
                                                                        & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                                           << 2U)) 
                                                                       | ((0x8000U 
                                                                           & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U]) 
                                                                          | ((0x4000U 
                                                                              & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                                                >> 2U)) 
                                                                             | ((0x2000U 
                                                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                                                >> 4U)) 
                                                                                | ((0x1000U 
                                                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                                                >> 6U)) 
                                                                                | ((0x800U 
                                                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                                                >> 8U)) 
                                                                                | ((0x400U 
                                                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                                                >> 0xaU)) 
                                                                                | ((0x200U 
                                                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                                                >> 0xcU)) 
                                                                                | ((0x100U 
                                                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                                                >> 0xeU)) 
                                                                                | ((0x80U 
                                                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                                                >> 0x10U)) 
                                                                                | ((0x40U 
                                                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                                                >> 0x12U)) 
                                                                                | ((0x20U 
                                                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                                                >> 0x14U)) 
                                                                                | ((0x10U 
                                                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                                                >> 0x16U)) 
                                                                                | ((8U 
                                                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                                                >> 0x18U)) 
                                                                                | ((4U 
                                                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                                                >> 0x1aU)) 
                                                                                | ((2U 
                                                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                                                >> 0x1cU)) 
                                                                                | (1U 
                                                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                                                                >> 0x1eU)))))))))))))))))))))))))))))))))) 
            << 1U) | (QData)((IData)((1U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U] 
                                            >> 0x1fU)))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__opsr 
        = (1U & ((vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U] 
                  >> 5U) | (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U] 
                            >> 6U)));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
        = (0x1ffffffffULL & ((0x1ffffffffULL & (((- (QData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__opsr))) 
                                                 & (((QData)((IData)(
                                                                     vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[1U])) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U])))) 
                                                | ((- (QData)((IData)(
                                                                      (1U 
                                                                       & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U] 
                                                                          >> 4U))))) 
                                                   & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__slopn))) 
                             >> (0x1fU & ((- (IData)(
                                                     (1U 
                                                      & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__opsr) 
                                                         | (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U] 
                                                            >> 4U))))) 
                                          & ((vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U] 
                                              << 0x1fU) 
                                             | (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[1U] 
                                                >> 1U))))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sl_res 
        = ((QData)((IData)(((0x80000000U & ((IData)(
                                                    (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                     >> 1U)) 
                                            << 0x1fU)) 
                            | ((0x40000000U & ((IData)(
                                                       (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                        >> 2U)) 
                                               << 0x1eU)) 
                               | ((0x20000000U & ((IData)(
                                                          (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                           >> 3U)) 
                                                  << 0x1dU)) 
                                  | ((0x10000000U & 
                                      ((IData)((vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                >> 4U)) 
                                       << 0x1cU)) | 
                                     ((0x8000000U & 
                                       ((IData)((vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                 >> 5U)) 
                                        << 0x1bU)) 
                                      | ((0x4000000U 
                                          & ((IData)(
                                                     (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                      >> 6U)) 
                                             << 0x1aU)) 
                                         | ((0x2000000U 
                                             & ((IData)(
                                                        (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                         >> 7U)) 
                                                << 0x19U)) 
                                            | ((0x1000000U 
                                                & ((IData)(
                                                           (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                            >> 8U)) 
                                                   << 0x18U)) 
                                               | ((0x800000U 
                                                   & ((IData)(
                                                              (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                               >> 9U)) 
                                                      << 0x17U)) 
                                                  | ((0x400000U 
                                                      & ((IData)(
                                                                 (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                  >> 0xaU)) 
                                                         << 0x16U)) 
                                                     | ((0x200000U 
                                                         & ((IData)(
                                                                    (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                     >> 0xbU)) 
                                                            << 0x15U)) 
                                                        | ((0x100000U 
                                                            & ((IData)(
                                                                       (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                        >> 0xcU)) 
                                                               << 0x14U)) 
                                                           | ((0x80000U 
                                                               & ((IData)(
                                                                          (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                           >> 0xdU)) 
                                                                  << 0x13U)) 
                                                              | ((0x40000U 
                                                                  & ((IData)(
                                                                             (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                              >> 0xeU)) 
                                                                     << 0x12U)) 
                                                                 | ((0x20000U 
                                                                     & ((IData)(
                                                                                (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                                >> 0xfU)) 
                                                                        << 0x11U)) 
                                                                    | ((0x10000U 
                                                                        & ((IData)(
                                                                                (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                                >> 0x10U)) 
                                                                           << 0x10U)) 
                                                                       | ((0x8000U 
                                                                           & ((IData)(
                                                                                (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                                >> 0x11U)) 
                                                                              << 0xfU)) 
                                                                          | ((0x4000U 
                                                                              & ((IData)(
                                                                                (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                                >> 0x12U)) 
                                                                                << 0xeU)) 
                                                                             | ((0x2000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                                >> 0x13U)) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                                >> 0x14U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & ((IData)(
                                                                                (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                                >> 0x15U)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & ((IData)(
                                                                                (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                                >> 0x16U)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & ((IData)(
                                                                                (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                                >> 0x17U)) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & ((IData)(
                                                                                (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                                >> 0x18U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & ((IData)(
                                                                                (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                                >> 0x19U)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & ((IData)(
                                                                                (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                                >> 0x1aU)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & ((IData)(
                                                                                (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                                >> 0x1bU)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((IData)(
                                                                                (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                                >> 0x1cU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((IData)(
                                                                                (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                                >> 0x1dU)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(
                                                                                (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                                >> 0x1eU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((IData)(
                                                                                (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                                >> 0x1fU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (IData)(
                                                                                (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res 
                                                                                >> 0x20U)))))))))))))))))))))))))))))))))))) 
           << 1U);
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_res 
        = ((((((- (IData)((1U & ((vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U] 
                                  >> 2U) | (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U] 
                                            >> 3U))))) 
               & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__addsub_res)) 
              | ((- (IData)((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__opsr))) 
                 & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res))) 
             | ((- (IData)((1U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U] 
                                  >> 4U)))) & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sl_res))) 
            | ((- (IData)((1U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U] 
                                 >> 7U)))) & (((IData)(
                                                       (0x1ffffffffULL 
                                                        & (- (QData)((IData)(
                                                                             (1U 
                                                                              & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U] 
                                                                                >> 7U))))))) 
                                               & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[0U]) 
                                              ^ ((IData)(
                                                         (0x1ffffffffULL 
                                                          & (- (QData)((IData)(
                                                                               (1U 
                                                                                & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U] 
                                                                                >> 7U))))))) 
                                                 & ((vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U] 
                                                     << 0x1fU) 
                                                    | (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[1U] 
                                                       >> 1U)))))) 
           | ((- (IData)((1U & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb[2U] 
                                >> 8U)))) & (IData)((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__addsub_res 
                                                                                >> 0x20U))))))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd 
        = ((((((- (IData)((0U != ((vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[0U] 
                                   | vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[1U]) 
                                  | vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb[2U])))) 
               & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_res) 
              | ((- (IData)((1U & (((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                    >> 9U) | ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                              >> 8U))))) 
                 & (((- (IData)((1U & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                       >> 9U)))) & 
                     (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs1 
                      & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__exal_opn2)) 
                    | ((- (IData)((1U & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                         >> 8U)))) 
                       & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs1 
                          | vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__exal_opn2))))) 
             & (- (IData)((1U & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__usele))))) 
            | (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_res 
               & (- (IData)((1U & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__usele) 
                                   >> 2U)))))) | (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rdat 
                                                  & (- (IData)(
                                                               (1U 
                                                                & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__usele) 
                                                                   >> 1U))))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__ls_wen 
        = ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__hs_ls4rd_rdy)
            ? 0U : ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__hs_ls4ex_rdy)
                     ? (0xfU & (((- (IData)((1U & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                                   >> 7U)))) 
                                 | ((- (IData)((1U 
                                                & ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                                   >> 6U)))) 
                                    & ((2U & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_res)
                                        ? 0xcU : 3U))) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                                >> 5U)))) 
                                   & ((2U & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_res)
                                       ? ((1U & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_res)
                                           ? 8U : 4U)
                                       : ((1U & vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_res)
                                           ? 2U : 1U)))))
                     : 0U));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjex_pc_setpc 
        = (1U & (((((((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                      >> 1U) | ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                >> 2U)) | ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                           >> 4U)) 
                   & (0U != vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_res)) 
                  | ((((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                       | ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                          >> 3U)) | ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb) 
                                     >> 5U)) & (~ (IData)(
                                                          (0U 
                                                           != vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_res))))) 
                 | (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_bju__DOT__justb)));
    vlTOPp->tb_top__DOT__cpu0__DOT__sram_wen = (0xfU 
                                                & (((- (IData)(
                                                               (0x8000U 
                                                                == 
                                                                (0xffffU 
                                                                 & (vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__ls_adr 
                                                                    >> 0x10U))))) 
                                                    >> 1U) 
                                                   & ((0x7fffffffU 
                                                       & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__ls_wen)) 
                                                      | ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__ls_ren) 
                                                         >> 1U))));
    vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_pc__DOT__pc_add1 
        = ((IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjex_pc_setpc)
            ? ((0x80U & (IData)(vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb))
                ? vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs1
                : vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_rd__DOT__pc__DOT__qout_r)
            : vlTOPp->tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_rd__DOT__pc__DOT__qout_r);
}

void Vtb_top::_eval_initial(Vtb_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top::_eval_initial\n"); );
    Vtb_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__tb_top__DOT__clk = vlTOPp->tb_top__DOT__clk;
    vlTOPp->__Vclklast__TOP__tb_top__DOT__rst_n = vlTOPp->tb_top__DOT__rst_n;
}

void Vtb_top::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top::final\n"); );
    // Variables
    Vtb_top__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtb_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtb_top::_eval_settle(Vtb_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top::_eval_settle\n"); );
    Vtb_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vtb_top::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top::_ctor_var_reset\n"); );
    // Body
    tb_top__DOT__clk = VL_RAND_RESET_I(1);
    tb_top__DOT__rst_n = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<16384; ++__Vi0) {
            tb_top__DOT__sram_mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
    tb_top__DOT__i = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__hs_ram4ls_rdy = VL_RAND_RESET_I(1);
    tb_top__DOT__cpu0__DOT__sram_wen = VL_RAND_RESET_I(4);
    tb_top__DOT__cpu0__DOT__adr = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__wdat = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__hs_ls4rd_rdy = VL_RAND_RESET_I(1);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__valin = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__opb = VL_RAND_RESET_I(10);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__usele = VL_RAND_RESET_I(3);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd_wen = VL_RAND_RESET_I(1);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__deval = VL_RAND_RESET_I(1);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs1 = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rs2 = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__hs_ex4rd_rdy = VL_RAND_RESET_I(1);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rd = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__hs_ls4ex_rdy = VL_RAND_RESET_I(1);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__rdat = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_pc__DOT__pc_add1 = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_rd__DOT__ready__DOT__qout_r = VL_RAND_RESET_I(1);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_rd__DOT__inl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_rd__DOT__pc__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv32_jim = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv32_slli = VL_RAND_RESET_I(1);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv32_srli = VL_RAND_RESET_I(1);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv32_srai = VL_RAND_RESET_I(1);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_alubus = VL_RAND_RESET_I(10);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_bjubus = VL_RAND_RESET_I(10);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__dec_lsubus = VL_RAND_RESET_I(10);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_decode__DOT__rv_im = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_r[__Vi0] = VL_RAND_RESET_I(32);
    }}
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__rf_wen = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__1__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__2__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__3__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__4__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__5__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__6__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__7__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__8__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__9__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__10__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__11__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__12__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__13__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__14__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__15__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__16__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__17__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__18__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__19__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__20__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__21__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__22__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__23__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__24__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__25__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__26__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__27__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__28__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__29__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__30__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_regfile__DOT__regfile__BRA__31__KET____DOT__rfno0__DOT__rf_dffl__DOT__qout_r = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(73, tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_opb);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__cal_res = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4al_val = VL_RAND_RESET_I(1);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__exal_opn2 = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(73, tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__alcal_cal_opb);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4bj_val = VL_RAND_RESET_I(1);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_bj4ex_rdy = VL_RAND_RESET_I(1);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjex_pc_setpc = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(73, tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__bjcal_cal_opb);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__hs_ex4ag_val = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(73, tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__agcal_cal_opb);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__opsr = VL_RAND_RESET_I(1);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__slopn = VL_RAND_RESET_Q(33);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__addsub_res = VL_RAND_RESET_Q(33);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sr_res = VL_RAND_RESET_Q(33);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_cal__DOT__sl_res = VL_RAND_RESET_Q(33);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_bju__DOT__opn_u = VL_RAND_RESET_I(1);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_bju__DOT__justb = VL_RAND_RESET_I(1);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_agu__DOT__lslb = VL_RAND_RESET_I(1);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_agu__DOT__lslh = VL_RAND_RESET_I(1);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_agu__DOT__val__DOT__qout_r = VL_RAND_RESET_I(1);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_exu__DOT__u_exu_agu__DOT__adr__DOT__qout_r = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__out_rdy = VL_RAND_RESET_I(1);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__ls_adr = VL_RAND_RESET_I(32);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__ls_wen = VL_RAND_RESET_I(4);
    tb_top__DOT__cpu0__DOT__u_cirno9_core__DOT__u_lsu__DOT__ls_ren = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<16384; ++__Vi0) {
            tb_top__DOT__cpu0__DOT__u_sram32__DOT__mem_r[__Vi0] = VL_RAND_RESET_I(32);
    }}
}
