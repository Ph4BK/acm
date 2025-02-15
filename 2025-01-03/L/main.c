#include <stdio.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n], b[m];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int flag = 1;
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        for (int j = 0; j < n; j++) {
            if (a[j] % b[i]) {
                flag = 0;
                break;
            }
        }
        if (flag == 0) {
            break;
        }
    }
    if (flag == 0) {
        printf("No\n");
        return 0;
    }
    if (n == 1) {
        long long temp = b[0];
        for (int i = 1; i < m; i++) {
            temp = temp * b[i] / gcd(temp, b[i]);
            if (temp > a[0]) break;
        }
        if (temp == a[0]) {
            printf("Yes\n");
            for (int i = 0; i < m; i++) {
                printf("%d ", b[i]);
            }
            printf("\n");
        }
        else {
            printf("No\n");
        }
        return 0;
    }
    if (m == 1) {
        int temp = a[0];
        for (int i = 1; i < n; i++) {
            temp = gcd(temp, a[i]);
            if (temp < b[0]) break;
        }
        if (temp == b[0]) {
            printf("Yes\n");
            for (int i = 0; i < n; i++) {
                printf("%d", a[i]);
                printf("\n");
            }
        }
        else {
            printf("No\n");
        }
        return 0;
    }
    printf("Yes\n");
    for (int i = 0; i <= n - 2; i++) {
        printf("%d ", a[i]);
        for (int j = 1; j < m; j++) {
            printf("%d ", b[j]);
        }
        printf("\n");
    }
    printf("%d %d ", b[0], a[n - 1]);
    for (int j = 2; j < m; j++) {
        printf("%d ", b[j]);
    }
    printf("\n");
    return 0;
}
