#include <iostream>
#include <math.h>
using namespace std;

int n;

bool isInteger(int x, int y){
    float a = (float)(x*y)/100;
    return floor(a)==a;
}

int percent(){
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    
    int index = 1;
    while(index < 1000000000){
        if (isInteger(index, A))
            if (isInteger(index, B))
                if (isInteger(index, C))
                    if (isInteger(index, E))
                        if (isInteger(index, D))
                            return index;
        index++;
    }

    return index;
}

int main (){
    cin >> n;
    for (int i=0; i<n; i++){
        cout << percent() << endl;
    }
}