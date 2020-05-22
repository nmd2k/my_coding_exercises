#include <iostream>
using namespace std;

int main() {
    int n, q, k;
    cin >> n >> q;
    int a[][] = new int*[n];
    for (int i=0; i<n; i++)
    {
        cin >> k;
        a[i] = new int[k];
        for (int j=0; j<k; j++)
            cin >> a[i][j];
    }
    int u,v;
    for (int i=0; i<q; i++)
    {
        cin >> u>> v;
        cout << a[u][v]<<endl;
    }
 return 0;
}
