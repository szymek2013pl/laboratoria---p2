#include "Complex.hpp"

Complex::Complex(double a, double b) : real_part{a}, imag_part{b} {

    alive_objects++;

}

Complex::Complex(const Complex& other) : real_part{other.real_part}, imag_part{other.imag_part} {

    alive_objects++;

}

Complex::~Complex() {

    alive_objects--;

}

double Complex::get_real() const {    
    
    return this->real_part;

}

double Complex::get_imag() const {

    return this->imag_part;

}

double Complex::modulus() const {

    double a = get_real();
    double b = get_imag();

    return sqrt(a * a + b * b);

}

void Complex::print() const {

    std::string ans;

    ans += '(';
    ans += std::to_string(this->real_part);

    if (this->imag_part >= 0) {

        ans += " + ";
        ans += std::to_string(this->imag_part);

    }

    else {

        ans += " - ";
        ans += std::to_string(-1 * (this->imag_part));

    }

    ans += "i";
    ans += ')';

    std::cout << ans << std::endl;


}

Complex Complex::add(const Complex& other) const {

    double real = this->real_part + other.get_real();
    double imag = this->imag_part + other.get_imag();
            
    Complex added(real, imag);
            
    return added;

}

Complex Complex::multiply(const Complex& other) const {

    double real = this->real_part * other.get_real() - this->imag_part * other.get_imag();
    double imag = this->real_part * other.get_imag() + this->imag_part * other.get_real();

    Complex multiplied(real, imag);

    return multiplied;

}

unsigned int Complex::alive_objects = 0;

unsigned int Complex::get_alive_count() {

    return alive_objects;

}
