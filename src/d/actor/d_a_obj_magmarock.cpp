/**
 * d_a_obj_magmarock.cpp
 * Object - Dragon Roost Cavern - Lava slab
 */

#include "d/dolzel_rel.h" // IWYU pragma: keep
#include "d/actor/d_a_obj_magmarock.h"

#include "d/d_bg_s_movebg_actor.h"
#include "d/d_lib.h"
#include "d/d_procname.h"
#include "d/d_priority.h"
#include "d/d_s_play.h"

const char daObjMagmarock::Act_c::M_arcname[6] = "Kyjim";

/* 00000078-00000128       .text set_mtx__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::set_mtx() {
    /* Nonmatching */
}

/* 00000128-00000258       .text demo_move__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::demo_move() {
    /* Nonmatching */
}

/* 00000258-00000410       .text ControlEffect__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::ControlEffect() {
    /* Nonmatching */
}

/* 0000044C-00000560       .text play_anim__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::play_anim() {
    /* Nonmatching */
}

/* 00000560-0000058C       .text appear_proc_init__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::appear_proc_init() {
    /* Nonmatching */
}

/* 0000058C-000005EC       .text appear_proc__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::appear_proc() {
    /* Nonmatching */
}

/* 000005EC-00000618       .text wait_proc_init__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::wait_proc_init() {
    /* Nonmatching */
}

/* 00000618-00000644       .text wait_proc__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::wait_proc() {
    /* Nonmatching */
}

/* 00000644-000006E0       .text stay_proc_init__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::stay_proc_init() {
    /* Nonmatching */
}

/* 000006E0-00000720       .text stay_proc__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::stay_proc() {
    /* Nonmatching */
}

/* 00000720-000007B8       .text quake_proc_init__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::quake_proc_init() {
    /* Nonmatching */
}

/* 000007B8-0000084C       .text quake_proc__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::quake_proc() {
    /* Nonmatching */
}

/* 0000084C-00000878       .text vanish_proc_init__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::vanish_proc_init() {
    /* Nonmatching */
}

/* 00000878-000008F8       .text vanish_proc__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::vanish_proc() {
    /* Nonmatching */
}

/* 000008F8-00000AEC       .text ride_call_back__14daObjMagmarockFP4dBgWP10fopAc_ac_cP10fopAc_ac_c */
void daObjMagmarock::ride_call_back(dBgW*, fopAc_ac_c*, fopAc_ac_c*) {
    /* Nonmatching */
}

/* 00000AEC-00000B0C       .text CheckCreateHeap__14daObjMagmarockFP10fopAc_ac_c */
BOOL daObjMagmarock::CheckCreateHeap(fopAc_ac_c* i_this) {
    daObjMagmarock::Act_c* a_this = (daObjMagmarock::Act_c*)i_this;
    a_this->CreateHeap();
}

/* 00000B0C-00000DA0       .text CreateHeap__Q214daObjMagmarock5Act_cFv */
BOOL daObjMagmarock::Act_c::CreateHeap() {
    /* Nonmatching */
    BOOL ret = FALSE;
    J3DModelData* modelData = (J3DModelData*)dComIfG_getObjectRes(M_arcname, 9);
    if (modelData == NULL) {
        JUT_ASSERT(0x14D, modelData != 0);
    }
    field_0x2F4 = mDoExt_J3DModel__create(modelData, 0, 0x11020203);
    M_brk = (mDoExt_brkAnm*)dComIfG_getObjectRes(M_arcname, 0xC);
    M_bck = (mDoExt_bckAnm*)dComIfG_getObjectRes(M_arcname, 6);
    if (M_brk == NULL) {
        JUT_ASSERT(0x155, M_brk != NULL);
    }
    if (M_bck == NULL) {
        JUT_ASSERT(0x156, M_bck != NULL);
    }
    int brkInitVal = M_brk->init(modelData, &field_0x2F8, FALSE, J3DFrameCtrl::EMode_LOOP, 1.0f, 0, -1, false, 0);
    int bckInittVal = M_bck->init(modelData, &field_0x314, FALSE, J3DFrameCtrl::EMode_LOOP, 1.0f, 0, -1, false);
    PSMTXTrans(mDoMtx_stack_c::now, current.pos.x, current.pos.y, current.pos.z);
    mDoMtx_stack_c::YrotM(shape_angle.y);
    mDoMtx_stack_c::scaleM(scale.x, scale.y, scale.z);
    PSMTXCopy(mDoMtx_stack_c::now, field_0x328);
    cBgD_t* cBgDt = (cBgD_t *)dComIfG_getObjectRes(M_arcname, 0xF);
    dBgW* dbgw = dBgW_NewSet(cBgDt, dBgW::MOVE_BG_e, &field_0x328);
    field_0x358 = dbgw;
    field_0x358->m_crr_func = dBgS_MoveBGProc_Typical;
    if (field_0x358 == NULL) {
        ret = FALSE;
    }else {
        ret = FALSE;
        if (field_0x2F4 != NULL && brkInitVal != 0 && bckInittVal != 0) {
            ret = TRUE;
        }
    }
    return ret;
}

