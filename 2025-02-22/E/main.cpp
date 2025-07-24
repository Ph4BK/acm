#include <bits/stdc++.h>
using namespace std;
int skill[2000];
#define MOD 1000000007
#define HALF 500000004
#define ll long long

ll combination(int m, int n) {
    ll ans = 1;
    for (int i = m; i > m - n; i--) {
        ans *= i;
        ans %= MOD;
    }
    ll base = 1;
    for (int i = 1; i <= n; i++) {
        base *= i;
        base %= MOD;
    }
    int exp = MOD - 2;
    ll div = 1;
    while (exp) {
        if (exp & 1) {
            div *= base;
            div %= MOD;
        }
        exp >>= 1;
        base *= base;
        base %= MOD;
    }
    ans *= div;
    ans %= MOD;
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> skill[i];
    }
    sort(skill, skill + n);
    int dif = 0;
    for (int i = 0; i < k; i++) {
        dif += skill[n - i - 1] - skill[i];
    }
    cout << dif << ' ';
    ll ans = 1;
    if (skill[0] == skill[n - 1]) {
        ans = combination(n, k) * combination(n - k, k);
        ans %= MOD;
        ans *= HALF;
        ans %= MOD;
    }
    else {
        if (skill[k - 1] == skill[n - k]) {
            int temp = skill[k - 1];
            int left = k - 1, right = n - k;
            while (skill[--left] == temp);
            left++;
            while (skill[++right] == temp);
            right--;
            ans = combination(right - left + 1, k - left) * combination(right - k + 1, right - n + k + 1);
            ans %= MOD;
        }
        else {
            int temp = skill[k - 1];
            int left = k - 1, right = k - 1;
            while (skill[--left] == temp);
            left++;
            while (skill[++right] == temp);
            right--;
            ans *= combination(right - left + 1, k - left);
            temp = skill[n - k];
            left = right = n - k;
            while (skill[--left] == temp);
            left++;
            while (skill[++right] == temp);
            right--;
            ans *= combination(right - left + 1, right - n + k + 1);
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
