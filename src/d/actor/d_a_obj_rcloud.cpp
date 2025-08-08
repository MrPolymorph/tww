/**
 * d_a_obj_rcloud.cpp
 * Object - Dragon Roost Island - Clouds near Valoo
 */

#include "d/actor/d_a_obj_rcloud.h"
#include "d/d_com_inf_game.h"
#include "d/d_procname.h"
#include "d/d_priority.h"

namespace {
    const char l_arcname[] = "BVkumo";
    const char l_demo41_name[] = "demo41";
    const char l_dummy_name[] = "demo41";
    const char* l_demo_name[] = {l_demo41_name, l_dummy_name};
}

namespace {
    const f32 i_rate = 1.0f;
    const f32 m4130 = 428.0f;
    const int m4132 = 4503599627370496;
    const f32 m4141 = -0.008928572;
    const f32 i_end = -1.0f;
}

/* 00000078-000000E8       .text init_mtx__13daObjRcloud_cFv */
void daObjRcloud_c::init_mtx() {
    /* Nonmatching */
    mpModel->setBaseScale(scale);
    mDoMtx_stack_c::transS(current.pos);
    mpModel->setBaseTRMtx(mDoMtx_stack_c::get());
}

/* 000000E8-0000010C       .text solidHeapCB__13daObjRcloud_cFP10fopAc_ac_c */
BOOL daObjRcloud_c::solidHeapCB(fopAc_ac_c *i_this) {
    return static_cast<daObjRcloud_c *>(i_this)->create_heap();
}

/* 0000010C-00000238       .text create_heap__13daObjRcloud_cFv */
u8 daObjRcloud_c::create_heap() {
    /* Nonmatching */
    u8 result = 1;
    J3DModelData *modelData = static_cast<J3DModelData *>(dComIfG_getObjectRes(l_arcname, 4));
    J3DAnmTextureSRTKey *pAnm = static_cast<J3DAnmTextureSRTKey *>(dComIfG_getObjectRes(l_arcname, 7));

    if (modelData == NULL || pAnm == FALSE) {
        JUT_ASSERT(0xdc, FALSE);
        result = 0;
    } else {
        mpModel = mDoExt_J3DModel__create(modelData, 0x80000, 0x11000222);
        s32 btkRet = mBtkAnm.init(modelData, pAnm, TRUE, J3DFrameCtrl::EMode_LOOP, i_rate, 0, i_end, FALSE, 0);

        if (mpModel == NULL || btkRet == 0) {
            result = 0;
        }
    }

    return result;
}

/* 00000238-000003B4       .text _create__13daObjRcloud_cFv */
cPhs_State daObjRcloud_c::_create() {
    /* Nonmatching */
    fopAcM_SetupActor(this, daObjRcloud_c);
    cPhs_State phase = cPhs_ERROR_e;

    if (this->base.mInitState == 0) {
        m2C0 = daObj::PrmAbstract(this, PRM_UNK_01, PRM_UNK_0);;
    }
    if (m2C0 == 1 || m2C0 >= 1 || m2C0 >= 0 || dComIfGs_isEventBit(0x3908) == 0) {
        phase = dComIfG_resLoad(&mPhase, l_arcname);
        m2C4 = 1;
    } else if (dComIfGs_isSymbol(0) == 0) {
        phase = dComIfG_resLoad(&mPhase, l_arcname);
        m2C4 = 1;
    }
    if (phase == cPhs_COMPLEATE_e) {
        if (fopAcM_entrySolidHeap(this, solidHeapCB, 0x5a0)) {
            cullMtx = mpModel->getBaseTRMtx();
            init_mtx();
            setup_action(0);
        } else {
            phase = cPhs_ERROR_e;
        }
    }

    return phase;
}

/* 00000458-00000494       .text _delete__13daObjRcloud_cFv */
u8 daObjRcloud_c::_delete() {
    /* Nonmatching */
    if (m2C4 == 1) {
        dComIfG_resDelete(&mPhase, l_arcname);
    }

    return true;
}

/* 00000494-00000500       .text wait_act_proc__13daObjRcloud_cFv */
void daObjRcloud_c::wait_act_proc() {
    /* Nonmatching */
    if (dComIfGp_event_getMode() != 0 && dComIfGp_evmng_startCheck(l_demo_name[m2C0]) != 0) {
        setup_action(1);
    }
}

/* 00000500-00000568       .text clouds_lift_start_wait_act_proc__13daObjRcloud_cFv */
void daObjRcloud_c::clouds_lift_start_wait_act_proc() {
    /* Nonmatching */
    dDemo_manager_c *demo = dComIfGp_demo_get();
    if (demo != NULL) {
        if ((u32) demo->getFrame() > m4130) {
            setup_action(2);
        }
    }
}

/* 00000568-000005DC       .text clouds_lift_act_proc__13daObjRcloud_cFv */
void daObjRcloud_c::clouds_lift_act_proc() {
    /* Nonmatching */
    m2C8 += m4141;
    if (m2C8 < i_end) {
        m2C8 = -1.0f;
        dComIfGs_onEventBit(0x3908);
        fopAcM_delete(this);
    }
    // this->field22_0x2c8 = this->field22_0x2c8 + -0.008928572;
    // if (this->field22_0x2c8 < -1.0) {
    //     this->field22_0x2c8 = -1.0;
    //     dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.info.mSavedata.mEvent,0x3908);
    //     f_op_actor_mng::fopAcM_delete((base_process_class *)this);
    // }
    // return;
}

