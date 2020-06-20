#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int n;

bool IsPowerOfTwo(long int x)
{
    return (x != 0) && ((x & (x - 1)) == 0);
}


int main (){
    cin >> n;
    long int a[n];
    vector <long int> result;

    for (int i=0; i<n; i++){
        cin >> a[i];
        if(IsPowerOfTwo(a[i])) result.push_back(a[i]);
    }

    if (result.empty()){
        cout << "No";
    }
    else {
        sort(result.begin(), result.end());
        for (auto i= result.begin(); i != result.end(); i++){
            cout << *i << ' ';
        }
    }
    
}