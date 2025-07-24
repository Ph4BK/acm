#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, k;
int arr[26];
int stat[26];
ll S;
ll ans;
map <pair<int, ll>, int> f; // <<number of factorials, current sum>, method count>

ll fact(ll x) {
    ll ret = 1;
    for (ll i = 1; i <= x; i++) {
        ret *= i;
        if (ret > S) return -1;
    }
    return ret;
}

void check1() {
    int cnt = 0;
    ll sum = 0;
    for (int i = 1; i <= m; i++) {
        if (stat[i] == 1) {
            if (sum + arr[i] > S) return;
            sum += arr[i];
        }
        if (stat[i] == 2) {
            ll temp = fact(arr[i]);
            if ((temp == -1) || (++cnt > k) || (sum + temp > S)) return;
            sum += temp;
        }
    }
    f[{cnt, sum}]++; // add to the method count
    f[{-1, sum}] = 1; // mark the sum as occurred
}

void dfs1(int cur) {
    if (cur > m) {
        check1();
        return;
    }
    for (int i = 0; i <= 2; i++) {
        stat[cur] = i;
        dfs1(cur + 1);
    }
}

map <pair<int, ll>, ll> g; // memorize the searched queries
// add up f[{i, sum}], 0 <= i <= cnt
ll qry(int cnt, ll sum) {
    if (g.contains({cnt, sum})) return g[{cnt, sum}];
    return g[{cnt, sum}] = f[{cnt, sum}] + (cnt ? qry(cnt - 1, sum) : 0);
}

void check2() {
    int cnt = 0;
    ll sum = 0;
    for (int i = m + 1; i <= n; i++) {
        if (stat[i] == 1) {
            if (sum + arr[i] > S) return;
            sum += arr[i];
        }
        if (stat[i] == 2) {
            ll temp = fact(arr[i]);
            if ((temp == -1) || (++cnt > k) || (sum + temp > S)) return;
            sum += temp;
        }
    }
    if (f.contains({-1, S - sum})) ans += qry(k - cnt, S - sum);
}

void dfs2(int cur) {
    if (cur > n) {
        check2();
        return;
    }
    for (int i = 0; i <= 2; i++) {
        stat[cur] = i;
        dfs2(cur + 1);
    }
}

int main() {
    cin >> n >> k >> S;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    m = n >> 1;
    dfs1(1);
    dfs2(m + 1);
    cout << ans << endl;
    return 0;
}
