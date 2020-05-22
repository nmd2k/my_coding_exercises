#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int value (string a)
{
    int num = stoi (a);
    return num;
}

int main ()
{
    string a,b,c;
    cin >> a>>b>>c;
    if (a == "?") cout << value(c)-value(b);
    if (b == "?") cout << value(c)-value(a);
    if (c == "?") cout << value(a)+value(b);
    return 0;
}
