#include <iostream>
using namespace std;
int dif[5000002];

int main() {
    int n, p;
    cin >> n >> p;
    int cur, last = 0;
    for (int i = 1; i <= n; i++) {
        cin >> cur;
        dif[i] = cur - last;
        last = cur;
    }
    for (int i = 0; i < p; i++) {
        int from, to, add;
        cin >> from >> to >> add;
        dif[from] += add;
        dif[to + 1] -= add;
    }
    int min = dif[1], temp = dif[1];
    for (int i = 2; i <= n; i++) {
        temp += dif[i];
        if (temp < min) min = temp;
    }
    cout << min << endl;
    return 0;
}
