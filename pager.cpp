#include <iostream>
#include <string>
#include <vector>

struct bounded_buffer {

    std::vector <std::string> buffer;
    int capacity;

};

int buffer_size(const bounded_buffer * buffer) {

    return buffer -> buffer.size();

}

int buffer_capacity(const bounded_buffer * buffer) {

    return buffer -> capacity;

}

void flush_buffer(bounded_buffer * buffer) {

    for (int i = 0; i < buffer -> buffer.size(); i++) {

        std::cout << buffer->buffer[i] << std::endl;

    }

}

void add_to_buffer(bounded_buffer * buffer, std::string line) {

    if (buffer->buffer.size() >= buffer->capacity) {

        return;

    }

    buffer->buffer.push_back(line);

}

int main () {

    std::vector<std::string> vec;

    bounded_buffer b;
    b.buffer = vec;
    b.capacity = 4;

    add_to_buffer(&b, "pies");
    add_to_buffer(&b, "kot");
    flush_buffer(&b);

    std::cout << buffer_size(&b) << std::endl;
    std::cout << buffer_capacity(&b) << std::endl;

}