#include <iostream>
#include <string>
#define ifor(i, m) for (int i=0; i<(m); i++)
using namespace std;

int main ()
{
    string str;
    cin >> str;
    ifor (i, str.length()){
        ifor (j, str.length()){
            cout << str[i] << str[j] << ' ';
            ifor (k, str.length()){
                cout << str[i] << str[j] << str[k] << ' ';
            }
        }
    }
    return 0;
}
