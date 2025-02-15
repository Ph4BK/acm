#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long numerator_fact[100005];
long long denominator_fact[100005];
long long q_minus_p[100005];
long long divide_q[100005];

long long pow(long long base, int exp) {
    if (exp == 0) return 1;
    long long sqrt = pow(base, exp / 2);
    long long temp = sqrt * sqrt % MOD;
    if (exp % 2 == 0) return temp;
    return temp * base % MOD;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long p, q;
        cin >> n >> p >> q;
        long long mult = pow(p, n);
        q_minus_p[0] = 1;
        for (int i = 1; i <= n - 1; i++) {
            q_minus_p[i] = q_minus_p[i - 1] * (q - p) % MOD;
        }
        long long inv_q = pow(q, MOD - 2);
        long long temp = pow(inv_q, n);
        for (int i = 0; i <= n - 1; i++) {
            divide_q[i] = temp;
            temp = temp * inv_q % MOD;
        }
        temp = 1;
        for (int i = 0; i <= n - 1; i++) {
            numerator_fact[i] = temp;
            temp = temp * (n + i) % MOD;
        }
        temp = 1;
        for (int i = 1; i <= n - 1; i++) {
            temp = temp * i % MOD;
        }
        //temp = (n - 1)!
        temp = pow(temp, MOD - 2); //1 / (n - 1)!
        for (int i = n - 1; i >= 0; i--) {
            denominator_fact[i] = temp;
            temp = temp * i % MOD;
        }
        long long sum = 0;
        for (int i = 0; i <= n - 1; i++) {
            long long cur = ((numerator_fact[i] * denominator_fact[i]) % MOD) *\
        ((q_minus_p[i] * divide_q[i]) % MOD) % MOD;
            sum = (sum + cur) % MOD;
        }
        sum = (sum * mult) % MOD;
        cout << sum << endl;
    }
    return 0;
}
