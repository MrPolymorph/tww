#ifndef JAIANIMATION_H
#define JAIANIMATION_H

#include "global.h"

class Vec;
class JAISound;
class JAIBasic;
namespace JAInter {
    class Actor;
};
class JAIAnimeFrameSoundData;

struct JAIAnimeSound__Slot {
    /* 0x0 */ u8 mbIsPlaying;
    /* 0x4 */ JAISound* mpSound;
    /* 0x8 */ void* mpData;
};

class JAIAnimeSound {
public:
    JAIAnimeSound();
    void initActorAnimSound(void*, u32, f32);
    void setAnimSoundVec(JAIBasic*, Vec*, f32, f32, u32, u8);
    void setAnimSoundActor(JAIBasic*, JAInter::Actor*, f32, f32, u8);
    void playActorAnimSound(JAIBasic*, JAInter::Actor*, f32, u8);
    void startAnimSound(void*, u32, JAISound**, JAInter::Actor*, u8);
    void setSpeedModifySound(JAISound*, JAIAnimeFrameSoundData*, f32);
    void stop();

public:
    /* 0x00 */ JAIAnimeSound__Slot mSlots[8];
    /* 0x60 */ u32 m60;
    /* 0x64 */ u32 m64;
    /* 0x68 */ u32 m68;
    /* 0x6C */ u32 m6C;
    /* 0x70 */ void* m70[2];
    /* 0x78 */ int mDataCounterInc;
    /* 0x7C */ int mDataCounterLimit;
    /* 0x80 */ u32 mDataCounter;
    /* 0x84 */ int mLoopCount;
    /* 0x88 */ f32 mCurrentTime;
    /* 0x8C */ u8 m8C[0x90 - 0x8C];
    /* 0x90 */ u16* mpData;
    /* 0x94 */ /* vtable */
};  // Size: 0x98

#endif /* JAIANIMATION_H */
