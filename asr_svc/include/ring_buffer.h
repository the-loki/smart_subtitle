//
// Created by loki7 on 24-12-18.
//

#pragma once
#include <atomic>
#include <vector>

namespace smart_subtitle
{
    class RingBuffer
    {
    public:
        explicit RingBuffer(size_t capacity);
        bool Push(const uint8_t* data, size_t size);
        bool Pop(uint8_t* data, size_t size);

    private:
        size_t Increment(size_t index, size_t step) const;

        std::atomic<size_t> head_;
        std::atomic<size_t> tail_;
        std::vector<uint8_t> buffer_;
    };
} // smart_subtitle
