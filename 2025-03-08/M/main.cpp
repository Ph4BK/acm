#include <iostream>
using namespace std;
constexpr int MAX = 100005;
int arr[MAX];
int shorten[MAX];

int main() {
    int n, m;
    cin >> n >> m;
    int total_len = 0;
    for (int i = 0; i < m; ++i) {
        cin >> arr[i];
        total_len += arr[i];
    }
    if (total_len < n) {
        cout << -1 << endl;
        return 0;
    }
    int max_len = 0;
    for (int i = 0; i < m; ++i) {
        max_len = max(max_len, arr[i] + i);
    }
    if (max_len > n) {
        cout << -1 << endl;
        return 0;
    }
    int over = total_len - n;
    for (int i = 0; i < m; ++i) {
        if (!over) break;
        int temp = min(over, arr[i] - 1);
        shorten[i] = temp;
        over -= temp;
    }
    int p = 0;
    for (int i = 0; i < m; ++i) {
        cout << p + 1 << ' ';
        p += arr[i] - shorten[i];
    }
    return 0;
}
