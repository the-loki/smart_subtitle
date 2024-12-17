//
// Created by loki7 on 24-12-16.
//

#pragma once

#include <chrono>
#include <cstdint>
#include <functional>
#include <miniaudio.h>

namespace smart_subtitle
{
    class AudioCapture final
    {
    protected:
        bool started_;
        ma_device device_;
        ma_device_config device_config_;

    public:
        std::chrono::time_point<std::chrono::steady_clock> start_time_;
        std::function<void(const uint8_t* data, size_t size, uint64_t)> audio_data_callback_;

    public:
        AudioCapture();

        virtual bool Start();

        virtual ~AudioCapture();

        void SetCallback(const decltype(audio_data_callback_)& callback);
    };
}
