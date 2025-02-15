#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int mark[n + 1];
    for (int i = 1; i <= n; i++) {
        mark[i] = -1;
    }
    int move[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> move[i];
    }
    queue<int> q;
    q.push(a);
    mark[a] = 0;
    while (!q.empty()) {
        int temp = q.front();
        if (temp == b) {
            cout << mark[temp] << endl;
            return 0;
        }
        q.pop();
        if (temp + move[temp] <= n && mark[temp + move[temp]] == -1) {
            mark[temp + move[temp]] = mark[temp] + 1;
            q.push(temp + move[temp]);
        }
        if (temp - move[temp] >= 1 && mark[temp - move[temp]] == -1) {
            mark[temp - move[temp]] = mark[temp] + 1;
            q.push(temp - move[temp]);
        }
    }
    cout << mark[b] << endl;
    return 0;
}
