#include <iostream>
#include <math.h>
using namespace std;

int main(){
    long int a,b,c;
    cin >> a >> b >> c;

    int sum = a*b*c;
    long int arr[7] = {0};
    int count = 0;
    if (a==1) count++; 
    if (b==1) count++; 
    if (c==1) count++; 

    if (count == 3) arr[6] = 1;


    if (count == 2){
        if (a!=1) a-=2;
        if (b!=1) b-=2;
        if (c!=1) c-=2;
        
        arr[5] = 2;
        arr[4] = a*b*c;
    }

    if (count == 1){
        arr[4] = 4;
        arr[3] = (a+b+c-5)*2;
        arr[2] = a*b*c - arr[4] - arr[3];
    }

    if (count == 0){
        if (a!=1) a-=2;
        if (b!=1) b-=2;
        if (c!=1) c-=2;

        arr[1] = a*b*2 + b*c*2 + a*c*2;
        arr[2] = (a+b+c)*4;
        arr[3] = 8;

        int temp = sum - (arr[1] + arr[2] + arr[3] + arr[4] + arr[5] + arr[6]);
        if (temp < 0) arr[0] = 0; 
        else {arr[0] == temp;}
    }

    for (int i=0;i<7;i++)
        cout << arr[i] << ' ';
    return 0;
}