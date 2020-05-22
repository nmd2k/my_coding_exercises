#include <iostream>
using namespace std;

struct fraction{
    int numerator, denominator;
    void getPrint () {
        if (denominator < 0) {
            cout << -numerator << "/" << -denominator;
        }
        else if (numerator%denominator == 0) {
            cout << numerator/denominator;
        }
        else cout << numerator << "/" << denominator;
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
fraction shortcut (int numerator, int denominator){
    int z;
    fraction after;
    z = ucln(numerator, denominator);
//    cout << "z = " << z << endl;
    after.numerator = numerator/z;
    after.denominator = denominator/z;
    return after;
}

int main() {
    fraction a;
    cin >> a.numerator >> a.denominator;
    fraction fractionAfter = shortcut (a.numerator, a.denominator);
    fractionAfter.getPrint();
    return 0;
}
