#include <bits/stdc++.h>
#define MOD 1000000007
#define BASE 31
long long obverse_left[500005];
long long obverse_right[500005];
long long inverse_left[500005];
long long inverse_right[500005];
long long exponent[500005];
using namespace std;

int main() {
    exponent[0] = 1;
    for (int i = 1; i < 500005; i++) {
        exponent[i] = exponent[i - 1] * BASE % MOD;
    }
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) break;
            left++;
            right--;
        }
        if (left >= right) {
            cout << "Yes" <<endl;
            continue;
        }
        string s2 = s.substr(left, right - left + 1);
        int len2 = s2.length();
        obverse_left[0] = s2[0] - 'a';
        for (int i = 1; i < len2; i++) {
            obverse_left[i] = (obverse_left[i - 1] * BASE + (s2[i] - 'a')) % MOD;
        }
        obverse_right[0] = s2[len2 - 1] - 'a';
        for (int i = 1; i < len2; i++) {
            obverse_right[i] = (obverse_right[i - 1] + (s2[len2 - i - 1] - 'a') * exponent[i]) % MOD;
        }
        inverse_left[0] = s2[0] - 'a';
        for (int i = 1; i < len2; i++) {
            inverse_left[i] = (inverse_left[i - 1] + (s2[i] - 'a') * exponent[i]) % MOD;
        }
        inverse_right[0] = s2[len2 - 1] - 'a';
        for (int i = 1; i < len2; i++) {
            inverse_right[i] = (inverse_right[i - 1] * BASE + (s2[len2 - i - 1] - 'a')) % MOD;
        }
        int flag = 0;
        for (int i = 1; i <= len2 - 2; i++) {
            long long hash1 = (inverse_left[i] * exponent[len2 - i - 1] + obverse_right[len2 - i - 2]) % MOD;
            long long hash2 = (inverse_right[len2 - i - 2] * exponent[i + 1] + obverse_left[i]) % MOD;
            if (hash1 == hash2) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            cout << "Yes" <<endl;
            continue;
        }
        for (int i = len2 - 2; i >= 1; i--) {
            long long hash1 = (obverse_left[i - 1] * exponent[len2 - i] + inverse_right[len2 - i - 1]) % MOD;
            long long hash2 = (obverse_right[len2 - i - 1] * exponent[i] + inverse_left[i - 1]) % MOD;
            if (hash1 == hash2) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            cout << "Yes" <<endl;
            continue;
        }
        cout << "No" <<endl;
    }
    return 0;
}
