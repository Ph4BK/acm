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
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + matrix[i][j];
        }
    }
    int ans = INT_MIN;
    for (int x2 = 1; x2 <= n; x2++) {
        for (int x1 = 0; x1 < x2; x1++) {
            for (int y2 = 1; y2 <= n; y2++) {
                for (int y1 = 0; y1 < y2; y1++) {
                    int temp = prefix[x2][y2] - prefix[x2][y1] - prefix[x1][y2] + prefix[x1][y1];
                    ans = max(ans, temp);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
