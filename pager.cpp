#include <iostream>
#include <string>
#include <vector>
#include "bounded_buffer.hpp"

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