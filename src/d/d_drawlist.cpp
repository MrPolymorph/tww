//
// Generated by dtk
// Translation Unit: d_drawlist.cpp
//

#include "d/d_drawlist.h"
#include "d/d_com_inf_game.h"
#include "m_Do/m_Do_lib.h"
#include "m_Do/m_Do_mtx.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "SSystem/SComponent/c_rnd.h"
#include "SSystem/SComponent/c_bg_s_shdw_draw.h"

/* 800804A4-800804C0       .text setViewPort__14dDlst_window_cFffffff */
void dDlst_window_c::setViewPort(f32 x, f32 y, f32 w, f32 h, f32 n, f32 f) {
    mViewport.mXOrig = x;
    mViewport.mYOrig = y;
    mViewport.mWidth = w;
    mViewport.mHeight = h;
    mViewport.mNearZ = n;
    mViewport.mFarZ = f;
}

/* 800804C0-800804D4       .text setScissor__14dDlst_window_cFffff */
void dDlst_window_c::setScissor(f32 x, f32 y, f32 w, f32 h) {
    mViewport.mScissor.mXOrig = x;
    mViewport.mScissor.mYOrig = y;
    mViewport.mScissor.mWidth = w;
    mViewport.mScissor.mHeight = h;
}

/* 800804D4-80080694       .text draw__13dDlst_2DTri_cFv */
void dDlst_2DTri_c::draw() {
    /* Nonmatching */
}

/* 80080694-80080784       .text draw__15dDlst_2DPoint_cFv */
void dDlst_2DPoint_c::draw() {
    /* Nonmatching */
}

/* 80080784-80080A50       .text draw__11dDlst_2DT_cFv */
void dDlst_2DT_c::draw() {
    /* Nonmatching */
}

/* 80080A50-800811E8       .text draw__12dDlst_2DT2_cFv */
void dDlst_2DT2_c::draw() {
    /* Nonmatching */
}

/* 800811E8-800812F4       .text init__12dDlst_2DT2_cFP7ResTIMGffffUcUcUcff */
void dDlst_2DT2_c::init(ResTIMG*, f32, f32, f32, f32, u8, u8, u8, f32, f32) {
    /* Nonmatching */
}

/* 800812F4-800817CC       .text draw__11dDlst_2DM_cFv */
void dDlst_2DM_c::draw() {
    /* Nonmatching */
}

/* 800817CC-80081850       .text init__11dDlst_2Dm_cFP7ResTIMGP7ResTIMGff */
void dDlst_2Dm_c::init(ResTIMG* t0, ResTIMG* t1, f32 sx, f32 sy) {
    mTex[0].mbHasTlut = mDoLib_setResTimgObj(t0, &mTex[0].mTexObj, 0, &mTex[0].mTlutObj);
    mTex[1].mbHasTlut = mDoLib_setResTimgObj(t1, &mTex[1].mTexObj, 1, &mTex[1].mTlutObj);
    mScaleX = sx;
    mScaleY = sy;
}

/* 80081850-80081864       .text setPos__11dDlst_2Dm_cFssss */
void dDlst_2Dm_c::setPos(s16 x0, s16 y0, s16 x1, s16 y1) {
    mX0 = x0;
    mY0 = y0;
    mX1 = x1;
    mY1 = y1;
}

/* 80081864-80081870       .text setScale__11dDlst_2Dm_cFff */
void dDlst_2Dm_c::setScale(f32 sx, f32 sy) {
    mScaleX = sx;
    mScaleY = sy;
}

/* 80081870-80081888       .text setScroll__11dDlst_2Dm_cFiss */
void dDlst_2Dm_c::setScroll(int idx, s16 x, s16 y) {
    TexEntry * pTex = &mTex[idx];
    pTex->mScrollX = x;
    pTex->mScrollY = y;
}

