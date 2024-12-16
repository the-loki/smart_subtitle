//
// Created by loki7 on 24-12-16.
//

#pragma once

#include <miniaudio.h>

class audio_capture
{
protected:
    ma_device device_;
    ma_encoder encoder_;
    ma_device_config device_config_;
    ma_encoder_config encoder_config_;

public:
    audio_capture();
    virtual bool init();
    virtual ~audio_capture();
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void set_callback(void (*callback)(const void* data, size_t size)) = 0;
};
