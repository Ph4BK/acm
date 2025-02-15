#include <bits/stdc++.h>
using namespace std;
long long dp[1005][1005][2];
#define MOD 1000000007

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j][0] = dp[i][j][1] = 0;
            }
        }
        dp[1][k][1] = 1;
        long long sum = k >= 2 ? 1 : 0;
        for (int j = k; j >= 1; j--) {
            for (int i = 1; i <= n - 1; i++) {
                dp[i + 1][j][1] += dp[i][j][1];
                dp[i + 1][j][1] %= MOD;
            }
            for (int i = n; i >= 2; i--) {
                dp[i - 1][j][0] += dp[i][j][0];
                dp[i - 1][j][0] %= MOD;
            }
            for (int i = 1; i <= n; i++) {
                dp[i + 1][j - 1][1] += dp[i][j][0];
                dp[i + 1][j - 1][1] %= MOD;
                dp[i - 1][j - 1][0] += dp[i][j][1];
                dp[i - 1][j - 1][0] %= MOD;
            }
            sum += dp[1][j][0] + dp[n][j][1];
            sum %= MOD;
        }
        cout << sum << endl;
    }
    return 0;
}