/* 80081888-80081DA4       .text draw__11dDlst_2Dm_cFv */
void dDlst_2Dm_c::draw() {
    /* Nonmatching - scroll math isn't right */

    GXVtxAttrFmtList fmtList[GX_VA_MAX_ATTR + 1];

    s16 tex0_s0 = mTex[0].mScrollX;
    s16 tex0_s1 = (tex0_s0 + 256.0f);
    s16 tex0_t0 = mTex[0].mScrollY;
    s16 tex0_t1 = (tex0_t0 + 256.0f);

    s16 tex1_s0 = mTex[1].mScrollX;
    s16 tex1_s1 = (tex1_s0 + 256.0f);
    s16 tex1_t0 = mTex[1].mScrollY;
    s16 tex1_t1 = (tex1_t0 + 256.0f);

    GXGetVtxAttrFmtv(GX_VTXFMT0, fmtList);

    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_S16, 8);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX1, GX_TEX_ST, GX_S16, 8);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX1, GX_DIRECT);
    GXLoadTexObj(&this->mTex[0].mTexObj, GX_TEXMAP0);
    if (this->mTex[0].mbHasTlut)
        GXLoadTlut(&this->mTex[0].mTlutObj, GXGetTexObjTlut(&mTex[0].mTexObj));
    GXLoadTexObj(&this->mTex[1].mTexObj, GX_TEXMAP1);
    if (this->mTex[1].mbHasTlut != 0)
        GXLoadTlut(&this->mTex[1].mTlutObj, GXGetTexObjTlut(&mTex[1].mTexObj));

    GXSetNumChans(0);
    GXSetTevColor(GX_TEVREG0, mC0);
    GXSetTevColor(GX_TEVREG1, mC1);

    GXSetNumTexGens(2);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX2x4, GX_TG_TEX1, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);

    GXSetNumTevStages(2);

    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_C1, GX_CC_C0, GX_CC_TEXC, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_A1, GX_CA_A0, GX_CA_TEXA, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);

    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR_NULL);
    GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_TEXC, GX_CC_CPREV, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_TEXA, GX_CA_APREV, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);

    GXSetAlphaCompare(GX_GREATER, 0, GX_AOP_OR, GX_GREATER, 0);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRC_ALPHA, GX_BL_INV_SRC_ALPHA, GX_LO_SET);
    GXLoadPosMtxImm(mDoMtx_getIdentity(), GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);                                     

    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    GXPosition3f32(mX0, mY0, 0.0f);
    GXTexCoord2s16(tex0_s0, tex0_t0);
    GXTexCoord2s16(tex1_s0, tex1_t0);

    GXPosition3f32(mX1, mY0, 0.0f);
    GXTexCoord2s16(tex0_s1, tex0_t0);
    GXTexCoord2s16(tex1_s1, tex1_t0);

    GXPosition3f32(mX1, mY1, 0.0f);
    GXTexCoord2s16(tex0_s1, tex0_t1);
    GXTexCoord2s16(tex1_s1, tex1_t1);

    GXPosition3f32(mX0, mY1, 0.0f);
    GXTexCoord2s16(tex0_s0, tex0_t1);
    GXTexCoord2s16(tex1_s0, tex1_t1);
    GXEnd();

    GXSetVtxAttrFmtv(GX_VTXFMT0, fmtList);
}

/* 80081DA4-80082130       .text draw__12dDlst_2DMt_cFv */
void dDlst_2DMt_c::draw() {
    /* Nonmatching */
}

/* 80082130-800821B0       .text __ct__10dDlst_2D_cFP7ResTIMGssUc */
dDlst_2D_c::dDlst_2D_c(ResTIMG* timg, s16 x, s16 y, u8 alpha) {
    mPicture.initiate(timg, NULL);
    mX = x;
    mY = y;
    mAlpha = alpha;
}

/* 800821B0-80082264       .text draw__10dDlst_2D_cFv */
void dDlst_2D_c::draw() {
    mPicture.setAlpha(mAlpha);
    mPicture.draw(mX, mY, false, false, false);
}

/* 80082424-80082794       .text draw__18dDlst_effectLine_cFv */
void dDlst_effectLine_c::draw() {
    /* Nonmatching */
}

/* 80082794-80082828       .text update__18dDlst_effectLine_cFR4cXyzR8_GXColorUsUsUsUsffff */
void dDlst_effectLine_c::update(cXyz&, _GXColor&, u16, u16, u16, u16, f32, f32, f32, f32) {
    /* Nonmatching */
}

/* 80082828-80082838       .text set__22dDlst_alphaModelData_cFUcPA4_fUc */
void dDlst_alphaModelData_c::set(u8 type, Mtx mtx, u8 alpha) {
    mType = type;
    mpMtx = mtx;
    mAlpha = alpha;
}

