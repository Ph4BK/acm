#include <bits/stdc++.h>
using namespace std;

struct coord {
    int x, y;
};

int board[410][410];
coord walk[] = {{1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}};

int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            board[i][j] = -1;
        }
    }
    board[x][y] = 0;
    queue<coord> q;
    q.push({x, y});
    while(!q.empty()) {
        coord cur{};
        for (auto & it : walk) {
            cur.x = q.front().x + it.x;
            cur.y = q.front().y + it.y;
            if (cur.x >= 1 && cur.x <= n && cur.y >= 1 && cur.y <= m) {
                if (board[cur.x][cur.y] == -1) {
                    board[cur.x][cur.y] = board[q.front().x][q.front().y] + 1;
                    q.push(cur);
                }
            }
        }
        q.pop();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", board[i][j]);
        }
        cout << endl;
    }
    return 0;
}
