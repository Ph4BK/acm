#include <stdio.h>
#include <string.h>

int main() {
    char fill[21] = "Haruhikage";
    int n;
    scanf("%d", &n);
    char list[2 * n][21];
    int p = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", list[p]);
        if (strcmp(list[p], "Tomori") == 0) {
            strcpy(list[++p], fill);
        }
        p++;
    }
    for (int i = 0; i < p; i++) {
        printf("%s\n", list[i]);
    }
    return 0;
}