extern void GFLoadPosMtxImm(MtxP, GXPosNrmMtx);
extern void GFSetCurrentMtx(u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern void GFSetChanMatColor(GXChannelID, GXColor);
extern void GFSetVtxDescv(GXVtxDescList*);
extern void GFSetVtxAttrFmtv(GXVtxFmt, GXVtxAttrFmtList*);
extern void GFSetBlendModeEtc(GXBlendMode, GXBlendFactor, GXBlendFactor, GXLogicOp, u8, u8, u8);
extern void GFSetArray(GXAttr, void*, u8);

char l_backRevZMat[0x40] = {};
char l_frontZMat[0x20] = {};
char l_frontNoZSubMat[0x20] = {};

Vec l_bonboriPos[0x2a] = {};
char l_bonboriDL[0xa0] = {};

Vec l_beam_checkPos[0x10] = {};
char l_beam_checkDL[0xe0] = {};

Vec l_cubePos[0x10] = {};
char l_cubeDL[0xe0] = {};

Vec l_bonbori2Pos[0x2a] = {};
char l_bonbori2DL[0xa0] = {};

/* 80082838-80082E44       .text draw__22dDlst_alphaModelData_cFPA4_f */
void dDlst_alphaModelData_c::draw(Mtx viewMtx) {
    /* Nonmatching - color and data order */
    Mtx mtx;
    MTXConcat(viewMtx, mpMtx, mtx);
    GFLoadPosMtxImm(mtx, GX_PNMTX0);
    GFSetCurrentMtx(GX_PNMTX0, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY);

    GXColor color = { 0, 0, 0, 0 };
    color.a = mAlpha;
    GFSetChanMatColor(GX_ALPHA0, color);

    if (mType == 0) {
        /* Bonbori */
        GFSetArray(GX_VA_POS, l_bonboriPos, sizeof(*l_bonboriPos));
        GXCallDisplayList(l_backRevZMat, sizeof(l_backRevZMat));
        GXCallDisplayList(l_bonboriDL, sizeof(l_bonboriDL));
        GXCallDisplayList(l_frontZMat, sizeof(l_frontZMat));
        GXCallDisplayList(l_bonboriDL, sizeof(l_bonboriDL));
        GXCallDisplayList(l_frontNoZSubMat, sizeof(l_frontNoZSubMat));
        GXCallDisplayList(l_bonboriDL, sizeof(l_bonboriDL));
    } else if (mType == 1) {
        /* Bonborix2 */
        GFSetArray(GX_VA_POS, l_bonboriPos, sizeof(*l_bonboriPos));
        Mtx tmp;
        MTXScale(tmp, 0.8f, 0.8f, 0.8f);
        MTXConcat(mtx, tmp, tmp);
        GFLoadPosMtxImm(tmp, GX_PNMTX1);

        GXCallDisplayList(l_backRevZMat, sizeof(l_backRevZMat));
        GXCallDisplayList(l_bonboriDL, sizeof(l_bonboriDL));
        GFSetCurrentMtx(GX_PNMTX1, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY);
        GXCallDisplayList(l_bonboriDL, sizeof(l_bonboriDL));

        GXCallDisplayList(l_frontZMat, sizeof(l_frontZMat));
        GFSetCurrentMtx(GX_PNMTX0, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY);
        GXCallDisplayList(l_bonboriDL, sizeof(l_bonboriDL));
        GFSetCurrentMtx(GX_PNMTX1, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY);
        GXCallDisplayList(l_bonboriDL, sizeof(l_bonboriDL));

        GXCallDisplayList(l_frontNoZSubMat, sizeof(l_frontNoZSubMat));
        GFSetCurrentMtx(GX_PNMTX0, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY);
        GXCallDisplayList(l_bonboriDL, sizeof(l_bonboriDL));
        GFSetCurrentMtx(GX_PNMTX1, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY);
        GXCallDisplayList(l_bonboriDL, sizeof(l_bonboriDL));
    } else if (mType == 5) {
        /* Bonborix3 */
        GFSetArray(GX_VA_POS, l_bonboriPos, sizeof(*l_bonboriPos));
        Mtx tmp;
        MTXScale(tmp, 0.8f, 0.8f, 0.8f);
        MTXConcat(mtx, tmp, tmp);
        GFLoadPosMtxImm(tmp, GX_PNMTX1);

        MTXScale(tmp, 0.6f, 0.6f, 0.6f);
        MTXConcat(mtx, tmp, tmp);
        GFLoadPosMtxImm(tmp, GX_PNMTX2);

        GXCallDisplayList(l_backRevZMat, sizeof(l_backRevZMat));
        GXCallDisplayList(l_bonboriDL, sizeof(l_bonboriDL));
        GFSetCurrentMtx(GX_PNMTX1, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY);
        GXCallDisplayList(l_bonboriDL, sizeof(l_bonboriDL));
        GFSetCurrentMtx(GX_PNMTX2, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY);
        GXCallDisplayList(l_bonboriDL, sizeof(l_bonboriDL));

        GXCallDisplayList(l_frontZMat, sizeof(l_frontZMat));
        GFSetCurrentMtx(GX_PNMTX0, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY);
        GXCallDisplayList(l_bonboriDL, sizeof(l_bonboriDL));
        GFSetCurrentMtx(GX_PNMTX1, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY);
        GXCallDisplayList(l_bonboriDL, sizeof(l_bonboriDL));
        GFSetCurrentMtx(GX_PNMTX2, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY);
        GXCallDisplayList(l_bonboriDL, sizeof(l_bonboriDL));

        GXCallDisplayList(l_frontNoZSubMat, sizeof(l_frontNoZSubMat));
        GFSetCurrentMtx(GX_PNMTX0, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY);
        GXCallDisplayList(l_bonboriDL, sizeof(l_bonboriDL));
        GFSetCurrentMtx(GX_PNMTX1, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY);
        GXCallDisplayList(l_bonboriDL, sizeof(l_bonboriDL));
        GFSetCurrentMtx(GX_PNMTX2, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY, GX_IDENTITY);
        GXCallDisplayList(l_bonboriDL, sizeof(l_bonboriDL));
    } else if (mType == 2) {
        /* BeamCheck */
        GFSetArray(GX_VA_POS, l_beam_checkPos, sizeof(*l_beam_checkPos));
        GXCallDisplayList(l_backRevZMat, sizeof(l_backRevZMat));
        GXCallDisplayList(l_beam_checkDL, sizeof(l_beam_checkDL));
        GXCallDisplayList(l_frontZMat, sizeof(l_frontZMat));
        GXCallDisplayList(l_beam_checkDL, sizeof(l_beam_checkDL));
        GXCallDisplayList(l_frontNoZSubMat, sizeof(l_frontNoZSubMat));
        GXCallDisplayList(l_beam_checkDL, sizeof(l_beam_checkDL));
    } else if (mType == 3) {
        /* Cube */
        /* BeamCheck */
        GFSetArray(GX_VA_POS, l_cubePos, sizeof(*l_cubePos));
        GXCallDisplayList(l_backRevZMat, sizeof(l_backRevZMat));
        GXCallDisplayList(l_frontZMat, sizeof(l_frontZMat));
        GXCallDisplayList(l_cubeDL, sizeof(l_cubeDL));
    } else if (mType == 4) {
        /* Bonbori2 */
        GFSetArray(GX_VA_POS, l_bonbori2Pos, sizeof(*l_bonbori2Pos));
        GXCallDisplayList(l_backRevZMat, sizeof(l_backRevZMat));
        GXCallDisplayList(l_bonbori2DL, sizeof(l_bonbori2DL));
        GXCallDisplayList(l_frontZMat, sizeof(l_frontZMat));
        GXCallDisplayList(l_bonbori2DL, sizeof(l_bonbori2DL));
        GXCallDisplayList(l_frontNoZSubMat, sizeof(l_frontNoZSubMat));
        GXCallDisplayList(l_bonbori2DL, sizeof(l_bonbori2DL));
    }
}

/* 80082E44-80082E58       .text __ct__18dDlst_alphaModel_cFv */
dDlst_alphaModel_c::dDlst_alphaModel_c() {
    mCapacity = 0;
    mpData = NULL;
    mNum = 0;
}

/* 80082E58-80082EFC       .text create__18dDlst_alphaModel_cFi */
dDlst_alphaModel_c * dDlst_alphaModel_c::create(int num) {
    dDlst_alphaModel_c * i_this = new dDlst_alphaModel_c();
    if (i_this != NULL) {
        dDlst_alphaModelData_c * pData = new dDlst_alphaModelData_c[num];
        if (pData != NULL) {
            i_this->mpData = pData;
            i_this->mCapacity = num;
            return i_this;
        }

        if (i_this != NULL)
            delete i_this;
    }
    return NULL;
}

/* 80082EFC-80082F38       .text __dt__22dDlst_alphaModelData_cFv */
dDlst_alphaModelData_c::~dDlst_alphaModelData_c() {
    /* Nonmatching */
}

/* 80082F38-80082F3C       .text __ct__22dDlst_alphaModelData_cFv */
dDlst_alphaModelData_c::dDlst_alphaModelData_c() {
    /* Nonmatching */
}

/* 80082F3C-80082F9C       .text set__18dDlst_alphaModel_cFUcPA4_fUc */
BOOL dDlst_alphaModel_c::set(u8 type, Mtx mtx, u8 alpha) {
    /* Nonmatching */
}

/* 80082F9C-80083064       .text draw__18dDlst_alphaModel_cFPA4_f */
BOOL dDlst_alphaModel_c::draw(Mtx mtx) {
    if (mNum == 0)
        return FALSE;

    static char l_matDL[0x60] = {};

    static GXVtxDescList l_vtxDescList[2] = {
    };

    static GXVtxAttrFmtList l_vtxAttrFmtList[2] = {
    };

    GXCallDisplayList(l_matDL, sizeof(l_matDL));
    GFSetVtxDescv(l_vtxDescList);
    GFSetVtxAttrFmtv(GX_VTXFMT0, l_vtxAttrFmtList);
    GXSetClipMode(GX_CLIP_ENABLE);

    dDlst_alphaModelData_c * pData = &mpData[0];
    for (s32 i = 0; i < mNum; pData++, i++)
        pData->draw(mtx);

    GFSetBlendModeEtc(GX_BM_NONE, GX_BL_ZERO, GX_BL_ZERO, GX_LO_CLEAR, 1, 0, 1);
    return TRUE;
}

/* 80083064-800832C4       .text draw__22dDlst_alphaModelPacketFv */
void dDlst_alphaModelPacket::draw() {
    /* Nonmatching */
}

/* 800832C4-800833CC       .text set__18dDlst_shadowPoly_cFP10cBgD_Vtx_tUsUsUsP8cM3dGPla */
int dDlst_shadowPoly_c::set(cBgD_Vtx_t*, u16, u16, u16, cM3dGPla*) {
    /* Nonmatching */
}

/* 800833CC-800834A4       .text set__18dDlst_shadowPoly_cFR4cXyzR4cXyzR4cXyz */
int dDlst_shadowPoly_c::set(cXyz&, cXyz&, cXyz&) {
    /* Nonmatching */
}

/* 800834A4-80083568       .text draw__18dDlst_shadowPoly_cFv */
void dDlst_shadowPoly_c::draw() {
    /* Nonmatching */
}

/* 800836E0-800837F0       .text init__18dDlst_shadowReal_cFv */
void dDlst_shadowReal_c::init() {
    u32 texDataSize = GXGetTexBufferSize(0x80, 0x80, GX_TF_I4, GX_FALSE, 0);
    mpTexData = new(0x20) u8[texDataSize];

    GXInitTexObj(&mTexObj, mpTexData, 0x80, 0x80, GX_TF_I4, GX_CLAMP, GX_CLAMP, GX_FALSE);
    GXInitTexObjLOD(&mTexObj, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_ANISO_1);

    mpCallBack = new J3DCallBackPacket();
    mpDrawBuffer = new J3DDrawBuffer();
    mpDrawBuffer->setInvalidSort();
}

/* 800837F0-80083850       .text reset__18dDlst_shadowReal_cFv */
void dDlst_shadowReal_c::reset() {
    if (mState == 1) {
        mState = 2;
    } else {
        mState = 0;
        field_0x1 = -1;
    }

    mpDrawBuffer->frameInit();
    mModelNum = 0;
}

/* 80083850-8008398C       .text imageDraw__18dDlst_shadowReal_cFPA4_f */
void dDlst_shadowReal_c::imageDraw(Mtx) {
    /* Nonmatching */
}

/* 8008398C-80083B8C       .text draw__18dDlst_shadowReal_cFv */
void dDlst_shadowReal_c::draw() {
    /* Nonmatching */
}

/* 80083B8C-80083DA0       .text psdRealCallBack__FP13cBgS_ShdwDrawP10cBgD_Vtx_tiiiP8cM3dGPla */
void psdRealCallBack(cBgS_ShdwDraw*, cBgD_Vtx_t*, int, int, int, cM3dGPla*) {
    /* Nonmatching */
}

/* 80083DA0-80083E18       .text seaRealCallBack__FPvR4cXyzR4cXyzR4cXyz */
void seaRealCallBack(void*, cXyz&, cXyz&, cXyz&) {
    /* Nonmatching */
}

/* 80083E18-800840B0       .text realPolygonCheck__FP4cXyzffP4cXyzP18dDlst_shadowPoly_c */
void realPolygonCheck(cXyz*, f32, f32, cXyz*, dDlst_shadowPoly_c*) {
    /* Nonmatching */
}

/* 80084138-800841B0       .text __dt__13cBgS_ShdwDrawFv */
cBgS_ShdwDraw::~cBgS_ShdwDraw() {
    /* Nonmatching */
}

/* 800841B0-8008450C       .text setShadowRealMtx__FPA4_fPA4_fPA4_fP4cXyzP4cXyzffP18dDlst_shadowPoly_cf */
void setShadowRealMtx(Mtx, Mtx, Mtx, cXyz*, cXyz*, f32, f32, dDlst_shadowPoly_c*, f32) {
    /* Nonmatching */
}

/* 8008450C-800846C8       .text set__18dDlst_shadowReal_cFUlScP8J3DModelP4cXyzffP12dKy_tevstr_c */
u32 dDlst_shadowReal_c::set(u32, s8, J3DModel*, cXyz*, f32, f32, dKy_tevstr_c*) {
    /* Nonmatching */
}

/* 800846C8-80084844       .text set2__18dDlst_shadowReal_cFUlScP8J3DModelP4cXyzffP12dKy_tevstr_c */
u32 dDlst_shadowReal_c::set2(u32, s8, J3DModel*, cXyz*, f32, f32, dKy_tevstr_c*) {
    /* Nonmatching */
}

/* 80084844-800848E8       .text add__18dDlst_shadowReal_cFP8J3DModel */
bool dDlst_shadowReal_c::add(J3DModel* model) {
    if (mModelNum == 0 || model == NULL)
        return false;

    JUT_ASSERT(0xfe0, mModelNum < MODEL_MAX);
    mpModels[mModelNum++] = model;
    return true;
}

/* 800848E8-80084AC8       .text draw__20dDlst_shadowSimple_cFv */
void dDlst_shadowSimple_c::draw() {
    /* Nonmatching */
}

/* 80084AC8-80084D48       .text set__20dDlst_shadowSimple_cFP4cXyzffP4cXyzsfP9_GXTexObj */
void dDlst_shadowSimple_c::set(cXyz*, f32, f32, cXyz*, s16, f32, _GXTexObj*) {
    /* Nonmatching */
}

/* 80084D48-80084D94       .text init__21dDlst_shadowControl_cFv */
void dDlst_shadowControl_c::init() {
    dDlst_shadowReal_c * pReal = &mReal[0];
    for (s32 i = 0; i < (s32)ARRAY_SIZE(mReal); i++, pReal++)
        pReal->init();
}

/* 80084D94-80084DEC       .text reset__21dDlst_shadowControl_cFv */
void dDlst_shadowControl_c::reset() {
    dDlst_shadowReal_c * pReal = &mReal[0];
    for (s32 i = 0; i < (s32)ARRAY_SIZE(mReal); i++, pReal++)
        pReal->reset();
    mSimpleNum = 0;
}

/* 80084DEC-80084EF0       .text imageDraw__21dDlst_shadowControl_cFPA4_f */
void dDlst_shadowControl_c::imageDraw(Mtx mtx) {
    static char l_matDL[0x80] = {};

    GXSetViewport(0.0f, 0.0f, 256.0f, 256.0f, 0.0f, 1.0f);
    GXSetScissor(0, 0, 0x100, 0x100);
    GXCallDisplayList(l_matDL, sizeof(l_matDL));
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_CLEAR);
    GXSetClipMode(GX_CLIP_DISABLE);
    GXSetTexCopySrc(0, 0, 256, 256);
    GXSetTexCopyDst(128, 128, GX_TF_I4, GX_TRUE);
    j3dSys.setDrawModeOpaTexEdge();
    dDlst_shadowReal_c * pReal = &mReal[0];
    for (s32 i = 0; i < (s32)ARRAY_SIZE(mReal); i++, pReal++)
        pReal->imageDraw(mtx);
    GXSetClipMode(GX_CLIP_ENABLE);
}

