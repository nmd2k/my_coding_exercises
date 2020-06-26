#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int x) {
    if (x == 2) return true;
    for (int j=2; j*j<=x; j++) {
        if (x % j == 0) break;
        else if (j+1 > sqrt(x)) {
            return true;
        }

    }
    return false;
}

bool containsDigit(int number, int digit) {
    while (number != 0) {
        int temp = number % 10;
        if (temp == digit) return true;
        number /= 10;
    }
    return false;
}

int main() {
    int a, b, d, count = 0;
    cin >> a >> b >> d;

    for (int i=a; i<=b; i++){
        if(isPrime(i) && containsDigit(i, d)) { count ++; }
    }
    
    cout << count << endl;
}