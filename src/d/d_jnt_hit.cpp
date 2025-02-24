//
// Generated by dtk
// Translation Unit: d_jnt_hit.cpp
//

#include "d/d_jnt_hit.h"
#include "dolphin/types.h"

/* 80060BE8-80060C44       .text __ct__12JntHit_HIO_cFv */
JntHit_HIO_c::JntHit_HIO_c() {
    m06 = 0;
    m08 = 0;
    m0C = 50.0f;
    m10.set(cXyz::Zero);
    m1C = 0.0f;
    m20 = 0.0f;
    m24 = 100.0f;
    mChildID = -1;
}

/* 80060C44-80060EC4       .text CreateInit__8JntHit_cFv */
BOOL JntHit_c::CreateInit() {
    __jnt_hit_data_c* pHitData = mpHitData;
    int posCount = 0;
    int i;
    for (i = 0; i < mHitDataCount; i++) {
        if (isCylinder(pHitData->mShapeType)) {
            posCount += 2;
        } else if (isSphere(pHitData->mShapeType)) {
            posCount += 1;
        }
        pHitData++;
    }
    
    mpShapeTypes = new s16[mHitDataCount];
    mpOffsets = new cXyz[posCount];
    mpRadiuses = new f32[mHitDataCount];
    mpJointIndexes = new s16[mHitDataCount];
    if (!mpShapeTypes || !mpOffsets || !mpRadiuses || !mpJointIndexes) {
        return FALSE;
    }
    
    pHitData = mpHitData;
    s16* pShapeType = mpShapeTypes;
    s16* pJointIndex = mpJointIndexes;
    f32* pRadius = mpRadiuses;
    cXyz* pOffset = mpOffsets;
    for (i = 0; i < mHitDataCount;) {
        pShapeType[0] = pHitData->mShapeType;
        pJointIndex[0] = pHitData->mJointIndex;
        pRadius[0] = pHitData->mRadius;
        
        if (isCylinder(pShapeType[0])) {
            pOffset[0] = pHitData->mpOffsets[0];
            pOffset[1] = pHitData->mpOffsets[1];
            pOffset++;
        } else if (isSphere(pShapeType[0])) {
            pOffset[0] = pHitData->mpOffsets[0];
        }
        
        pOffset++;
        i++;
        pHitData++;
        pShapeType++;
        pJointIndex++;
        pRadius++;
    }
    
    return TRUE;
}

/* 80060EC4-80061440       .text CylHitPosAngleOffset__8JntHit_cFP4cXyzP5csXyzP4cXyzP5csXyz4cXyz4cXyzf */
void JntHit_c::CylHitPosAngleOffset(cXyz*, csXyz*, cXyz*, csXyz*, cXyz, cXyz, f32) {
    /* Nonmatching */
}

/* 80061440-80061830       .text Cyl2HitPosAngleOffset__8JntHit_cFP4cXyzP5csXyzP4cXyzP5csXyz4cXyz4cXyzf */
void JntHit_c::Cyl2HitPosAngleOffset(cXyz*, csXyz*, cXyz*, csXyz*, cXyz, cXyz, f32) {
    /* Nonmatching */
}

/* 80061830-80061ACC       .text SphHitPosAngleOffset__8JntHit_cFP4cXyzP5csXyzP4cXyzP5csXyz4cXyzf */
void JntHit_c::SphHitPosAngleOffset(cXyz*, csXyz*, cXyz*, csXyz*, cXyz, f32) {
    /* Nonmatching */
}

/* 80061ACC-80061C28       .text HitBufferUpdate__8JntHit_cFPiP4cXyziP5csXyzP4cXyz */
void JntHit_c::HitBufferUpdate(int*, cXyz*, int, csXyz*, cXyz*) {
    /* Nonmatching */
}

/* 80061C28-800627DC       .text searchJntHitPosAngleOffset__8JntHit_cFP4cXyzP5csXyzP4cXyzP5csXyz */
s32 JntHit_c::searchJntHitPosAngleOffset(cXyz*, csXyz*, cXyz*, csXyz*) {
    /* Nonmatching */
}

/* 800627DC-8006286C       .text JntHit_create__FP8J3DModelP16__jnt_hit_data_cs */
JntHit_c* JntHit_create(J3DModel* model, __jnt_hit_data_c* jntHitData, s16 hitDataCount) {
    JntHit_c * pJntHit = new JntHit_c();

    if (pJntHit != NULL) {
        pJntHit->mpHitData = jntHitData;
        pJntHit->mpModel = model;
        pJntHit->mHitDataCount = hitDataCount;
        if (pJntHit->CreateInit())
            return pJntHit;
    }

    return NULL;
}

/* 8006286C-800628B4       .text __dt__12JntHit_HIO_cFv */
JntHit_HIO_c::~JntHit_HIO_c() {
    /* Nonmatching */
}

