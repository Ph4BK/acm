#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 500001
ll arr[MAXN];
ll prefix[MAXN];
deque<ll> q;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] + arr[i];
    }
    q.push_back(0);
    ll ans = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        while (q.front() + m < i)
            q.pop_front();
        ans = max(ans, prefix[i] - prefix[q.front()]);
        while (!q.empty() && prefix[q.back()] >= prefix[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout << ans << endl;
    return 0;
}
