#include <iostream>
#include <vector>
#define ifor (i,m) for (int i=0; i<(m); i++)
using namespace std;

const string star = "*";
const string blank = "0";
vector <vector <char> > base (1, vector <char> (1));
bool check (int l){
    if (l == 1) return true;
    else if (l%2 == 0) return true;
    return false;
}

void printVector (const vector <vector <char> >& vector){
    ifor (i, vector.size()){
        ifor (j, vector.size()){
            cout << vector[i][j] << ' ';
        }
        cout << endl;
    }
}

vector<vector <char> > draw (int l, vector <vector <char> >&arr){
    if (l==1) return 0;
}

int main () {
    base[0][0] = star;
    printVector(base);
//    int l;
//    cin >> l;
//    vector <vector <char> > arr(l, vector<char> (l));
//    if (check (l)){
//        draw (l, arr);
//    }
    return 0;
}
