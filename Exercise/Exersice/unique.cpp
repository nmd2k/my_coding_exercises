    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;

    int main ()
    {
        int n;
        cin >> n;
        vector <int> a(n);
        vector <int> b;
        for (int i=0; i<n; i++){
            cin >> a[i];
        }
        sort (a.begin(), a.end());
        for (int i=0; i<n; i++){
            if (a[i] != a[i+1]){
                b.push_back(a[i]);
            }
        }
        cout << b.size();
        return 0;
    }
