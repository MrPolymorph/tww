#ifndef D_A_OBJ_RCLOUD_H
#define D_A_OBJ_RCLOUD_H

#include "f_op/f_op_actor.h"
#include "m_Do/m_Do_ext.h"
#include "d/d_a_obj.h"

class daObjRcloud_c : public fopAc_ac_c {
public:
    typedef void (daObjRcloud_c::*ProcFunc)();
    void param_get_arg() const {}

    void init_mtx();
    static BOOL solidHeapCB(fopAc_ac_c*);

    u8 create_heap();
    cPhs_State _create();
    u8 _delete();
    void wait_act_proc();
    void clouds_lift_start_wait_act_proc();
    void clouds_lift_act_proc();
    void setup_action(int);
    bool _execute();
    void setTexMtx();
    bool _draw();

    enum Prm_e {
        PRM_UNK_01 = 0x01,
        PRM_UNK_0 = 0x0,
    };

public:
    /* 0x290 */ request_of_phase_process_class mPhase;
    /* 0x298 */ J3DModel* mpModel;
    /* 0x29C */ mDoExt_btkAnm mBtkAnm;
    /* 0x2B0 */ ProcFunc mCurrProcFunc;
    /* 0x2BC */ int m2BC;
    /* 0x2C0 */ int m2C0;
    /* 0x2C4 */ u8 m2C4;
    /* 0x2C5 */ u8 m2C5[0x2C8 - 0x2C5];
    /* 0x2C8 */ f32 m2C8;
};

#endif /* D_A_OBJ_RCLOUD_H */
