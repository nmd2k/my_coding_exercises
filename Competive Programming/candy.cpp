#include <iostream>
using namespace std;

int count(int arr[], int front, int back, int x){
    int count = 0;
    while (front <= back) 
    {
        if (arr[front] <= x && front != back) {
            count ++;}
        if (arr[back] <= x) count ++;
        front++; 
        back--; 
    } 
    return count;
}

bool checkPoint (int arr[], int n){
    for (int i=0; i<n; i++){
        if (arr[i] > 0) return true;
    }

    return false;
}

int main (){
    int n; cin >> n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    int point[n];
    point[n-1] = 0;
    for (int i=n-2; i>=0; i--){
        point[i] = count(arr, i+1, n-1, arr[i]);
    }

    int max = arr[n-1];
    for (int i=0; i<n-1; i++){
        int temp = arr[i] + point[i];
        if (temp > max) max = temp;
    }
    
    if (checkPoint(point, n)) cout << max;
    else {
        cout << n;
    }
}