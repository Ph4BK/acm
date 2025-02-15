#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n, sum, d;
int len[51], a[65], pre[51];

void dfs(int u, int k, int p) {
    if (u == 0) {
        dfs(d, k - 1, a[n - 1]);
        return;
    }
    if (k == 0) {
        cout << d << endl;
        exit(0);
    }
    p = min(p, u);
    while (p && (len[p] == 0)) p--;
    while (p) {
        if (len[p]) {
            len[p]--;
            dfs(u - p, k, p);
            len[p]++;
            if ((u == p) || (u == d)) return;
            p = pre[p];
        }
        else {
            p = pre[p];
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >>x;
        sum += x;
        len[a[i] = x]++;
    }
    sort(a, a + n);
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) pre[a[i]] = a[i - 1];
    }
    for (d = a[n - 1]; (d << 1) <= sum; d++) {
        if ((sum % d) == 0) dfs(d, sum / d, a[n - 1]);
    }
    cout << sum << endl;
    return 0;
}
