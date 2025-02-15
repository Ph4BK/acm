#include <algorithm>
#include <iostream>
using namespace std;
int arr[200000];

int main() {
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort (arr, arr + n);
    long long ans = 0;
    int p1 = 0, p2 = 0;
    for (int i = 0; i < n; i++) {
        while (arr[p1] < arr[i] - c && p1 < n) p1++;
        while (arr[p2] <= arr[i] - c && p2 < n) p2++;
        ans += p2 - p1;
    }
    cout << ans << endl;
    return 0;
}
