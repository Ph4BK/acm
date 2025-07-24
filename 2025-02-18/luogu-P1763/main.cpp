#include <iostream>
#include <cmath>
#include <valarray>
#define ll long long
using namespace std;
ll mem[11], ans[11];
bool flag = false;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

struct fraction {
    ll numerator, denominator;

    static fraction new_fraction(ll a, ll b) {
        ll g = gcd(a, b);
        a /= g;
        b /= g;
        if (b < 0) {
            a = -a;
            b = -b;
        }
        return fraction{a, b};
    }

    fraction operator+(const fraction& other) const {
        ll a = numerator * other.denominator + other.numerator * denominator;
        ll b = denominator * other.denominator;
        return new_fraction(a, b);
    }

    fraction operator-(const fraction& other) const {
        ll a = numerator * other.denominator - other.numerator * denominator;
        ll b = denominator * other.denominator;
        return new_fraction(a, b);
    }
};

void dfs(int depth, int layer, fraction target) {
    if (layer > depth) return;
    if (target.numerator == 1 && target.denominator > mem[layer - 1]) {
        mem[layer] = target.denominator;
        if (!flag || mem[layer] < ans[layer]) {
            for (int i = 1; i <= depth; i++) {
                ans[i] = mem[i];
            }
        }
        flag = true;
        return;
    }
    if (layer == depth - 1) {
        bool local_flag = false;
        ll a = target.numerator;
        ll b = target.denominator;
        ll k_min = 4 * b / (a * a) + 1;
        for (ll k = k_min;; k++) {
            ll delta = a * a * k * k - 4 * b * k;
            ll sqrt_delta = sqrt(delta);
            for (int i = -1; i <= 1; i++) {
                if ((sqrt_delta + i) * (sqrt_delta + i) == delta) {
                    sqrt_delta += i;
                    local_flag = true;
                    break;
                }
            }
            ll x = (a * k - sqrt_delta) / 2;
            ll y = (a * k + sqrt_delta) / 2;
            if (y > 1e7 || (flag && y > ans[depth])) break;
            if (local_flag) {
                if ((a * k - sqrt_delta) % 2) continue;
                flag = true;
                mem[depth - 1] = x;
                mem[depth] = y;
                for (int i = 1; i <= depth; i++)
                    ans[i] = mem[i];
                break;
            }
        }
        return;
    }
    ll left = max(target.denominator / target.numerator + 1, mem[layer - 1] + 1);
    ll right = (depth - layer + 1) * target.denominator / target.numerator;
    if (flag && right >= ans[depth])
        right = ans[depth] - 1;
    for (ll i = left; i <= right; i++) {
        mem[layer] = i;
        dfs(depth, layer + 1, target - fraction{1, i});
    }
}

int main() {
    ll a, b;
    cin >> a >> b;
    fraction target = fraction::new_fraction(a, b);
    for (int i = 1; i <= 10; i++) {
        dfs(i, 1, target);
        if (flag) {
            for (int j = 1; j <= i; j++) {
                cout << ans[j] << " ";
            }
            break;
        }
    }
    return 0;
}
