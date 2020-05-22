/* Print every n-length binary element which no have 2 bits 1 adjacent*/
#include <iostream>
using namespace std;

int n;
long a[100];
bool used_bit_0[100];

void show(){
    for (int i=1; i<=n; i++){
        cout << a[i];
    }
    cout << endl;
}

void backtracking(int pos){
    if (pos == n+1) {
        show();
        return;
    }

    for (int i=0; i<=1; i++){
        if (i == 0){
            if (!used_bit_0[pos-1]){
                a[pos] = i;
                used_bit_0[pos] = true;
                backtracking(pos+1);
                used_bit_0[pos] = false;
            }
        }
        else {
            a[pos] = i; 
            backtracking(pos+1);
        }
    }
}

int main(){
    cin >> n;
    backtracking(1);
    return 0;
}