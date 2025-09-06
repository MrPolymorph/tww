#ifndef D_A_OBJ_MAGMAROCK_H
#define D_A_OBJ_MAGMAROCK_H

#include "f_op/f_op_actor.h"

class dBgW;

namespace daObjMagmarock {
    static void ride_call_back(dBgW*, fopAc_ac_c*, fopAc_ac_c*);
    static BOOL CheckCreateHeap(fopAc_ac_c*);
    
    class Act_c : public fopAc_ac_c {
    public:
        void MeltDownRequest() {}
        inline cPhs_State _create();
        inline bool _delete();
        inline bool _draw();
        inline bool _execute();
        void checkProcess(void (daObjMagmarock::Act_c::*)()) {}
        void setProcess(void (daObjMagmarock::Act_c::*)()) {}
    
        void set_mtx();
        void demo_move();
        void ControlEffect();
        void play_anim();
        void appear_proc_init();
        void appear_proc();
        void wait_proc_init();
        void wait_proc();
        void stay_proc_init();
        void stay_proc();
        void quake_proc_init();
        void quake_proc();
        void vanish_proc_init();
        void vanish_proc();
        BOOL CreateHeap();
        void CreateInit();
        void LiftUpRequest(cXyz&);
        void BeforeLiftRequest(cXyz&);
        void calc_ground_quat();
        const static char M_arcname[];
    public:
        /* Place member variables here */
        J3DModel* field_0x2F4;
        mDoExt_brkAnm* M_brk;
        mDoExt_bckAnm* M_bck;
        J3DAnmTevRegKey field_0x2F8;
        J3DAnmTransform field_0x314;
        Mtx field_0x328;
        cXyz field_0x214;
        int field_0x430;
        int field_0x4298;
        int field_0x429A;
        int field_0x450;
        int field_0x448;
        int field_0x44C;
        int field_0x438;
        int field_0x454;
        int field_0x456;
        int field_0x458;
        int field_0x29E;
        Quaternion field_0x2B0;
        Quaternion field_0x2C0;
        Quaternion field_0x2D0;
        u8 field_0x29F;
        JPABaseEmitter* field_0x2A0;
        JPABaseEmitter* field_0x2A4;
        dBgW* field_0x358;
        dKy_tevstr_c field_0x35C;
        //dBgW* field_0x32C;
        void* ptr;
    };
    
    namespace Method {
        cPhs_State Create(void*);
        BOOL Delete(void*);
        BOOL Execute(void*);
        BOOL Draw(void*);
        BOOL IsDelete(void*);
        extern actor_method_class Table;
    };
};

#endif /* D_A_OBJ_MAGMAROCK_H */
