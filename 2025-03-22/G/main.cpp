#include <iostream>
using namespace std;

int dict[10] = {0b1110111, 0b0000011, 0b0111110, 0b0011111,
                0b1001011, 0b1011101, 0b1111101, 0b0010011,
                0b1111111, 0b1011111};
bool stat[10];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string cntr;
        cin >> cntr;
        for (auto& it: stat) it = true;
        for (int digit = 6; digit >= 0; --digit) {
            char temp = cntr[6 - digit];
            if (temp == 'G') {
                for (int num = 0; num <= 9; ++num) {
                    if (!((dict[num] >> digit) & 1)) stat[num] = false;
                }
            }
            if (temp == 'g') {
                for (int num = 0; num <= 9; ++num) {
                    if ((dict[num] >> digit) & 1) stat[num] = false;
                }
            }
        }
        int pred = -1;
        for (int num = 0; num <= 9; ++num) {
            if (stat[num]) {
                if (pred == -1) pred = num;
                else {
                    pred = -1;
                    break;
                }
            }
        }
        if (pred == -1) cout << '*';
        else cout << pred;
    }
    return 0;
}
