#pragma once 

class Complex2D 
{
public:
    Complex2D();
    Complex2D(double re, double im);
    Complex2D(double a);
    Complex2D(const Complex2D& other);

    void setRe(double real);
    void setIm(double imaginary);


    double getRe() const;
    double getIm() const;
    
    Complex2D operator+(const Complex2D&) const;
    Complex2D operator-(const Complex2D&) const;
    Complex2D operator*(const Complex2D&) const;
    Complex2D operator/(const Complex2D&) const;
    bool operator<(const Complex2D&) const;
    bool operator>(const Complex2D&) const;

    void afficher() const;

private:
    double re;
    double im;
};