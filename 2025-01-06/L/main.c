#include <stdio.h>
//1 3 76进制
long long exp[10] = {1, 100, 10000, 1000000, 100000000, 10000000000, 1000000000000, 100000000000000, 10000000000000000, 1000000000000000000};

int is_leap(long long year) {
    int ans = 0;
    for (int i = 0; i < 9; i++) {
        if (year % (4 * exp[i])) break;
        ans = 1;
        if (year % exp[i + 1]) break;
        ans = 0;
    }
    return ans;
}

long long count_common(long long year) {
    long long count = 0;
    for (int i = 0; i < 10 && year >= exp[i]; i++) {
        count = count + year / exp[i] - year / (4 * exp[i]);
    }
    return count;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        long long k;
        scanf("%lld",&k);
        k += 1533;
        long long high = (k / 3 + 1) * 4;
        long long low = k / 19 * 25;
        while (low < high) {
            long long mid = (low + high) / 2;
            if (count_common(mid) < k) low = mid + 1;
            else high = mid;
        }
        if (is_leap(high)) high--;
        printf("%lld\n", high);
    }
}
