#include<iostream>

using namespace std;

string getError(int num1, int num2, char op){
    string str = "";
    if (op == '+' or op == '-' or op == 'x') {
        return str;
    }
    else if (op == '/'){
        if (num2 == '0'){
            str = "Divided by zero";
            return str;
        }
        else return str;
    }
    else return "Invalid operator";
}

int main() {
    int a, b;
    char op;
    cin >> a >> op >> b;
    cout << getError(a, b, op);

    return 0;
}
