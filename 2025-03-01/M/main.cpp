#include <iostream>
using namespace std;
#define MAX 1005
char fab[MAX][MAX];
int cnt_right[MAX][MAX];
int cnt_down[MAX][MAX];
int up[MAX][MAX];
int down[MAX][MAX];

int main() {
    int row, col;
    cin >> row >> col;
    for (int i = 0; i < row; i++) {
        cin >> fab[i];
    }
    for (int i = row - 1; i >= 0; i--) {
        for (int j = col - 1; j >= 0; j--) {
            if (i == row - 1) cnt_down[i][j] = 1;
            else cnt_down[i][j] = 1 + (fab[i][j] == fab[i + 1][j] ? cnt_down[i + 1][j] : 0);
            if (j == col - 1) cnt_right[i][j] = 1;
            else cnt_right[i][j] = 1 + (fab[i][j] == fab[i][j + 1] ? cnt_right[i][j + 1] : 0);
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            up[i][j] = cnt_right[i][j];
            if (i > 0 && fab[i][j] == fab[i - 1][j]) {
                up[i][j] = min(up[i][j], up[i - 1][j]);
            }
        }
    }
    for (int i = row - 1; i >= 0; i--) {
        for (int j = 0; j < col; j++) {
            down[i][j] = cnt_right[i][j];
            if (i < row - 1 && fab[i][j] == fab[i + 1][j]) {
                down[i][j] = min(down[i][j], down[i + 1][j]);
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int h = cnt_down[i][j];
            if (i + 2 * h >= row || cnt_down[i + h][j] != h || cnt_down[i + 2 * h][j] < h) continue;
            ans += min(up[i + 3 * h - 1][j], min(down[i][j], down[i + h][j]));
        }
    }
    cout << ans << endl;
    return 0;
}
