//
// Generated by dtk
// Translation Unit: d_kankyo_rain.cpp
//

#include "d/d_kankyo_rain.h"
#include "d/d_bg_s_gnd_chk.h"
#include "d/d_com_inf_game.h"
#include "d/d_kankyo.h"
#include "d/d_kankyo_wether.h"
#include "f_op/f_op_camera_mng.h"
#include "m_Do/m_Do_lib.h"

/* 8008AA30-8008AB3C       .text vectle_calc__FP10DOUBLE_POSP4cXyz */
void vectle_calc(DOUBLE_POS* i_pos, cXyz* o_out) {
    double s = sqrt(i_pos->x * i_pos->x + i_pos->y * i_pos->y + i_pos->z * i_pos->z);

    if (s != 0.0) {
        o_out->x = i_pos->x / s;
        o_out->y = i_pos->y / s;
        o_out->z = i_pos->z / s;
    } else {
        o_out->x = 0.0;
        o_out->y = 0.0;
        o_out->z = 0.0;
    }
}

/* 8008AB3C-8008AB94       .text get_vectle_calc__FP4cXyzP4cXyzP4cXyz */
void get_vectle_calc(cXyz* param_0, cXyz* param_1, cXyz* param_2) {
    DOUBLE_POS pos;
    pos.x = param_1->x - param_0->x;
    pos.y = param_1->y - param_0->y;
    pos.z = param_1->z - param_0->z;

    vectle_calc(&pos, param_2);
}

/* 8008AB94-8008ABB4       .text dKyr_get_vectle_calc__FP4cXyzP4cXyzP4cXyz */
void dKyr_get_vectle_calc(cXyz* param_0, cXyz* param_1, cXyz* param_2) {
    get_vectle_calc(param_0, param_1, param_2);
}

/* 8008ABB4-8008AC64       .text dKy_set_eyevect_calc__FP12camera_classP3Vecff */
void dKy_set_eyevect_calc(camera_class* i_camera, Vec* param_1, f32 param_2, f32 param_3) {
    cXyz tmp;
    get_vectle_calc(&i_camera->mLookat.mEye, &i_camera->mLookat.mCenter, &tmp);
    param_1->x = i_camera->mLookat.mEye.x + tmp.x * param_2;
    param_1->y = (i_camera->mLookat.mEye.y + tmp.y * param_3) - 200.0f;
    param_1->z = i_camera->mLookat.mEye.z + tmp.z * param_2;
}

/* 8008AC64-8008AD60       .text dKy_set_eyevect_calc2__FP12camera_classP3Vecff */
void dKy_set_eyevect_calc2(camera_class* i_camera, Vec* param_1, f32 param_2, f32 param_3) {
    cXyz tmp;
    DOUBLE_POS pos;

    pos.x = i_camera->mLookat.mCenter.x - i_camera->mLookat.mEye.x;
    if (param_3 != 0.0f) {
        pos.y = i_camera->mLookat.mCenter.y - i_camera->mLookat.mEye.y;
    } else {
        pos.y = 0.0f;
    }
    pos.z = i_camera->mLookat.mCenter.z - i_camera->mLookat.mEye.z;

    vectle_calc(&pos, &tmp);

    param_1->x = i_camera->mLookat.mEye.x + tmp.x * param_2;
    param_1->y = i_camera->mLookat.mEye.y + tmp.y * param_3;
    param_1->z = i_camera->mLookat.mEye.z + tmp.z * param_2;

    if (param_3 == 0.0f) {
        param_1->y = 0.0f;
    }
}

static inline void dKyr_init_btitex(GXTexObj* i_obj, ResTIMG* i_img) {
    GXInitTexObj(i_obj, (&i_img->format + i_img->imageOffset), i_img->width, i_img->height,
                 (GXTexFmt)i_img->format, (GXTexWrapMode)i_img->wrapS, (GXTexWrapMode)i_img->wrapT,
                 (GXBool)(i_img->mipmapCount > 1));
}

