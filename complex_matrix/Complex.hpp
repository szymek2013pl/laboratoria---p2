#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>
#include <string>
#include <memory>

class Complex {

    private:

        double real_part;
        double imag_part;
        static unsigned int alive_objects;
    
    public:

        Complex(double a = 0.0, double b = 0.0);

        Complex(const Complex& other);

        ~Complex();

        double get_real() const;

        double get_imag() const;

        double modulus() const;

        void print() const;

        Complex add(const Complex& other) const;

        Complex multiply(const Complex& other) const;

        static unsigned int get_alive_count(); 

};

#endif
