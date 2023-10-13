#include "ComplexNumber.h"
#include <cmath>
//https://code-live.ru/post/separate-compilation-cpp/
//https://moodle.kstu.ru/mod/page/view.php?id=8143&lang=ja

double ComplexNumber::GetReal() const { return real; }
double ComplexNumber::GetImaginary() const { return imaginary; }
void ComplexNumber::SetComplexNumberReal(double _real) { real = _real; }
void ComplexNumber::SetComplexNumberImaginary(double _imaginary) { imaginary = _imaginary; }

ComplexNumber ComplexNumber :: operator+(ComplexNumber c1) const {
    ComplexNumber c;
    c.real = (real + c1.real);
    c.imaginary = (imaginary + c1.imaginary);

    return c;
}
ComplexNumber ComplexNumber :: operator + (double number) {
    ComplexNumber c;
    c.real = real;
    c.imaginary = imaginary;
    c.real += number;
    return c;
}
ComplexNumber ComplexNumber :: operator-(ComplexNumber c1) const {
    ComplexNumber c;
    c.real = (real - c1.real);
    c.imaginary = (imaginary - c1.imaginary);
    return c;
}
ComplexNumber ComplexNumber :: operator-(double number) {
    ComplexNumber c;
    c.real = real;
    c.imaginary = imaginary;
    c.real -= number;
    return c;
}

ComplexNumber ComplexNumber :: operator*(ComplexNumber c1) const {
    ComplexNumber c;
    c.real = (real * c1.real - imaginary * c1.imaginary);
    c.imaginary =
        (imaginary * c1.real + real * c1.imaginary);
    return c;
}
ComplexNumber ComplexNumber :: operator/(ComplexNumber c1) const {
    ComplexNumber c;
    c.real = (real * c1.real + imaginary * c1.imaginary) /
        (c1.real * c1.real + c1.imaginary * c1.imaginary);
    c.imaginary = (imaginary * c1.real - real * c1.imaginary) /
        (c1.real * c1.real + c1.imaginary * c1.imaginary);
    return c;
}

double ComplexNumber::Module() const {
    double temp;
    temp = sqrt(real * real + imaginary * imaginary);
    return temp;
}
ComplexNumber ComplexNumber::Conjugate() const {
    ComplexNumber temp;
    temp.real = real;
    temp.imaginary = imaginary * (-1);
    return temp;
}
ComplexNumber ComplexNumber :: operator+=(const ComplexNumber& c) {
    real += c.real;
    imaginary += c.imaginary;
    return *this;
}
ComplexNumber ComplexNumber :: operator-=(const ComplexNumber& c) {
    real -= c.real;
    imaginary -= c.imaginary;
    return *this;
}
ComplexNumber ComplexNumber :: operator=(const ComplexNumber& c) {
    if (this == &c) return *this;
    real = c.real;
    imaginary = c.imaginary;
    return *this;
}

ComplexNumber ComplexNumber :: operator*=(const ComplexNumber c1) {
    ComplexNumber c;
    c.real = (real * c1.real - imaginary * c1.imaginary);
    c.imaginary =
        (imaginary * c1.real + real * c1.imaginary);
    real = c.real;
    imaginary = c.imaginary;
    return *this;
}
ComplexNumber ComplexNumber :: operator/=(const ComplexNumber c1) {
    ComplexNumber c;
    c.real = (real * c1.real + imaginary * c1.imaginary) /
        (c1.real * c1.real + c1.imaginary * c1.imaginary);
    c.imaginary = (imaginary * c1.real - real * c1.imaginary) /
        (c1.real * c1.real + c1.imaginary * c1.imaginary);
    real = c.real;
    imaginary = c.imaginary;
    return *this;
}
bool ComplexNumber:: operator  ==(const ComplexNumber c) const {
    if (real == c.real && imaginary == c.imaginary) {
        return true;
    }
    return false;
}
bool ComplexNumber:: operator ==(const double number) const {
    if (real == number && imaginary == 0.0) {
        return true;
    }
    return false;
}
bool ComplexNumber:: operator!=(const ComplexNumber c) const {
    if (real != c.real || imaginary != c.imaginary) {
        return true;
    }
    return false;
}
bool ComplexNumber:: operator!=(const double number) const {
    if (real != number || imaginary != 0.0) {
        return true;
    }
    return false;
}
ComplexNumber  ComplexNumber:: operator++(void) {
    real++;
    //запомнить предыдущее вернуть старое
    return *this;
}
const ComplexNumber ComplexNumber:: operator++(int c) {
    real++;

    return *this;
}
ComplexNumber ComplexNumber:: operator--(void) {
    real--;
    return *this;
}
ComplexNumber ComplexNumber:: operator--(int c) {
    real--;
    return *this;
}


std::istream& operator>>(std::istream& in, ComplexNumber& cn) {
    double _real, _imaginary;
    char dummy;
    in >> _real >> dummy;
    in >> _imaginary >> dummy;
    if (in) {
        cn.SetComplexNumberImaginary(_imaginary);
        cn.SetComplexNumberReal(_real);
    }

    return in;
}
std::ostream& operator<<(std::ostream& out, ComplexNumber& cn) {
    out << cn.GetReal();
    if (cn.GetImaginary() > 0)
        out << "+";
    if (cn.GetImaginary() != 0)
        out << cn.GetImaginary() << "*i";
    return out;
}
ComplexNumber operator +(double s, const ComplexNumber& c) {
    ComplexNumber temp;
    temp.real += (s + c.real);
    temp.imaginary += c.imaginary;
    return temp;
}
ComplexNumber operator -(double s, const ComplexNumber& c) {
    ComplexNumber temp;
    temp.real += (s - c.real);
    temp.imaginary -= c.imaginary;
    return temp;
}