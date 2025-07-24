#include <iostream>
#include <vector>
using namespace std;
int grid[1005][1005];
int mark_pos[1000005];
int mark_neg[1000005];
vector<pair<int, int>> adj{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    int r, c, n, p;
    cin >> r >> c >> n >> p;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (grid[i][j] == 0 || grid[i][j] > p) continue;
            for (const auto& e : adj) {
                int temp = grid[i + e.first][j + e.second];
                if (temp == 0) continue;
                if (temp + p - grid[i][j] > n) continue;
                int dif = grid[i][j] - temp;
                if (dif > 0) mark_pos[dif] = 1;
                else mark_neg[-dif] = 1;
            }
        }
    }
    int cnt = 0;
    for (const auto& i : mark_pos) {
        if (i) cnt++;
    }
    for (const auto& i : mark_neg) {
        if (i) cnt++;
    }
    cout << cnt << '/' << n - 1 << endl;
    return 0;
}
