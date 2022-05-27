#include <iostream>
#include <math.h>
#include <limits.h>

using namespace std;

int reverse(int x) {
    int32_t val = x;
    int64_t reversed = 0;
    
    bool is_neg = val<0;
    val = abs(val);

    while (val>0) {
        if (reversed > INT_MAX/10) {
            return 0;
        }
        reversed = reversed*10 + val%10;
        val /= 10;
    }

    return reversed*(is_neg?-1:1);
}


int main(){
    int x = -123;
    cout << reverse(x) << endl;
    return 0;
}