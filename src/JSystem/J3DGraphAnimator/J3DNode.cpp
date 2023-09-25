//
// Generated by dtk
// Translation Unit: J3DNode.cpp
//

#include "JSystem/J3DGraphAnimator/J3DNode.h"
#include "dolphin/types.h"

/* 802F5BA4-802F5BC8       .text __ct__7J3DNodeFv */
J3DNode::J3DNode() {
    mCallBackUserData = NULL;
    mCallBack = NULL;
    mChild = NULL;
    mYounger = NULL;
}

/* 802F5BC8-802F5C10       .text __dt__7J3DNodeFv */
J3DNode::~J3DNode() {
    /* Nonmatching */
}

/* 802F5C10-802F5C44       .text appendChild__7J3DNodeFP7J3DNode */
void J3DNode::appendChild(J3DNode* pChild) {
    if (mChild == NULL) {
        mChild = pChild;
    } else {
        J3DNode* curChild = mChild;
        while (curChild->getYounger() != NULL) {
            curChild = curChild->getYounger();
        }
        curChild->setYounger(pChild);
    }
}

/* 802F5C44-802F5C48       .text entryIn__7J3DNodeFv */
void J3DNode::entryIn() {
    /* Nonmatching */
}
