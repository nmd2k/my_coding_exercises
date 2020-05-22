#include <iostream>
#include <string>

using namespace std;
int main ()
{
    string *str;
    int size = 0;
    string s;
    while (cin >> s)
    {
        size++;
        string *temp = new string[size];
        for(int i = 0; i < size - 1; i++)
        {
            *(temp + i) = *(str + i);
        }
        *(temp + size-1) = s;
        delete[] str;
        str = temp;
    }
    for(int i = 0; i < size; i++) {
        cout << *(str + i) << ' ';
    }
//    getch();
}
