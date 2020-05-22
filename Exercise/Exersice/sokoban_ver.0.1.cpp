#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
/* _map
######
#    #
#    #
#    #
#    #
######
*/

struct address {
    int x;
    int y;

};


string wall[] = {
    "#######",
    "#",
};

void gameRender (vector<vector <char> > & playArea){
    cout << wall[0] << endl;
    for (int i=0; i<5; i++){
        cout << wall[1];
        for (int j=0; j<5; j++){
            cout << playArea[i][j];
        }
        cout << wall[1] << endl;
    }
    cout << wall[0];
}

void inputMap (vector<vector <char> > & playArea){
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            playArea[i][j] = ' ';
        }
    }
}

void control (vector<vector <char> > & playArea, char direction, address player, address box)
{
    switch (direction){
    case 'w':
        playArea [player.x][player.y] = ' ';
        player.x-=1;
        //Khoi tao lai vi tri!
        playArea[player.x][player.y] = '@';
        break;

    case 's':
        playArea [player.x][player.y] = ' ';
        player.x+=1;
        //Khoi tao lai vi tri!
        playArea[player.x][player.y] = '@';
        break;
    case 'd':
        playArea [player.x][player.y] = ' ';
        player.y+=1;
        playArea [player.x][player.y] = '@';
        break;
    case 'a':
        playArea [player.x][player.y] = ' ';
        player.y-=1;
        playArea [player.x][player.y] = '@';
        break;
    }
}

void setupGame (vector<vector <char> > & playArea, address player, address box)
{
    inputMap(playArea);
    //Player position:
    char direction;
    player.x = 1, player.y = 1;
    playArea[player.x][player.y] = '@';
    do {
        system("cls");
        control (playArea, direction, player, box);
        gameRender(playArea);
        //Keypress!
    }while (cin>>direction);

}

int main ()
{
    //Khoi tao
    struct player, box;
    vector<vector <char> > playArea(5, vector<char> (5));
    //Chay setup
    setupGame(playArea, player, box);

    return 0;
}
