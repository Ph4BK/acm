#include <iostream>
#include <climits>
using namespace std;
int matrix[121][121];
int prefix[121][121];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            prefix[i][j] = prefix[i - 1][j] + matrix[i][j];
        }
    }
    int ans = INT_MIN;
    for (int a = 1; a <= n; a++) {
        for(int b = 0; b < a; b++) {
            int sum = 0;
            for (int j = 1; j <= n; j++) {
                sum += prefix[a][j] - prefix[b][j];
                if (sum > ans) ans = sum;
                if (sum < 0) sum = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
