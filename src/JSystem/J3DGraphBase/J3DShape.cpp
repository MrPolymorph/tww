//
// Generated by dtk
// Translation Unit: J3DShape.cpp
//

#include "JSystem/J3DGraphBase/J3DShape.h"
#include "JSystem/J3DGraphBase/J3DPacket.h"
#include "JSystem/J3DGraphBase/J3DSys.h"
#include "JSystem/J3DGraphBase/J3DVertex.h"
#include "dolphin/gd/GDBase.h"
#include "dolphin/gd/GDGeometry.h"
#include "dolphin/os/OS.h"
#include "dolphin/types.h"

extern void J3DGDSetVtxAttrFmtv(_GXVtxFmt, GXVtxAttrFmtList *, bool);
extern void J3DFifoLoadPosMtxImm(Mtx, u32);
extern void J3DFifoLoadNrmMtxImm(Mtx, u32);

/* 802DD18C-802DD1FC       .text initialize__8J3DShapeFv */

void J3DShape::initialize() {
    mMaterial = NULL;
    mIndex = -1;
    mMtxGroupNum = 0;
    mFlags = 0;
    mRadius = 0.0f;
    mMin.x = 0.0f;
    mMin.y = 0.0f;
    mMin.z = 0.0f;
    mMax.x = 0.0f;
    mMax.y = 0.0f;
    mMax.z = 0.0f;
    mVtxDesc = NULL;
    mShapeMtx = NULL;
    mShapeDraw = NULL;
    mVertexData = NULL;
    mDrawMtxData = NULL;
    mScaleFlagArray = NULL;
    mDrawMtx = NULL;
    mNrmMtx = NULL;
    mCurrentViewNo = &j3dDefaultViewNo;
    mHasNBT = false;
    mHasPNMTXIdx = false;
}

/* 802DD1FC-802DD27C       .text calcNBTScale__8J3DShapeFRC3VecPA3_A3_fPA3_A3_f */
void J3DShape::calcNBTScale(Vec const& scale, Mtx33* pSrc, Mtx33* pDst) {
    for (u16 i = 0; i < getMtxGroupNum(); i++)
        getShapeMtx(i)->calcNBTScale(scale, pSrc, pDst);
}

/* 802DD27C-802DD2F0       .text countBumpMtxNum__8J3DShapeCFv */
u32 J3DShape::countBumpMtxNum() const {
    u32 num = 0;
    for (u16 i = 0; i < getMtxGroupNum(); i++)
        num += getShapeMtx(i)->getUseMtxNum();
    return num;
}

/* 802DD2F0-802DD308       .text J3DLoadCPCmd__FUcUl */
void J3DLoadCPCmd(u8 cmd, u32 param) {
    GFX_FIFO(u8) = GX_CMD_LOAD_CP_REG;
    GFX_FIFO(u8) = cmd;
    GFX_FIFO(u32) = param;
}

/* 802DD308-802DD344       .text J3DLoadArrayBasePtr__F7_GXAttrPv */
static void J3DLoadArrayBasePtr(_GXAttr attr, void* data) {
    u32 idx = (attr == GX_VA_NBT) ? 1 : (attr - GX_VA_POS);
    J3DLoadCPCmd(0xA0 + idx, ((u32)data & 0x7FFFFFFF));
}

/* 802DD344-802DD3B4       .text loadVtxArray__8J3DShapeCFv */
void J3DShape::loadVtxArray() const {
    J3DLoadArrayBasePtr(GX_VA_POS, j3dSys.getVtxPos());
    if (!mHasNBT) {
        J3DLoadArrayBasePtr(GX_VA_NRM, j3dSys.getVtxNrm());
    }
    J3DLoadArrayBasePtr(GX_VA_CLR0, j3dSys.getVtxCol());
}

/* 802DD3B4-802DD3F0       .text isSameVcdVatCmd__8J3DShapeFP8J3DShape */
bool J3DShape::isSameVcdVatCmd(J3DShape* other) {
    u8* a = other->mVcdVatCmd;
    u8* b = mVcdVatCmd;
    for (u32 i = 0; i < kVcdVatDLSize; i++)
        if (a[i] != b[i])
            return false;
    return true;
}

