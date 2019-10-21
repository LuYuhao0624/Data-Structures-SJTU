#include <iostream>

using namespace std;

int fast_exp_mod(int base, int order, int divisor) {
    int res = 1;
    while(order) {
        if(order & 1) {
            res *= base;
            res %= divisor;
        }
        base *= base;
        base %= divisor;
        order >>= 1;
    }
    return res;
}

int main() {
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    cout << (x % n + (m % n) * fast_exp_mod(10, k, n)) % n;
    return 0;
}