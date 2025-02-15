#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char garbage[1000001];
    int garbage_cnt = n;
    while(garbage_cnt--) {
        scanf("%s", garbage);
    }
    long long temp = 1;
    for(int i = 2; i <= n; i++) {
        temp = i * (temp + 1) % 1000000007;
    }
    printf("%lld\n", temp);
    return 0;
}
