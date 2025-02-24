#ifndef D_D_DETECT_H
#define D_D_DETECT_H

#include "SSystem/SComponent/c_xyz.h"

class dDetectPlace_c {
public:
    /* 0x00 */ cXyz mPos;
    /* 0x0C */ s16 mEnable;
};

class dDetect_c {
public:
    dDetect_c();
    ~dDetect_c();

    void proc();
    bool chk_quake(const cXyz*) const;
    void set_quake(const cXyz*);
    void chk_quake_area(const cXyz*) const;
    void search_tag_light(void*, void*);
    void chk_light(const cXyz*) const;
    void chk_attention(cXyz*) const;

    /* 0x00 */ dDetectPlace_c mPlace[1];
    /* 0x10 */ s16 mTimer;
};  // Size: 0x14

#endif /* D_D_DETECT_H */