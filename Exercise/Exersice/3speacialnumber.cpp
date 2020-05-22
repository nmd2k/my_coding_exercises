#include <iostream>
#include <cmath>
using namespace std;

void checkInteger (int num)
{
	for (int j=2; j<=num; j++){
        if (j == 2) cout << j << ' ';
        else {
                int check = 0;
                for (int i=2; i<j; i++){
                    if (j%i==0) check ++;
                }
            if (check == 0) cout << j << ' ';
        }
	}
	cout << endl;
}

void checkPerfect (int num)
{
    for (int j=1; j<=num; j++){
        int sum = 0;
        for(int i=1;i<=j/2;i++){
            if(j%i==0)
                sum+=i;
        }
        if(sum==j) cout << j << ' ';
    }
    cout << endl;

}

void checkSquare (int num)
{
    for (int j=0; j<=num; j++){
//        if (j==0) cout << j << ' ';
        for (int i=1; i<j; i++){
            if (i*i == j) cout << j << ' ';
        }
    }
    cout << endl;
}

int main ()
{
    int num;
    cin >> num;
    checkInteger (num);
//    checkPerfect (num);
//    checkSquare (num);
    return 0;
}