/* 8008AD60-8008AE54       .text dKyr_set_btitex__FP9_GXTexObjP7ResTIMG */
void dKyr_set_btitex(GXTexObj* i_obj, ResTIMG* i_img) {
    GXInitTexObj(i_obj, (&i_img->format + i_img->imageOffset), i_img->width, i_img->height,
                 (GXTexFmt)i_img->format, (GXTexWrapMode)i_img->wrapS, (GXTexWrapMode)i_img->wrapT,
                 (GXBool)(i_img->mipmapCount > 1));

    GXInitTexObjLOD(i_obj, (GXTexFilter)i_img->minFilter, (GXTexFilter)i_img->magFilter,
                    i_img->minLOD * 0.125f, i_img->maxLOD * 0.125f, i_img->LODBias * 0.01f,
                    (GXBool)i_img->biasClamp, (GXBool)i_img->doEdgeLOD,
                    (GXAnisotropy)i_img->maxAnisotropy);

    GXLoadTexObj(i_obj, GX_TEXMAP0);
}

/* 8008AE54-8008B44C       .text dKyr_kamome_move__Fv */
void dKyr_kamome_move() {
    /* Nonmatching */
}

/* 8008B44C-8008B504       .text dKyr_wind_init__Fv */
void dKyr_wind_init() {
    g_env_light.mpWind->mbHasCustomWindPower = false;
    g_env_light.mpWind->field_0x759 = 0;

    for (int i = 0; i < 2; i++) {
        g_env_light.mpWind->mKamomeEff[i].field_0x1e = 0;
        g_env_light.mpWind->mKamomeEff[i].field_0x18 = 0.0f;
        g_env_light.mpWind->mKamomeEff[i].field_0x1c = cM_rndF(1800.0f);
        g_env_light.mpWind->mKamomeEff[i].mpBaseEmitter = NULL;
    }
}

/* 8008B504-8008C4BC       .text dKyr_wind_move__Fv */
void dKyr_wind_move() {
    /* Nonmatching */
}

/* 8008C624-8008C888       .text dKyr_lenzflare_move__Fv */
// NONMATCHING
void dKyr_lenzflare_move() {
    dKankyo_sun_Packet* sun_p = g_env_light.mpSunPacket;
    dKankyo_sunlenz_Packet* lenz_p = g_env_light.mpSunlenzPacket;
    camera_class* camera_p = dComIfGp_getCamera(0);

    if (!(g_env_light.mpSunPacket->mVisibility < 0.0001f)) {
        cXyz eyeVect;
        dKy_set_eyevect_calc(dComIfGp_getCamera(0), &eyeVect, 7200.0005f, 7200.0005f);

        cXyz sunDirSmth;
        dKyr_get_vectle_calc(&eyeVect, sun_p->mPos, &sunDirSmth);
        lenz_p->mPositions[0] = sun_p->mPos[0];
        lenz_p->mPositions[1] = sun_p->mPos[0];

        cXyz projected;
        mDoLib_project(lenz_p->mPositions, &projected);

        cXyz center;
        center.x = 320.0f;
        center.y = 240.0f;
        center.z = 0.0f;

        cXyz vectle;
        dKyr_get_vectle_calc(&center, &projected, &vectle);
        s16 angle = cM_atan2s(vectle.x, vectle.y);

        lenz_p->mAngleDeg = angle;
        lenz_p->mAngleDeg *= 0.005493164f;
        lenz_p->mAngleDeg += 180.0f;

        cXyz camFwd;
        dKyr_get_vectle_calc(&camera_p->mLookat.mEye, &camera_p->mLookat.mCenter, &camFwd);

        f32 var_f4 = sunDirSmth.abs(camFwd);
        var_f4 = (var_f4 * 350.0f) + 250.0f;

        for (int i = 2; i < 8; i++) {
            lenz_p->mPositions[i].x = sun_p->mPos[0].x - i * sunDirSmth.x * var_f4;
            lenz_p->mPositions[i].y = sun_p->mPos[0].y - i * sunDirSmth.y * var_f4;
            lenz_p->mPositions[i].z = sun_p->mPos[0].z - i * sunDirSmth.z * var_f4;
        }
    }
}

