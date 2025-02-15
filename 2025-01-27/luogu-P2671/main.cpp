#include <iostream>
using namespace std;
#define MOD 10007
int num[100005];
int colors[100005];
int count[100005][2];
int sum[100005][2];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> colors[i];
        count[colors[i]][i % 2]++;
        sum[colors[i]][i % 2] += num[i];
        sum[colors[i]][i % 2] %= MOD;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        count[colors[i]][i % 2] %= MOD;
        ans += i * ((count[colors[i]][i % 2] - 2) * num[i] % MOD + sum[colors[i]][i % 2]) % MOD;
    }
    ans %= MOD;
    cout << ans << endl;
    return 0;
}
