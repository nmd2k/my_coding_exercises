#include <iostream>
using namespace std;

int n;

int sum(int n) {
    int count = 0, i = 1;
    while (n>0){
        if (n >= 2*i) {
            n-=2*i;
            count+=2;
            i++;
        }
        else if (n<2*i) {
            if(n>i) {
                count+=2; return count;
            }
            else {
                count ++; return count;
            }
        } 
    }
    return count;
}

int main (){
    cin >> n;
    cout << sum(n);
}