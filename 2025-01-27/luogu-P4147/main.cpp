#include <iostream>
using namespace std;
char a[1000][1000];
int h[1000][1000];
int l[1000][1000];
int r[1000][1000];

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            h[i][j] = 1;
            r[i][j] = m - 1;
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (a[i - 1][j] == 'F') h[i][j] = h[i - 1][j] + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j - 1] == 'F')
                l[i][j] = l[i][j - 1];
            else
                l[i][j] = j;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = m - 2; j >= 0; j--) {
            if (a[i][j + 1] == 'F')
                r[i][j] = r[i][j + 1];
            else
                r[i][j] = j;
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (a[i - 1][j] == 'F') {
                l[i][j] = l[i - 1][j] > l[i][j] ? l[i - 1][j] : l[i][j];
                r[i][j] = r[i - 1][j] < r[i][j] ? r[i - 1][j] : r[i][j];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'F') {
                int temp = h[i][j] * (r[i][j] - l[i][j] + 1);
                if (temp > ans) ans = temp;
            }
        }
    }
    cout << ans * 3 << endl;
    return 0;
}
