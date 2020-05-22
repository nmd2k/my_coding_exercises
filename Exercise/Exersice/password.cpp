#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <algorithm>
#define ifor(i, m) for (int i = 0; i < (m); i++)
using namespace std;

bool checkString (const string& str1,const string& str2)
{
    string str2Rev = str2;
    reverse(str2Rev.begin (), str2Rev.end());
    if (str1.compare(str2Rev) == 0)
	{
		return true;
	}
	return false;
}

void input (vector <string> &str, int numb)
{
    string strinput;
    ifor (i, numb){
        cin >> strinput;
        str.push_back(strinput);
    }
}

//void upper (vector <string> &str)
//{
//    for (int i=0; i<str.length(); i++)
//    {
//        str[i] = toupper(str[i]);
//    }
//}

void output (const string &str)
{
    int middle = str.length()/2;
    cout << str.length() << endl;
    cout << str[middle];
}

int main ()
{
    int numb;
    vector <string> str;
    cin >> numb;
    input (str, numb);
    ifor (i, numb){
        for (int j=i+1; j<numb; j++){
//            str [i] = upper(str[i]);
//            str [j] = upper(str[j]);
            if (checkString (str[i], str[j])){
                output (str[i]);
                }
        }
    }


    return 0;
}