GXColor default_color = {0, 0, 0, 0};
/* 00000DA0-000013B4       .text CreateInit__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::CreateInit() {
    /* Nonmatching */
    scale.setall(1.0f);
    cullMtx = field_0x2F4->getBaseTRMtx();
    fopAcM_setCullSizeBox(this, -200.0f, -30.0f, -200.0f, 200.0f, 30.0f,200.0f);
    PSMTXCopy(field_0x2F4->getBaseTRMtx(), field_0x328);
    field_0x430 = 0;
    field_0x4298 = 0;
    field_0x429A = 0;
    field_0x450 = 0;
    field_0x448 = 0x1E;
    field_0x44C = 0;
    field_0x438 = 0;
    field_0x454 = 0;
    field_0x456 = 0;
    field_0x458 = 0;
    field_0x29E = 0;
    speed.setall(0.0f);
    home.pos.x = current.pos.x;
    home.pos.y = current.pos.y;
    home.pos.z = current.pos.z;
    home.pos.y+= 15.0f;
    gravity = -2.5f;
    field_0x2D0 = ZeroQuat;
    field_0x2C0 = field_0x2D0;
    field_0x2B0 = field_0x2C0;
    set_mtx();
    ptr = ride_call_back;
    field_0x29F = base.mParameters >> 0x18;
    if (field_0x29F == 0) {
        appear_proc_init();
        if (field_0x2A0 == NULL) {
            s8 reverb = dComIfGp_getReverb(current.roomNo);
            fopAcM_seStart(this, JA_SE_MAGMA_TO_ISLE, reverb);
            cXyz coord;
            coord.x = 0.0f;
            coord.y = 1.0f;
            coord.z = 0.0f;
            dComIfGp_getVibration().StartShock(4, 1, coord);
            field_0x35C = tevStr;
            g_env_light.settingTevStruct(TEV_TYPE_ACTOR, &current.pos, &field_0x35C);
            field_0x35C.mColorC0.r += 0.12f;
            field_0x35C.mColorC0.g += 0.12f;
            field_0x35C.mColorC0.b += 0.12f;
            field_0x35C.mColorK0.r += 0.12f;
            field_0x35C.mColorK0.g += 0.12f;
            field_0x35C.mColorK0.b += 0.12f;
            u8 alpha = REG10_F(25);
            JPABaseEmitter* emitter = dComIfGp_particle_set(0x8072, &current.pos, NULL, NULL, alpha, NULL, -1, NULL, NULL, NULL);
            field_0x2A0 = emitter;
            u8 alpha2 = REG10_F(26);
            JPABaseEmitter* emitter2 = dComIfGp_particle_set(0x8073, &current.pos, NULL, NULL, alpha2, NULL, -1, NULL, NULL, NULL);
            field_0x2A4 = emitter2;
            if (field_0x2A0 != NULL) {
                field_0x2A0->setGlobalPrmColor(default_color.r, default_color.g, default_color.b);
                field_0x2A0->setGlobalEnvColor(default_color.r, default_color.g, default_color.b);
            }
            if (field_0x2A4 != NULL) {
                field_0x2A4->setGlobalPrmColor(default_color.r, default_color.g, default_color.b);
                field_0x2A4->setGlobalEnvColor(default_color.r, default_color.g, default_color.b);
            }
        }
    }else {
        stay_proc_init();
    }
    //return true;
}

/* 000013B4-00001560       .text LiftUpRequest__Q214daObjMagmarock5Act_cFR4cXyz */
void daObjMagmarock::Act_c::LiftUpRequest(cXyz&) {
    /* Nonmatching */
}

/* 00001560-0000167C       .text BeforeLiftRequest__Q214daObjMagmarock5Act_cFR4cXyz */
void daObjMagmarock::Act_c::BeforeLiftRequest(cXyz&) {
    /* Nonmatching */
}

/* 0000167C-000017DC       .text calc_ground_quat__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::calc_ground_quat() {
    /* Nonmatching */
}

/* 000017DC-0000198C       .text Create__Q214daObjMagmarock6MethodFPv */
cPhs_State daObjMagmarock::Method::Create(void* i_this) {
    /* Nonmatching */
    daObjMagmarock::Act_c* a_this = (daObjMagmarock::Act_c*)i_this;
    return a_this->_create();

}

/* 00001A90-00001B14       .text Delete__Q214daObjMagmarock6MethodFPv */
BOOL daObjMagmarock::Method::Delete(void*) {
    /* Nonmatching */
}

/* 00001B14-00001B38       .text Execute__Q214daObjMagmarock6MethodFPv */
BOOL daObjMagmarock::Method::Execute(void* i_this) {
    daObjMagmarock::Act_c* a_this = (daObjMagmarock::Act_c*)i_this;
    return a_this->_execute();
}

/* 00001B38-00001EC0       .text _execute__Q214daObjMagmarock5Act_cFv */
bool daObjMagmarock::Act_c::_execute() {
    /* Nonmatching */
}

/* 00001EC0-00002128       .text Draw__Q214daObjMagmarock6MethodFPv */
BOOL daObjMagmarock::Method::Draw(void*) {
    /* Nonmatching */
}

/* 00002128-00002130       .text IsDelete__Q214daObjMagmarock6MethodFPv */
BOOL daObjMagmarock::Method::IsDelete(void*) {
    return TRUE;
}

actor_method_class daObjMagmarock::Method::Table = {
    (process_method_func)daObjMagmarock::Method::Create,
    (process_method_func)daObjMagmarock::Method::Delete,
    (process_method_func)daObjMagmarock::Method::Execute,
    (process_method_func)daObjMagmarock::Method::IsDelete,
    (process_method_func)daObjMagmarock::Method::Draw,
};

actor_process_profile_definition g_profile_Obj_Magmarock = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 0x0003,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_Obj_Magmarock,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(daObjMagmarock::Act_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ PRIO_Obj_Magmarock,
    /* Actor SubMtd */ &daObjMagmarock::Method::Table,
    /* Status       */ fopAcStts_CULL_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
