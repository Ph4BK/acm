#include <iostream>
using namespace std;
int arr[100001];
int prefix[100001];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << endl;
    }
    return 0;
}
