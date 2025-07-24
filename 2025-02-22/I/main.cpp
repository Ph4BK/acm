#include <iostream>
using namespace std;
int brand[1001];
pair<int, int> bottle[100];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        brand[a]++;
        bottle[i] = {a, b};
    }
    for (int i = 0; i < n; i++){
        if (bottle[i].first != bottle[i].second){
            brand[bottle[i].second] = 0;
        }
        else{
            if (brand[bottle[i].second] == -1){
                brand[bottle[i].second] = 0;
            }
            else if (brand[bottle[i].second] > 0){
                brand[bottle[i].second] = -1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 1000; i++){
        if (brand[i] == -1) brand[i] = 1;
        ans += brand[i];
    }
    cout << ans << endl;
}