#include <iostream>
#include <deque>
using namespace std;
int temperature[100000];

int main() {
    int c, n;
    cin >> c >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temperature[i];
    }
    int prev = -1;
    int min = 100;
    deque<int> q;
    q.push_back(0);
    for (int i = 0; i < n; ++i) {
        while (!q.empty() && temperature[i] >= temperature[q.front()]) {
            q.pop_front();
        }
        q.push_front(i);
        if (i > prev + c) {
            if (temperature[q.back()] < min) min = temperature[q.back()];
            prev = q.back();
            q.pop_back();
        }
    }
    cout << min << endl;
    return 0;
}
