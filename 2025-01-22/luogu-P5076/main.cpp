#include <iostream>
#include <climits>
#define MAXN 100010
using namespace std;

int q, cnt, opt, x, idx;

struct Node {
    int left, right, size, value, num;
    explicit Node(int v)
        : left(0), right(0), size(1), value(v), num(1) {}
    Node(){}
} t[MAXN];

int rks(int x, int root) {
    if (root) {
        if (x < t[root].value)
            return rks(x, t[root].left);
        if (x > t[root].value) {
            return rks(x, t[root].right) + t[t[root].left].size + t[root].num;
        }
        return t[t[root].left].size + 1;
    }
    return 1;
}

int kth(int x, int root) {
    if (x <= t[t[root].left].size)
        return kth(x, t[root].left);
    if (x <= t[t[root].left].size + t[root].num)
        return t[root].value;
    return kth(x - t[t[root].left].size - t[root].num, t[root].right);
}

void insert(int x, int root) {
    t[root].size++;
    if (x < t[root].value) {
        if (!t[root].left)
            t[t[root].left = ++cnt] = Node(x);
        else
            insert(x, t[root].left);
    }
    else if (x > t[root].value) {
        if (!t[root].right)
            t[t[root].right = ++cnt] = Node(x);
        else
            insert(x, t[root].right);
    }
    else
        t[root].num++;
}

int main() {
    cin >> q;
    t[1] = Node(INT_MAX);
    cnt = 1;
    while (q--) {
        cin >> opt >> x;
        switch (opt) {
            case 1:
                cout << rks(x, 1) << endl;
                break;
            case 2:
                cout << kth(x, 1) << endl;
                break;
            case 3:
                idx = rks(x, 1) - 1;
                if (idx == 0)
                    cout << -2147483647 << endl;
                else
                    cout << kth(idx, 1) << endl;
                break;
            case 4:
                if (kth(rks(x, 1), 1) == x)
                    idx = rks(x, 1) + 1;
                else
                    idx = rks(x, 1);
                if (idx > cnt)
                    cout << 2147483647 << endl;
                else
                    cout << kth(idx, 1) << endl;
                break;
            case 5:
                insert(x, 1);
                break;
            default:
                cout << "Wrong option!" << endl;
        }
    }
    return 0;
}
