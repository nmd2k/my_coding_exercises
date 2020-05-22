#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void reverseMatrix (vector <vector <char> > &matrix, int size){
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            if (matrix [i][j] == '.') matrix [i][j] = '0';
            else matrix [i][j] = '.';
        }
    }
}
 void printMatrix (vector <vector <char> > &matrix, int size){
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
 }


int main ()
{
    int n, size; cin >> n;
    if (n>1) size = pow(n,2);
    else size = 2;
    vector <vector <char> > matrix(size, vector <char> (size));

//    cout << "truoc: " << endl;

    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            matrix[i][j] = '.';
        }
    }
    printMatrix (matrix, size);


//    cout << "Sau: " << endl;
//    reverseMatrix (matrix, size);
//    printMatrix (matrix, size);

    return 0;
}
