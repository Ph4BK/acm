#include <bits/stdc++.h>
using namespace std;
pair <int, int> burn[] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
pair <int, int> walk[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct node {
    int hit, visit;
};

node grid[303][303];

int main() {
    int m;
    cin >> m;
    for (int i = 0; i < 303; i++) {
        for(int j = 0; j < 303; j++) {
            grid[i][j].hit = 114514;
            grid[i][j].visit = -1;
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        for (int k = 0; k < 5; k++) {
            int temp_x = x + burn[k].first;
            int temp_y = y + burn[k].second;
            if (temp_x >= 0 && temp_y >= 0) {
                if (grid[temp_x][temp_y].hit > t) {
                    grid[temp_x][temp_y].hit = t;
                }
            }
        }
    }
    queue<pair<int, int>> q;
    grid[0][0].visit = 0;
    q.emplace(0, 0);
    while (!q.empty()) {
        pair<int, int> temp = q.front();
        q.pop();
        if (grid[temp.first][temp.second].hit == 114514) {
            cout << grid[temp.first][temp.second].visit << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            pair<int, int> next{temp.first + walk[i].first, temp.second + walk[i].second};
            if (next.first >= 0 && next.second >= 0) {
                if (grid[next.first][next.second].hit > grid[temp.first][temp.second].visit + 1 && grid[next.first][next.second].visit == -1) {
                    grid[next.first][next.second].visit = grid[temp.first][temp.second].visit + 1;
                    q.push(next);
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
