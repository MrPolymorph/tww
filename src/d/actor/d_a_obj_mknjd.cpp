//
// Generated by dtk
// Translation Unit: d_a_obj_mknjd.cpp
//

#include "f_op/f_op_actor_mng.h"
#include "f_op/f_op_msg.h"
#include "f_op/f_op_draw_tag.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "JSystem/J3DGraphBase/J3DSys.h"
#include "d/d_procname.h"
#include "d/d_com_inf_game.h"
#include "d/d_bg_s_movebg_actor.h"
#include "d/d_item_data.h"
#include "d/d_particle.h"
#include "m_Do/m_Do_ext.h"
#include "dolphin/types.h"


static const char* daObjMknjD_jointName[] = {
    "Hahen1",
    "Hahen2",
    "Hahen3",
    "Hahen4",
    "Hahen5",
    "Hahen6",
    "Hahen7",
    "Hahen8",
    "Hahen9",
    "Hahen10",
    "Hahen11",
    "Hahen12",
    "Hahen13",
    "Hahen14",
    "Hahen15",
    "Hahen16",
    "Hahen17",
    "Hahen18",
    "Hahen19",
    "Hahen20"
};

const char* daObjMknjD_EventName[] = {
    "MKNJD_D_DEMO",
    "MKNJD_K_DEMO",

    "MKNJD_D_CHECK",
    "MKNJD_K_CHECK",

    "MKNJD_D_ERROR",
    "MKNJD_K_ERROR",

    "MKNJD_D_LESSON",
    "MKNJD_K_LESSON",
};

namespace daObjMknjD {
    class Act_c : public dBgS_MoveBgActor {
    public:
        s32 Mthd_Create();
        s32 Mthd_Delete();

        s16 XyCheckCB(int);
        s16 XyEventCB(int);

        int CreateHeap();
        int Create();

        int Delete();

        void set_mtx();
        void init_mtx();

        void setGoal(int);
        void setPlayerAngle(int);
        u32 talk(int);
        void privateCut();
        void daObjMknjD_break();

        int Execute(float(**)[3][4]);
        int Draw();

        static const char M_arcname[];

        /* 0x02C8 */ cXyz mLeftHalfPos;
        /* 0x02D4 */ cXyz mRightHalfPos;

        /* 0x02E0 */ cXyz mShardPositions[0x14];
        /* 0x03D0 */ float mShardHeights[0x14];

        /* 0x0420 */ request_of_phase_process_class mPhs;

        /* 0x0428 */ J3DModel* mModel0;
        /* 0x042C */ J3DModel* mModel1;
        
        /* 0x0430 */ u16 m0430;
        /* 0x0432 */ u16 m0432;
        /* 0x0434 */ u16 m0434;
        /* 0x0438 */ u32 mBreakTimer;

        /* 0x043C */ u8 mModel0Alpha;
        /* 0x043D */ bool m043D;
        /* 0x043E */ u8 m043E;
        /* 0x043F */ u8 m043F;

        /* 0x0440 */ JPABaseEmitter* mEmitter0;
        /* 0x0444 */ JPABaseEmitter* mEmitter1;
        /* 0x0448 */ JPABaseEmitter* mEmitter2;
        /* 0x044C */ JPABaseEmitter* mEmitter3;

        /* 0x0450 */ dPa_smokeEcallBack mSmokeCBs[4];

        /* 0x04D0 */ cXyz m04D0;
        
        /* 0x04DC */ s16 mCheckEventIdx;
        /* 0x04DE */ s16 mDemoEventIdx;
        /* 0x04E0 */ s16 mErrorEventIdx;
        /* 0x04E2 */ s16 mLessonEventIdx;
        
        /* 0x04E4 */ u8 mActionIdx;
        /* 0x04E5 */ u8 mTactMode;
        /* 0x04E6 */ u8 mGiveItemId;

        /* 0x04E8 */ cXyz mGoalPos;

