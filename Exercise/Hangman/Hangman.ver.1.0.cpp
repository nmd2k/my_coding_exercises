#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <stdlib.h>

set <string> usedWord;

using namespace std;
//initialize
string generateWord ()
{
    vector <string> text;
    ifstream input("text.txt");
    while (!input.eof()) {
        string line;
        input >> line;
        if (input) {
            text.push_back(line);
        }
    }
    int idx = rand() % text.size();
//    cout << text[idx];
    return text[idx];
}

string getHang (int guessLeft)
{
    string Hanger [] = {
        "            |\n"
        "            |\n"
        "            |\n"
        "            |\n"
        "            |\n"
        "            |\n"
        "          -----",
        "            |----------\n"
        "            |         |\n"
        "            |\n"
        "            |\n"
        "            |\n"
        "            |\n"
        "          -----",
        "            |----------\n"
        "            |         |\n"
        "            |         o\n"
        "            |\n"
        "            |\n"
        "            |\n"
        "          -----",
        "            |----------\n"
        "            |         |\n"
        "            |         o\n"
        "            |         |\n"
        "            |\n"
        "            |\n"
        "          -----",
        "            |----------\n"
        "            |         |\n"
        "            |         o\n"
        "            |        /|\n"
        "            |\n"
        "            |\n"
        "          -----",
        "            |----------\n"
        "            |         |\n"
        "            |         o\n"
        "            |        /|\\\n"
        "            |\n"
        "            |\n"
        "          -----",
        "            |----------\n"
        "            |         |\n"
        "            |         o\n"
        "            |        /|\\\n"
        "            |        /\n"
        "            |\n"
        "          -----",
        "            |----------\n"
        "            |         |\n"
        "            |         o\n"
        "            |        /|\\\n"
        "            |        / \\\n"
        "            |\n"
        "          -----",
    };
    return Hanger[7-guessLeft];
}

void renderGame (int guessLeft, string playerWord)
{

    //cout << "You have " << guessLeft << " turn left." << endl;
    system("cls");
    cout << endl << endl<< endl<< endl<< endl<< endl;
    cout << endl << getHang (guessLeft) << endl
         << "       Guessed Word:  " << playerWord << endl;
         << "       Used Word:  ";
    for (int i=0; i<usedWord.size(); i++){
        cout << usedWord[i] << ", ";
    }
}

char readAGuess ()
{
    char playerGuessWord;
    cout << "       Your guess: ";
    cin >> playerGuessWord;
    usedWord.push_back(playerGuessWord);
    cout << endl;
    return playerGuessWord;
}

bool checkGame (string guessWord, char playerGuess)
{
    for (int i=0; i<(int)guessWord.length(); i++){
        if (playerGuess == guessWord[i]){
//            playerWord [i] = playerGuess;

            return true;
        }
    }
    return false;
}

string updateGuessWord (string guessWord, string playerWord, char playerGuess)
{
    for (int i=0; i<(int)guessWord.length(); i++){
        if (playerGuess == guessWord[i]){
            playerWord [i] = playerGuess;
        }
    }
    return playerWord;
}

void setupGame ()
{
    int guessLeft = 7;
    string guessWord = generateWord();
    string playerWord = string(guessWord.length(), '-');                // New structure!
    do {
        renderGame(guessLeft, playerWord);
        char playerGuess = readAGuess ();
        if (checkGame(guessWord, playerGuess)){
            playerWord = updateGuessWord(guessWord, playerWord, playerGuess);
        }
        else guessLeft --;

        //renderGame(guessLeft, playerWord);

        if (guessWord == playerWord) {
            cout << endl << "       ***YOU WIN***" << endl;
            cout << "       The word is: " << guessWord << endl;
            break;
        }
    } while (guessLeft != 0);
    if (guessWord != playerWord) {
        renderGame(guessLeft, playerWord);
        cout << "       The word is: " << guessWord << endl
             << "       You hanged!" << endl;
    }

}

int main()
{
    srand(time(0));
    char choice;
    do{
        setupGame();
        cout << endl << "       ***Play more?*** (y/n): ";
        cin >> choice;
    } while (choice == 'y');
    return 0;
}
