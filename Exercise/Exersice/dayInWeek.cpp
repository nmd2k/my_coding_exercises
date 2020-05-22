#include <iostream>
#include <cmath>
using namespace std;

int calDate (int day, int month, int year)
{
    double year0 = (double)(year - (14-month)/12);
    double x = (double)(year0 + year0/4 - year0/100 + year0/400);
    double month0 = (double)(month +12*((14-month)/12)-2);
    int day0 = (double)(day + x + 31*month0/12);
    int result = day0%7;
    return result;
}

int main ()
{
    int day, month, year;
    cin >> day >> month >> year;
    cout << calDate (day, month, year);
    return 0;
}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//    int d, m, y;
//    cin >> d >> m >> y;
//    int y0 = 0, x = 0, m0 = 0, d0 = 0;
//    y0 = -(14 - m) / 12 + y;
    x += y0/4;
    x -= y0 / 100;
    x += y0 / 400;
        x += y0;
//    m0 = m + 12 * ((14 - m) / 12) - 2;
//    d0 = (d + x + 31 * m0 / 12);
//    cout << d0 % 7;
//}
