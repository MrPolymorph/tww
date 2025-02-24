//
// Generated by dtk
// Translation Unit: JASDriverIF.cpp
//

#include "JSystem/JAudio/JASDriverIF.h"
#include "JSystem/JAudio/JASDSPChannel.h"
#include "JSystem/JAudio/JASDSPInterface.h"
#include "JSystem/JUtility/JUTAssert.h"

/* 8028A978-8028A9A0       .text init__Q28JASystem6DriverFv */
void JASystem::Driver::init() {
    /* Nonmatching */
    DSPInterface::initBuffer();
    TDSPChannel::initAll();
    //TGlobalChannel::init();
}

u16 JASystem::Driver::MAX_MIXERLEVEL = 0x2ee0;

/* 8028A9A0-8028AAC4       .text setMixerLevel__Q28JASystem6DriverFff */
void JASystem::Driver::setMixerLevel(f32 channel_level, f32 dsp_level) {
    /* Nonmatching */
    JUT_ASSERT(58, (0.0 <= channel_level) && (channel_level <= 2.0));
    JUT_ASSERT(59, (0.0 <= dsp_level) && (dsp_level <= 8.0));
    MAX_MIXERLEVEL = channel_level * 16383.5f;
    DSPInterface::setDSPMixerLevel(dsp_level);
}

/* 8028AAC4-8028AACC       .text getChannelLevel__Q28JASystem6DriverFv */
u16 JASystem::Driver::getChannelLevel() {
    return MAX_MIXERLEVEL;
}

u16 JASystem::Driver::MAX_AUTOMIXERLEVEL = 0x7fff;

/* 8028AACC-8028AAD4       .text getAutoLevel__Q28JASystem6DriverFv */
u16 JASystem::Driver::getAutoLevel() {
    return MAX_AUTOMIXERLEVEL;
}

u32 JASystem::Driver::JAS_SYSTEM_OUTPUT_MODE = 1;

/* 8028AAD4-8028AADC       .text setOutputMode__Q28JASystem6DriverFUl */
void JASystem::Driver::setOutputMode(u32 param_1) {
    JAS_SYSTEM_OUTPUT_MODE = param_1;
}

/* 8028AADC-8028AAE4       .text getOutputMode__Q28JASystem6DriverFv */
u32 JASystem::Driver::getOutputMode() {
    return JAS_SYSTEM_OUTPUT_MODE;
}

u8 JASystem::Driver::JAS_UPDATE_INTERVAL = 1;

/* 8028AAE4-8028AAEC       .text getUpdateInterval__Q28JASystem6DriverFv */
u8 JASystem::Driver::getUpdateInterval() {
    return JAS_UPDATE_INTERVAL;
}
