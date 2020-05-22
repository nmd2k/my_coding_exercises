#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int arithmetic(int num1, int num2, char op){
    if(op == '+') return num1+num2;
    if(op == '-') return num1-num2;
    if(op == 'x') return num1*num2;
    if(op == '/') return num1/num2;
}

double mathFunc(double num, string op){
    if(op == "cos") return cos(num);
    if(op == "sin") return sin(num);
    if(op == "sqrt") return sqrt(num);

}

void calculate(int argc, char* argv[]){
    if (argc == 3){
        string str(argv[1]);
        double num = atoi(argv[2]);
        cout << fixed << setprecision (2) << mathFunc(num, str);
    }
    if (argc == 4){
        double num1 = atoi(argv[1]);
        double num2 = atoi(argv[3]);
        char op = *argv [2];
        cout << arithmetic(num1, num2, op);
    }
}

int main() {
    int argc;
    cin >> argc;
    char* argv[argc];

    for(int i = 1; i < argc; i++) {
        argv[i] = new char[20];
        cin >> argv[i];
    }

    calculate(argc, argv);

    return 0;
}
