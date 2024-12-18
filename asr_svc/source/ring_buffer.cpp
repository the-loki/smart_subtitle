//
// Created by loki7 on 24-12-18.
//

#include "ring_buffer.h"

namespace smart_subtitle
{
    RingBuffer::RingBuffer(const size_t capacity) : head_(0), tail_(0), buffer_(capacity)
    {
    }


    bool RingBuffer::Push(const uint8_t* data, const size_t size)
    {
        const size_t current_tail = tail_.load(std::memory_order_relaxed);
        const size_t next_tail = Increment(current_tail, size);

        if (next_tail > buffer_.size() || next_tail == head_.load(std::memory_order_acquire))
        {
            return false;
        }

        std::memcpy(&buffer_[current_tail], data, size);
        tail_.store(next_tail, std::memory_order_release);
        return true;
    }

    bool RingBuffer::Pop(uint8_t* data, const size_t size)
    {
        const size_t current_head = head_.load(std::memory_order_relaxed);

        if (current_head + size > buffer_.size() || current_head == tail_.load(std::memory_order_acquire))
        {
            return false;
        }

        std::memcpy(data, &buffer_[current_head], size);
        head_.store(Increment(current_head, size), std::memory_order_release);
        return true;
    }


    size_t RingBuffer::Increment(const size_t index, const size_t step) const
    {
        return (index + step) % buffer_.size();
    }
} // smart_subtitle
