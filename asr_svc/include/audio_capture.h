//
// Created by loki7 on 24-12-16.
//

#pragma once

#include <cstdint>
#include <functional>
#include <miniaudio.h>

namespace smart_subtitle {
    class AudioCapture final {
    protected:
        bool started_;
        ma_device device_;
        ma_device_config device_config_;

    public:
        std::function<void(const uint8_t *data, size_t size)> audio_data_callback_;

    public:
        AudioCapture();

        virtual bool Start();

        virtual ~AudioCapture();

        void SetCallback(const decltype(audio_data_callback_) &callback);
    };
}
