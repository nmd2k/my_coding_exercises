#include <iostream>
using namespace std;

int n, k;

int search(int a[], int front, int back, int x){
    int count = 0;
    for (int i = front; i < back; i++){
        if (x == a[i]){
            count++;
        }
    }
    return count;
}

int main(){
    cin >> n >> k;
    int a[n], b[k];

    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i<k; i++){
        cin >> b[i];
    }

    for (int i=0; i<k; i++){
        int left = search(a, 0, b[i]-1, a[b[i]-1]);
        int right = search(a, b[i], n, a[b[i]-1]);
        cout << left << ' ' << right << endl;
    }

    return 0;
}