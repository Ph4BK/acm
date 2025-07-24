#include <iostream>
using namespace std;

int main() {
    long long x, y, price;
    cin >> x >> y >> price;
    cout << (x + y) / price << " ";
    x %= price;
    y %= price;
    if (x + y >= price) cout << min(price - x, price - y) << endl;
    else cout << 0 << endl;
    return 0;
}
