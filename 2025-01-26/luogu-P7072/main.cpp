#include <iostream>
using namespace std;
int bucket[601];

int main() {
    int n, rate;
    cin >> n >> rate;
    for (int i = 1; i <= n; i++) {
        int score;
        cin >> score;
        bucket[score]++;
        int prize = i * rate / 100;
        if (prize == 0) prize = 1;
        int cnt = 0;
        int line;
        for (line = 600; cnt < prize; line--) {
            cnt += bucket[line];
        }
        line++;
        cout << line << " ";
    }
    return 0;
}
