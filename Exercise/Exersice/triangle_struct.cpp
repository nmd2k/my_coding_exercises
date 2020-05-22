#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct triangle
{
    int edge1,edge2,edge3;
    triangle(int initEdge1,int initEdge2, int initEdge3)
    {
        // your code here
    }

    double getArea()
    {
        // your code here
    }
};

int main()
{
    int edge1,edge2,edge3;
    cin >> edge1 >> edge2 >> edge3;
    triangle tri(edge1,edge2,edge3);
    double area = tri.getArea();
    if (area == -1) cout << "invalid" << endl;
    else cout << fixed << setprecision(2) << area << endl;
    return 0;
}
