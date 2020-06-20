#include <iostream>
using namespace std;

int a[100];
int n;
int T;

bool subsetSum (int a[], int n, int T){
    if (T==0) {
        return true;
    }
    else if (T>0 && n == 0) return false;

    if (T<a[n])
    return subsetSum(a, n-1, T) or subsetSum(a, n-1, T-a[n]);
}

int main (){
    cin >> n >> T;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    if(subsetSum(a, n, T)) cout << "True";
    else cout << "False";
}