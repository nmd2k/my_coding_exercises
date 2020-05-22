#include <iostream>
#include <string>

using namespace std;

int countLetter (string a, char c){
    int count = 0;
    for (int i=0; i<a.length(); i++){
        if (a[i] == c) count ++;
    }
    return count;
}

bool checkPermission (string a){
    int countA = countLetter (a, 'A');
    int countL = countLetter (a, 'L');
    // cout << countA << ' ' << countL << endl;
    if (countA > 1) return false;
    if (countL > 2) {
        bool continous = false;
        int count = 0;
        for (int i=0; i<a.length(); i++){
            if (a[i] == 'L') {
                if (continous == true) count ++;
                
                else if (continous != true){
                    count = 1;
                    continous = true;
                }
            
                if (count > 2) return false;
            }
            else {continous = false; count = 0;}
        }
    }
    return true;
}

int main (){
    int n; cin >> n;
    while (n>0) {
        string a; cin >> a;
        if (checkPermission (a)) cout << "yes" << endl;
        else cout << "no" << endl;
        n--;
    }
}