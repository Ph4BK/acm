#include <iostream>
using namespace std;
int mtr[1002][1002];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        mtr[x1][y1]++;
        mtr[x2 + 1][y2 + 1]++;
        mtr[x1][y2 + 1]--;
        mtr[x2 + 1][y1]--;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mtr[i][j] += mtr[i - 1][j] + mtr[i][j - 1] - mtr[i - 1][j - 1];
            cout << mtr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
