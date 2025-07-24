#include <iostream>
#include <cstring>
using namespace std;
int mark[300];

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(mark, 0, sizeof(mark));
        int n, x;
        cin >> n >> x;
        for (int i = 0; i < n; ++i) {
            int rank;
            cin >> rank;
            mark[rank] = 1;
        }
        for (int rank = 1; rank < 300; ++rank) {
            if (!x) break;
            if (!mark[rank]) {
                mark[rank] = 1;
                --x;
            }
        }
        for (int rank = 1; rank < 300; ++rank) {
            if (mark[rank] == 0) {
                cout << rank - 1 << endl;
                break;
            }
        }
    }
    return 0;
}
