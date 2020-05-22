#include <iostream>
#include <string>
using namespace std;

bool checkGame (string guessWord, string playerWord, char playerGuess)
{
    for (int i=0; i<(int)guessWord.length(); i++){
        if (playerGuess == guessWord[i]){
            playerWord [i] = playerGuess;
            cout << "playerWord2: " << playerWord <<endl;
            return true;
        }
    }
    return false;
}

int main ()
{
    string guessWord = "Hello";
    string playerWord = string (guessWord.length(), '-');
    cout << "playerWord: " <<playerWord << endl;
    char playerGuess;
    cin >> playerGuess;

}
