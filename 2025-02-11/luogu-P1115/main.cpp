#include <iostream>
#include <climits>
using namespace std;
int arr[200000];
int ans = INT_MIN;

void dc(int l, int r) {
    if (l == r) {
        ans = max(ans, arr[l]);
        return;
    }
    int mid = (l + r) >> 1;
    int l_max = INT_MIN, r_max = INT_MIN;
    int l_sum = 0, r_sum = 0;
    for (int i = mid; i >= l; i--) {
        l_sum += arr[i];
        l_max = max(l_max, l_sum);
    }
    for (int i = mid + 1; i <= r; i++) {
        r_sum += arr[i];
        r_max = max(r_max, r_sum);
    }
    ans = max(ans, l_max + r_max);
    dc(l, mid);
    dc(mid + 1, r);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    dc(0, n - 1);
    cout << ans << endl;
    return 0;
}
