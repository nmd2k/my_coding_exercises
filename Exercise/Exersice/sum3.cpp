#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >>n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a.begin(), a.end());
//    for(int i=0; i<n; i++){
//        for(int j=i+1; j<n; j++){
//            int k=n-1;
//            do{
//                k--;
////                if (v[k]!=v[k-1]){
//                    if((v[i]+v[j]+v[k])==0){
//                        cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<endl;
//                    }
////                }
////                else break;
//            } while (k>j and v[k]!=v[k-1]);
//        }
//    }
    for (int i = 0; i < n; i++)
    {
        int k = n - 1;
        if(i == 0 || a[i] > a[i-1])
            for (int j = i + 1; j < k; j++)
            {
                if (j == i + 1 || a[j] > a[j - 1])
                {
                    while (j < k && a[i] + a[j] + a[k] > 0)
                        k--;
                    if (i < j && j < k && a[i] + a[j] + a[k] == 0)
                        cout << a[i] << ' ' << a[j] << ' ' << a[k] << endl;
                }
            }
        }
    return 0;
}
