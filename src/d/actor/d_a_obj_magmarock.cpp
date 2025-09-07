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
    Quaternion qStack_18;
    field_0x2F4->setBaseScale(scale);
    PSMTXTrans(mDoMtx_stack_c::get(), current.pos.x, current.pos.y, current.pos.z);
    mDoMtx_ZXYrotM(mDoMtx_stack_c::get(), shape_angle.x, shape_angle.y, shape_angle.z);
    PSQUATMultiply(&field_0x2B0, &field_0x2D0, &qStack_18);
    mDoMtx_stack_c::quatM(&qStack_18);
    field_0x2F4->setBaseTRMtx(mDoMtx_stack_c::get());
    MTXCopy(mDoMtx_stack_c::get(), field_0x328);
}

/* 00000128-00000258       .text demo_move__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::demo_move() {
    /* Nonmatching */
    if (dComIfGs_isEventBit(0x380) || field_0x29F != 0) {
        return;
    }
    if (field_0x45A == 0) {
        if (eventInfo.checkCommandDemoAccrpt()) {
            field_0x45A++;
        } else {
            fopAcM_orderOtherEvent2(this, "magma_cam", dEvtFlag_NOPARTNER_e);
            eventInfo.onCondition(dEvtCnd_UNK2_e);
        }
    } else if (field_0x45A == 1) {
        int staffIdx = dComIfGp_evmng_getMyStaffId("Magrock");
        if (dComIfGp_evmng_endCheck("magma_cam")) {
            dComIfGp_event_reset();
            field_0x45A++;
            dComIfGs_onEventBit(0x380);
        } else {
            dComIfGp_evmng_cutEnd(staffIdx);
        }
    }
}

/* 00000258-00000410       .text ControlEffect__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::ControlEffect() {
    /* Nonmatching */
    if (field_0x45C == 0) {
        JP
        if (field_0x2AC != NULL) {
        }
    }
}

/* 0000044C-00000560       .text play_anim__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::play_anim() {
    /* Nonmatching */
    int iVar1 = field_0x44C;
    if (iVar1 > 0x178) {
        if (field_0x438 > 0.0f) {
            if (iVar1 < 0xF || iVar1 > 0x3C && field_0x438 < (f32) field_0x2F8->getFrameMax()) {
                return;
            } else {
                field_0x438 += 1.0f;
            }
        }
    }
    if (field_0x44C < 0x3C && field_0x434 < field_0x314->getFrameMax()) {
        field_0x434 += 1.0f;
        return;
    }
    if (field_0x44C > 0x177 && field_0x434 > 0.0f) {
        field_0x434 -= 1.0f;
    }
}

/* 00000560-0000058C       .text appear_proc_init__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::appear_proc_init() {
    /* Nonmatching */
    field_0x448 = 0x1E;
    field_0x2E0 = appear_proc;
}

/* 0000058C-000005EC       .text appear_proc__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::appear_proc() {
    /* Nonmatching */
    if (field_0x448 == 10) {
        dComIfG_Bgsp()->Regist(field_0x358, this);
    }
    if (field_0x448 == 0) {
        wait_proc_init();
    }
}

/* 000005EC-00000618       .text wait_proc_init__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::wait_proc_init() {
    /* Nonmatching */
    field_0x448 = 300;
    field_0x2E0 = wait_proc;
}

/* 00000618-00000644       .text wait_proc__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::wait_proc() {
    /* Nonmatching */
    if (this->field_0x448 == 0) {
        quake_proc_init();
    }
}

/* 00000644-000006E0       .text stay_proc_init__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::stay_proc_init() {
    /* Nonmatching */
    u32 uVar2 = base.mParameters & 0xFF;
    if (uVar2 == 0xFF) {
        uVar2 = 0;
    }
    field_0x438 = 30.0f;
    field_0x434 = 30.0f;
    field_0x448 = (u8)uVar2 * 0xF + 0x1E;
    field_0x44C = 0x14A;
    dComIfG_Bgsp()->Regist(field_0x358, this);
    field_0x2E0 = stay_proc;
}

/* 000006E0-00000720       .text stay_proc__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::stay_proc() {
    /* Nonmatching */
    if (this->field_0x29E != 0 && (this->field_0x448 += -1) == 0) {
        quake_proc_init();
    }
}

/* 00000720-000007B8       .text quake_proc_init__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::quake_proc_init() {
    /* Nonmatching */

    mDoAud_seStart(JA_SE_ISLE_TO_MAGMA, &eyePos, 0, dComIfGp_getReverb(current.roomNo));
    field_0x448 = 0x2D;
    field_0x2E0 = quake_proc;
}