/* 802DD3F0-802DD6B8       .text makeVtxArrayCmd__8J3DShapeFv */
void J3DShape::makeVtxArrayCmd() {
    GXVtxAttrFmtList* vtxAttr = mVertexData->getVtxAttrFmtList();

    u8 stride[0x0C];
    void* array[0x0C];
    for (u32 i = 0; i < 0x0C; i++) {
        stride[i] = 0;
        array[i] = 0;
    }

    for (; vtxAttr->mAttrib != GX_VA_NULL; vtxAttr++) {
        switch (vtxAttr->mAttrib) {
        case GX_VA_POS: {
            if (vtxAttr->mCompType == GX_F32)
                stride[vtxAttr->mAttrib - GX_VA_POS] = 0x0C;
            else
                stride[vtxAttr->mAttrib - GX_VA_POS] = 0x06;
            array[vtxAttr->mAttrib - GX_VA_POS] = mVertexData->getVtxPosArray();
            mVertexData->setVtxPosFrac(vtxAttr->mCompShift);
            mVertexData->setVtxPosType((GXCompType)vtxAttr->mCompType);
        } break;
        case GX_VA_NRM: {
            if (vtxAttr->mCompType == GX_F32)
                stride[vtxAttr->mAttrib - GX_VA_POS] = 0x0C;
            else
                stride[vtxAttr->mAttrib - GX_VA_POS] = 0x06;
            array[vtxAttr->mAttrib - GX_VA_POS] = mVertexData->getVtxNrmArray();
            mVertexData->setVtxNrmFrac(vtxAttr->mCompShift);
            mVertexData->setVtxNrmType((GXCompType)vtxAttr->mCompType);
        } break;
        case GX_VA_CLR0:
        case GX_VA_CLR1: {
            stride[vtxAttr->mAttrib - GX_VA_POS] = 0x04;
            array[vtxAttr->mAttrib - GX_VA_POS] =
                mVertexData->getVtxColorArray(vtxAttr->mAttrib - GX_VA_CLR0);
        } break;
        case GX_VA_TEX0:
        case GX_VA_TEX1:
        case GX_VA_TEX2:
        case GX_VA_TEX3:
        case GX_VA_TEX4:
        case GX_VA_TEX5:
        case GX_VA_TEX6:
        case GX_VA_TEX7: {
            if (vtxAttr->mCompType == GX_F32)
                stride[vtxAttr->mAttrib - GX_VA_POS] = 0x08;
            else
                stride[vtxAttr->mAttrib - GX_VA_POS] = 0x04;
            array[vtxAttr->mAttrib - GX_VA_POS] = mVertexData->getVtxTexCoordArray(vtxAttr->mAttrib - GX_VA_TEX0);
        } break;
        default:
            break;
        }
    }

    GXVtxDescList* vtxDesc = mVtxDesc;
    mHasPNMTXIdx = false;
    for (; vtxDesc->attr != GX_VA_NULL; vtxDesc++) {
        if (vtxDesc->attr == GX_VA_NBT && vtxDesc->type != GX_NONE) {
            mHasNBT = true;
            stride[GX_VA_NRM - GX_VA_POS] *= 3;
            array[GX_VA_NRM - GX_VA_POS] = mVertexData->getVtxNBTArray();
        }

        if (vtxDesc->attr == GX_VA_PNMTXIDX && vtxDesc->type != GX_NONE) {
            mHasPNMTXIdx = true;
        }
    }

    for (s32 i = 0; i < 0x0C; i++) {
        if (array[i] != 0)
            GDSetArray((GXAttr)(i + GX_VA_POS), array[i], stride[i]);
        else
            GDSetArrayRaw((GXAttr)(i + GX_VA_POS), NULL, stride[i]);
    }
}

/* 802DD6B8-802DD72C       .text makeVcdVatCmd__8J3DShapeFv */
void J3DShape::makeVcdVatCmd() {
    GDLObj gdl_obj;
    GDInitGDLObj(&gdl_obj, mVcdVatCmd, kVcdVatDLSize);
    GDSetCurrent(&gdl_obj);
    GDSetVtxDescv(mVtxDesc);
    makeVtxArrayCmd();
    J3DGDSetVtxAttrFmtv(GX_VTXFMT0, mVertexData->getVtxAttrFmtList(), mHasNBT);
    GDPadCurr32();
    GDFlushCurrToMem();
    GDSetCurrent(NULL);
}

