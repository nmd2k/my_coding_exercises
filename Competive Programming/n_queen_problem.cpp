#include <iostream>
#include <vector>
using namespace std;
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

int n = 8;
int a[7][7];
int used[7][7];

class Queen {
    public: 
        int x, y;

    Queen(int _x, int _y){
        int x = _x;
        int y = _y;
    }
};

vector <Queen> queens;

void show(){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (1) {
                cout << GREEN << a[i][j] << RESET;
            } else {
                cout << a[i][j];
            }
        }
        cout << endl;
    }
}

bool checkValid(int x, int y){
    for (int i=0; i<n; i++){
        if(x == queens[i].x) return false;
        if(y == queens[i].y) return false;
        if(abs(x - queens[i].x) == abs(y - queens[i].y)) return false;
    }
}

void backtrack(int x, int y){
    if (y == n-1){
        if (x == n-1){
            show();
            return;
        } else {
            backtrack(x+1, y);
        }
    }
    for (int i=0; i<n; i++){
        if(checkValid(x, y)){
            a[x][y] = 1;
            backtrack(x, y+1);
            a[x][y] = 0;
        }
    }

}

int main(){
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<n; j++){
    //         cin >> a[i][j];
    //     }
    // }

    backtrack(0, 0);
    return 0;
}