/* Print every permutation of n from 1...n */
#include <iostream>
using namespace std;

int n;
int a[100];
bool used[100];

void show() {
    for (int i=1; i<=n; i++){
        cout << a[i];
    }
    cout << endl;
}

void backtrack (int pos) {
    if (pos == n+1) {
        show();
        return;
    }

    for (int i=1; i<=n; i++) {
        if (!used[i]) {
            a[pos] = i;
            used[i] = true;
            backtrack(pos+1);
            used[i] = false; //when it's done, return it!
        }
    }
}

int main () {
    cin >> n;
    backtrack(1);
    return 0;
}