/*Placing all solutions in N-queen problem*/
#include <iostream>
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"
using namespace std;

int sudoku_start[9][9] = 
                    {  { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, 
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 }, 
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 }, 
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 }, 
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 }, 
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 }, 
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 }, 
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 }, 
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } }; 
int sudoku[9][9];
int used[9];

void input(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> sudoku_start[i][j];
        }
    }
}

void show(){
    cout << "Solution:" << endl;
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            if (j%3==0 && j!=0) cout << "| ";
            if (sudoku_start[i][j] == 0){
                cout << GREEN << sudoku[i][j] << RESET << " ";
            } 
            else { cout << YELLOW << sudoku[i][j] << RESET << " "; }
        }
        cout << endl;
        if ((i+1)%3==0) cout << "---------------------" << endl;
        
    }
}

void toEqual(int a[9][9], int b[9][9]){
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            a[i][j] = b[i][j];
        }
    }
}

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
    if (y==9){
        //reach the end of sudoku box
        if (x==8){
            show();
            return;
        }
        
        //reach the end of row
        else { solveSudoku(x+1, 0); }
    }

    //0 means element don't have any value
    else if(sudoku[x][y] == 0){
        for (int i=1; i<=9; i++){
            if (checkValid(x, y, i)){
                sudoku[x][y] = i;
                solveSudoku(x, y+1);
                sudoku[x][y] = 0;
            }
        }
    }

    else {
        solveSudoku(x, y+1);
    }
}

int main (){
    //input();
    toEqual(sudoku,sudoku_start);
    solveSudoku(0, 0);
    return 0;
}