#include <bits/stdc++.h>
#include <ctime>
using namespace std;
int num[21];
int prefix[21];
double dp[21][7];
#define sqr(x) ((x)*(x))
constexpr double time_limit = .98;
constexpr double down = .99;
constexpr double markov = 1000.;

int main() {
    srand(time(nullptr));
    int n, m;
    cin >> n >> m;
    double aver = 0.;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        aver += num[i];
    }
    aver /= m;
    clock_t start = clock();
    double min_ans = 1e100, ans = 1e100;
    double T = 1e5;
    while (T > 1e-3) {
        if (double(clock() - start) / CLOCKS_PER_SEC > time_limit) break;
        T *= down;
        for (int mk = 0; mk < markov / pow(T, .25); mk++) {
            int x = rand() % n + 1;
            int y = rand() % n + 1;
            if (x == y) continue;
            swap(num[x], num[y]);
            for (int i = 1; i <= n; i++) {
                prefix[i] = prefix[i - 1] + num[i];
            }
            memset(dp, 127, sizeof(dp));
            dp[0][0] = 0.;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    for (int k = 0; k <= i - 1; k++) {
                        dp[i][j] = min(dp[i][j], dp[k][j - 1] + sqr(prefix[i] - prefix[k] - aver));
                    }
                }
            }
            double tmp = dp[n][m];
            min_ans = min(min_ans, tmp);
            if (tmp < ans || exp((ans - tmp) / T) > rand()) ans = tmp;
            else swap(num[x], num[y]);
        }
    }
    printf("%.2lf\n", sqrt(min_ans / m));
    return 0;
}