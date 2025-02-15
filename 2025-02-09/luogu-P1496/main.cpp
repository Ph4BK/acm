#include <bits/stdc++.h>
using namespace std;
#define MAXN 20000
int a[MAXN];
int b[MAXN];
int c[2 * MAXN];
int d[2 * MAXN];
int f[2 * MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cin >> b[i];
        d[2 * i] = a[i];
        d[2 * i + 1] = b[i];
    }
    sort(d, d + 2 * n);
    int prev = c[0] = d[0];
    int cnt = 1;
    for (int i = 1; i < 2 * n; i++) {
        if (prev != d[i]) {
            prev = d[i];
            c[cnt++] = d[i];
        }
    }
    for (int i = 0; i < n; i++) {
        int x = lower_bound(c, c + cnt, a[i]) - c;
        int y = lower_bound(c, c + cnt, b[i]) - c;
        for (int j = x; j < y; j++) {
            f[j] = 1;
        }
    }
    long long ans = 0;
    for (int i = 0; i < cnt; i++) {
        if (f[i]) {
            ans += c[i + 1] - c[i];
        }
    }
    cout << ans << endl;
}