/* 000007B8-0000084C       .text quake_proc__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::quake_proc() {
    /* Nonmatching */
    field_0x454 += field_0x456;
    cLib_addCalcAngleS2(&field_0x456, 0x1000, 2, 0x100);
    cLib_addCalc2(&field_0x430, REG10_F(10) + 750.0f, 0.25f, 50.0f);
    if (field_0x448 == 0) {
        vanish_proc_init();
    }
}

/* 0000084C-00000878       .text vanish_proc_init__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::vanish_proc_init() {
    /* Nonmatching */
    field_0x448 = 0x5A;
    field_0x2E0 = vanish_proc;
}

/* 00000878-000008F8       .text vanish_proc__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::vanish_proc() {
    /* Nonmatching */
    field_0x454 += field_0x456;
    cLib_addCalcAngleS2(&field_0x456, 0, 4, 0x40);
    if (field_0x448 == 0x50) {
        dComIfG_Bgsp()->Release(field_0x358);
    }
    if (field_0x448 < 0) {
        fopAcM_delete(this);
    }
}

/* 000008F8-00000AEC       .text ride_call_back__14daObjMagmarockFP4dBgWP10fopAc_ac_cP10fopAc_ac_c */
void daObjMagmarock::ride_call_back(dBgW* param_1, fopAc_ac_c* param_2, fopAc_ac_c* param_3) {
    /* Nonmatching */
    daObjMagmarock::Act_c* a_this = (daObjMagmarock::Act_c*)param_1;
    cXyz local30;
    cXyz local3C;
    cXyz local48 = param_3->current.pos - param_2->current.pos;
    //local30.set(local48);
    local3C.x = 0;
    local3C.y = -1.0f;
    local3C.z = 0;
    cXyz local54 = local30.outprod(local3C);
    //local30.set(local54);
    f32 fVar4 = PSVECSquareMag(&local30);
    if (fVar4 > 0.0f) {
        f64 fVar2 = __frsqrtes(fVar4);
        fVar2 = 0.5 * fVar2 * (3.0 - fVar4 * fVar2 * fVar2);
        fVar2 = 0.5 * fVar2 * (3.0 - fVar4 * fVar2 * fVar2);
        fVar4 = fVar2 * fVar4 * 0.5 * (3.0 - fVar4 * fVar2 * fVar2);
    }else {
        return;
    }
    if (local30.normalizeRS()) {
        s16 iVar1 = (s16)(-fVar4 * ((param_2->current.pos.y - param_2->home.pos.y) * 0.001 * 4.0 + 2.0));
        cLib_addCalcAngleS2(&a_this->field_0x298, iVar1, 8, 0x200);
        a_this->field_0x29C = 1;
        a_this->field_0x29E = 1;
        fVar4 = JMASSin(a_this->field_0x298);
        a_this->field_0x2C0.x = local30.x * fVar4;
        a_this->field_0x2C0.y = local30.y * fVar4;
        a_this->field_0x2C0.z = local30.z * fVar4;
        a_this->field_0x2C0.w = JMASCos(a_this->field_0x298);
    }

}

/* 00000AEC-00000B0C       .text CheckCreateHeap__14daObjMagmarockFP10fopAc_ac_c */
BOOL daObjMagmarock::CheckCreateHeap(fopAc_ac_c *i_this) {
    daObjMagmarock::Act_c *a_this = (daObjMagmarock::Act_c *) i_this;
    a_this->CreateHeap();
}

