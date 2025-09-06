// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vme7.h for the primary calling header

#ifndef VERILATED_VME7___024ROOT_H_
#define VERILATED_VME7___024ROOT_H_  // guard

#include "verilated.h"

class Vme7__Syms;

class Vme7___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(ps2_clk,0,0);
        VL_IN8(rst,0,0);
        VL_IN8(ps2_data,0,0);
        VL_OUT8(data,7,0);
        VL_OUT8(ascii,7,0);
        CData/*7:0*/ me7__DOT__count;
        CData/*0:0*/ me7__DOT__flag;
        CData/*0:0*/ me7__DOT__state;
        CData/*0:0*/ me7__DOT__next_state;
        CData/*3:0*/ me7__DOT__one__DOT__count;
        CData/*2:0*/ me7__DOT__one__DOT__ps2_clk_sync;
        CData/*0:0*/ me7__DOT__one__DOT____Vlvbound_h1a91ade8__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_hede0c227__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_hf71681aa__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h34fc6167__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h37c9d5f5__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h1c342157__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_hdd3649dd__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h15732fc1__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h60ae9ad8__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h1997ee49__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h1e156eb1__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h5171ac0e__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h13ade830__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h5499cb8d__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h84cc0607__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h406caffd__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h60dc900e__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h71eca00a__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h68b33184__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h47a1452d__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h92ee800c__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h3e8bdc5b__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h5f4cce94__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_hb2ac9dc4__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h78a13ad2__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h7d356b2e__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h0e57f19f__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h0e6a3af6__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h30b18abd__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h0e7e1c84__0;
        CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h224682a9__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_hede0c227__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_hf71681aa__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h34fc6167__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h37c9d5f5__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h1c342157__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_hdd3649dd__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h15732fc1__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h60ae9ad8__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h1997ee49__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h1e156eb1__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h5171ac0e__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h13ade830__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h5499cb8d__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h84cc0607__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h406caffd__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h60dc900e__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h71eca00a__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h68b33184__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h47a1452d__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h92ee800c__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h3e8bdc5b__0;
    };
    struct {
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h5f4cce94__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_hb2ac9dc4__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h78a13ad2__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h7d356b2e__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h0e57f19f__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h0e6a3af6__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h30b18abd__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h0e7e1c84__0;
        CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h224682a9__0;
        CData/*2:0*/ __Vdly__me7__DOT__one__DOT__ps2_clk_sync;
        CData/*3:0*/ __Vdly__me7__DOT__one__DOT__count;
        CData/*0:0*/ __Vtrigrprev__TOP__ps2_clk;
        CData/*0:0*/ __Vtrigrprev__TOP__clk;
        CData/*0:0*/ __VactContinue;
        VL_OUT16(xian,13,0);
        VL_OUT16(xian2,13,0);
        VL_OUT16(xian3,13,0);
        VL_OUT16(xian4,13,0);
        SData/*9:0*/ me7__DOT__one__DOT__buffer;
        IData/*31:0*/ __VstlIterCount;
        IData/*31:0*/ __VactIterCount;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vme7__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vme7___024root(Vme7__Syms* symsp, const char* v__name);
    ~Vme7___024root();
    VL_UNCOPYABLE(Vme7___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
