#include <iostream>
#include <vector>
#include <string>
using namespace std;


string longestPalindrome(string s) {
    int size = s.size();
    int l = 0, h = 0;
    
    // int array 2d
    int arr[size][size];

    // init with 1
    for (int i=0; i<size; i++) {
        arr[i][i] = 1;
    }


    for (int k=1; k<size; k++) {
        for (int i=0; i<size-k; i++) {
            int j = i+k;

            if (s[i] == s[j]) {
                if (k==1) {
                    arr[i][j] = 1;
                }
                else {
                    arr[i][j] = arr[i+1][j-1];
                }
            }

            else {
                arr[i][j] = 0;
            }

            if (arr[i][j] == 1) {
                if (j-i+1 > h-l+1) {
                    l = i;
                    h = j;
                }
            }
        }
    }

    return s.substr(l, h-l+1);
}

int main() {
    
    string s;
    cin >> s;
    
    cout << longestPalindrome(s);

    return 0;
}