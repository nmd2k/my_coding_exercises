#include <iostream>
#include <vector>

using namespace std;

char letter[26]{
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'
    , 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'
    , 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

long int giaithua (int &n){
    if (n == 1) return 1;
    else return n*giaithua(n-1);
}

long int nAk (int &N, int &K){
    return giaithua(N)/giaithua(N-K);
}

void printletter (int &value, int &K){
    for (int i=0; i<K; i++){
        cout <<
    }

}
int main ()
{
    int N, K;
    cin >> N >> K;
//    long int value = nAk (N, K);
//    int count =  value/N;
//    cout << value;
    for (int i=0; i<N; i++){
        printletter(i, K);
    }
    return 0;
}
