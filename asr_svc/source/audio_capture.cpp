//
// Created by loki7 on 24-12-16.
//

#define MINIAUDIO_IMPLEMENTATION
#include "audio_capture.h"

static void AudioDataCallbackWrapper(ma_device *device, void *output, const void *input,
                                     const ma_uint32 frame_count) {
    if (const auto target = static_cast<smart_subtitle::AudioCapture *>(device->pUserData);
        target && target->audio_data_callback_) {
        const auto data = static_cast<const uint8_t *>(input);
        const auto size = frame_count * device->capture.channels * ma_get_bytes_per_sample(device->capture.format);
        target->audio_data_callback_(data, size);
    }
}

namespace smart_subtitle {
    AudioCapture::AudioCapture(): started_(false), device_(), device_config_() {
    }

    bool AudioCapture::Start() {
        if (started_) {
            return false;
        }

        constexpr ma_backend backends[] = {ma_backend_wasapi};
        device_config_ = ma_device_config_init(ma_device_type_loopback);
        device_config_.pUserData = this;
        device_config_.capture.pDeviceID = nullptr;
        device_config_.sampleRate = 44100;
        device_config_.capture.channels = 1;
        device_config_.capture.format = ma_format_f32;
        device_config_.dataCallback = &AudioDataCallbackWrapper;

        if (const auto result = ma_device_init_ex(backends, std::size(backends), nullptr,
                                                  &device_config_,
                                                  &device_); result != MA_SUCCESS) {
            printf("Failed to initialize loop-back device.\n");
            return false;
        }

        if (const auto result = ma_device_start(&device_); result != MA_SUCCESS) {
            ma_device_uninit(&device_);
            printf("Failed to start loop-back device.\n");
            return false;
        }

        started_ = true;
        return true;
    }

    AudioCapture::~AudioCapture() {
        if (started_) {
            ma_device_uninit(&device_);
        }
    }

    void AudioCapture::SetCallback(const decltype(audio_data_callback_) &callback) {
        this->audio_data_callback_ = callback;
    }
}
