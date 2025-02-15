#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    ll inner{};
    ll total{};
    int size{};
    vector<int>child;
};

node city[200005];
vector<int> adjacent[200005];

ll C2(ll n) {
    return n * (n - 1) / 2;
}

void build(int prev_idx, int temp_idx) {
    for (int i = 0; i < adjacent[temp_idx].size(); i++) {
        if (adjacent[temp_idx][i] == prev_idx) continue;
        city[temp_idx].child.push_back(adjacent[temp_idx][i]);
        build(temp_idx, adjacent[temp_idx][i]);
    }
}

int dfs_inner(node& temp) {
    int sum = 1;
    for (int i = 0; i < temp.child.size(); i++) {
        sum += dfs_inner(city[temp.child[i]]);
        temp.inner += city[temp.child[i]].inner + C2(city[temp.child[i]].size);
    }
    temp.size = sum;
    return sum;
}

void dfs_total(node& temp, int n) {
    for (int i = 0; i < temp.child.size(); i++) {
        city[temp.child[i]].total = temp.total - C2(city[temp.child[i]].size)\
        + C2(n - city[temp.child[i]].size);
        dfs_total(city[temp.child[i]], n);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adjacent[temp1 - 1].push_back(temp2 - 1);
        adjacent[temp2 - 1].push_back(temp1 - 1);
    }
    build(-1, 0);
    dfs_inner(city[0]);
    city[0].total = city[0].inner;
    dfs_total(city[0], n);
    for (int i = 0; i < n; i++) {
        cout << city[i].total << endl;
    }
    return 0;
}
