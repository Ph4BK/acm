#include <iostream>
#include <string>
using namespace std;

int main() {
    string front;
    cin >> front;
    string back;
    cin >> back;
    int len = front.length();
    long long ans = 1;
    for (int i = 0; i <= len - 2; i++) {
        for (int j = len - 1; j >= 1; j--) {
            if (front[i] == back[j] && front[i + 1] == back[j - 1])
                ans <<= 1;
        }
    }
    cout << ans << endl;
    return 0;
}
