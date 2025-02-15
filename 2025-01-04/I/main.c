#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int tunnel[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &tunnel[i]);
            tunnel[i] -= 1;
        }
        int marked[n];
        for (int i = 0; i < n; i++) marked[i] = 0;
        int count = 0;
        int space = 0;
        for (int start = 0; start < n; start++) {
            int add = 0;
            int cur = start;
            while (marked[cur] == 0) {
                add = 1;
                count++;
                marked[cur] = 1;
                cur = tunnel[cur];
            }
            if (add) space++;
            if (count == n) break;
        }
        printf("%d\n", space - 1);
    }
    return 0;
}
