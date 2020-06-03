#include <iostream>
#include <math.h>
using namespace std;

int main (){
    int n, k;
    cin >> n >> k;

    long double x = pow(10, n-1); 
    long long int y = ceil(x/k);

    if (x < k or k*y == 0) cout << "NO";
    else cout << k*y;
}