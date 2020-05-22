#include <iostream>
#include <vector>
using namespace std;
#define ifor(i, m) for (int i = 0; i < (m); i++)

void input (vector<int> &vt, size)
{
    ifor(i, size){
        int value;
        cin >> value;
        vt.push_back(value);
    }
}
 // count the frequency of number are?
 // which is the biggest?


int main ()
{
    int size;
    cin >> size;
    vector <int> arr;
    input (arr, size);
    return 0;
}
