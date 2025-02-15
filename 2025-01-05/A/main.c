#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n % 2) printf("%d\n", (n + 2) * (n + 2) / 2);
    else printf("%d\n", (n / 2 + 1) * (n / 2 + 1));
    return 0;
}
