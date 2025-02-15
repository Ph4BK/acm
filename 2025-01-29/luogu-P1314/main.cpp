#include <iostream>
#include <climits>
using namespace std;
#define MAXN 200010
int weight[MAXN];
int value[MAXN];
long long pre_value[MAXN];
int pre_count[MAXN];
int l[MAXN];
int r[MAXN];
int n, m;
long long s;

long long score(int W) {
    for (int i = 1; i <= n; i++) {
        if (weight[i] >= W) {
            pre_value[i] = pre_value[i - 1] + value[i];
            pre_count[i] = pre_count[i - 1] + 1;
        }
        else {
            pre_value[i] = pre_value[i - 1];
            pre_count[i] = pre_count[i - 1];
        }
    }
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        ans += (pre_count[r[i]] - pre_count[l[i] - 1]) * (pre_value[r[i]] - pre_value[l[i] - 1]);
    }
    return ans;
}

int main() {
    cin >> n >> m >> s;
    int high = 1, low = 1;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
        high = high > weight[i] ? high : weight[i];
        cin >> value[i];
    }
    high++;
    for (int i = 0; i < m; i++) {
        cin >> l[i];
        cin >> r[i];
    }
    long long dif = LONG_LONG_MAX;
    while (low < high) {
        int mid = (low + high) / 2;
        long long temp = score(mid);
        dif = min(dif, abs(temp - s));
        if (temp <= s) high = mid;
        else low = mid + 1;
    }
    cout << dif << endl;
    return 0;
}