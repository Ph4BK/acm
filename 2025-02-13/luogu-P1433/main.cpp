#include <iostream>
#include <cmath>
using namespace std;
double x[15], y[15];
double dist[15][15];
double dp[1 << 15][15];
int n;

void init() {
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 1e6;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = dist[j][i] = sqrt(pow(x[i] - x[j], 2) + pow(y[j] - y[i], 2));
        }
    }
    init();
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = sqrt(pow(x[i], 2) + pow(y[i], 2));
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) continue;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if ((mask & (1 << j)) == 0) continue;
                dp[mask][j] = min(dp[mask][j], dp[mask - (1 << j)][i] + dist[i][j]);
            }
        }
    }
    double ans = 1e6;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[(1 << n) - 1][i]);
    }
    printf("%.2f\n", ans);
    return 0;
}