        /* 0x04F4 */ u32 mMsgId;
        /* 0x04F8 */ u32 mMsgInstId;
        /* 0x04FC */ msg_class* mMsgPtr;

        /* 0x0500 */ s32 m0500;
        /* 0x0504 */ bool m0504;
    };

    const char Act_c::M_arcname[] = "MknjD";

    static void manage_friend_draw(int);
    static void setMaterial(J3DMaterial*, u8);
}

/* 00000078-0000012C       .text nodeCallBackL__FP7J3DNodei */
void nodeCallBackL(J3DNode*, int) {
    /* Nonmatching */
}

/* 0000012C-000001E0       .text nodeCallBackR__FP7J3DNodei */
void nodeCallBackR(J3DNode*, int) {
    /* Nonmatching */
}

/* 000001E0-000002B0       .text nodeCallBack_Hahen__FP7J3DNodei */
void nodeCallBack_Hahen(J3DNode*, int) {
    /* Nonmatching */
}

/* 000002B0-000002D0       .text daObjMknjD_XyCheckCB__FPvi */
static s16 daObjMknjD_XyCheckCB(void* i_this, int i_param2) {
    return static_cast<daObjMknjD::Act_c*>(i_this)->XyCheckCB(i_param2);
}

/* 000002D0-000002F0       .text daObjMknjD_XyEventCB__FPvi */
static s16 daObjMknjD_XyEventCB(void* i_this, int i_param2) {
    return static_cast<daObjMknjD::Act_c*>(i_this)->XyEventCB(i_param2);
}

/* 000002F0-00000314       .text XyCheckCB__Q210daObjMknjD5Act_cFi */
s16 daObjMknjD::Act_c::XyCheckCB(int i_itemIdx) {
    return dComIfGp_getSelectItem(i_itemIdx) == WIND_TACT ? 1 : 0;
}

/* 00000314-0000031C       .text XyEventCB__Q210daObjMknjD5Act_cFi */
s16 daObjMknjD::Act_c::XyEventCB(int) {
    return mLessonEventIdx;
}

/* 0000031C-00000620       .text CreateHeap__Q210daObjMknjD5Act_cFv */
int daObjMknjD::Act_c::CreateHeap() {
    /* Nonmatching */
    return 0;
}

/* 00000620-000008E8       .text Create__Q210daObjMknjD5Act_cFv */
int daObjMknjD::Act_c::Create() {
    /* Nonmatching */
    return 0;
}

/* 000008E8-00000A84       .text Mthd_Create__Q210daObjMknjD5Act_cFv */
s32 daObjMknjD::Act_c::Mthd_Create() {
    /* Nonmatching */
    return 0;
}

/* 00000B64-00000BDC       .text Delete__Q210daObjMknjD5Act_cFv */
int daObjMknjD::Act_c::Delete() {
    dComIfGp_getAttention().mFlags &= 0x7fffffff;

    for (int i = 0; i < 4; i++) {
        mSmokeCBs[i].end();
    }

    return 1;
}

/* 00000BDC-00000C34       .text Mthd_Delete__Q210daObjMknjD5Act_cFv */
s32 daObjMknjD::Act_c::Mthd_Delete() {
    int bgDeleteResult = MoveBGDelete();
    
    if (mBase.mUnk2 != 3) {
        dComIfG_resDelete(&mPhs, M_arcname);
    }

    return bgDeleteResult;
}

/* 00000C34-00000CC8       .text set_mtx__Q210daObjMknjD5Act_cFv */
void daObjMknjD::Act_c::set_mtx() {
    /* Nonmatching */
}

/* 00000CC8-00000D28       .text init_mtx__Q210daObjMknjD5Act_cFv */
void daObjMknjD::Act_c::init_mtx() {
    /* Nonmatching */
}

/* 00000D28-00000E04       .text setGoal__Q210daObjMknjD5Act_cFi */
void daObjMknjD::Act_c::setGoal(int) {
    /* Nonmatching */
}

