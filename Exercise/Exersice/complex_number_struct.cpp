#include <iostream>
using namespace std;
struct complexNumber
{
    double realPart,imaginaryPart;
    void complexPrint (){
        cout << realPart << ' ' << imaginaryPart;
    }
};
complexNumber multiply (complexNumber a, complexNumber b){
    complexNumber product;
    product.realPart = a.realPart*b.realPart - a.imaginaryPart*b.imaginaryPart;
    product.imaginaryPart = a.realPart*b.imaginaryPart + a.imaginaryPart*b.realPart;
    return product;
}

int main()
{
    complexNumber complex1, complex2;
    cin >> complex1.realPart >> complex1.imaginaryPart
        >> complex2.realPart >> complex2.imaginaryPart;
    complexNumber product = multiply(complex1, complex2);
    cout << product.realPart << " " << product.imaginaryPart << endl;
    return 0;
}
