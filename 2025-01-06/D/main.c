#include <stdio.h>
#include <math.h>

double dis(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int n;
    scanf("%d", &n);
    int x[n];
    int y[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    double dp[n];
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = dis(x[i], y[i], x[0], y[0]);
        for (int j = 1; j <= i; j++) {
            double temp = dp[j - 1] + dis(x[i], y[i], x[j], y[j]);
            if (temp > dp[i]) {
                dp[i] = temp;
            }
        }
    }
    printf("%.10f\n", dp[n - 1]);
    return 0;
}
