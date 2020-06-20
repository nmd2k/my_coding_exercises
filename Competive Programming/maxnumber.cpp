#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string a, b;
vector <char> subset;

int main()
{    
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()){
        if(a[i] == b[j]){
            subset.push_back(a[i]);
            i++; j++;
        }
        else if(a[i] > b[j]){
            j++;
        }
        else{i++;}
    }

    if (subset.empty()) cout << "No solution";
    else{
        sort(subset.begin(), subset.end(), greater <>());
        for (int i=0; i<subset.size(); i++){
            cout << subset[i];
        }
    }

    return 0;
}