/* 8008C888-8008C8B8       .text dKyr_moon_arrival_check__Fv */
BOOL dKyr_moon_arrival_check() {
    /* Nonmatching */
}

/* 8008C8B8-8008CF68       .text dKyr_sun_move__Fv */
void dKyr_sun_move() {
    /* Nonmatching */
}

/* 8008CF68-8008D0B4       .text dKyr_rain_init__Fv */
void dKyr_rain_init() {
    /* Nonmatching */
}

/* 8008D0B4-8008D0DC       .text rain_bg_chk__FP19dKankyo_rain_Packeti */
void rain_bg_chk(dKankyo_rain_Packet*, int) {
    /* Nonmatching */
}

/* 8008D0DC-8008D53C       .text overhead_bg_chk__Fv */
void overhead_bg_chk() {
    /* Nonmatching */
}

/* 8008D638-8008DAF0       .text forward_overhead_bg_chk__FP4cXyzf */
void forward_overhead_bg_chk(cXyz*, f32) {
    /* Nonmatching */
}

/* 8008DAF0-8008E79C       .text dKyr_rain_move__Fv */
void dKyr_rain_move() {
    /* Nonmatching */
}

/* 8008E79C-8008F0BC       .text dKyr_housi_move__Fv */
void dKyr_housi_move() {
    /* Nonmatching */
}

/* 8008F0BC-8008F23C       .text dKyr_snow_init__Fv */
void dKyr_snow_init() {
    /* Nonmatching */
}

/* 8008F23C-8008F9FC       .text dKyr_snow_move__Fv */
void dKyr_snow_move() {
    /* Nonmatching */
}

/* 8008F9FC-8009065C       .text dKyr_kazanbai_move__Fv */
void dKyr_kazanbai_move() {
    /* Nonmatching */
}

/* 8009065C-80090C68       .text dKyr_kazanbai_tamari_move__Fv */
void dKyr_kazanbai_tamari_move() {
    /* Nonmatching */
}

/* 80090C68-80090D50       .text dKyr_star_init__Fv */
void dKyr_star_init() {
    /* Nonmatching */
}

/* 80090D50-80090DE0       .text dKyr_star_move__Fv */
void dKyr_star_move() {
    /* Nonmatching */
}

/* 80090DE0-80091964       .text wave_move__Fv */
void wave_move() {
    /* Nonmatching */
}

/* 80091964-80092294       .text cloud_shadow_move__Fv */
void cloud_shadow_move() {
    /* Nonmatching */
}

/* 80092294-80092310       .text light_at_hit_check__FP4cXyz */
void light_at_hit_check(cXyz*) {
    /* Nonmatching */
}

/* 80092310-80092330       .text dKyr_poison_live_check__Fv */
BOOL dKyr_poison_live_check() {
    /* Nonmatching */
}

/* 80092330-80092448       .text dKyr_poison_light_colision__Fv */
void dKyr_poison_light_colision() {
    /* Nonmatching */
}

/* 80092448-8009258C       .text poison_init__Fv */
void poison_init() {
    /* Nonmatching */
}

/* 8009258C-800937BC       .text poison_move__Fv */
void poison_move() {
    /* Nonmatching */
}

/* 800937BC-800940D4       .text vrkumo_move__Fv */
void vrkumo_move() {
    /* Nonmatching */
}

