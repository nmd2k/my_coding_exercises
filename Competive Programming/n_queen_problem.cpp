#include <iostream>
#include <stack>
#include <iterator>
using namespace std;
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

int n = 8;
int a[100][100];
int used[100][100];
stack <Queen> queen_stack;

class Queen {
    public:
        int x, y;

    Queen(int _x, int _y){
        int x = _x;
        int y = _y;
    }
};

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

bool checkValid(int x, int y){
    for (int i=0; i<n; i++){
    }
}

int main(){
    cin >> n;
    backtrack(0, 0);
    return 0;
}