/* 00000E04-00000E84       .text setPlayerAngle__Q210daObjMknjD5Act_cFi */
void daObjMknjD::Act_c::setPlayerAngle(int) {
    /* Nonmatching */
}

/* 00000E84-00000F88       .text talk__Q210daObjMknjD5Act_cFi */
u32 daObjMknjD::Act_c::talk(int i_param1) {
    u32 msgMode = 0xFF;

    if (mMsgInstId == 0xFFFFFFFF) {
        if (i_param1 == 1) {
            u32 msgId;

            if (m0500 == 0) {
                g_dComIfG_gameInfo.play.mTactMode = mTactMode;
                msgId = 0x05B3;
            }
            else {
                msgId = 0x1901;
            }
            
            mMsgId = msgId;
        }

        mMsgInstId = fopMsgM_messageSet(mMsgId, this);
        mMsgPtr = NULL;
    }
    else {
        if (mMsgPtr) {
            msgMode = mMsgPtr->mMode;

            if (msgMode == 0x0E) {
                if (g_dComIfG_gameInfo.play.field_0x4949 != 0) {
                    m0504 = true;
                    fopMsgM_messageSendOn();
                }

                mMsgPtr->mMode = 0x10;
            }
            else if (msgMode == 0x12) {
                mMsgPtr->mMode = 0x13;
                mMsgInstId = 0xFFFFFFFF;
            }
        }
        else {
            mMsgPtr = fopMsgM_SearchByID(mMsgInstId);
        }
    }

    return msgMode;
}

/* 00000F88-00001348       .text privateCut__Q210daObjMknjD5Act_cFv */
void daObjMknjD::Act_c::privateCut() {
    /* Nonmatching */
}

/* 00001348-00001400       .text manage_friend_draw__10daObjMknjDFi */
void daObjMknjD::manage_friend_draw(int i_param1) {
    u16 medliProc = PROC_NPC_MD;
    fopAc_ac_c* judgeResult = static_cast<fopAc_ac_c*>(fopAcIt_Judge(fpcSch_JudgeForPName, &medliProc));

    if (judgeResult != NULL) {
        if (i_param1 == 1) {
            u32 prio = fpcLf_GetPriority(judgeResult);
            fopDwTg_ToDrawQ(&judgeResult->mDwTg, prio);
        }
        else {
            fopDwTg_DrawQTo(&judgeResult->mDwTg);
        }
    }

    u16 makarProc = PROC_NPC_CB1;
    judgeResult = static_cast<fopAc_ac_c*>(fopAcIt_Judge(fpcSch_JudgeForPName, &makarProc));
    
    if (judgeResult != NULL) {
        if (i_param1 == 1) {
            u32 prio = fpcLf_GetPriority(judgeResult);
            fopDwTg_ToDrawQ(&judgeResult->mDwTg, prio);
        }
        else {
            fopDwTg_DrawQTo(&judgeResult->mDwTg);
        }
    }
}

/* 00001400-0000195C       .text daObjMknjD_break__Q210daObjMknjD5Act_cFv */
void daObjMknjD::Act_c::daObjMknjD_break() {
    /* Nonmatching */
}

/* 0000195C-000020E0       .text Execute__Q210daObjMknjD5Act_cFPPA3_A4_f */
int daObjMknjD::Act_c::Execute(float(**)[3][4]) {
    /* Nonmatching */
    return 0;
}

/* 000020E0-000022FC       .text setMaterial__10daObjMknjDFP11J3DMaterialUc */
void daObjMknjD::setMaterial(J3DMaterial* i_mat, u8 i_alpha) {
    for (; i_mat != NULL; i_mat = i_mat->getNext()) {
        if (i_alpha == 0) {
            i_mat->getShape()->hide();
        }
        else {
            i_mat->getShape()->show();

            if (i_alpha == 0xFF) {
                i_mat->setMaterialMode(1);

                i_mat->getPEBlock()->getZMode()->setUpdateEnable(1);
                i_mat->getPEBlock()->getZMode()->setCompareEnable(1);

                i_mat->getPEBlock()->getBlend()->setType(0);
            }
            else {
                i_mat->setMaterialMode(1);

                i_mat->getPEBlock()->getZMode()->setUpdateEnable(0);
                i_mat->getPEBlock()->getZMode()->setCompareEnable(0);

                i_mat->getPEBlock()->getBlend()->setType(1);
                i_mat->getPEBlock()->getBlend()->setSrcFactor(4);
                i_mat->getPEBlock()->getBlend()->setDstFactor(5);
            }

            i_mat->getTevKColor(3)->a = i_alpha;
        }
    }
}

