#ifndef DYNAMIC_MATRIX_HPP
#define DYNAMIC_MATRIX_HPP

#include <iostream>

struct DynamicMatrix {

    int ** data;
    int rows;
    int cols;

};

void matrix_init(DynamicMatrix& m, int rows, int cols);

void matrix_destroy(DynamicMatrix& m);

void matrix_fill(DynamicMatrix& m, int value);

void matrix_print(DynamicMatrix& m);

void matrix_add_row(DynamicMatrix& m);

#endif