/* 800940D4-80094144       .text dKy_wave_chan_init__Fv */
void dKy_wave_chan_init() {
    g_env_light.mWaveChan.field_0x0 = -1.0f;
    g_env_light.mWaveChan.field_0x4 = 0.0f;
    g_env_light.mWaveChan.field_0x8 = 0.0f;
    g_env_light.mWaveChan.mWaveSpeed = 0.1f;
    g_env_light.mWaveChan.mWaveSpawnDist = 3000.0f;
    g_env_light.mWaveChan.mWaveSpawnRadius = 3150.0f;
    g_env_light.mWaveChan.mWaveScale = 250.0f;
    g_env_light.mWaveChan.mWaveScaleRand = 0.217f;
    g_env_light.mWaveChan.mWaveCounterSpeedScale = 1.6f;
    g_env_light.mWaveChan.mWaveScaleBottom = 5.0f;
    g_env_light.mWaveChan.mWaveCount = 0;
    g_env_light.mWaveChan.mWaveReset = 0;
    g_env_light.mWaveChan.field_0x2f = 0;
}

/* 80094144-8009428C       .text snap_sunmoon_proc__FP4cXyzi */
void snap_sunmoon_proc(cXyz*, int) {
    /* Nonmatching */
}

/* 8009428C-8009514C       .text dKyr_drawSun__FPA4_fP4cXyzR8GXColorPPUc */
void dKyr_drawSun(Mtx, cXyz*, GXColor&, u8**) {
    /* Nonmatching */
}

/* 8009514C-80095E8C       .text dKyr_drawLenzflare__FPA4_fP4cXyzR8GXColorPPUc */
void dKyr_drawLenzflare(Mtx, cXyz*, GXColor&, u8**) {
    /* Nonmatching */
}

/* 80095E8C-8009682C       .text dKyr_drawRain__FPA4_fPPUc */
void dKyr_drawRain(Mtx, u8**) {
    /* Nonmatching */
}

/* 8009682C-80096D18       .text dKyr_drawSibuki__FPA4_fPPUc */
void dKyr_drawSibuki(Mtx drawMtx, u8** pImg) {
    dKankyo_rain_Packet * pPkt = g_env_light.mpRainPacket;
    camera_class *pCamera = dComIfGp_getCamera(0);

    if (g_env_light.mSnowCount != 0 || dComIfGd_getView() == NULL)
        return;

    Mtx camMtx;
    MTXInverse(dComIfGd_getViewRotMtx(), camMtx);

    f32 alpha = 200.0f;
    if (pPkt->mStatus & 1)
        alpha = 0.0f;

    cLib_addCalc(&pPkt->mSibukiAlpha, alpha, 0.2f, 30.0f, 0.001f);

    cXyz eyevect, camDir;
    dKy_set_eyevect_calc(pCamera, &eyevect, 7000.0f, 4000.0f);
    dKyr_get_vectle_calc(&pCamera->mLookat.mEye, &pCamera->mLookat.mCenter, &camDir);

    float alphaFade = 0.0f;
    if (camDir.y <= 0.0f)
        alphaFade = 1.0f;
    else if (camDir.y < 0.5f)
        alphaFade = 1.0f - (camDir.y / 0.5f);

    GXColor color = { 0xB4, 0xC8, 0xC8, 0x00 };
    color.a = (u8)(pPkt->mSibukiAlpha * alphaFade);

    GXTexObj texObj;
    dKyr_init_btitex(&texObj, (ResTIMG*)pImg[1]);
    GXLoadTexObj(&texObj, GX_TEXMAP0);

    GXSetNumChans(0);
    GXSetTevColor(GX_TEVREG0, color);
    GXSetTevColor(GX_TEVREG1, color);
    GXSetNumTexGens(1);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, false, GX_PTIDENTITY);
    GXSetNumTevStages(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_C1, GX_CC_C0, GX_CC_TEXC, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_A0, GX_CA_TEXA, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRC_ALPHA, GX_BL_INV_SRC_ALPHA, GX_LO_SET);
    GXSetAlphaCompare(GX_GREATER, 0, GX_AOP_OR, GX_GREATER, 0);
    GXSetZMode(true, GX_GEQUAL, false);
    GXSetCullMode(GX_CULL_NONE);
    GXSetClipMode(GX_CLIP_DISABLE);
    GXSetNumIndStages(0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_S16, 8);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXLoadPosMtxImm(drawMtx, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);

    f32 scale;
    if (dComIfGd_getView() == NULL) {
        scale = 0.2f;
    } else {
        scale = dComIfGd_getView()->mFovy / 20.0f;
        if (scale >= 1.0f)
            scale = 1.0f;
        scale = 1.0f - scale;
    }

    for (s32 i = 0; i < g_env_light.mRainCount / 2; i++) {
        f32 size = 20.0f + scale * cM_rndF(25.0f);

        f32 x = eyevect.x + cM_rndFX(3600.0f);
        f32 y = eyevect.y + cM_rndFX(1500.0f);
        f32 z = eyevect.z + cM_rndFX(3600.0f);

        f32 x0 = x - size, x1 = x + size;
        f32 z0 = z - size, z1 = z + size;

        cXyz p0( x0, y, z0 );
        cXyz p1( x1, y, z0 );
        cXyz p2( x1, y, z1 );
        cXyz p3( x0, y, z1 );

        GXBegin(GX_QUADS, GX_VTXFMT0, 4);
        GXPosition3f32(p0.x, p0.y, p0.z);
        GXTexCoord2s16(0, 0);
        GXPosition3f32(p1.x, p1.y, p1.z);
        GXTexCoord2s16(0x1FF, 0);
        GXPosition3f32(p2.x, p2.y, p2.z);
        GXTexCoord2s16(0x1FF, 0x1FF);
        GXPosition3f32(p3.x, p3.y, p3.z);
        GXTexCoord2s16(0, 0x1FF);
        i_GXEnd();
    }

    GXSetClipMode(GX_CLIP_ENABLE);
    J3DShape::sOldVcdVatCmd = NULL;
}

