#include <iostream>
using namespace std;

int main ()
{
    int a, b;
    cin >> a;
    while (a>0){
        cin >> b;
        if (a!=b) cout << a << ' ';
        a = b;
    }
    cout << a;
    return 0;
}
