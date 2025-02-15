#include <iostream>
#include <cmath>
using namespace std;
int space[500][500];

void product(const int* first, const int* second, int* result) {
    for (int j = 499; j >= 0; j--) {
        int carry = 0;
        for (int i = 499; i + j - 499 >= 0; i--) {
            int temp = first[i] * second[j] + carry;
            carry = temp / 10;
            space[499 - j][i + j - 499] = temp % 10;
        }
    }
    int sum = 0;
    for (int i = 499; i >= 0; i--) {
        for (int j = 0; i + j <= 499; j++) {
            sum += space[j][i];
        }
        result[i] = sum % 10;
        sum /= 10;
    }
}

void pow (int* base, int pow, int* result) {
    while (pow) {
        if (pow & 1) {
            int temp[500] = {0};
            product(result, base, temp);
            for (int i = 0; i < 500; i++) {
                result[i] = temp[i];
            }
        }
        int temp[500] = {0};
        product(base, base, temp);
        for (int i = 0; i < 500; i++) {
            base[i] = temp[i];
        }
        pow >>= 1;
    }
}

int main() {
    int p;
    cin >> p;
    int digit = p * log10(2) + 1;
    cout << digit << endl;
    int two[500] = {0};
    two[499] = 2;
    int ans[500] = {0};
    ans[499] = 1;
    pow(two, p, ans);
    ans[499]--;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++) {
            cout << ans[50 * i + j];
        }
        cout << endl;
    }
    return 0;
}
