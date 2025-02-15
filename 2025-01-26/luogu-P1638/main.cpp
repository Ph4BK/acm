#include <iostream>
using namespace std;
int sequence[1000005];
int count[2005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> sequence[i];
    }
    int l = 1, r = 0;
    int ansl = 0, ansr = 0;
    int dif = 0;
    int len = 1919810;
    while (r <= n) {
        if (dif < m) {
            r++;
            if (count[sequence[r]] == 0) dif++;
            count[sequence[r]]++;
        }
        else {
            if (r - l + 1 < len) {
                len = r - l + 1;
                ansl = l;
                ansr = r;
            }
            count[sequence[l]]--;
            if (count[sequence[l]] == 0) dif--;
            l++;
        }
    }
    cout << ansl << " " << ansr << endl;
    return 0;
}
