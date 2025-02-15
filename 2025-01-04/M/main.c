#include <stdio.h>
#define MOD 1000000007

long long pow2(int exp) {
    int digit = 0;
    while (exp >> ++digit);
    long long list[digit];
    list[0] = 2;
    for (int i = 1; i < digit; i++) {
        list[i] = list[i - 1] * list[i - 1] % MOD;
    }
    long long result = 1;
    for (int i = 0; i < digit; i++) {
        if (exp >> i & 1) {
            result = result * list[i] % MOD;
        }
    }
    return result;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        long long result = pow2(n - 1) - n + 2 * (n / 2) + 1;
        long long temp = (n / 2 + 2) * pow2(n / 2 - 1) % MOD;
        result = (result - temp + MOD) % MOD;
        printf("%lld\n", result);
    }
    return 0;
}
