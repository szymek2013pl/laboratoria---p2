#include "ComplexMatrix.hpp"
#include "Complex.hpp"

ComplexMatrix::ComplexMatrix(unsigned int r, unsigned int c) : rows{r}, cols{c} {

    data = new Complex [rows * cols];

}

ComplexMatrix::ComplexMatrix(const ComplexMatrix& other) : rows{other.rows}, cols{other.cols} {

    data = new Complex [rows * cols];

    for (unsigned int i = 0; i < rows * cols; i++) {

        data[i] = other.data[i];

    }

}

ComplexMatrix& ComplexMatrix::operator=(const ComplexMatrix& other) {

    if (this == &other) {

        return *this;

    }

    Complex * temp = new Complex [other.rows * other.cols];

    for (unsigned int i = 0; i < other.rows * other.cols; i++) {

        temp[i] = other.data[i];

    }
    
    delete [] data;

    data = temp;

    rows = other.rows;
    cols = other.cols;

    return *this;

}

ComplexMatrix::ComplexMatrix(ComplexMatrix&& other) : rows{other.rows}, cols{other.cols}, data{other.data} {

    other.rows = 0;
    other.cols = 0;
    other.data = nullptr;

}

ComplexMatrix& ComplexMatrix::operator=(ComplexMatrix&& other) {

    if (this == &other) {

        return *this;

    }

    delete [] data;

    rows = other.rows;
    cols = other.cols;
    data = other.data;

    other.rows = 0;
    other.cols = 0;
    other.data = nullptr;

    return *this;

}

ComplexMatrix::~ComplexMatrix() {

    delete [] data;

}

void ComplexMatrix::set_value(unsigned int r, unsigned int c, const Complex& val) {

    if (r >= this->rows || c >= this->cols) {

        std::cerr << "Wyjscie poza indeks" << std::endl;
        return;

    }
    
    this->data[r * this->cols + c] = val;

}

Complex ComplexMatrix::get_value(unsigned int r, unsigned int c) const {

    if (r >= this->rows || c >= this->cols) {

        return Complex(0.0, 0.0);

    }
    
    return this->data[r * this->cols + c];

}

void ComplexMatrix::print() const {

    for (unsigned int i = 0; i < this->rows * this->cols; i++) {

        if (i != 0 && i % this->cols == 0) {

            std::cout << std::endl;

        }

        this->data[i].print();
        std::cout << " ";

    }

}
