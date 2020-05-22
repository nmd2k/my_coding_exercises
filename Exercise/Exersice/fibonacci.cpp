#include <iostream>
using namespace std;

int fibonacci(int n){
    if (n==0) {
        return 0;
    }
    if (n==1) {
        return 1;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

//int printFibonacci(int n){
//    if (n==0) {
//        cout << 0 << ' ';
//    }
//    if (n==1) {
//        cout << 1 << ' ';
//        return 1;
//    }
//    else{
//        cout << printFibonacci(n-1) << ' ' << printFibonacci(n-2) << ' ';
//        return fibonacci(n-1) + fibonacci(n-2);
//    }
//}

bool checkFibonacci (int n)
{
    for (int i=0; i<100; i++){
        if (fibonacci(i) == n) return true;
    }
    return false;
}

int main ()
{
    int n;
    cin >> n;
    if (checkFibonacci(n)) {
            cout << "Thuoc day Fibonacci" << endl;
//            printFibonacci(n);
            cout << n;
    }
    else cout << "Khong thuoc day Fibonacci";
    return 0;
}
