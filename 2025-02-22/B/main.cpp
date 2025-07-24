#include <iostream>
#include <climits>
#define ll long long
#define MAX_N 405
#define INF 10000000000000000
using namespace std;
ll path[3][MAX_N][MAX_N];
int n, m;

void floyd0() {
    for (int k = 1; k <= n; k++) {
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                path[0][x][y] = min(path[0][x][y], path[0][x][k] + path[0][k][y]);
            }
        }
    }
}

void floyd1() {
    for (int k = 1; k <= n; k++) {
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                path[1][x][y] = min(path[1][x][y], path[1][x][k] + path[1][k][y]);
            }
        }
    }
}

void floyd2() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            path[2][i][j] = min(path[2][i][j], 2 * path[1][i][j] + path[0][j][i]);
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                path[2][x][y] = min(path[2][x][y], path[2][x][k] + path[2][k][y]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            for (int k = 0; k < 3; k++) {
                path[k][i][j] = INF;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int from, to, carry;
        ll cost;
        cin >> from >> to >> cost >> carry;
        for (int k = 0; k <= carry; k++) {
            path[k][from][to] = min(path[k][from][to], cost);
        }
    }
    floyd0();
    floyd1();
    floyd2();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (path[2][i][j] == INF) cout << -1 << ' ';
            else cout << path[2][i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}