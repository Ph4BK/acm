#include <iostream>
using namespace std;

long long pow (long long base, int exp, int mod) {
    long long ans = 1;
    while (exp) {
        if (exp & 1) ans = ans * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return ans % mod;
}

int main() {
    int a, b, p;
    cin >> a >> b >> p;
    long long ans = pow(a, b, p);
    printf("%d^%d mod %d=%lld", a, b, p, ans);
    return 0;
}
