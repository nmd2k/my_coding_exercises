#include <iostream>
#include <cmath>
using namespace std;


void readName (int a)
{
    if (-10<=a and a<=10) {
        if (a<0) {
            cout << "negative ";
            switch (abs(a))
            {
                case 0: cout << "zero"; break;
                case 1: cout << "one";break;
                case 2: cout << "two";break;
                case 3: cout << "three";break;
                case 4: cout << "four";break;
                case 5: cout << "five";break;
                case 6: cout << "six";break;
                case 7: cout << "seven";break;
                case 8: cout << "eight";break;
                case 9: cout << "nine";break;
                case 10: cout << "ten";break;
            }
        }
        else {
            switch (abs(a))
            {
                case 0: cout << "zero"; break;
                case 1: cout << "one";break;
                case 2: cout << "two";break;
                case 3: cout << "three";break;
                case 4: cout << "four";break;
                case 5: cout << "five";break;
                case 6: cout << "six";break;
                case 7: cout << "seven";break;
                case 8: cout << "eight";break;
                case 9: cout << "nine";break;
                case 10: cout << "ten";break;
            }
        }
    }
}

int main ()
{
    int a;
    cin >> a;
    readName (a);
    return 0;
}
