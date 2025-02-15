#include <iostream>
using namespace std;
int arr[500000];
int temp[500000];
long long ans;

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
            temp[i] = arr[p1++];
        }
        else {
            if (arr[p1] <= arr[p2]) {
                ans += p2 - mid - 1;
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
        scanf("%d", &arr[i]);
    }
    merge_sort(0, n - 1);
    cout << ans << endl;
    return 0;
}