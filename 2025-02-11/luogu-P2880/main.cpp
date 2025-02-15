#include <iostream>
int arr[50000];
int max[50000][16];
int min[50000][16];

int main() {
    int n, q;
    int l, r;
    std::cin >> n >> q;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        max[i][0] = min[i][0] = arr[i];
    }
    for (int exp = 1; exp < 16; exp++) {
        for (int i = 0; i + (1 << exp) <= n; i++) {
            min[i][exp] = std::min(min[i][exp - 1], min[i + (1 << exp - 1)][exp - 1]);
            max[i][exp] = std::max(max[i][exp - 1], max[i + (1 << exp - 1)][exp - 1]);
        }
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        l--;
        r--;
        int len = r - l + 1;
        int exp = -1;
        while (len) {
            len >>= 1;
            exp++;
        }
        int range_max = std::max(max[l][exp], max[r + 1 - (1 << exp)][exp]);
        int range_min = std::min(min[l][exp], min[r + 1 - (1 << exp)][exp]);
        printf("%d\n", range_max - range_min);
    }
    return 0;
}
