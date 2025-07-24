#include <iostream>
#include <cstring>
using namespace std;
int mask[1 << 18];

void dfs(int n) {
    if (n == 0) return;
    int last = n & 0b11;
    int lastPos = 0;
    for (int pos = 1; pos <= 9; pos++) {
        int deepen = -1;
        if (n >= 1 << (2 * pos)) {
            deepen = 0;
            int cur = (n & (0b11 << (2 * pos))) >> (2 * pos);
            if (cur != last) {
                deepen = 1;
                last = cur;
            }
        }
        if (deepen) {
            int use = pos - lastPos;
            int temp = ((n & ((1 << 18) - (1 << 2 * pos))) >> (2 * use)) + (n & ((1 << (2 * lastPos)) - 1));
            int now = mask[n];
            if (use == 3) now++;
            if (now > mask[temp]) {
                mask[temp] = now;
                dfs(temp);
            }
            lastPos = pos;
        }
        if (deepen == -1) break;
    }
}

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        memset(mask, 255, sizeof(mask));
        int temp = 0;
        for (int i = 0; i < 9; i++) {
            temp <<= 2;
            char c = getchar();
            if (c == 'g') temp += 1;
            if (c == 'a') temp += 2;
            if (c == 'o') temp += 3;
        }
        getchar();
        mask[temp] = 0;
        dfs(temp);
        cout << mask[0] << endl;
    }
    return 0;
}
