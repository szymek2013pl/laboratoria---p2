#include "alocator.hpp"

void shared_init(SharedInt& p, int value) {

    p.data = new int;
    *(p.data) = value;

    p.ref_count = new int;
    *(p.ref_count) = 1;

}

void shared_copy(SharedInt& dest, const SharedInt& src) {

    if (dest.data == src.data) {

        return;

    }
    
    shared_destroy(dest);

    dest.data = src.data;
    dest.ref_count = src.ref_count;
    
    if (dest.ref_count != nullptr) {

        *(dest.ref_count) += 1;

    }
    
}

void shared_destroy(SharedInt& p) {

    if (p.ref_count != nullptr){
    
        *(p.ref_count) -= 1;

        if (*(p.ref_count) == 0) {

            delete p.data;
            delete p.ref_count;

        }
    }

    p.data = nullptr;
    p.ref_count = nullptr;

}

void ring_init(RingBuffer& rb, int initial_capacity) {

    rb.elements = new int [initial_capacity];
    rb.capacity = initial_capacity;
    rb.size = 0;
    rb.head = 0;
    rb.tail = 0;

}

void ring_push(RingBuffer& rb, int val) {

    if (rb.size == rb.capacity) {

        ring_expand(rb, rb.capacity * 2);

    }

    rb.elements[rb.tail] = val;
    rb.tail = (rb.tail + 1) % rb.capacity;
    rb.size ++;

}

void ring_expand(RingBuffer& rb, int new_cap) {

    int * temp = new int [new_cap];

    for (int i = 0; i < rb.size; i++) {

        int idx = (rb.head + i) % rb.capacity;
        temp[i] = rb.elements[idx];

    }

    delete [] rb.elements;
    rb.elements = temp;

    rb.head = 0;
    rb.tail = rb.size;
    rb.capacity = new_cap;

}

void buffer_init(ByteBuffer& bb, int initial_bytes) {

    bb.data = new char [initial_bytes];
    bb.capacity = initial_bytes;
    bb.current_offset = 0;

}

void buffer_expand(ByteBuffer& bb, int needed_bytes) {

    char * temp;
    
    if (bb.current_offset + needed_bytes > bb.capacity) {

        int new_capacity;
        
        if (bb.current_offset + needed_bytes > 2 * bb.capacity) {

            new_capacity = bb.current_offset + needed_bytes;
            temp = new char [new_capacity];

        }

        else {

            new_capacity = 2 * bb.capacity;
            temp = new char [new_capacity];

        }

        for (int i = 0; i < bb.current_offset; i++) {

            temp[i] = bb.data[i];

        }

        delete [] bb.data;
        bb.data = temp;
        bb.capacity = new_capacity;

    }

}

void buffer_write_int(ByteBuffer& bb, int val) {

    buffer_expand(bb, sizeof(val));

    int * ptr = reinterpret_cast<int*>(&bb.data[bb.current_offset]);
    *ptr = val;

    bb.current_offset += sizeof(val);

}

void buffer_write_string(ByteBuffer& bb, const char* str) {

    int len = strlen(str);

    buffer_expand(bb, len + 1);

    for (int i = 0; i < len; i++) {

        bb.data[i + bb.current_offset] = str[i];

    }

    bb.data[len + bb.current_offset] = '\0';
    bb.current_offset += len + 1;

}
