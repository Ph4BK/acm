#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    int answer[t];
    for (int i = 0; i < t; i++) answer[i] = 1;
    for (int k = 0; k < t; k++) {
        int n;
        scanf("%d", &n);
        getchar();
        int mtr[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mtr[i][j] = getchar() - '0';
            }
            getchar();
        }
        getchar();
        int mtr2[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int temp = getchar() - '0';
                mtr2[i][j] = temp;
                mtr[i][j] ^= temp;
            }
            getchar();
        }
        if (n >= 2) {
            for (int row = 0; row < n - 1; row++) {
                int stat = mtr[row][0] ^ mtr[row + 1][0];
                for (int j = 1; j < n; j++) {
                    if (mtr[row][j] ^ mtr[row + 1][j] != stat) {
                        answer[k] = 0;
                    }
                }
            }
            for (int col = 0; col < n - 1; col++) {
                int stat = mtr[0][col] ^ mtr[0][col + 1];
                for (int i = 1; i < n; i++) {
                    if (mtr[i][col] ^ mtr[i][col + 1] != stat) {
                        answer[k] = 0;
                    }
                }
            }
        }
    }
    for (int i = 0; i < t; i++) {
        if (answer[i]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
