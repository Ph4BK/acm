#include <iostream>
#include <vector>
using namespace std;
int rec[100010];
vector<int> connect[100010];

void dfs(int temp, int fill) {
    rec[temp] = fill;
    for (int it : connect[temp]) {
        if (rec[it]) continue;
        dfs(it, fill);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        connect[to].push_back(from);
    }
    for (int i = n; i >= 1; i--) {
        if (rec[i]) continue;
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++) {
        cout << rec[i] << " ";
    }
    return 0;
}
