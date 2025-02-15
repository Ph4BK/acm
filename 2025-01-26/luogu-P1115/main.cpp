#include <iostream>
using namespace std;
int arr[200000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int f = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        f = f > 0 ? f + arr[i] : arr[i];
        max = f > max ? f : max;
    }
    cout << max << endl;
    return 0;
}
