#include <bits/stdc++.h>
using namespace std;

struct element {
    int data;
    char first;
    char second;
};

bool cmp(const element &a, const element &b) {
    return a.data < b.data;
}

int main() {
    int repeat[26] = {};
    int pair = 0;
    int sum = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int beauty[n];
    for (int i = 0; i < n; i++) {
        cin >> beauty[i];
    }
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == s[n - i - 1]) {
            pair++;
            repeat[s[i] - 'a']++;
        }
    }
    int max_idx = max_element(repeat, repeat + 26) - repeat;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            sum += beauty[i] + beauty[n - i - 1];
        }
        else {
            sum += max(beauty[i], beauty[n - i - 1]);
        }
    }
    if (2 * repeat[max_idx] <= pair) {
        cout << sum << endl;
        return 0;
    }
    int size = n / 2 - pair;
    element list[size];
    int p = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            list[p].data = min(beauty[i], beauty[n - i - 1]);
            list[p].first = s[i];
            list[p].second = s[n - i - 1];
            p++;
        }
    }
    sort(list, list + size, cmp);
    int remain = 2 * repeat[max_idx] - pair;
    char x = max_idx + 'a';
    for (int i = 0; i < size; i++) {
        if (remain == 0) break;
        if (list[i].first != x && list[i].second != x) {
            sum -= list[i].data;
            remain--;
        }
    }
    cout << sum << endl;
    return 0;
}
