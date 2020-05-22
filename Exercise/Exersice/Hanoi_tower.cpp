#include <iostream>

using namespace std;

void hanoi_tower (int n, char A, char B, char C){
    if (n == 0) {
        cout << "di chuyen dia 1" << " tu " << A << " den " << B << endl;
        return;
    }
    else {
        return hanoi_tower (n-1, A, C, B);
        cout << "di chuyen dia " << n << " tu " << A << " den " << B << endl;
        return hanoi_tower (n-1, C, B, A);
    }
}

int main ()
{
    int n;
    cin >> n;
    char a = 'A', b = 'B', c = 'C';
    hanoi_tower(n, a, b, c);
    return 0;
}
