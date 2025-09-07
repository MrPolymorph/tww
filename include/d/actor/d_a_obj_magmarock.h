#ifndef D_A_OBJ_MAGMAROCK_H
#define D_A_OBJ_MAGMAROCK_H

#include "f_op/f_op_actor.h"

class dBgW;

namespace daObjMagmarock {
    static void ride_call_back(dBgW*, fopAc_ac_c*, fopAc_ac_c*);
    static BOOL CheckCreateHeap(fopAc_ac_c*);
    
    class Act_c : public fopAc_ac_c {
    public:
        typedef void (Act_c::*ProcFunc)();

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
        BOOL BeforeLiftRequest(cXyz&);
        void calc_ground_quat();
        const static char M_arcname[];
        //virtual ~Act_c();
    public:
        /* Place member variables here */
        u8 field_0x294[0xB];
        s16 field_0x298;
        int field_0x29A;
        s16 field_0x29C;
        u8 field_0x29E;
        u8 field_0x29F;
        JPABaseEmitter* field_0x2A0;
        JPABaseEmitter* field_0x2A4;
        Quaternion field_0x2B0;
        Quaternion field_0x2C0;
        Quaternion field_0x2D0;
        ProcFunc field_0x2E0;
        request_of_phase_process_class field_0x2EC;
        J3DModel* field_0x2F4;
        mDoExt_brkAnm* M_brk;
        mDoExt_bckAnm* M_bck;
        J3DAnmTevRegKey* field_0x2F8;
        J3DAnmTransform* field_0x314;
        Mtx field_0x328;
        dBgW* field_0x358;
        dKy_tevstr_c field_0x35C;
        f32 field_0x430;
        f32 field_0x434;
        f32 field_0x438;
        cXyz field_0x43C;
        int field_0x448;
        int field_0x44C;
        int field_0x450;
        s16 field_0x454;
        s16 field_0x456;
        s16 field_0x45A;
        s16 field_0x45C;
        s16 field_0x45E;
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
