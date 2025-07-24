#include <iostream>
using namespace std;

long long cal(int pow, int mod) {
    long long ans = 1;
    for (int i = 1; i <= pow; ++i) {
        ans *= (1 << (i - 1)) + 1;
        ans %= mod;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d, m;
        cin >> d >> m;
        int temp = d;
        int digit = 0;
        while (temp) {
            ++digit;
            temp >>= 1;
        }
        long long ans = 0;
        for (int i = 0; i < digit - 1; ++i) {
            ans += cal(i, m) * (1 << i);
            ans %= m;
        }
        ans += cal(digit - 1, m) * (d + 1 - (1 << (digit - 1)));
        ans %= m;
        cout << ans << endl;
    }
    return 0;
}
