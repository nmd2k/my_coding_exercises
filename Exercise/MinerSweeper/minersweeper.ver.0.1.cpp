#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
using namespace std;


int  generateRandNumber (int n) {
	int x=rand()%n;
	return x;
}

void generateRandLocation (int size , int bomb, vector <vector<int> > &gameStructure)
{
    for (int i=0; i<bomb; i++){
		int Ox = generateRandNumber(size);
		int Oy = generateRandNumber(size);
		if (gameStructure[Ox][Oy] != 1){
			gameStructure[Ox][Oy] = 1;
		}
		else i--;
	}

}

void render (int size, vector <vector<char> > playerStructure)
{
    cout << "# ";
    for (int j=1; j<=size; j++){                 //rules
         cout << j << ' ';
    }
    cout << endl;
    for (int i=0; i<size; i++){
        cout << i+1 << ' ';                     //rules
        for (int j=0; j<size; j++) {
            cout << playerStructure[i][j] << ' ';
        }
        cout << endl;
    }
}

void renderTest (int size, vector <vector<int> > playerStructure)
{
    cout << "# ";
    for (int j=1; j<=size; j++){                 //rules
         cout << j << ' ';
    }
    cout << endl;
    for (int i=0; i<size; i++){
        cout << i+1 << ' ';                     //rules
        for (int j=0; j<size; j++) {
            cout << playerStructure[i][j] << ' ';
        }
        cout << endl;
    }
}

void input (int size, vector <vector<int> > &gameStructure)
{
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++) {
            gameStructure[i][j] = 0;
        }
    }
}

void inputPlayer (int size, vector <vector<char> > &playerStructure)
{
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++) {
            playerStructure[i][j] = 'x';
        }
    }
}

int playerChoice (vector <vector<int> > &gameStructure, vector <vector<char> > &playerStructure)
{
    int Ox, Oy;
    cout << "   Ox: ";
    cin >> Ox;
    cout << "   Oy: ";
    cin >> Oy;
    // Update the structure
    if (gameStructure[Ox-1][Oy-1]!=1) {
        playerStructure[Ox-1][Oy-1] = gameStructure[Ox-1][Oy-1] + '0';
        return 0;
    }
    else return 1;
}

bool gameOver (int value){
    if (value == 1) return true;
    return false;
}

void setup (int size, int bomb)
{
    vector <vector <int> > gameStructure (size, vector<int> (size));
    vector <vector <char> > playerStructure (size, vector<char> (size));
    int value;

    //playerStructure = gameStructure;
    input(size, gameStructure);
    inputPlayer (size, playerStructure);

    generateRandLocation (size, bomb, gameStructure);
    render(size, playerStructure);

    //renderTest(size, gameStructure); cout << endl; //test
    do {
        value = playerChoice(gameStructure, playerStructure);
        render(size, playerStructure);
    } while (!gameOver(value));

    // endgame
    if (value == 1) cout << endl << "***You lose***" << endl << endl;
    if (value == 0) cout << endl << "***YOU WIN***" << endl << endl;


}

int main ()
{
    srand(time(0));
    int size = 1, bomb = 1;
    char choice;
    do {
        cout << "Size of the game (n<10): ";
        cin >> size;
        cout << "How many bomb: ";
        cin >> bomb;
        setup (size, bomb);
        cout << endl << "Play more (y/n): ";
        cin >>  choice;
    } while (choice == 'y');
    return 0;
}