/* 00000B0C-00000DA0       .text CreateHeap__Q214daObjMagmarock5Act_cFv */
BOOL daObjMagmarock::Act_c::CreateHeap() {
    /* Nonmatching */
    BOOL ret = FALSE;
    J3DModelData *modelData = (J3DModelData *) dComIfG_getObjectRes(M_arcname, 9);
    JUT_ASSERT(0x14D, modelData != 0);
    field_0x2F4 = mDoExt_J3DModel__create(modelData, 0, 0x11020203);
    M_brk = (mDoExt_brkAnm *) dComIfG_getObjectRes(M_arcname, 0xC);
    M_bck = (mDoExt_bckAnm *) dComIfG_getObjectRes(M_arcname, 6);
    JUT_ASSERT(0x155, M_brk != NULL);
    JUT_ASSERT(0x156, M_bck != NULL);
    int brkInitVal = M_brk->init(modelData, field_0x2F8, FALSE, J3DFrameCtrl::EMode_LOOP, 1.0f, 0, -1, false, 0);
    int bckInittVal = M_bck->init(modelData, field_0x314, FALSE, J3DFrameCtrl::EMode_LOOP, 1.0f, 0, -1, false);
    PSMTXTrans(mDoMtx_stack_c::get(), current.pos.x, current.pos.y, current.pos.z);
    mDoMtx_stack_c::YrotM(shape_angle.y);
    mDoMtx_stack_c::scaleM(scale.x, scale.y, scale.z);
    MTXCopy(mDoMtx_stack_c::get(), field_0x328);
    cBgD_t *cBgDt = (cBgD_t *) dComIfG_getObjectRes(M_arcname, 0xF);
    dBgW *dbgw = dBgW_NewSet(cBgDt, dBgW::MOVE_BG_e, &field_0x328);
    field_0x358 = dbgw;
    field_0x358->m_crr_func = dBgS_MoveBGProc_Typical;
    if (field_0x358 == NULL) {
        ret = FALSE;
    } else {
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
    fopAcM_setCullSizeBox(this, -200.0f, -30.0f, -200.0f, 200.0f, 30.0f, 200.0f);
    MTXCopy(field_0x2F4->getBaseTRMtx(), field_0x328);
    field_0x430 = 0;
    field_0x298 = 0;
    field_0x29A = 0;
    field_0x450 = 0;
    field_0x448 = 0x1E;
    field_0x44C = 0;
    field_0x438 = 0;
    field_0x454 = 0;
    field_0x456 = 0;
    field_0x45A = 0;
    field_0x29E = 0;
    speed.setall(0.0f);
    home.pos.x = current.pos.x;
    home.pos.y = current.pos.y;
    home.pos.z = current.pos.z;
    home.pos.y += 15.0f;
    gravity = -2.5f;
    field_0x2D0 = ZeroQuat;
    field_0x2C0 = field_0x2D0;
    field_0x2B0 = field_0x2C0;
    set_mtx();
    field_0x358->mpRideCb = ride_call_back;
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
            JPABaseEmitter *emitter = dComIfGp_particle_set(0x8072, &current.pos, NULL, NULL, alpha, NULL, -1, NULL,
                                                            NULL, NULL);
            field_0x2A0 = emitter;
            u8 alpha2 = REG10_F(26);
            JPABaseEmitter *emitter2 = dComIfGp_particle_set(0x8073, &current.pos, NULL, NULL, alpha2, NULL, -1, NULL,
                                                             NULL, NULL);
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
    } else {
        stay_proc_init();
    }
}

/* 000013B4-00001560       .text LiftUpRequest__Q214daObjMagmarock5Act_cFR4cXyz */
bool daObjMagmarock::Act_c::LiftUpRequest(cXyz& i_cXyz) {
    /* Nonmatching */
    cXyz local24;
    bool returnValue = false;
    ProcFunc local30;
    field_0x43C.x = i_cXyz.x;
    field_0x43C.y = i_cXyz.y;
    field_0x43C.z = i_cXyz.z;

    local30 = wait_proc;
    BOOL isWaitProc = (field_0x2E0 == local30);
    if (isWaitProc == 0) {
        ProcFunc local3C = appear_proc;
        BOOL isAppearProc = field_0x2E0 == local3C;
        if (isAppearProc != 0) {
            local24.set(current.pos - field_0x43C);
            local24.y = 0;
            if (!local24.normalizeRS()) {
                local24.x = 0.0f;
                local24.y = 0.0f;
                local24.z = 1.0f;
            }
            PSVECScale(&local24, &local24, 10.0f);
            PSVECAdd(&current.pos, &local24, &current.pos);
        }
        returnValue = false;
    } else {
        cLib_addCalcPos2(&current.pos, i_cXyz, 0.05, 5.0);
        cLib_addCalc2(&field_0x430, 750.0, 0.5, 40.0);
        cLib_addCalcAngleS2(&field_0x456, 0x1200, 4, 0x100);
        field_0x454 += field_0x456;
        cLib_addCalc2(&current.pos.y, i_cXyz.y, 0.25, 150.0);
        field_0x45C = 1;
        returnValue = true;
    }

    return returnValue;
}

/* 00001560-0000167C       .text BeforeLiftRequest__Q214daObjMagmarock5Act_cFR4cXyz */
BOOL daObjMagmarock::Act_c::BeforeLiftRequest(cXyz& param_1) {
    /* Nonmatching */
    field_0x43C.set(param_1);
    if (field_0x43C.y < (home.pos.y + 25.0f)) {
        field_0x43C.y = home.pos.y + 25.0f;
    }
    ProcFunc proc = wait_proc;
    s32 procEquals = proc == field_0x2E0 ? 1 : 0;
    if (procEquals == NULL) {
        return false;
    }

    cLib_addCalcPos2(&current.pos, field_0x43C, 0.05F, 5.0f);
    cLib_addCalc2(&field_0x430, 500.0f, 0.25f, 20.0f);
    cLib_addCalcAngleS2(&field_0x456, 0xA00, 8, 0x100);
    field_0x454 += field_0x456;
    cLib_addCalc2(&current.pos.y, field_0x43C.y, 0.25f, 150.0f);
    field_0x45C = 1;
    field_0x45E = 1;
    return TRUE;
}