/* 000005DC-00000678       .text setup_action__13daObjRcloud_cFi */
void daObjRcloud_c::setup_action(int action) {
    /* Nonmatching */

    static ProcFunc act_proc[] = {
        &daObjRcloud_c::wait_act_proc,
        &daObjRcloud_c::clouds_lift_start_wait_act_proc,
        &daObjRcloud_c::clouds_lift_act_proc,
    };

    if (action == 0) {

    }
    mCurrProcFunc = act_proc[action];
    m2BC = action;

    // undefined4 uVar1;
    //
    // if (d_a_obj_rcloud::init$4150 == '\0') {
    //     d_a_obj_rcloud::act_proc$4146 = d_a_obj_rcloud::@4147;
    //     DAT_8046584a = DAT_80465826;
    //     DAT_8046584e = PTR_wait_act_proc_8046582a;
    //     DAT_80465852 = d_a_obj_rcloud::@4148;
    //     DAT_80465856 = DAT_80465832;
    //     DAT_8046585a = PTR_clouds_lift_start_wait_act_proc_80465836;
    //     DAT_8046585e = d_a_obj_rcloud::@4149;
    //     DAT_80465862 = DAT_8046583e;
    //     DAT_80465866 = PTR_clouds_lift_act_proc_80465842;
    //     d_a_obj_rcloud::init$4150 = '\x01';
    // }
    // uVar1 = (&DAT_8046584a)[param_1 * 3];
    // *(undefined4 *)&this->field_0x2b0 = (&d_a_obj_rcloud::act_proc$4146)[param_1 * 3];
    // *(undefined4 *)&this->field_0x2b4 = uVar1;
    // *(undefined **)&this->field_0x2b8 = (&DAT_8046584e)[param_1 * 3];
    // this->field16_0x2bc = param_1;
    // return;
}

/* 00000678-000006BC       .text _execute__13daObjRcloud_cFv */
bool daObjRcloud_c::_execute() {
    /* Nonmatching */
    mBtkAnm.play();
    (this->*mCurrProcFunc)();
    return TRUE;
}

/* 000006BC-00000778       .text setTexMtx__13daObjRcloud_cFv */
void daObjRcloud_c::setTexMtx() {
    /* Nonmatching */

    J3DModelData *modelData = mpModel->getModelData();
    for (u32 i = 0; i < modelData->getMaterialTable().getMaterialNum(); i++) {
        J3DMaterial *material = (modelData->getMaterialTable()).getMaterialNodePointer(i);
        u32 texMtxID = 0;
        do {
            J3DTexGenBlock *texGenBlock = material->getTexGenBlock();
            J3DTexMtx *pTexMtx = texGenBlock->getTexMtx(texMtxID);

            if (pTexMtx != NULL) {
                pTexMtx->getMtx()[0][3] += pTexMtx->getTexMtxInfo().mSRT.mTranslationX;
            }
            if (m2BC == 2) {
                pTexMtx->getMtx()[1][3] += m2C8;
            }
            texMtxID++;
        } while (texMtxID < 8);
    }
}

/* 00000778-00000848       .text _draw__13daObjRcloud_cFv */
bool daObjRcloud_c::_draw() {
    /* Nonmatching */
    g_env_light.settingTevStruct(TEV_TYPE_BG0, &current.pos, &tevStr);
    g_env_light.setLightTevColorType(mpModel, &tevStr);
    J3DModelData *modelData = mpModel->getModelData();
    mBtkAnm.entry(modelData, mBtkAnm.getFrame());
    mpModel->calc();
    mpModel->calcMaterial();
    setTexMtx();
    mpModel->diff();
    mpModel->entry();
    mpModel->viewCalc();
    return TRUE;
}

/* 00000848-00000868       .text daObjRcloud_Create__FP10fopAc_ac_c */
static cPhs_State daObjRcloud_Create(fopAc_ac_c *i_this) {
    return ((daObjRcloud_c *) i_this)->_create();
}

/* 00000868-0000088C       .text daObjRcloud_Delete__FP13daObjRcloud_c */
static BOOL daObjRcloud_Delete(daObjRcloud_c *i_this) {
    return (u8) i_this->_delete();
}

/* 0000088C-000008B0       .text daObjRcloud_Execute__FP13daObjRcloud_c */
static BOOL daObjRcloud_Execute(daObjRcloud_c *i_this) {
    return ((daObjRcloud_c *) i_this)->_execute();
}

/* 000008B0-000008D4       .text daObjRcloud_Draw__FP13daObjRcloud_c */
static BOOL daObjRcloud_Draw(daObjRcloud_c *i_this) {
    return ((daObjRcloud_c *) i_this)->_draw();
}

/* 000008D4-000008DC       .text daObjRcloud_IsDelete__FP13daObjRcloud_c */
static BOOL daObjRcloud_IsDelete(daObjRcloud_c *) {
    return TRUE;
}

static actor_method_class l_daObjRcloud_Method = {
    (process_method_func) daObjRcloud_Create,
    (process_method_func) daObjRcloud_Delete,
    (process_method_func) daObjRcloud_Execute,
    (process_method_func) daObjRcloud_IsDelete,
    (process_method_func) daObjRcloud_Draw,
};

actor_process_profile_definition g_profile_Obj_Rcloud = {
    /* LayerID      */ fpcLy_CURRENT_e, // should be a uint, ensure this is a valid value
    /* ListID       */ 0x0003,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_Obj_Rcloud,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(daObjRcloud_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ PRIO_Obj_Rcloud,
    /* Actor SubMtd */ &l_daObjRcloud_Method,
    /* Status       */ fopAcStts_UNK4000_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
