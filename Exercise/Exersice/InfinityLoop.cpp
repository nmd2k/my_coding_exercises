#include <iostream>
#include <cmath>
using namespace std;


void Calculator ()
{
        int n;
        cout << "Nhap gia tri de, anh ban thien lanh: " << endl;
        cin >> n;
        cout << "Gia tri n+1 = " << n+1 << endl;
}

int main ()
{
    char c;
    do {
        Calculator();
        cout << "Muon tiep tuc khong anh ban thien lanh:? (Y/N)" << endl;
        cin >> c;
    } while (c == 'Y' or c == "Yes" or c == 'y' or c == "yes");
    return 0;
}
