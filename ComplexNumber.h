#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H
#include <iostream>

class ComplexNumber
{
public:
    ComplexNumber() {}
    ComplexNumber(double _real) { real = _real; }
    ComplexNumber(double _real, double _imaginary) {
        imaginary = _imaginary;
        real = _real;
    }
    double Module() const;
    ComplexNumber Conjugate() const;
    double GetReal() const;
    double GetImaginary() const;
    void SetComplexNumberReal(double _real);
    void SetComplexNumberImaginary(double _imaginary);
    ComplexNumber operator+(ComplexNumber c1) const;
    ComplexNumber operator+(double number);
    ComplexNumber operator-(ComplexNumber c1) const;
    ComplexNumber operator-(double number);
    ComplexNumber operator*(ComplexNumber c1) const;
    ComplexNumber operator/(ComplexNumber c1) const;
    ComplexNumber operator+=(const ComplexNumber& c);
    ComplexNumber operator-=(const ComplexNumber& c);
    ComplexNumber operator=(const ComplexNumber& c);
    ComplexNumber operator*=(const ComplexNumber c1);
    ComplexNumber operator/=(const ComplexNumber c1);
    bool operator==(const ComplexNumber c) const;
    bool operator==(const double number) const;
    bool operator!=(const ComplexNumber c) const;
    bool operator!=(const double number) const;
    ComplexNumber operator++(void);
    const ComplexNumber operator++(int c);
    ComplexNumber operator--(void);
    ComplexNumber operator--(int c);
    friend std::ostream& operator<<(std::ostream& out, ComplexNumber& cn);
    friend std::istream& operator>>(std::istream& in, ComplexNumber& cn);
    friend ComplexNumber operator +(double s, const ComplexNumber& c);
    friend ComplexNumber operator -(double s, const ComplexNumber& c);
    //friend ComplexNumber operator *(double s, const ComplexNumber &c);
    //friend ComplexNumber operator /(double s, const ComplexNumber &c);

protected:

private:
    double real{ 0.0 };
    double imaginary{ 0.0 };
};

#endif // COMPLEXNUMBER_H
