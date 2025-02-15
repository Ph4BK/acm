#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n % 4 == 1) printf("1\n");
    if (n % 4 == 3) printf("0\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", (i + j) % n + 1);
        printf("\n");
    }
    return 0;
}
