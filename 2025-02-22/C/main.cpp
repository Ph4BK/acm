#include <iostream>
using namespace std;
char board[11][11];
int score[3][12][12];
pair<int, int> adj[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

void add(int x, int y){
    if (board[x][y] == 'M') {
        for (int k = 0; k < 8; k++) {
            score[1][x + adj[k].first][y + adj[k].second]++;
        }
    }
    if (board[x][y] == 'P') {
        for (int k = 0; k < 8; k++) {
            score[0][x + adj[k].first][y + adj[k].second]++;
        }
    }
    if (board[x][y] == 'O') {
        for (int k = 0; k < 8; k++) {
            score[2][x + adj[k].first][y + adj[k].second]++;
        }
    }
}

int prize(int x, int y){
    if (board[x][y] == 'M') return score[0][x][y];
    if (board[x][y] == 'P') return score[1][x][y];
    if (board[x][y] == 'O') return score[2][x][y];
    return 0;
}

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            add(i, j);
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            sum += prize(i, j);
        }
    }
    sum /= 2;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            char c = board[i][j];
            if (c == 'M' || c == 'P' || c =='O'){
                sum++;
            }
        }
    }
    cout << sum << ' ';
    while(true) {
        int max_score = 0;
        int max_i = 0, max_j = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++){
                board[i][j] -= 32;
                int temp = prize(i, j);
                board[i][j] += 32;
                if (temp > max_score){
                    max_score = temp;
                    max_i = i;
                    max_j = j;
                }
            }
        }
        if (max_score == 0) break;
        sum += max_score + 1;
        board[max_i][max_j] -= 32;
        add(max_i, max_j);
    }
    cout << sum << endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
}