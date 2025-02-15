#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    vector<int>child;
};

int dfs(node* arr, const node& tempNode, vector<int>& require) {
    int size = tempNode.child.size();
    if (size == 0) {
        return tempNode.data;
    }
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += dfs(arr, arr[tempNode.child[i]], require);
    }
    require.push_back(sum);
    return sum;
}

int main(){
    int n;
    scanf("%d", &n);
    node arr[n + 1];
    arr[0].data = 2200;
    for (int i = 1; i <= n; i++) {
        int f, a;
        scanf("%d%d", &f, &a);
        arr[i].data = a;
        arr[f].child.push_back(i);
    }
    vector<int>limit;
    for (int i = 0; i < n; i++) {
        if (arr[i].child.empty()) {
            if (arr[i].data > 2200) {
                printf("NO\n");
                return 0;
            }
        }
        else {
            limit.push_back(arr[i].data);
        }
    }
    vector<int> require;
    int total_power = dfs(arr, arr[0], require);
    if (total_power > 2200) {
        printf("NO\n");
        return 0;
    }
    sort(limit.begin(), limit.end());
    sort(require.begin(), require.end());
    for (int i = 0; i < limit.size(); i++) {
        if (require[i] > limit[i]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
