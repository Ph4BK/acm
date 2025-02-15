#include <bits/stdc++.h>
using namespace std;
int x_from[1000];
int y_from[1000];
int x_to[1000];
int y_to[1000];
int ori_x[2000];
int ori_y[2000];
int pro_x[2000];
int pro_y[2000];
map<int, int> map_x;//1 based
map<int, int> map_y;//1 based
int mtr[2002][2002];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x_from[i] >> y_from[i] >> x_to[i] >> y_to[i];
        ori_x[2 * i] = x_from[i];
        ori_x[2 * i + 1] = x_to[i];
        ori_y[2 * i] = y_from[i];
        ori_y[2 * i + 1] = y_to[i];
    }
    sort(ori_x, ori_x + 2 * n);
    int prev_x = pro_x[0] = ori_x[0];
    int cnt_x = map_x[ori_x[0]] = 1;
    for (int i = 1; i < 2 * n; i++) {
        if (ori_x[i] != prev_x) {
            prev_x = pro_x[cnt_x] = ori_x[i];
            map_x[ori_x[i]] = ++cnt_x;
        }
    }
    sort(ori_y, ori_y + 2 * n);
    int prev_y = pro_y[0] = ori_y[0];
    int cnt_y = map_y[ori_y[0]] = 1;
    for (int i = 1; i < 2 * n; i++) {
        if (ori_y[i] != prev_y) {
            prev_y = pro_y[cnt_y] = ori_y[i];
            map_y[ori_y[i]] = ++cnt_y;
        }
    }
    for (int i = 0; i < n; i++) {
        mtr[map_x[x_from[i]]][map_y[y_from[i]]]++;
        mtr[map_x[x_to[i]]][map_y[y_to[i]]]++;
        mtr[map_x[x_from[i]]][map_y[y_to[i]]]--;
        mtr[map_x[x_to[i]]][map_y[y_from[i]]]--;
    }
    long long sum = 0;
    for (int i = 1; i <= cnt_x; i++) {
        for (int j = 1; j <= cnt_y; j++) {
            mtr[i][j] += mtr[i - 1][j] + mtr[i][j - 1] - mtr[i - 1][j - 1];
            if (mtr[i][j]) {
                sum += (long long)(pro_x[i] - pro_x[i - 1]) * (pro_y[j] - pro_y[j - 1]);
            }
        }
    }
    cout << sum << endl;
    return 0;
}
