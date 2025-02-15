#include <iostream>
#include <vector>
#include <queue>
#define MOD 80112002
using namespace std;

struct species {
    int prey{};
    vector<int> predator;
};
species list[5010];
int f[5010];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        list[from].predator.push_back(to);
        list[to].prey++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (list[i].prey == 0) {
            f[i] = 1;
            q.push(i);
        }
    }
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        for (int i = 0; i < list[temp].predator.size(); i++) {
            list[list[temp].predator[i]].prey--;
            f[list[temp].predator[i]] = (f[list[temp].predator[i]] + f[temp]) % MOD;
            if (list[list[temp].predator[i]].prey == 0) {
                q.push(list[temp].predator[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (list[i].predator.empty()) {
            ans = (ans + f[i]) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}