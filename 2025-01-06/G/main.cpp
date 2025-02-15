#include <bits/stdc++.h>
using namespace std;
int arr[1000000];
int st_max[21][1000000];
int count_front[1000000];

void fill_max(int n) {
    for (int j = 0; j < n; j++) {
        st_max[0][j] = arr[j];
    }
    for (int i = 1; n >> i; i++) {
        for (int j = 0; j <= n - (1 << i); j++) {
            st_max[i][j] = max(st_max[i - 1][j], st_max[i - 1][j + (1 << i - 1)]);
        }
    }
}

int find_max(int l, int r) {
    int digit = 0;
    while (r - l + 1 >> ++digit);
    digit--;
    return max(st_max[digit][l], st_max[digit][r - (1 << digit) + 1]);
}

void count(vector<vector<int>>&idx, int n) {
    for (int i = 0; i < n; i++) {
        idx[arr[i] - 1].push_back(i);
        count_front[i] = idx[arr[i] - 1].size() - 1;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        fill_max(n);
        vector<vector<int>>idx(n);
        count(idx, n);
        long long count = 0;
        for (int i = 0; i < n; i++) {
            if (count_front[i] + k > (int)idx[arr[i] - 1].size()) continue;
            int left, right;
            left = i, right = n - 1;
            while (left < right) {
                int mid = (left + right) / 2 + 1;
                if (find_max(left, mid) <= arr[i]) left = mid;
                else right = mid - 1;
            }
            if (left < idx[arr[i] - 1][count_front[i] + k - 1]) continue;
            long long right_len = left - idx[arr[i] - 1][count_front[i] + k - 1] + 1;
            long long left_len;
            if (i == 0 || arr[i - 1] >= arr[i]) {
                left_len = 1;
            }
            else {
                left = 0; right = i - 1;
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (find_max(mid, right) < arr[i]) right = mid;
                    else left = mid + 1;
                }
                left_len = i - left + 1;
            }
            count += left_len * right_len;
        }
        printf("%lld\n", count);
    }
    return 0;
}
