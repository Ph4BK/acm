#include <bits/stdc++.h>
using namespace std;

int main(){
    set<string> dict;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        dict.insert(s);
    }
    cout << dict.size() << endl;
    return 0;
}
