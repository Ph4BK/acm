#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
int st[20][1 << 19];
ll add[1 << 18];
ll l[1 << 18];
ll r[1 << 18];
vector<ll> dif_pos;

int find(const ll target, const vector<ll>& dif_pos) {
    int left = 0, right = dif_pos.size() - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (target <= dif_pos[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    if (dif_pos[left] == target) return left;
    cerr << "Target not found" << endl;
    return -1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char tmp_dir;
        ll tmp_len, tmp_pos;
        cin >> tmp_dir >> tmp_len >> tmp_pos;
        l[i] = tmp_pos;
        dif_pos.push_back(tmp_pos);
        if (tmp_dir == '-') {
            dif_pos.push_back(tmp_pos + tmp_len);
            add[i] = 1;
            r[i] = tmp_pos + tmp_len;
        }
        if (tmp_dir == '|') {
            dif_pos.push_back(tmp_pos + 1);
            add[i] = tmp_len;
            r[i] = tmp_pos + 1;
        }
    }
    sort(dif_pos.begin(), dif_pos.end());
    dif_pos.erase(unique(dif_pos.begin(), dif_pos.end()), dif_pos.end());
    for (int i = 0; i < n; ++i) {
        int left = find(l[i], dif_pos);
        int right = find(r[i], dif_pos);
    }
    return 0;
}