/* 80096D18-800973CC       .text drawPoison__FPA4_fPPUc */
void drawPoison(Mtx, u8**) {
    /* Nonmatching */
}

/* 800973CC-80097AD0       .text dKyr_drawHousi__FPA4_fPPUc */
void dKyr_drawHousi(Mtx, u8**) {
    /* Nonmatching */
}

/* 80097AD0-800987B8       .text dKyr_drawKazanbai__FPA4_fPPUc */
void dKyr_drawKazanbai(Mtx, u8**) {
    /* Nonmatching */
}

/* 800987B8-80098FF0       .text dKyr_drawSnow__FPA4_fPPUc */
void dKyr_drawSnow(Mtx, u8**) {
    /* Nonmatching */
}

/* 80098FF0-80099D38       .text dKyr_drawStar__FPA4_fPPUc */
void dKyr_drawStar(Mtx, u8**) {
    /* Nonmatching */
}

/* 80099D38-8009A5D4       .text drawWave__FPA4_fPPUc */
void drawWave(Mtx, u8**) {
    /* Nonmatching */
}

/* 8009A5D4-8009AB88       .text drawCloudShadow__FPA4_fPPUc */
void drawCloudShadow(Mtx, u8**) {
    /* Nonmatching */
}

/* 8009AB88-8009B9C4       .text drawVrkumo__FPA4_fR8GXColorPPUc */
void drawVrkumo(Mtx, GXColor&, u8**) {
    /* Nonmatching */
}

/* 8009B9C4-8009B9D8       .text dKyr_thunder_init__Fv */
void dKyr_thunder_init() {
    g_env_light.mThunderEff.mStateTimer = 0;
}

/* 8009B9D8-8009BDEC       .text dKyr_thunder_move__Fv */
void dKyr_thunder_move() {
    /* Nonmatching */
}
