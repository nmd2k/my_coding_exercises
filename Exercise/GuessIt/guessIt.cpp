#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int generateRandomNumber ()
{
    int randNum;
    randNum = rand() % 100 + 1;
//    cout << "Random Number: " << randNum << endl;
    return randNum;
}

int playerGuessIt (int randNum)
{
    int playerNum;
    cin >> playerNum;
    return playerNum;
}

void checkNum (int randNum, int playerNum)
{
    if (randNum > playerNum) {
        cout << "Your number is too small!" << endl;
    }
    else if (randNum < playerNum){
        cout << "Hmmm, too big, my friends!"<< endl;
    }
    else cout << "Got ya, Congratulation!" << endl;
}

void setup()
{
    int randNum = generateRandomNumber();
    int playerNum;
    cout << "Make a guess!" << endl;
    do {
        playerNum = playerGuessIt (randNum);
        checkNum (randNum, playerNum);
    } while (playerNum != randNum);
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