/* 0000167C-000017DC       .text calc_ground_quat__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::calc_ground_quat() {
    /* Nonmatching */
    f32 yPos;
    dMagma_packet_c *magmaPacket = dComIfGp_getMagma();
    if (magmaPacket != NULL) {
        yPos = magmaPacket->checkYpos(current.pos);
    } else {
        yPos = current.pos.y - 10.0f;
    }

    if (yPos > -99999992.0f) {
        home.pos.y = (yPos + 10.0f) + 15.0f;
    }

    home.pos.x = current.pos.x;
    home.pos.z = current.pos.z;
    field_0x40C[0].x = 0;
    field_0x40C[0].y = 0;
    field_0x40C[0].z = 120.0f;
    field_0x40C[1].x = 103.9;
    field_0x40C[1].y = 0;
    field_0x40C[1].z = -60.0f;
    field_0x40C[2].x = -103.9f;
    field_0x40C[2].y = 0;
    field_0x40C[2].z = -60.0f;

    for (int i = 0; i < 3; i++) {
        field_0x40C[i] += home.pos;
        magmaPacket = dComIfGp_getMagma();
        if (magmaPacket != NULL) {
            yPos = magmaPacket->checkYpos(field_0x40C[i]);
        } else {
            yPos = current.pos.y - 10.0f;
        }

        if (yPos > -99999992.0f) {
            field_0x40C[i].y = yPos + 15.0f;
        }
    }
    dLib_calc_QuatFromTriangle(&field_0x2D0, 0.25f, &field_0x40C[0], &field_0x40C[1], &field_0x40C[2]);
}

cPhs_State daObjMagmarock::Act_c::_create() {
    fopAcM_SetupActor(this, Act_c);
    cPhs_State state = dComIfG_resLoad(&field_0x2EC, M_arcname);
    if (state == cPhs_COMPLEATE_e) {
        if (dComIfGp_getMagma() != NULL) {
            state = cPhs_ERROR_e;
        } else {
            if (fopAcM_entrySolidHeap(this, CheckCreateHeap, 0x5D40)) {
                CreateInit();
            }
        }
    }
    return state;
}

/* 000017DC-0000198C       .text Create__Q214daObjMagmarock6MethodFPv */
cPhs_State daObjMagmarock::Method::Create(void *i_this) {
    /* Nonmatching */
    daObjMagmarock::Act_c *a_this = (daObjMagmarock::Act_c *) i_this;
    return a_this->_create();
}

/* 00001A90-00001B14       .text Delete__Q214daObjMagmarock6MethodFPv */
BOOL daObjMagmarock::Method::Delete(void *i_this) {
    /* Nonmatching */
    BOOL ret = FALSE;
    daObjMagmarock::Act_c *a_this = (daObjMagmarock::Act_c *) i_this;
    dComIfG_resDelete(&a_this->field_0x2EC, a_this->M_arcname);
    if (a_this->heap != NULL) {
        if (a_this->field_0x358->ChkUsed() == false) {
            ret = FALSE;
        } else {
            ret = TRUE;
        }
        if (ret) {
            dComIfG_Bgsp()->Release(a_this->field_0x358);
        }
    }
    return TRUE;
}

/* 00001B14-00001B38       .text Execute__Q214daObjMagmarock6MethodFPv */
BOOL daObjMagmarock::Method::Execute(void *i_this) {
    daObjMagmarock::Act_c *act = static_cast<daObjMagmarock::Act_c *>(i_this);
    return act->_execute();
}

/* 00001B38-00001EC0       .text _execute__Q214daObjMagmarock5Act_cFv */
bool daObjMagmarock::Act_c::_execute() {
    /* Nonmatching */
}

/* 00001EC0-00002128       .text Draw__Q214daObjMagmarock6MethodFPv */
BOOL daObjMagmarock::Method::Draw(void *) {
    /* Nonmatching */
}

/* 00002128-00002130       .text IsDelete__Q214daObjMagmarock6MethodFPv */
BOOL daObjMagmarock::Method::IsDelete(void *) {
    return TRUE;
}

actor_method_class daObjMagmarock::Method::Table = {
    (process_method_func) daObjMagmarock::Method::Create,
    (process_method_func) daObjMagmarock::Method::Delete,
    (process_method_func) daObjMagmarock::Method::Execute,
    (process_method_func) daObjMagmarock::Method::IsDelete,
    (process_method_func) daObjMagmarock::Method::Draw,
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
