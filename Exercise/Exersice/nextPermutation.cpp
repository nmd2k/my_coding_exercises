#include <iostream>
#include <vector>
using namespace std;

void Swap (int&a, int&b){
    int c = a;
    a = b; b = c;
}

int getPermutation (int n){
    if (n<=1) return 1;
    return n*getPermutation(n-1);
}

void nextPermutation (vector<int>& a){
    int size = a.size();
    int i = size - 1;
    int r = size - 1;
    for (i; i>=0; i--){
        if (a[i]>a[i-1]){
            break;
        }
    }
    for (int j=size; j>=0; j--){
        if (a[j] > a[i-1]) {
            Swap(a[i-1], a[j]);
            break;
        }
    }
    while (i < r){
        Swap(a[i], a[r]);
        r--;
        i++;
    }
}

void print (vector<int> a){
    for (int i = 0; i<a.size(); i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main (){
    int n;
    cin >> n;
    vector <int> arr(n);

    int times = getPermutation(n);
    //cout << times << endl;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "permutation: " << endl;
    while (times>0){
        print(arr);
        nextPermutation(arr);
        times--;
    }
}
