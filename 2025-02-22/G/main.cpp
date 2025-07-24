#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        bool flag = false;
        if (b - a == 1 && d - c == 1){
            int col = c - a;
            if (col >= 1 && a % col){
                flag = true;
                int row = d / col + 1;
                cout << row << " " << col << endl;
            }
        }
        if (!flag){
            cout << -1 << endl;
        }
    }
    return 0;
}