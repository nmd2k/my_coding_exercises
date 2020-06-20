#include <iostream>
using namespace std;

int N, Q, row[300000][5];

int main(){
    cin >> N;

    for (int i = 1; i <= N; i++){
        int day, chieucao, mau;
        cin >> day >> chieucao >> mau;

        for (int j = 1; j <= 5; j ++){
            if (mau == j) {
                row[i][j] = row[i-1][j] + day*chieucao;
            }
            else row[i][j] = row[i-1][j];
        }
    }
        
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int pi, pj, c;
        cin >> pi >> pj >> c;
        cout << row[pj][c] - row[pi][c] << endl;
    }

    return 0;
}