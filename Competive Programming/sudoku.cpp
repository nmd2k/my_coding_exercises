/*Placing all solutions in N-queen problem*/
#include <iostream>
using namespace std;

int n;
int sudoku[9][9];
int used[9];

bool checkValid(int x, int y, int k){
    //check row
    for(int i = 0; i <9 ; i++){
        if(sudoku[x][i] == k) return false;
    }

    //check column
    for(int i = 0; i <9 ; i++){
        if(sudoku[i][y] == k) return false;
    }

    //check the 9-box
    int a = x/3, b = y/3;
    for(int i = 3*a; i < 3*a+3; i++){
        for(int j = 3*b; j < 3*b+3; j++){
            if(sudoku[i][j] == k) return false;
        }
    }
    return true;
}

void solveSudoku(int x, int y){
    //reach the end of sudoku box
    if (y==8){
        if (x==8){
            show();
            return;
        }
    }

    //reach the end of row
    if (x==8){
        y++;
        x = 0;
    }  

    if(sudoku[x][y] == 0) {
        for (int i=1; i<=9; i++){
            //checkValid check all the element, even the one that's not completely
            if (checkValid(x, y, i)){
                sudoku[x][y] = i;
                solveSudoku (x + 1, y);
                sudoku[x][y] = 0;
            }
        }
    }
}


void show() {
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << sudoku[i][j] << "  ";
        }
        cout << endl;
    }
}

int main (){
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> sudoku[i][j];
        }
    }

    show();

    solveSudoku(0, 0);
    return 0;
}

/*
3 0 6 5 0 8 4 0 0 
5 2 0 0 0 0 0 0 0 
0 8 7 0 0 0 0 3 1 
0 0 3 0 1 0 0 8 0 
9 0 0 8 6 3 0 0 5 
0 5 0 0 9 0 6 0 0 
1 3 0 0 0 0 2 5 0 
0 0 0 0 0 0 0 7 4 
0 0 5 2 0 6 3 0 0
*/