#ifndef COMPLEXMATRIX_HPP
#define COMPLEXMATRIX_HPP

#include "Complex.hpp"

class ComplexMatrix {

    private:

        unsigned int rows;
        unsigned int cols;
        Complex * data;

    public:

        ComplexMatrix(unsigned int r, unsigned int c);

        ComplexMatrix(const ComplexMatrix& other);

        ComplexMatrix& operator=(const ComplexMatrix& other);

        ComplexMatrix(ComplexMatrix&& other);

        ComplexMatrix& operator=(ComplexMatrix&& other);

        ~ComplexMatrix();

        void set_value(unsigned int r, unsigned int c, const Complex& val);

        Complex get_value(unsigned int r, unsigned int c) const;

        void print() const;

};

#endif
