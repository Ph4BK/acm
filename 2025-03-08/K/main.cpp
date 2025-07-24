#include <iostream>
#include <cstring>
using namespace std;
constexpr int MAX = 200005;
int arr[MAX];
int seg1[MAX];
int seg2[MAX];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int maxNum = 0;
        int maxIdx = -1;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
            if (arr[i] > maxNum) {
                maxNum = arr[i];
                maxIdx = i;
            }
        }
        if (maxNum >= n || 2 * maxNum < n) {
            cout << 0 << endl;
            continue;
        }
        bool maxLeft = false, maxRight = false;
        int sol = 0;
        if (maxIdx <= maxNum) {
            maxLeft = true;
            for (int i = 1; i <= maxNum; ++i) {
                if (seg1[arr[i]]) {
                    maxLeft = false;
                    break;
                }
                seg1[arr[i]] = 1;
            }
            if (maxLeft) {
                for (int i = 1; i <= maxNum; ++i) {
                    if (!seg1[i]) {
                        maxLeft = false;
                        break;
                    }
                }
            }
            memset(seg1, 0, sizeof(seg1));
            if (maxLeft) {
                for (int i = maxNum + 1; i <= n; ++i) {
                    if (seg2[arr[i]]) {
                        maxLeft = false;
                        break;
                    }
                    seg2[arr[i]] = 1;
                }
            }
            if (maxLeft) {
                for (int i = 1; i <= n - maxNum; ++i) {
                    if (!seg2[i]) {
                        maxLeft = false;
                        break;
                    }
                }
            }
            memset(seg2, 0, sizeof(seg2));
            if (maxLeft) ++sol;
        }
        if (n - maxIdx + 1 <= maxNum) {
            maxRight = true;
            for (int i = n - maxNum + 1; i <= n; ++i) {
                if (seg1[arr[i]]) {
                    maxRight = false;
                    break;
                }
                seg1[arr[i]] = 1;
            }
            if (maxRight) {
                for (int i = 1; i <= maxNum; ++i) {
                    if (!seg1[i]) {
                        maxRight = false;
                        break;
                    }
                }
            }
            memset(seg1, 0, sizeof(seg1));
            if (maxRight) {
                for (int i = 1; i <= n - maxNum; ++i) {
                    if (seg2[arr[i]]) {
                        maxRight = false;
                        break;
                    }
                    seg2[arr[i]] = 1;
                }
            }
            if (maxRight) {
                for (int i = 1; i <= n - maxNum; ++i) {
                    if (!seg2[i]) {
                        maxRight = false;
                        break;
                    }
                }
            }
            memset(seg2, 0, sizeof(seg2));
            if (maxRight) ++sol;
        }
        cout << sol << '\n';
        if (maxLeft) cout << maxNum << ' ' << n - maxNum << '\n';
        if (maxRight) cout << n - maxNum << ' ' << maxNum << '\n';
    }
    return 0;
}
