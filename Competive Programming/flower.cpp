#include <iostream>
using namespace std;

long int N;
unsigned long long int q;

int main (){
    cin >> N;

    int trees[N];
    long int max = 0;
    for (int i=0; i<N; i++){
        cin >> trees[i];
        if (trees[i] > max) max = trees[i];
    }

    cin >> q;

    long int sum = 0;
    for (int i=0; i<N; i++){
        sum += (max - trees[i]);
    }
    
    cout << sum*q;
    return 0;
}