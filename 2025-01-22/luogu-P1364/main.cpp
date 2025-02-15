#include <iostream>
#include <climits>
using namespace std;

struct node {
    int population;
    int connect[3];
};

node arr[105];

int dfs(int cur, int prev, int layer) {
    int sum = layer * arr[cur].population;
    for (int i = 0; i < 3; i++) {
        if (arr[cur].connect[i] != prev && arr[cur].connect[i] != 0) {
            sum += dfs(arr[cur].connect[i], cur, layer + 1);
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].population;
        int a, b;
        cin >> a >> b;
        arr[i].connect[1] = a;
        arr[i].connect[2] = b;
        arr[a].connect[0] = i;
        arr[b].connect[0] = i;
    }
    int min = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int temp = dfs(i, -1, 0);
        if (temp < min) min = temp;
    }
    cout << min << endl;
    return 0;
}
