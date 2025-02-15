#include <stdio.h>

long long power(int base, int exp) {
    int digit = 0;
    while (exp >> ++digit);
    long long list[digit];
    list[0] = base;
    for (int i = 1; i < digit; i++) {
        list[i] = list[i - 1] * list[i - 1] % 998244353;
    }
    long long result = 1;
    for (int i = 0; i < digit; i++) {
        if (exp >> i & 1) {
            result *= list[i];
            result %= 998244353;
        }
    }
    return result;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    long long sum = 0;
    long long prev1 = 1;
    long long prev2 = 1;
    for (int i = 1; i < n; i++) {
        long long temp = power(i + 1, m);
        temp = (temp - prev1 - prev2 + 998244353 * 2) % 998244353;
        prev1 = (prev1 + temp) % 998244353;
        prev2 = (prev2 + prev1) % 998244353;
        temp = temp * (n - i) % 998244353;
        temp = temp * i % 998244353;
        temp = temp * i % 998244353;
        sum = (sum + temp) % 998244353;
    }
    printf("%lld\n", sum);
    return 0;
}