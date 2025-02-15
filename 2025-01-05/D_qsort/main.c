#include <stdio.h>
#include <stdlib.h>
//p/q
struct fraction {
    int p;
    int q;
    int sign;
};

typedef struct fraction fraction;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

//x/y -> p/q
fraction make_fraction(int x, int y) {
    fraction fr;
    if (x > 0 || (x == 0 && y > 0)) fr.sign = 0;
    else fr.sign = 1;
    int minus = 0;
    if ((x > 0 && y < 0) || (x < 0 && y > 0)) minus = 1;
    x = x > 0 ? x : -x;
    y = y > 0 ? y : -y;
    int div = gcd(x, y);
    fr.p = x / div;
    fr.q = y / div;
    if (minus) fr.p = -fr.p;
    return fr;
}

long long cmp(const void* a, const void* b) {
    fraction fr1 = *(fraction*)a;
    fraction fr2 = *(fraction*)b;
    long long temp1 = (long long)fr1.p * (long long)fr2.q;
    long long temp2 = (long long)fr2.p * (long long)fr1.q;
    if (temp1 > temp2) return 1;
    if (temp1 < temp2) return -1;
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        fraction pos[n];
        fraction neg[n];
        int pos_cnt = 0, neg_cnt = 0;
        for (int i = 0; i < n; i++) {
            int x, y, u, v;
            scanf("%d %d %d %d", &x, &y, &u, &v);
            fraction temp = make_fraction(v - y, u - x);
            if (temp.sign == 0) {
                pos[pos_cnt++] = temp;
            }
            else {
                neg[neg_cnt++] = temp;
            }
        }
        qsort(pos, pos_cnt, sizeof(fraction), cmp);
        qsort(neg, neg_cnt, sizeof(fraction), cmp);
        int p1 = 0, p2 = 0;
        long long result = 0;
        int equal1 = 0, equal2 = 0;
        long long tmp1 = 0, tmp2 = 0;
        while (p1 < pos_cnt && p2 < neg_cnt) {
            if (equal1 == 0 && equal2 == 0) {
                if (cmp(&pos[p1], &neg[p2]) == 0) {
                    equal1 = 1;
                    equal2 = 1;
                    tmp1 = 1;
                    tmp2 = 1;
                }
            }
            if (equal1) {
                if (p1 < pos_cnt - 1 && cmp(&pos[p1 + 1], &neg[p2]) == 0) {
                    tmp1++;
                    p1++;
                }
                else {
                    equal1 = 0;
                }
            }
            if (equal2) {
                if (p2 < neg_cnt - 1 && cmp(&pos[p1], &neg[p2 + 1]) == 0) {
                    tmp2++;
                    p2++;
                }
                else {
                    equal2 = 0;
                }
            }
            if (equal1 == 0 && equal2 == 0) {
                result += tmp1 * tmp2;
                tmp1 = 0;
                tmp2 = 0;
                if (cmp(&pos[p1], &neg[p2]) <= 0) {
                    p1++;
                }
                else {
                    p2++;
                }
            }
        }
        printf("%lld\n", result);
    }
    return 0;
}
