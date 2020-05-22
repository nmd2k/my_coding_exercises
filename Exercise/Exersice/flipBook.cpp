#include<bits/stdc++.h>
using namespace std;
int solve(int n,int p){
    int fromleft=p/2;
    if(p%2==1) p--;
    if(n%2==1) n--;
    int fromright=(n-p)/2;
    return min(fromleft,fromright);
}
int main(){
    int n,p;
    cin>>n>>p;
    cout<<solve(n,p);

    return 0;
}
