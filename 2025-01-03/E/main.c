#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    int ans[t];
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        char arr[n + 1];
        scanf("%s", arr);
        if (arr[0] == '0' && arr[n - 1] == '0') ans[i] = 1;
        else ans[i] = 0;
    }
    for (int i = 0; i < t; i++) {
        if (ans[i]) printf("Bob\n");
        else printf("Alice\n");
    }
    return 0;
}
