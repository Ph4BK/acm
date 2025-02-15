#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        unordered_map<string, int> map;
        string target;
        cin >> target;
        size_t target_len = target.length();
        string text;
        cin >> text;
        size_t text_len = text.length();
        for (int i = 0; i <= text_len - target_len; i++) {
            string temp = text.substr(i, target_len);
            map[temp]++;
        }
        cout << map[target] << endl;
    }
    return 0;
}
