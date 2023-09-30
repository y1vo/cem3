#include <cmath>
#include <iostream>
using namespace std;

class ComplexNumber {
private:
  double real{0.0};
  double imaginary{0.0};

public:
  ComplexNumber() {}
  ComplexNumber(double _real) { real = _real; }
  ComplexNumber(double _real, double _imaginary) {
    imaginary = _imaginary;
    real = _real;
  }
  double GetReal() { return real; }
  double GetImaginary() { return imaginary; }
  void SetComplexNumberReal(double _real) { real = _real; }
  void SetComplexNumberImaginary(double _imaginary) { imaginary = _imaginary; }
  // +-0*/ c + c c + d d + c
  ComplexNumber operator+(ComplexNumber c1) {
    ComplexNumber c;
    c.real = (real + c1.real);
    c.imaginary = (imaginary + c1.imaginary);

    return c;
  }
  ComplexNumber operator+(double number) {
    real += number;
    return *this;
  }
  ComplexNumber operator-(ComplexNumber c1) {
    ComplexNumber c;
    c.real = (real - c1.real);
    c.imaginary = (imaginary - c1.imaginary);
    return c;
  }
  ComplexNumber operator-(double number) {
    real -= number;
    return *this;
  }

  ComplexNumber operator*(ComplexNumber c1) {
    ComplexNumber c;
    c.real = (real * c1.real - imaginary * c1.imaginary);
    c.imaginary =
        (imaginary * c1.real + real * c1.imaginary + real * c1.imaginary);
    return c;
  }
  ComplexNumber operator/(ComplexNumber c1) {
    ComplexNumber c;
    c.real = (real * c1.real + imaginary * c1.imaginary) /
             (c1.real * c1.real + c1.imaginary * c1.imaginary);
    c.imaginary = (imaginary * c1.real - real * c1.imaginary) /
                  (c1.real * c1.real + c1.imaginary * c1.imaginary);
    return c;
  }

  double Module() {
    double temp;
    temp = sqrt(real * real + imaginary * imaginary);
    return temp;
  }
  ComplexNumber Conjugate() {
    ComplexNumber temp;
    temp.real = real;
    temp.imaginary = imaginary * (-1);
    return temp;
  }
  ComplexNumber &operator+=(const ComplexNumber &c) {
    real += c.real;
    imaginary += c.imaginary;
    return *this;
  }
  ComplexNumber &operator-=(const ComplexNumber &c) {
    real -= c.real;
    imaginary -= c.imaginary;
    return *this;
  }
  ComplexNumber &operator=(const ComplexNumber &c) {
    if (this == &c) return *this;
    real = c.real;
    imaginary = c.imaginary;
    return *this;
  }

  ComplexNumber &operator*=(const ComplexNumber c1) {
    ComplexNumber c;
    c.real = (real * c1.real - imaginary * c1.imaginary);
    c.imaginary =
        (imaginary * c1.real + real * c1.imaginary + real * c1.imaginary);
    real = c.real;
    imaginary = c.imaginary;
    return *this;
  }
  ComplexNumber &operator/=(const ComplexNumber c1) {
    ComplexNumber c;
    c.real = (real * c1.real + imaginary * c1.imaginary) /
             (c1.real * c1.real + c1.imaginary * c1.imaginary);
    c.imaginary = (imaginary * c1.real - real * c1.imaginary) /
                  (c1.real * c1.real + c1.imaginary * c1.imaginary);
    real = c.real;
    imaginary = c.real;
    return *this;
  }
  bool operator==(const ComplexNumber c) {
    if (real == c.real && imaginary == c.imaginary) {
      return true;
    }
    return false;
  }
  bool operator==(const double number) {
    if (real == number && imaginary == 0.0) {
      return true;
    }
    return false;
  }
  bool operator!=(const ComplexNumber c) {
    if (real != c.real || imaginary != c.imaginary) {
      return true;
    }
    return false;
  }
  bool operator!=(const double number) {
    if (real != number || imaginary != 0.0) {
      return true;
    }
    return false;
  }
  ComplexNumber operator++(void) {
    real++;
    return *this;
  }
  ComplexNumber operator++(int c) {
    real++;
    return *this;
  }
  ComplexNumber operator--(void) {
    real--;
    return *this;
  }
  ComplexNumber operator--(int c) {
    real--;
    return *this;
  }
  friend ostream &operator<<(ostream &out, ComplexNumber &cn);
  friend istream &operator>>(istream &in, ComplexNumber &cn);
};
istream &operator>>(istream &in, ComplexNumber &cn) {
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
ostream &operator<<(ostream &out, ComplexNumber &cn) {
  out << cn.GetReal();
  if (cn.GetImaginary() > 0)
    out << "+";
  if (cn.GetImaginary() != 0)
    out << cn.GetImaginary() << "*i";
  return out;
}
int main() {
  ComplexNumber complex1{3, -4};
  ComplexNumber complex2{1, 13};
  ComplexNumber complex3{4, 0};
  ComplexNumber complex4{3, -4};
  ComplexNumber result{};
  double result1;

  //ввод и вывод
  cout << complex1 << endl << complex2 << endl << complex3 << endl;
  //сложение
  result += (complex1 + complex3);
  cout<<endl<<"c1+c2: "<<result<<endl;
  result = complex1 +1;
  //умножение
  result.SetComplexNumberReal(0);
  result.SetComplexNumberImaginary(0);
  result = (complex1 * complex2);
  cout<<endl<<"c1*c2: "<<result<<endl;
  //деление
  result.SetComplexNumberReal(0);
  result.SetComplexNumberImaginary(0);
  result = (complex1 / complex2);
  cout<<endl<<"c1/c2: "<<result<<endl;

  complex4 /= complex2;
  cout<<endl<<"c1/c2: "<<complex4<<endl;
  //-z
  result.SetComplexNumberReal(0);
  result.SetComplexNumberImaginary(0);
  result += complex1.Conjugate();
  cout<<endl<<result<<endl<<complex1<<endl;
  //модуль
  result1 = complex1.Module();
  cout << "Module: " << result1 << endl;
  //++
  complex1++;
  cout<<endl<<"++:"<<complex1<<endl;
  //c c  c d  d  c
  if(complex1 == complex1)cout<<endl<<"c1==c2"<<endl;
    else cout<<endl<<"c1!=c2"<<endl;
  if(complex1 != 13)cout<<endl<<"c1!=d1"<<endl;
    else cout<<endl<<"c1==d1"<<endl;
  /*if(13 != complex1 )cout<<endl<<"d1!=c1"<<endl;
    else cout<<endl<<"d1==c1"<<endl;*/
  //дайте, пожалуйста, подсказку как реализовать double + complex
  //остальное всё вроде бы ок

  return 0;
}
