#include<bits/stdc++.h>
using namespace std;
long long cnt, n, head[200005], siz[200005], ans[200005], cans[200005];
struct node {
    int u, v, nxt;
} a[400005];

void merge(int x, int y) {
    a[++cnt].u = x;
    a[cnt].v = y;
    a[cnt].nxt = head[x];
    head[x] = cnt;
}

void dfs_siz(int now, int f) {
    for (int i = head[now]; i; i = a[i].nxt) {
        if (a[i].v != f) {
            dfs_siz(a[i].v, now);
            siz[now] += siz[a[i].v];
        }
    }
    siz[now]++;
    return;
}

void dfs_cans(int now, int f) {
    for (int i = head[now]; i; i = a[i].nxt) {
        if (a[i].v != f) {
            dfs_cans(a[i].v, now);
            cans[now] += cans[a[i].v] + siz[a[i].v] * (siz[a[i].v] - 1) / 2;
        }
    }
    return;
}

void dfs_ans(int now, int f) {
    for (int i = head[now]; i; i = a[i].nxt) {
        if (a[i].v != f) {
            long long t = siz[a[i].v];
            ans[a[i].v] = ans[now] + (n - t) * (n - t - 1) / 2 - t * (t - 1) / 2;
            dfs_ans(a[i].v, now);
        }
    }
    return;
}

int main() {
    cin >> n;
    int t1, t2;
    for (int i = 1; i <= n - 1; i++) {
        cin >> t1 >> t2;
        merge(t1, t2);
        merge(t2, t1);
    }
    dfs_siz(1, 0);
    dfs_cans(1, 0);
    ans[1] = cans[1];
    dfs_ans(1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}
