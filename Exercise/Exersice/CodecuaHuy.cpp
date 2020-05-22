#include <iostream>
#include <vector>

using namespace std;

void change(string s, string t, vector<int> a)
{
    if(t.length()==s.length()) cout <<t<<" ";
    else
    {
        for(int i=0; i<s.size(); i++)
            if(a[i]==0)
            {
                a[i]=1;
                change(s, t+s[i], a);
                a[i]=0;
            }
    }
}

int main()
{
    string s;
    cin >>s;
    vector<int> a(s.size(), 0);
    change(s, "", a);
    return 0;
}
