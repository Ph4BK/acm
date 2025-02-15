#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);
    long long time = 0;
    long long x = 0;
    long long l, r;
    long long prev_r = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &l, &r);
        if (x + 1 > r || prev_r < l - 1) {
            printf("-1\n");
            return 0;
        }
        if (x + 1 >= l) {
            x += 1;
            time += 1;
        }
        else {
            time += l - x;
            x = l;
        }
        prev_r = r;
    }
    time += 1;
    printf("%lld\n", time);
    return 0;
}
