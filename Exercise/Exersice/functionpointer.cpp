#include <iostream>
#include <vector>
using namespace std;

void arrayIntInput(vector<int>&arr){
    int x;
    while (cin>>x){
        arr.push_back(x);
    }
}

void Swap (int&a, int&b){
    a = a + b;
    b = a - b;
    a = a - b;
}

void bubbleSort (vector <int>& arr){ //, bool (*even_odd)(int&)
    bool sorted = false;
    while (!sorted){
        sorted = true;
        for (int i=0; i<arr.size()-1; i++){
            if (arr[i] > arr[i+1]){
                Swap (arr[i], arr[i+1]);
                sorted = false;
            }
        }
    }
}

bool even_odd (int&a){
    if (a%2==0) return true;
    return false;
}

void printArray (vector <int>& arr){
    for (int i=0; i<arr.size(); i++){
        cout << arr[i] << ' ';
    }
}

int main ()
{
    vector <int> arr;
    //generate vector
    arrayIntInput (arr);
    bubbleSort(arr);
    printArray(arr);
    return 0;
}

/*#include <iostream>
#include <vector>
using namespace std;

bool returnHigherNumber (int&a, int&b){
    return a>b;
}
bool returnLowerNumber (int&a, int&b){
    return a<b;
}

void Swap(int&a, int&b){
    a = a+b;
    b = a-b;
    a = a-b;
}

void bubbleSort (vector <int>& arr, bool (*p)(int&, int&)){
    bool sorted = false;
    while (!sorted){
        sorted = true;
        for (int i=0; i<arr.size()-1; i++){
            if (p(arr[i], arr[i+1])) {
                Swap(arr[i], arr[i+1]);
                sorted = false;
            }
        }
    }
}

int main ()
{
    vector <int> arr (5);
    for (int i=0; i<5; i++){
        cin >> arr[i];
    }
    cout << "Ham tang: ";
    bubbleSort(arr, returnHigherNumber);
    for (int i=0; i<5; i++){
        cout << arr[i] << ' ';
    }
    cout << endl << "Ham giam: ";
    bubbleSort(arr, returnLowerNumber);
    for (int i=0; i<5; i++){
        cout << arr[i] << ' ';
    }
}
*/
