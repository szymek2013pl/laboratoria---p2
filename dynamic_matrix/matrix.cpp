#include "dynamic_matrix.hpp"

void matrix_init(DynamicMatrix& m, int rows, int cols) {

    m.data = new int *[rows];
    m.rows = rows;
    m.cols = cols;

    for (int i = 0; i < m.rows; i++) {

        m.data[i] = new int [m.cols];

    }

}

void matrix_destroy(DynamicMatrix& m) {

    for (int i = 0; i < m.rows; i++) {

        delete [] m.data[i];

    }

    delete [] m.data;

    m.data = nullptr;
    m.rows = 0;
    m.cols = 0;

}

void matrix_fill(DynamicMatrix& m, int value) {

    for (int i = 0; i < m.rows; i++) {

        for (int j = 0; j < m.cols; j++) {

            m.data[i][j] = value;

        }

    }

}

void matrix_print(DynamicMatrix& m) {

    if (m.rows == 0 || m.cols == 0) {

        std::cout << "macierz jest pusta" << std::endl;

        return;

    }
    
    for (int i = 0; i < m.rows; i++) {

        for (int j = 0; j < m.cols; j++) {

            std::cout << m.data[i][j] << " ";

        }

        std::cout << std::endl;

    }

}

void matrix_add_row(DynamicMatrix& m) {

    int ** new_data = new int * [m.rows + 1];
    
    for (int i = 0; i < m.rows; i++) {

        new_data[i] = m.data[i];

    }

    new_data[m.rows] = new int [m.cols];

    delete [] m.data;

    m.rows += 1;
    m.data = new_data;

}
