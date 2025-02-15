#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int max = 0;
    char president[21];
    while(n--) {
        int vote;
        char candidate[21];
        scanf("%s %d", candidate, &vote);
        if (vote > max) {
            max = vote;
            strcpy(president, candidate);
        }
    }
    printf("%s\n", president);
    return 0;
}
