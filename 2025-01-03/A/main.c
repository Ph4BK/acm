#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int ans[n];
    for (int i = 0; i < n; i++) {
        int S, Y, U;
        scanf("%d%d%d", &S, &Y, &U);
        int min = S / 2;
        if (min > Y) min = Y;
        if (min > U) min = U;
        ans[i] = min;
    }
    for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
    return 0;
}
