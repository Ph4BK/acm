#include <iostream>
#include <deque>
#include <climits>
using namespace std;
int arr[200001];
int dp_max[200001];
deque<int> q;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }
    q.push_front(0);
    for (int i = l; i <= n; i++) {
        while (q.front() + r < i) q.pop_front();
        dp_max[i] = dp_max[q.front()] + arr[i];
        int cur = i - l + 1;
        if (cur >= 1) {
            while (!q.empty() && dp_max[q.back()] <= dp_max[cur]) q.pop_back();
            q.push_back(cur);
        }
    }
    int ans = INT_MIN;
    for (int i = n; i >= n - r + 1; i--) {
        int jump = i / l;
        if (jump * r >= i) {
            ans = max(ans, dp_max[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
