#ifndef D_A_PLAYER_NPC_H
#define D_A_PLAYER_NPC_H

#include "d/actor/d_a_player.h"
#include "d/d_bg_s_acch.h"

class daPy_npc_c : public daPy_py_c {
public:
    /* 0x320 */ dBgS_ObjAcch mAcch;
    /* 0x4E4 */ u32 m4E4;
    /* 0x4E8 */ u8 m4E8;
    /* 0x4E9 */ u8 mDamageFogTimer;
    /* 0x4EA */ u8 field_4EA[0x4EC - 0x4EA];
    
    void returnLink() { m4E4 |= 1; }
    void offReturnLink() { m4E4 &= ~1; }
    bool isReturnLink() { return m4E4 & 1; }
    void onEventAccept() { m4E4 |= 2; }
    void offEventAccept() { m4E4 &= ~2; }
    bool isEventAccept() { return m4E4 & 2; }
    
    u8 getDamageFogTimer() { return mDamageFogTimer; }
    void setDamageFogTimer(u8 timer) { mDamageFogTimer = timer; }
    void executeDamageFog() { cLib_calcTimer(&mDamageFogTimer); }
    
    virtual void restartPoint(s16) {}
    virtual BOOL isTagCheckOK() { return TRUE; }
    virtual void setMessageAnimation(u8) {}
    
    int check_initialRoom();
    BOOL check_moveStop();
    void setRestart(s8);
    void unconditionalSetRestart(s8);
    void setOffsetHomePos();
    void setPointRestart(s16, s8);
    BOOL checkRestart(s8);
    BOOL initialRestartOption(s8, int);
    BOOL checkNowPosMove(const char*);
    void drawDamageFog();
    int chkMoveBlock(cXyz*);
};

void* daPy_npc_JudgeForPNameAndDistance(void* i_actor, void* i_prm);
fopAc_ac_c* daPy_npc_SearchAreaByName(fopAc_ac_c* i_this, s16 procName, f32 areaRadius, cXyz* outActorOffset);

#endif /* D_A_PLAYER_NPC_H */