/* 80084EF0-800850D4       .text draw__21dDlst_shadowControl_cFPA4_f */
void dDlst_shadowControl_c::draw(Mtx) {
    /* Nonmatching */
}

/* 800850D4-80085170       .text setReal__21dDlst_shadowControl_cFUlScP8J3DModelP4cXyzffP12dKy_tevstr_c */
int dDlst_shadowControl_c::setReal(u32, s8, J3DModel*, cXyz*, f32, f32, dKy_tevstr_c*) {
    /* Nonmatching */
}

/* 80085170-8008520C       .text setReal2__21dDlst_shadowControl_cFUlScP8J3DModelP4cXyzffP12dKy_tevstr_c */
int dDlst_shadowControl_c::setReal2(u32, s8, J3DModel*, cXyz*, f32, f32, dKy_tevstr_c*) {
    /* Nonmatching */
}

/* 8008520C-80085274       .text addReal__21dDlst_shadowControl_cFUlP8J3DModel */
bool dDlst_shadowControl_c::addReal(u32, J3DModel*) {
    /* Nonmatching */
}

/* 80085274-800852D8       .text setSimple__21dDlst_shadowControl_cFP4cXyzffP4cXyzsfP9_GXTexObj */
int dDlst_shadowControl_c::setSimple(cXyz*, f32, f32, cXyz*, s16, f32, _GXTexObj*) {
    /* Nonmatching */
}

