#include <iostream>
#include <string>

using namespace std;

int generateRandomNumber() {
    return 45;
}

int getPlayerGuess(){
    int playerGuessNumb;
    cout << "Enter your guess: ";
    cin >> playerGuessNumb;
    return playerGuessNumb;
}

void printAnswer(int guestNumber, int hostNumber){
    if (guestNumber == hostNumber) {
        cout << "Congratulations !!!" << endl;
    }
    if (guestNumber > hostNumber) {
        cout << "Your number is too big." << endl;
    }
    if (guestNumber < hostNumber) {
        cout << "Your number is too small." << endl;
    }
}

void setup ()
{
    int hostNumber = generateRandomNumber();
    int guestNumber;
    do {
        guestNumber = getPlayerGuess();
        printAnswer (guestNumber, hostNumber);
    } while (guestNumber != hostNumber);

}

int main ()
{
    setup();
    return 0;
}
