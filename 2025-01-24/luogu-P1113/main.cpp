#include <iostream>
#include <vector>
using namespace std;

struct task {
    int cost;
    vector<int> sub;
};
task list[10010];
int mark[10010];

void dfs(int temp, int last_cost) {
    int temp_cost = last_cost + list[temp].cost;
    if (temp_cost > mark[temp]) {
        mark[temp] = temp_cost;
        for (int i = 0; i < list[temp].sub.size(); i++) {
            dfs(list[temp].sub[i], mark[temp]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int no, cost;
        cin >> no >> cost;
        list[no].cost = cost;
        int pre;
        cin >> pre;
        while (pre) {
            list[pre].sub.push_back(no);
            cin >> pre;
        }
    }
    dfs(1, 0);
    int max = mark[1];
    for (int i = 2; i <= n; i++) {
        if (mark[i] > max) max = mark[i];
    }
    cout << max << endl;
    return 0;
}
