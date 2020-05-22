#include <iostream>
#include <string>
using namespace std;

int main (){
    string str;
    getline (cin, str);
    bool endSpace = true;
    int count = 0;
    for (int i=0; i<str.length()-1; i++){
        if (str[i] != ' ' and endSpace == true){
            count ++;
            endSpace = false;
        }
        if (str[i] == ' ' and str[i+1] != ' ') endSpace = true;
        //cout << endSpace << endl;
    }
    cout << count;
}