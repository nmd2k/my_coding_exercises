#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
using namespace std;

bool gameover ()
{
    char check;
    cout << "Is that your number? (<,>,=)" << endl;
    cin >> check;
    if (check == '=') return true;
    else return false;
}

//int botGuessIt ()
//{
//
//
//}

void setup()
{

    int botGuessNumber;
    string check;
    cout << "You think about a number!" << endl;
    getch();
    do {
        int randNum = rand() % 100 + 1;
//      cout << botGuessIt ();
        int low = 1, high = 100;
        cout << randNum << " ,is that your number? (smaller,bigger,equal)" << endl;
        cin >> check;
        if (check == "smaller") {
             cout << "Your number bigger than this? Hmmm" << endl;
             high = randNum;
        }
        else if (check == "bigger") {
            cout << "Your number smaller than this? Alright!" << endl;
            low = randNum;
        }
        else cout << "Nice1" << endl;
    } while (check != "equal");
}

int main ()
{
    srand(time(0));
    char choice;
    do{
        setup();
        cout << "Do you want to play more? (y/n): " << endl;
        cin >> choice;
    } while (choice != 'n');
    return 0;
}