void* J3DShape::sOldVcdVatCmd;

/* 802DD72C-802DD7CC       .text loadPreDrawSetting__8J3DShapeCFv */
void J3DShape::loadPreDrawSetting() const {
    if (sOldVcdVatCmd != mVcdVatCmd) {
        GXCallDisplayList(mVcdVatCmd, kVcdVatDLSize);
        sOldVcdVatCmd = mVcdVatCmd;
    }

    mCurrentMtx.load();
}

u8 J3DShape::sEnvelopeFlag;

/* 802DD7CC-802DD874       .text setArrayAndBindPipeline__8J3DShapeCFv */
void J3DShape::setArrayAndBindPipeline() const {
    J3DShapeMtx::setCurrentPipeline(getPipeline());
    loadVtxArray();
    j3dSys.setModelDrawMtx(mDrawMtx[*mCurrentViewNo]);
    j3dSys.setModelNrmMtx(mNrmMtx[*mCurrentViewNo]);
    J3DShapeMtx::sCurrentScaleFlag = mScaleFlagArray;
    J3DShapeMtx::sNBTFlag = mHasNBT;
    J3DShape::sEnvelopeFlag = mHasPNMTXIdx;
}

/* 802DD874-802DD9FC       .text drawFast__8J3DShapeCFv */
void J3DShape::drawFast() const {
    if (sOldVcdVatCmd != mVcdVatCmd) {
        GXCallDisplayList(mVcdVatCmd, kVcdVatDLSize);
        sOldVcdVatCmd = mVcdVatCmd;
    }

    if (sEnvelopeFlag != 0 && !mHasPNMTXIdx)
        mCurrentMtx.load();

    setArrayAndBindPipeline();
    if (!checkFlag(J3DShpFlag_NoMtx)) {
        for (u16 i = 0; i < getMtxGroupNum(); i++) {
            if (getShapeMtx(i) != NULL)
                getShapeMtx(i)->load();
            if (getShapeDraw(i) != NULL)
                getShapeDraw(i)->draw();
        }
    } else {
        J3DFifoLoadPosMtxImm(*j3dSys.getShapePacket()->getBaseMtxPtr(), GX_PNMTX0);
        J3DFifoLoadNrmMtxImm(*j3dSys.getShapePacket()->getBaseMtxPtr(), GX_PNMTX0);
        for (u16 i = 0; i < getMtxGroupNum(); i++)
            if (getShapeDraw(i) != NULL)
                getShapeDraw(i)->draw();
    }
}

/* 802DD9FC-802DDA44       .text draw__8J3DShapeCFv */
void J3DShape::draw() const {
    sOldVcdVatCmd = NULL;
    loadPreDrawSetting();
    drawFast();
}

/* 802DDA44-802DDAC8       .text simpleDraw__8J3DShapeCFv */
void J3DShape::simpleDraw() const {
    resetVcdVatCache();
    loadPreDrawSetting();
    J3DShapeMtx::setCurrentPipeline(getPipeline());
    loadVtxArray();
    for (u16 i = 0; i < getMtxGroupNum(); i++) {
        if (getShapeDraw(i) != NULL) {
            getShapeDraw(i)->draw();
        }
    }
}

/* 802DDAC8-802DDBC4       .text simpleDrawCache__8J3DShapeCFv */
void J3DShape::simpleDrawCache() const {
    if (sOldVcdVatCmd != mVcdVatCmd) {
        GXCallDisplayList(mVcdVatCmd, kVcdVatDLSize);
        sOldVcdVatCmd = mVcdVatCmd;
    }

    if (sEnvelopeFlag != 0 && !mHasPNMTXIdx)
        mCurrentMtx.load();

    loadVtxArray();
    for (u16 i = 0; i < getMtxGroupNum(); i++)
        if (getShapeDraw(i) != NULL)
            getShapeDraw(i)->draw();
}
