#ifndef TELEMETRYRINGBUFFER_HPP
#define TELEMETRYRINGBUFFER_HPP

#include "TelemetryData.hpp"

class TelemetryRingBuffer {

    private:

        TelemetryData* buffer;
        unsigned int capacity;
        unsigned int count;
        unsigned int head;
        static unsigned int active_buffers;
    
    public:

        TelemetryRingBuffer(unsigned int capacity = 5);
        ~TelemetryRingBuffer();

        TelemetryRingBuffer(const TelemetryRingBuffer& other);
        TelemetryRingBuffer& operator=(const TelemetryRingBuffer& other);

        TelemetryRingBuffer(TelemetryRingBuffer&& other);
        TelemetryRingBuffer& operator=(TelemetryRingBuffer&& other);

        void push(const TelemetryData& data);
        void print_chronological() const;

        static unsigned int get_active_buffers_count() {

            return active_buffers;

        }

};

#endif
