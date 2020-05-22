#include <iostream>
#include <set>
#include <string>

using namespace std;

int main (){
    string str1, str2;
    cin >> str1 >> str2;
    set <char> c_str1, c_str2;
    for (int i=0; i<str1.length(); i++){
        c_str1.insert(str1[i]);
    }
    for (int i=0; i<str2.length(); i++){
        c_str2.insert(str2[i]);
    }
    if (c_str1==c_str2) cout << "YES";
    else cout << "NO";
}