#ifndef ALOCATOR_HPP
#define ALOCATOR_HPP

#include <cstring>

// - zliczanie referencji i plytka kopia

struct SharedInt {
    
    int* data;  
    int* ref_count;

};

void shared_init(SharedInt& p, int value);

void shared_copy(SharedInt& dest, const SharedInt& src);

void shared_destroy(SharedInt& p);

// - kolejka

struct RingBuffer {
    
    int* elements;
    int capacity; 
    int size;     
    int head;
    int tail;
         
};

void ring_init(RingBuffer& rb, int initial_capacity);

void ring_push(RingBuffer& rb, int val);

void ring_expand(RingBuffer& rb, int new_cap);

// - operowanie na bajtach

struct ByteBuffer {
    
    char* data;
    int capacity;
    int current_offset;

};

void buffer_init(ByteBuffer& bb, int initial_bytes);

void buffer_expand(ByteBuffer& bb, int needed_bytes);

void buffer_write_int(ByteBuffer& bb, int val);

void buffer_write_string(ByteBuffer& bb, const char* str);

#endif
