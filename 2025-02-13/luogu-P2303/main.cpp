#include <iostream>
using namespace std;

long long quick_pow(long long base, int exp) {
    long long result = 1;
    while (exp) {
        if (exp & 1) result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}

int main() {
    long long n;
    cin >> n;
    long long ans = 1;
    for (long long i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        if (cnt) {
            ans *= (cnt + 1) * quick_pow(i, cnt) - cnt * quick_pow(i, cnt - 1);
        }
    }
    if (n > 1) ans *= 2 * n - 1;
    cout << ans << endl;
    return 0;
}
