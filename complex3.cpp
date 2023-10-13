#include "ComplexNumber.h"
using namespace std;

int main() {
    ComplexNumber complex1{ 3, -4 };
    ComplexNumber complex2{ 1, 13 };
    ComplexNumber complex3{ 4, 0 };
    ComplexNumber complex4{ 3, -4 };
    ComplexNumber result{};
    double result1;
    //ввод и вывод
    cout << complex1 << endl << complex2 << endl << complex3 << endl;
    
    //модуль
    result1 = complex1.Module();
    cout << "Module: " << result1 << endl;
    //++
    complex1++;
    cout << endl << "++:" << complex1 << endl;
    //c c  c d  d  c
    if (complex1 == complex1)cout << endl << "c1==c2" << endl;
    else cout << endl << "c1!=c2" << endl;
    if (complex1 != 13)cout << endl << "c1!=d1" << endl;
    else cout << endl << "c1==d1" << endl;
    /*if(13 != complex1 )cout<<endl<<"d1!=c1"<<endl;
      else cout<<endl<<"d1==c1"<<endl;*/
      //дайте, пожалуйста, подсказку как реализовать double + complex
      //остальное всё вроде бы ок

    return 0;
}