/* 000022FC-00002430       .text Draw__Q210daObjMknjD5Act_cFv */
int daObjMknjD::Act_c::Draw() {
    g_env_light.settingTevStruct(TEV_TYPE_BG0, getPositionP(), &mTevStr);
    g_env_light.setLightTevColorType(mModel1, &mTevStr);

    g_env_light.settingTevStruct(TEV_TYPE_BG0, getPositionP(), &mTevStr);
    g_env_light.setLightTevColorType(mModel0, &mTevStr);

    dComIfGd_setList();

    J3DModelData* mdlData = mModel0->getModelData();
    u16 jointCount = mdlData->getJointNum();
    for (u16 i = 0; i < jointCount; i++) {
        setMaterial(mdlData->getJointNodePointer(i)->getMesh(), mModel0Alpha);
    }

    dComIfGd_setListSky();

    mDoExt_modelUpdateDL(mModel0);
    if (m043D == true) {
        mDoExt_modelUpdateDL(mModel1);
    }

    dComIfGd_setListBG();

    return 1;
}

namespace daObjMknjD {
    namespace {
        /* 00002430-00002450       .text Mthd_Create__Q210daObjMknjD27@unnamed@d_a_obj_mknjd_cpp@FPv */
        s32 Mthd_Create(void* i_this) {
            return static_cast<Act_c*>(i_this)->Mthd_Create();
        }

        /* 00002450-00002470       .text Mthd_Delete__Q210daObjMknjD27@unnamed@d_a_obj_mknjd_cpp@FPv */
        s32 Mthd_Delete(void* i_this) {
            return static_cast<Act_c*>(i_this)->Mthd_Delete();
        }

        /* 00002470-00002490       .text Mthd_Execute__Q210daObjMknjD27@unnamed@d_a_obj_mknjd_cpp@FPv */
        s32 Mthd_Execute(void* i_this) {
            return static_cast<Act_c*>(i_this)->MoveBGExecute();
        }

        /* 00002490-000024BC       .text Mthd_Draw__Q210daObjMknjD27@unnamed@d_a_obj_mknjd_cpp@FPv */
        s32 Mthd_Draw(void* i_this) {
            return static_cast<Act_c*>(i_this)->Draw();
        }

        /* 000024BC-000024E8       .text Mthd_IsDelete__Q210daObjMknjD27@unnamed@d_a_obj_mknjd_cpp@FPv */
        s32 Mthd_IsDelete(void* i_this) {
            return static_cast<Act_c*>(i_this)->IsDelete();
        }

        static actor_method_class Mthd_Table = {
            (process_method_func)Mthd_Create,
            (process_method_func)Mthd_Delete,
            (process_method_func)Mthd_Execute,
            (process_method_func)Mthd_IsDelete,
            (process_method_func)Mthd_Draw,
        };
    }
}

extern actor_process_profile_definition g_profile_Obj_MknjD = {
    fpcLy_CURRENT_e,
    3,
    fpcPi_CURRENT_e,
    PROC_Obj_MknjD,
    &g_fpcLf_Method.mBase,
    sizeof(daObjMknjD::Act_c),
    0,
    0,
    &g_fopAc_Method.base,
    0x01C6,
    &daObjMknjD::Mthd_Table,
    0x00044100,
    fopAc_ACTOR_e,
    fopAc_CULLBOX_CUSTOM_e,
};
