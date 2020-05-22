#include <iostream>
using namespace std;

struct fraction{
    int numerator, denominator;
    void getPrint () {
        cout << numerator << "/" << denominator;
    }
};
int ucln(int a, int b){
    int c = a%b;
    if (c==0){
        return b;
    } else {
        return ucln(b, c);
    }
}
fraction add(fraction a, fraction b){
    int z;
    fraction sum;
    sum.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    sum.denominator = a.denominator * b.denominator;
    z = ucln(sum.numerator, sum.denominator);
    sum.numerator = sum.numerator/z;
    sum.denominator = sum.denominator/z;
    return sum;
}

int main() {
    fraction a, b;
    cin >> a.numerator >> a.denominator >> b.numerator >> b.denominator;
    fraction sum = add(a,b);
    sum.getPrint();
    return 0;
}
