#include <iostream>
using namespace std;
int arr[100001];
int add;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    while (m--){
        int opt;
        cin >> opt;
        if (opt == 1) {
            int idx, x;
            cin >> idx >> x;
            arr[idx] = x - add;
        }
        if (opt == 2){
            int y;
            cin >> y;
            add += y;
        }
        if (opt == 3){
            int idx;
            cin >> idx;
            cout << arr[idx] + add << endl;
        }
    }
    return 0;
}