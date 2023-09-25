//
// Generated by dtk
// Translation Unit: JUTVideo.cpp
//

#include "JSystem/JUtility/JUTVideo.h"
#include "JSystem/JUtility/JUTDirectPrint.h"
#include "JSystem/JUtility/JUTXfb.h"
#include "dolphin/gx/GX.h"

JUTVideo* JUTVideo::sManager;
OSTick JUTVideo::sVideoLastTick;
OSTick JUTVideo::sVideoInterval;
static bool sDrawWaiting;

/* 802C7C34-802C7C8C       .text createManager__8JUTVideoFPC16_GXRenderModeObj */
JUTVideo* JUTVideo::createManager(const GXRenderModeObj* param_0) {
    if (sManager == NULL) {
        sManager = new JUTVideo(param_0);
    }
    return sManager;
}

/* 802C7C8C-802C7CD4       .text destroyManager__8JUTVideoFv */
void JUTVideo::destroyManager() {
    if (sManager != NULL) {
        delete sManager;
        sManager = NULL;
    }
}

/* 802C7CD4-802C7DC8       .text __ct__8JUTVideoFPC16_GXRenderModeObj */
JUTVideo::JUTVideo(const GXRenderModeObj* param_0) {
    mRenderObj = NULL;
    VIInit();
    setRenderMode(param_0);
    mSetBlack = true;
    mSetBlackFrameCount = 2;
    VISetBlack(1);
    VIFlush();
    field_0x8 = 0;
    mRetraceCount = VIGetRetraceCount();
    field_0x10 = 1;
    field_0x18 = 0;
    sVideoLastTick = OSGetTick();
    sVideoInterval = 670000;
    mPreRetraceCallback = VISetPreRetraceCallback(preRetraceProc);
    mPostRetraceCallback = VISetPostRetraceCallback(postRetraceProc);
    mPreCallback = NULL;
    mPostCallback = NULL;
    OSInitMessageQueue(&mMessageQueue, &mMessage, 1);
    GXSetDrawDoneCallback(drawDoneCallback);
}

/* 802C7DC8-802C7E30       .text __dt__8JUTVideoFv */
JUTVideo::~JUTVideo() {
    VISetPreRetraceCallback(mPreRetraceCallback);
    VISetPostRetraceCallback(mPostRetraceCallback);
}

/* 802C7E30-802C8054       .text preRetraceProc__8JUTVideoFUl */
void JUTVideo::preRetraceProc(u32 retrace_count) {
    if (sManager->mPreCallback) {
        (*sManager->mPreCallback)(retrace_count);
    }

    OSTick tick = OSGetTick();
    sVideoInterval = tick - sVideoLastTick;
    sVideoLastTick = tick;

    JUTXfb* xfb = JUTXfb::getManager();
    if (!xfb) {
        VISetBlack(TRUE);
        VIFlush();
        return;
    }

    static void* frameBuffer = NULL;

    if (frameBuffer) {
        JUTVideo* videoManager = JUTGetVideoManager();
        const GXRenderModeObj* renderMode = videoManager->getRenderMode();
        JUTDirectPrint* directPrint = JUTDirectPrint::getManager();
        directPrint->changeFrameBuffer(frameBuffer, renderMode->fb_width, renderMode->efb_height);
    }

    if (sManager->mSetBlack == 1) {
        s32 frame_count = sManager->mSetBlackFrameCount;
        if (frame_count > 0) {
            frame_count--;
        }

        sManager->mSetBlackFrameCount = frame_count;
        sManager->mSetBlack = frame_count != 0;
        VISetBlack(TRUE);
        VIFlush();
        return;
    }

    if (!xfb) {
        VISetBlack(TRUE);
        VIFlush();
        return;
    }

    if (xfb->getBufferNum() == 3 || xfb->getBufferNum() == 2) {
        if (!sDrawWaiting) {
            s16 index = xfb->getDrawnXfbIndex();
            xfb->setDisplayingXfbIndex(index);
            if (index < 0) {
                VISetBlack(1);
                VIFlush();
            } else {
                VISetBlack(FALSE);
                VISetNextFrameBuffer(xfb->getDisplayingXfb());
                VIFlush();
                frameBuffer = xfb->getDisplayingXfb();
            }
        }
    } else if (xfb->getBufferNum() == 1) {
        if (xfb->getSDrawingFlag() == 0) {
            s16 index = xfb->getDrawnXfbIndex();
            if (index >= 0) {
                xfb->setDisplayingXfbIndex(index);
                GXCopyDisp(xfb->getDisplayingXfb(), GX_TRUE);
                GXFlush();
                xfb->setSDrawingFlag(2);
                frameBuffer = xfb->getDisplayingXfb();
                VISetBlack(FALSE);
            } else {
                VISetBlack(TRUE);
            }
        }
        VIFlush();
    }
}

/* 802C8054-802C807C       .text drawDoneStart__8JUTVideoFv */
void JUTVideo::drawDoneStart() {
    sDrawWaiting = true;
    GXSetDrawDone();
}

/* 802C807C-802C8088       .text dummyNoDrawWait__8JUTVideoFv */
void JUTVideo::dummyNoDrawWait() {
    sDrawWaiting = false;
}

/* 802C8088-802C8110       .text drawDoneCallback__8JUTVideoFv */
void JUTVideo::drawDoneCallback() {
    JUTXfb* xfb = JUTXfb::getManager();
    if (!xfb) {
        return;
    }

    sDrawWaiting = false;
    if (xfb->getBufferNum() == 1) {
        if (xfb->getSDrawingFlag() == 1) {
            xfb->setSDrawingFlag(0);

            void* frameBuffer = xfb->getDrawnXfb();
            if (frameBuffer) {
                VISetNextFrameBuffer(xfb->getDrawnXfb());
                VIFlush();
            }
        }
    }
}

/* 802C8110-802C815C       .text postRetraceProc__8JUTVideoFUl */
void JUTVideo::postRetraceProc(u32 retrace_count) {
    if (sManager->mPostCallback != NULL) {
        sManager->mPostCallback(retrace_count);
    }

    OSMessage message = (OSMessage*)VIGetRetraceCount();
    OSSendMessage(&sManager->mMessageQueue, message, OS_MESSAGE_NOBLOCK);
}

/* 802C815C-802C81D4       .text setRenderMode__8JUTVideoFPC16_GXRenderModeObj */
void JUTVideo::setRenderMode(const GXRenderModeObj* pObj) {
    if (mRenderObj != NULL && pObj->vi_tv_mode != mRenderObj->vi_tv_mode) {
        mSetBlack = true;
        mSetBlackFrameCount = 4;
    }
    mRenderObj = (GXRenderModeObj*)pObj;
    VIConfigure(mRenderObj);
    VIFlush();

    if (mSetBlack) {
        VIWaitForRetrace();
        VIWaitForRetrace();
    }
}

/* 802C81D4-802C81D8       .text waitRetraceIfNeed__8JUTVideoFv */
void JUTVideo::waitRetraceIfNeed() {
    /* Nonmatching */
}
