#include <iostream>
#include <climits>
#define MAXN 100010
int max[MAXN][17];
int next[MAXN];

struct plate {
    int diameter, capacity;
};
plate fountain[MAXN];

struct until {
    int sum, idx;
};
until flow[MAXN][17];

int get_max(int l, int r) {
    int len = r - l + 1;
    int exp = -1;
    while (len) {
        exp++;
        len >>= 1;
    }
    return std::max(max[l][exp], max[r + 1 - (1 << exp)][exp]);
}

int main() {
    int n, q;
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &fountain[i].diameter, &fountain[i].capacity);
    }
    fountain[n + 1].diameter = INT_MAX;
    fountain[n + 1].capacity = INT_MAX;
    for (int i = 1; i <= n + 1; i++) {
        max[i][0] = fountain[i].diameter;
    }
    for (int exp = 1; exp <= 16; exp++) {
        for (int i = 1; i - 1 + (1 << exp) <= n + 1; i++) {
            max[i][exp] = std::max(max[i][exp - 1], max[i + (1 << exp - 1)][exp - 1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        int l = i + 1, r = n + 1;
        int cur_next = n + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (get_max(i + 1, mid) > fountain[i].diameter) {
                cur_next = mid;
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        next[i] = cur_next;
    }
    next[n + 1] = n + 1;
    for (int i = 1; i <= n + 1; i++) {
        flow[i][0].sum = fountain[i].capacity;
        flow[i][0].idx = i;
    }
    for (int exp = 1; exp <= 16; exp++) {
        for (int i = 1; i <= n + 1; i++) {
            if (flow[i][exp - 1].idx == n + 1 || flow[next[flow[i][exp - 1].idx]][exp - 1].idx == n + 1) {
                flow[i][exp].idx = n + 1;
                flow[i][exp].sum = INT_MAX;
                continue;
            }
            flow[i][exp].idx = flow[next[flow[i][exp - 1].idx]][exp - 1].idx;
            flow[i][exp].sum = flow[i][exp - 1].sum + flow[next[flow[i][exp - 1].idx]][exp - 1].sum;
        }
    }
    while (q--) {
        int from, water;
        scanf("%d %d", &from, &water);
        int cur = from, check = next[from];
        water -= fountain[from].capacity;
        for (int exp = 16; exp >= 0; exp--) {
            if (flow[check][exp].sum <= water) {
                water -= flow[check][exp].sum;
                cur = flow[check][exp].idx;
                check = next[cur];
            }
        }
        if (water > 0) cur = next[cur];
        if (cur == n + 1) printf("0\n");
        else printf("%d\n", cur);
    }
    return 0;
}
