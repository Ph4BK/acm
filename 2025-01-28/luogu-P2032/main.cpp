#include <bits/stdc++.h>
using namespace std;
int arr[2000000];
deque<int> q;

int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        while (!q.empty() && arr[q.back()] <= arr[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i < k - 1) continue;
        while (!q.empty() && q.front() <= i - k) {
            q.pop_front();
        }
        cout << arr[q.front()] << endl;
    }
    return 0;
}
