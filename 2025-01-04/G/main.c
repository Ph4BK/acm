#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int days, questions;
        scanf("%d %d", &days, &questions);
        int pos = 0;
        int neg = 0;
        int zero = 0;
        for (int i = 0; i < days; i++) {
            int temp;
            scanf("%d", &temp);
            if (temp > 0) pos++;
            if (temp < 0) neg++;
            if (temp == 0) zero++;
        }
        int x;
        scanf("%d", &x);
        if (zero) {
            printf("Yes\n");
            continue;
        }
        if (neg == 0) {
            printf("No\n");
            continue;
        }
        if (neg == 3 || neg >= 5) {
            printf("Yes\n");
            continue;
        }
        if (neg == 4) {
            if (pos) printf("Yes\n");
            else printf("No\n");
            continue;
        }
        if (pos >= neg) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
