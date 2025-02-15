#include <stdio.h>

#define MOD 1000000007

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int days, items;
        scanf("%d %d", &days, &items);
        int schedule[2][days];
        for (int i = 0; i < days; i++) schedule[0][i] = 0;
        for (int i = 0; i < days; i++) schedule[1][i] = 0;
        for (int i = 0; i < items; i++) {
            int option, start;
            scanf("%d %d", &option, &start);
            schedule[option - 1][start - 1]++;
        }
        int cur = 0;
        int velocity = 0;
        int acceleration = 0;
        for (int i = 0; i < days; i++) {
            velocity = (velocity + schedule[0][i] + schedule[1][i] + 2 * acceleration) % MOD;
            acceleration += schedule[1][i];
            cur = (cur + velocity) % MOD;
            printf("%d ", cur);
        }
        printf("\n");
    }
    return 0;
}