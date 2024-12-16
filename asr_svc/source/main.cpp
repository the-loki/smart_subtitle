//
// Created by loki7 on 24-12-15.
//

#include <audio_capture.h>
#include <cstdio>

int main()
{
    smart_subtitle::AudioCapture capture;
    capture.Start();
    capture.SetCallback([](const uint8_t* data, size_t size) {});

    getchar();
    return 0;
}
