#include <iostream>
using namespace std;
#define ll long long
ll rating[200000];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> rating[i];
    }
    int rank = 2;
    int left = n;
    ll sum = 0;
    for (int i = 1; i < n; i++) {
        if (sum - (left - rank) * (rank - 1) * rating[i] < k) {
            left--;
            cout << i + 1 << endl;
        }
        else {
            sum += rating[i] * (rank - 1);
            rank++;
        }
    }
    return 0;
}
