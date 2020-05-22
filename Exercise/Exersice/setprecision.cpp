#include <iostream>
#include <cmath>
using namespace std;

int rnd (double x)
{
    int a = x;
    cout << "x*10 " << x*10 << endl;
    cout << "a*10 " << a*10 << endl;
    cout << abs(x*10 - a*10) << endl;
    if (abs(x*10 - a*10)>=5 and x>0) return a+1;
    if (abs(x*10 - a*10)>=5 and x<0) return a-1;
    return a;
}

int main() {
    double x;
    cin >> x;

    cout << rnd(x);

    return 0;
}
