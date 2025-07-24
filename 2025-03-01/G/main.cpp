#include <iostream>
using namespace std;
char str[200001];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int len;
        cin >> len;
        cin >> str;
        int ans = 0, add = 0;
        for (int i = 0; i < len - 3; i++) {
            if (str[i] == 'C' && str[i + 1] == 'C' && str[i + 2] == 'P' && str[i + 3] == 'C') ans++;
        }
        if (len >= 3) {
            if (str[0] == 'C' && str[1] == 'P' && str[2] == 'C') add = 1;
            if (str[len - 3] == 'C' && str[len - 2] == 'C' && str[len - 1] == 'P') add = 1;
            if (str[len - 3] == 'C' && str[len - 2] == 'C' && str[len - 1] == 'C') add = 1;
        }
        if (len >= 4) {
            if (str[len - 4] == 'C' && str[len - 3] == 'C' && str[len - 2] == 'C') add = 1;
        }
        if (!add) {
            for (int i = 0; i < len - 3; i++) {
                if (str[i] != 'C' && str[i + 1] == 'C' && str[i + 2] == 'P' && str[i + 3] == 'C') {
                    add = 1;
                    break;
                }
            }
        }
        if (!add) {
            for (int i = 0; i < len - 3; i++) {
                if (str[i] == 'C' && str[i + 1] == 'C' && str[i + 2] == 'P' && str[i + 3] != 'C') {
                    add = 1;
                    break;
                }
            }
        }
        if (!add) {
            for (int i = 0; i < len - 4; i++) {
                if (str[i] == 'C' && str[i + 1] == 'C' && str[i + 2] == 'C' && (str[i + 3] != 'P' || str[i + 4] != 'C')) {
                    add = 1;
                    break;
                }
            }
        }
        ans += add;
        cout << ans << endl;
    }
    return 0;
}
