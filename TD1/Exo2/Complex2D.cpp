#include <iostream>
#include <string>
#include <cmath>

#include "Complex2D.h"

Complex2D::Complex2D():re(0),im(0){}
Complex2D::Complex2D(double real, double imaginary):re(real), im(imaginary){}
Complex2D::Complex2D(double a):re(a),im(a){}
Complex2D::Complex2D(const Complex2D& other):re(other.re), im(other.im){}

void Complex2D::setRe(double real){
    re=real;
}

void Complex2D::setIm(double imaginary){
    im=imaginary;
}

double Complex2D::getRe() const{
    return re;
}

double Complex2D::getIm() const{
    return im;
}

Complex2D Complex2D::operator+(const Complex2D& other) const {
    return Complex2D(re + other.re, im + other.im);
}

Complex2D Complex2D::operator-(const Complex2D& other) const {
    return Complex2D(re - other.re, im - other.im);
}

Complex2D Complex2D::operator*(const Complex2D& other) const {
    return Complex2D(re*other.re-im*other.im, re*other.im+other.im+im*other.re);
}

Complex2D Complex2D::operator/(const Complex2D& other) const {
    double conjugue = other.re * other.re + other.im * other.im;
    return Complex2D((re * other.re + im * other.im) / conjugue, (im * other.re - re * other.im) / conjugue);
}


bool Complex2D::operator<(const Complex2D& other) const {
    return std::sqrt(re * re + im * im) < std::sqrt(other.re * other.re + other.im * other.im);
}

bool Complex2D::operator>(const Complex2D& other) const {
    return std::sqrt(re * re + im * im) > std::sqrt(other.re * other.re + other.im * other.im);
}

void Complex2D::afficher() const{
    std::cout<< re << "+" << im << "i" <<std::endl;
}