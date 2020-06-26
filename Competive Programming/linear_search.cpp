#include <iostream>
using namespace std;

int n;
int arr[100];

int search(int lo, int hi) {
    if (hi >= lo) {
        int index = lo + (hi - lo)/2;
        int x = arr[index];
        
        if (index == x) {return index;}
        if (index > x) return search(index+1, hi);
        return search(lo, index-1);
    }
    return -1;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << search(0, n);
}