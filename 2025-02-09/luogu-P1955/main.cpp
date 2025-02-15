#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
int equal_a[MAXN];
int equal_b[MAXN];
int unequal_a[MAXN];
int unequal_b[MAXN];
int c[2 * MAXN];
int d[2 * MAXN];
int fa[2 * MAXN];

int find(int i) {
    if (fa[i] == i) {
        return i;
    }
    return fa[i] = find(fa[i]);
}

void build(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) fa[a] = b;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int equal_cnt = 0, unequal_cnt = 0;
        for (int i = 0; i < n; i++) {
            int a, b, stat;
            cin >> a >> b >> stat;
            d[2 * i] = a;
            d[2 * i + 1] = b;
            if (stat == 1) {
                equal_a[equal_cnt] = a;
                equal_b[equal_cnt] = b;
                equal_cnt++;
            }
            else {
                unequal_a[unequal_cnt] = a;
                unequal_b[unequal_cnt] = b;
                unequal_cnt++;
            }
        }
        int prev = c[0] = d[0];
        int c_cnt = 1;
        for (int i = 1; i < 2 * n; i++) {
            if (d[i] != prev) {
                prev = d[i];
                c[c_cnt++] = d[i];
            }
        }
        sort(c, c + c_cnt);
        for (int i = 0; i < c_cnt; i++) {
            fa[i] = i;
        }
        for (int i = 0; i < equal_cnt; i++) {
            int idx_a = lower_bound(c, c + c_cnt, equal_a[i]) - c;
            int idx_b = lower_bound(c, c + c_cnt, equal_b[i]) - c;
            build(idx_a, idx_b);
        }
        int ok = 1;
        for (int i = 0; i < unequal_cnt; i++) {
            int idx_a = lower_bound(c, c + c_cnt, unequal_a[i]) - c;
            int idx_b = lower_bound(c, c + c_cnt, unequal_b[i]) - c;
            if (find(idx_a) == find(idx_b)) {
                ok = 0;
                break;
            }
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
