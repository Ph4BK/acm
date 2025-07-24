#include <bits/stdc++.h>
using namespace std;
vector<string> mark[26];

int main() {
    set<string> dict;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        dict.insert(s);
        mark[s[0] - 'A'].push_back(s);
    }
    for (auto target : dict) {
        int len = target.length();
        bool flag = true;
        for (int i = 0; i < len; i++){
            if (mark[target[i] - 'A'].empty()){
                flag = false;
                break;
            }
        }
        if (flag){
            cout << len << endl;
            for (int i = 0; i < len; i++){
                cout << mark[target[i] - 'A'].front() << endl;
            }
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}