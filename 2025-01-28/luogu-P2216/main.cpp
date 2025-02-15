#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000
int matrix[MAXN][MAXN];
int row_max[MAXN][MAXN];
int my_max[MAXN][MAXN];
int row_min[MAXN][MAXN];
int my_min[MAXN][MAXN];
deque<int> q;

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < a; i++) {
        q.clear();
        for (int j = 0; j < b; j++) {
            while (!q.empty() && matrix[i][q.back()] <= matrix[i][j]) q.pop_back();
            q.push_back(j);
            if (j < n - 1) continue;
            while (!q.empty() && q.front() <= j - n) q.pop_front();
            row_max[i][j - n + 1] = matrix[i][q.front()];
        }
    }
    for (int j = 0; j <= b - n; j++) {
        q.clear();
        for (int i = 0; i < a; i++) {
            while (!q.empty() && row_max[q.back()][j] <= row_max[i][j]) q.pop_back();
            q.push_back(i);
            if (i < n - 1) continue;
            while (!q.empty() && q.front() <= i - n) q.pop_front();
            my_max[i - n + 1][j] = row_max[q.front()][j];
        }
    }
    for (int i = 0; i < a; i++) {
        q.clear();
        for (int j = 0; j < b; j++) {
            while (!q.empty() && matrix[i][q.back()] >= matrix[i][j]) q.pop_back();
            q.push_back(j);
            if (j < n - 1) continue;
            while (!q.empty() && q.front() <= j - n) q.pop_front();
            row_min[i][j - n + 1] = matrix[i][q.front()];
        }
    }
    for (int j = 0; j <= b - n; j++) {
        q.clear();
        for (int i = 0; i < a; i++) {
            while (!q.empty() && row_min[q.back()][j] >= row_min[i][j]) q.pop_back();
            q.push_back(i);
            if (i < n - 1) continue;
            while (!q.empty() && q.front() <= i - n) q.pop_front();
            my_min[i - n + 1][j] = row_min[q.front()][j];
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i <= a - n; i++) {
        for (int j = 0; j <= b - n; j++) {
            ans = min(ans, my_max[i][j] - my_min[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
