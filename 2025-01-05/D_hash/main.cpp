#include <bits/stdc++.h>
using namespace std;

//p/q
struct fraction {
    int p, q;
    fraction(int temp1, int temp2) : p(temp1), q(temp2) {}
    bool operator==(const fraction& other) const {
        return p == other.p && q == other.q;
    }
};

class MyHashFunction {
public:
    size_t operator()(const fraction& fr) const {
        return hash<int>{}(fr.p) + 31 * hash<int>{}(fr.q);
    }
};

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

//x/y -> p/q
void fill_fraction(int x, int y, unordered_map<fraction, int, MyHashFunction>& pos, unordered_map<fraction, int, MyHashFunction>& neg) {
    int fill_pos = 0;
    if (x > 0 || (x == 0 && y > 0)) fill_pos = 1;
    int opposite = 0;
    if ((x > 0 && y < 0) || (x < 0 && y > 0)) opposite = 1;
    x = x > 0 ? x : -x;
    y = y > 0 ? y : -y;
    int div = gcd(x, y);
    int p = x / div, q = y / div;
    if (opposite) p = -p;
    fraction temp(p, q);
    if (fill_pos) {
        pos[temp]++;
    }
    else {
        neg[temp]++;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        unordered_map<fraction, int, MyHashFunction> pos;
        unordered_map<fraction, int, MyHashFunction> neg;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x, y, u, v;
            cin >> x >> y >> u >> v;
            fill_fraction(v - y, u - x, pos, neg);
        }
        long long sum = 0;
        for (auto it : pos) {
            sum += static_cast<long long>(it.second) * static_cast<long long>(neg[it.first]);
        }
        printf("%lld\n", sum);
    }
    return 0;
}
