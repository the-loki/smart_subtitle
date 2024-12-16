//
// Created by loki7 on 24-12-16.
//

#define MINIAUDIO_IMPLEMENTATION
#include "audio_capture.h"

audio_capture::audio_capture()
    : device_(), encoder_(), device_config_(), encoder_config_()
{
}

bool audio_capture::init()
{
    ma_backend backends[] = {ma_backend_wasapi};

    device_config_ = ma_device_config_init(ma_device_type_loopback);
    device_config_.pUserData = nullptr;
    device_config_.dataCallback = nullptr;
    device_config_.capture.pDeviceID = nullptr;
    device_config_.sampleRate = 44100;
    device_config_.capture.format = ma_format_f32;
    device_config_.capture.channels = 1;
}
