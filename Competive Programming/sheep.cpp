#include <iostream>
using namespace std;

int N;
int L;
int loss[100];

bool checkValid(int x)
{
    for (int i = 0; i < L; i++)
    {
        int y = x;
        while (y > 0)
        {
            if (y % 10 == loss[i]){
                return false;
            }
            y = y / 10;
        }
    }
    return true;
}

int biggestSheep(int sheep[])
{
    int index = 1;
    int biggest = 1;
    while (index <= N)
    {
        
        if (checkValid(biggest)) {
            sheep[index] = biggest;
            biggest ++;
            index++;
        }
        else {
            biggest++;
        }
    }
}

int main()
{
    cin >> N >> L;
    for (int i = 0; i < L; i++)
    {
        cin >> loss[i];
    }

    int sheep[N];
    biggestSheep(sheep);

    //the biggest number will be pointed at the last sheep, index N
    cout << sheep[N];

    return 0;
}