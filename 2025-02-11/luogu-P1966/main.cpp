#include <bits/stdc++.h>
using namespace std;
#define MOD 99999997
struct match {
    int len, idx;
};
match box1[100000];
match box2[100000];
int idx1[100000];
int idx2[100000];
int dict[100000];
int arr[100000];
int temp[100000];
int ans;

bool comp(const match &a, const match &b) {
    return a.len <= b.len;
}

void merge_sort(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int p1 = l, p2 = mid + 1;
    for (int i = l; i <= r; i++) {
        if (p1 == mid + 1) {
            temp[i] = arr[p2++];
        }
        else if (p2 == r + 1) {
            ans += p2 - mid - 1;
            ans %= MOD;
            temp[i] = arr[p1++];
        }
        else {
            if (arr[p1] <= arr[p2]) {
                ans += p2 - mid - 1;
                ans %= MOD;
                temp[i] = arr[p1++];
            }
            else {
                temp[i] = arr[p2++];
            }
        }
    }
    for (int i = l; i <= r; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        box1[i].idx = i;
        scanf("%d", &box1[i].len);
    }
    for (int i = 0; i < n; i++) {
        box2[i].idx = i;
        scanf("%d", &box2[i].len);
    }
    sort(box1, box1 + n, comp);
    for (int i = 0; i < n; i++) {
        idx1[box1[i].idx] = i;
    }
    sort(box2, box2 + n, comp);
    for (int i = 0; i < n; i++) {
        idx2[box2[i].idx] = i;
    }
    for (int i = 0; i < n; i++) {
        dict[idx2[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = dict[idx1[i]];
    }
    merge_sort(0, n - 1);
    cout << ans << endl;
    return 0;
}
