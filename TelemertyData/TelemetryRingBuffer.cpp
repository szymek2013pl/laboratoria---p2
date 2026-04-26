#include "TelemetryRingBuffer.hpp"

TelemetryRingBuffer::TelemetryRingBuffer(unsigned int capacity) : capacity{capacity}, count{0}, head{0} {

    buffer = new TelemetryData [capacity];
    active_buffers++;

}

TelemetryRingBuffer::~TelemetryRingBuffer() {

    delete [] buffer;
    active_buffers--;

}

TelemetryRingBuffer::TelemetryRingBuffer(const TelemetryRingBuffer& other) : capacity{other.capacity}, count{other.count}, head{other.head} {

    buffer = new TelemetryData [capacity];

    for (unsigned int i = 0; i < capacity; i++) {

        buffer[i] = other.buffer[i];

    }
    
    active_buffers++;

}

TelemetryRingBuffer& TelemetryRingBuffer::operator=(const TelemetryRingBuffer& other) {

    if (this == &other) {

        return *this;

    }

    if (this->capacity != other.capacity) {

        delete [] buffer;
        buffer = new TelemetryData [other.capacity];
        capacity = other.capacity;

    }

    for (unsigned int i = 0; i < capacity; i++) {

        buffer[i] = other.buffer[i];

    }

    count = other.count;
    head = other.head;

    return *this;

}

TelemetryRingBuffer::TelemetryRingBuffer(TelemetryRingBuffer&& other) : buffer{other.buffer}, capacity{other.capacity}, count{other.count}, head{other.head} {

    other.capacity = 0;
    other.head = 0;
    other.count = 0;
    other.buffer = nullptr;

    active_buffers++;


}

TelemetryRingBuffer& TelemetryRingBuffer::operator=(TelemetryRingBuffer&& other) {

    if (this == &other) {

        return *this;

    }
    
    delete [] buffer;

    capacity = other.capacity;
    count = other.count;
    head = other.head;
    buffer = other.buffer;

    other.capacity = 0;
    other.count = 0;
    other.head = 0;
    other.buffer = nullptr;

    return *this;

}


void TelemetryRingBuffer::push(const TelemetryData& data) {

    if (this->count < this->capacity) {

        this->count ++;

    }
    
    this->buffer[this->head] = data;
    this->head = (this->head + 1) % this->capacity;

}

void TelemetryRingBuffer::print_chronological() const {

    int start_index;
    
    if (count == capacity) {

        start_index = head;

    }

    else {

        start_index = 0;

    }

    for (unsigned int i = 0; i < this->count; i++) {

        int current_idx = (start_index + i) % this->capacity;
        this->buffer[current_idx].print();
        

    }

}

unsigned int TelemetryRingBuffer::active_buffers = 0;
