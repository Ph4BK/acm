#include <iostream>
using namespace std;
int stack[100000];

int main() {
    int n;
    cin >> n;
    long long sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        while (cnt > 0 && stack[cnt - 1] <= temp) cnt--;
        stack[cnt] = temp;
        sum += cnt;
        cnt++;
    }
    cout << sum << endl;
    return 0;
}