GXTexObj dDlst_shadowControl_c::mSimpleTexObj;

/* 800852D8-80085348       .text setSimpleTex__21dDlst_shadowControl_cFPv */
void dDlst_shadowControl_c::setSimpleTex(void* pImg) {
    GXInitTexObj(&mSimpleTexObj, pImg, 128, 128, GX_TF_I4, GX_CLAMP, GX_CLAMP, GX_FALSE);
    GXInitTexObjLOD(&mSimpleTexObj, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
}

/* 80085348-800855B4       .text draw__18dDlst_mirrorPacketFv */
void dDlst_mirrorPacket::draw() {
    /* Nonmatching */
}

/* 800855B4-80085624       .text init__18dDlst_mirrorPacketFP7ResTIMG */
void dDlst_mirrorPacket::init(ResTIMG* pImg) {
    if (pImg == NULL)
        pImg = (ResTIMG*) dComIfG_getObjectRes("Always", ALWAYS_BTI_SHMREF);

    mDoLib_setResTimgObj(pImg, &mTexObj, 0, NULL);
}

/* 80085624-80085808       .text mirrorPolygonCheck__FP4cXyzP4cXyzfP18dDlst_shadowPoly_c */
void mirrorPolygonCheck(cXyz*, cXyz*, f32, dDlst_shadowPoly_c*) {
    /* Nonmatching */
}

/* 80085808-800859DC       .text update__18dDlst_mirrorPacketFPA4_fUcf */
void dDlst_mirrorPacket::update(Mtx, u8, f32) {
    /* Nonmatching */
}

/* 800859DC-80085AF4       .text draw__20dDlst_alphaVolPacketFv */
void dDlst_alphaVolPacket::draw() {
    /* Nonmatching */
}

/* 80085AF4-80085BBC       .text draw__23dDlst_alphaInvVolPacketFv */
void dDlst_alphaInvVolPacket::draw() {
    /* Nonmatching */
}

/* 80085BBC-80085BFC       .text newData__13dDlst_peekZ_cFssPUl */
int dDlst_peekZ_c::newData(s16 x, s16 y, u32* pDst) {
    if (mCount >= 0x40)
        return 0;

    dDlst_peekZ_entry *pEntry = &mEntries[mCount];
    pEntry->x = x;
    pEntry->y = y;
    pEntry->dst = pDst;
    mCount++;
    return 1;
}

/* 80085BFC-80085C6C       .text peekData__13dDlst_peekZ_cFv */
void dDlst_peekZ_c::peekData() {
    dDlst_peekZ_entry * pEntry = &mEntries[0];
    for (s32 i = 0; i < mCount; pEntry++, i++)
        GXPeekZ(pEntry->x, pEntry->y, pEntry->dst);
    mCount = 0;
}

/* 80085C6C-80085D74       .text __ct__12dDlst_list_cFv */
dDlst_list_c::dDlst_list_c() {
    field_0x50 = &field_0x3c[ARRAY_SIZE(field_0x3c)];
    mp2DOpaTopEnd = &mp2DOpaTopArr[ARRAY_SIZE(mp2DOpaTopArr)];
    mp2DOpaEnd = &mp2DOpaArr[ARRAY_SIZE(mp2DOpaArr)];
    mp2DXluEnd = &mp2DXluArr[ARRAY_SIZE(mp2DXluArr)];
    mpOpaListSky = NULL;
    mpXluListSky = NULL;
    mpOpaListP0 = NULL;
    mpOpaListP1 = NULL;
    mpXluListP1 = NULL;
    mpOpaListBG = NULL;
    mpXluListBG = NULL;
    mpOpaList = NULL;
    mpXluList = NULL;
    mpOpaListFilter = NULL;
    mpOpaListMaskOff = NULL;
    mpXluListMaskOff = NULL;
    mpOpaListInvisible = NULL;
    mpXluListInvisible = NULL;
    mpOpaList2D = NULL;
    mpAlphaModel = NULL;
    mpSpotModel = NULL;
}

static J3DDrawBuffer * J3DDrawBuffer__create(u32 size) {
    J3DDrawBuffer * buffer = new J3DDrawBuffer();
    if (buffer != NULL) {
        if (buffer->allocBuffer(size) == 0)
            return buffer;
        delete buffer;
    }
    return NULL;
}

/* 80085F6C-800861F4       .text init__12dDlst_list_cFv */
bool dDlst_list_c::init() {
    mpOpaListSky = J3DDrawBuffer__create(0x20);
    mpXluListSky = J3DDrawBuffer__create(0x20);
    mpOpaListP0 = J3DDrawBuffer__create(1);
    mpOpaListP1 = J3DDrawBuffer__create(0x20);
    mpXluListP1 = J3DDrawBuffer__create(0x20);
    mpOpaListBG = J3DDrawBuffer__create(0x80);
    mpXluListBG = J3DDrawBuffer__create(0x80);
    mpOpaList = J3DDrawBuffer__create(0x100);
    mpXluList = J3DDrawBuffer__create(0x100);
    mpOpaListFilter = J3DDrawBuffer__create(0x20);
    mpOpaListMaskOff = J3DDrawBuffer__create(0x20);
    mpXluListMaskOff = J3DDrawBuffer__create(0x100);
    mpOpaListInvisible = J3DDrawBuffer__create(0x20);
    mpXluListInvisible = J3DDrawBuffer__create(0x20);
    mpOpaList2D = J3DDrawBuffer__create(1);

    if (mpOpaListSky == NULL || mpXluListSky == NULL || mpOpaListP0 == NULL || mpOpaListP1 == NULL || mpXluListP1 == NULL || mpOpaListBG == NULL || mpXluListBG == NULL || mpOpaList == NULL || mpXluList == NULL || mpOpaListFilter == NULL || mpOpaListMaskOff == NULL || mpXluListMaskOff == NULL || mpOpaListInvisible == NULL || mpXluListInvisible == NULL || mpOpaList2D == NULL)
        return false;

    mpOpaListSky->setNonSort();
    mpXluListSky->setNonSort();
    mpOpaListP0->setNonSort();
    mpOpaListP1->setNonSort();
    mpXluListP1->setNonSort();
    mpXluListBG->setNonSort();
    mpXluList->setZSort();
    mpOpaListFilter->setZSort();
    mpXluListMaskOff->setZSort();
    mpXluListInvisible->setZSort();
    mpOpaList2D->setNonSort();
    setOpaList();
    setXluList();
    field_0x4c = &field_0x3c[0];
    mp2DOpaTop = &mp2DOpaTopArr[0];
    mp2DOpa = &mp2DOpaArr[0];
    mp2DXlu = &mp2DXluArr[0];
    mShadowControl.init();
    mpAlphaModel = dDlst_alphaModel_c::create(0x40);
    mpSpotModel = dDlst_alphaModel_c::create(0x08);
    mpLightModel = dDlst_alphaModel_c::create(0x10);

    if (mpAlphaModel == NULL || mpSpotModel == NULL || mpLightModel == NULL)
        return false;

    return true;
}

/* 800861F4-80086368       .text __dt__12dDlst_list_cFv */
dDlst_list_c::~dDlst_list_c() {
    /* Nonmatching */
}

/* 80086368-80086490       .text reset__12dDlst_list_cFv */
void dDlst_list_c::reset() {
    mpOpaListSky->frameInit();
    mpXluListSky->frameInit();
    mpOpaListP0->frameInit();
    mpOpaListP1->frameInit();
    mpXluListP1->frameInit();
    mpOpaListBG->frameInit();
    mpXluListBG->frameInit();
    mpOpaList->frameInit();
    mpXluList->frameInit();
    mpOpaListFilter->frameInit();
    mpOpaListMaskOff->frameInit();
    mpXluListMaskOff->frameInit();
    mpOpaListInvisible->frameInit();
    mpXluListInvisible->frameInit();
    mpOpaList2D->frameInit();
    setOpaList();
    setXluList();
    field_0x4c = &field_0x3c[0];
    mp2DOpaTop = &mp2DOpaTopArr[0];
    mp2DOpa = &mp2DOpaArr[0];
    mp2DXlu = &mp2DXluArr[0];
    g_dComIfG_gameInfo.drawlist.mpAlphaModel->mNum = 0;
    g_dComIfG_gameInfo.drawlist.mpSpotModel->mNum = 0;
    g_dComIfG_gameInfo.drawlist.mpLightModel->mNum = 0;
    mShadowControl.reset();
    for (u32 i = 0; i < ARRAY_SIZE(m3DLineMatSortPacket); i++)
        m3DLineMatSortPacket[i].setMat(NULL);
}

/* 80086490-80086540       .text entryZSortXluDrawList__12dDlst_list_cFP13J3DDrawBufferP9J3DPacketR4cXyz */
void dDlst_list_c::entryZSortXluDrawList(J3DDrawBuffer* pBuffer, J3DPacket* pPacket, cXyz& pos) {
    /* Nonmatching */
    f32 z = -J3DCalcZValue(j3dSys.getViewMtx(), pos);
    u16 idx;
    if (z <= 40.05859) {
        idx = 0;
    } else if (z >= 9960.941f) {
        idx = 0xFF;
    } else {
        idx = z / 39.05859;
    }
    pBuffer->entryImm(pPacket, 0xFF - z);
}

/* 80086540-80086570       .text set__12dDlst_list_cFRPP12dDlst_base_cRPP12dDlst_base_cP12dDlst_base_c */
bool dDlst_list_c::set(dDlst_base_c**& pList, dDlst_base_c**& pEnd, dDlst_base_c* pItem) {
    if (pList >= pEnd)
        return false;

    *pList = pItem;
    pList++;
    return true;
}

/* 80086570-800865C8       .text draw__12dDlst_list_cFPP12dDlst_base_cPP12dDlst_base_c */
void dDlst_list_c::draw(dDlst_base_c** pList, dDlst_base_c** pEnd) {
    for (; pList < pEnd; pList++)
        (*pList)->draw();
}

/* 800865C8-800866C8       .text wipeIn__12dDlst_list_cFfR8_GXColor */
void dDlst_list_c::wipeIn(f32, _GXColor&) {
    /* Nonmatching */
}

/* 800866C8-800866F0       .text wipeIn__12dDlst_list_cFf */
void dDlst_list_c::wipeIn(f32 time) {
    wipeIn(-time, g_blackColor);
}

/* 800866F0-80086790       .text calcWipe__12dDlst_list_cFv */
void dDlst_list_c::calcWipe() {
    /* Nonmatching */
}

/* 80086790-8008696C       .text dDlst_texSpecmapST__FPC4cXyzPC12dKy_tevstr_cP12J3DModelDataf */
void dDlst_texSpecmapST(const cXyz*, const dKy_tevstr_c*, J3DModelData*, f32) {
    /* Nonmatching */
}

/* 80086AD0-80086AD8       .text getTri__22dDlst_shadowRealPoly_cFv */
dDlst_shadowTri_c * dDlst_shadowRealPoly_c::getTri() {
    return mShadowTri;
}

/* 80086AD8-80086AE0       .text getTriMax__22dDlst_shadowRealPoly_cFv */
s32 dDlst_shadowRealPoly_c::getTriMax() {
    return ARRAY_SIZE(mShadowTri);
}
