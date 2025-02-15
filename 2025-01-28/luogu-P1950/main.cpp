#include <iostream>
using namespace std;
char paper[1000][1000];
int h[1000][1000];
int l[1000][1000];
int r[1000][1000];
int stack[1000];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
            if (paper[i][j] == '.') h[i][j] = 1;
            else h[i][j] = 0;
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (paper[i - 1][j] == '.' && paper[i][j] == '.') h[i][j] = h[i - 1][j] + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        int p = -1;
        for (int j = 0; j < m; j++) {
            while (p >= 0 && h[i][stack[p]] > h[i][j]) p--;
            if (p == -1) l[i][j] = -1;
            else l[i][j] = stack[p];
            stack[++p] = j;
        }
    }
    for (int i = 0; i < n; i++) {
        int p = -1;
        for (int j = m - 1; j >= 0; j--) {
            while (p >= 0 && h[i][stack[p]] >= h[i][j]) p--;
            if (p == -1) r[i][j] = m;
            else r[i][j] = stack[p];
            stack[++p] = j;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += h[i][j] * (j - l[i][j]) * (r[i][j] - j);
        }
    }
    cout << ans << endl;
    return 0;
}
