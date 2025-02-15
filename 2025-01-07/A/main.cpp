#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int>setters;
    int n;
    cin >> n;
    int first;
    cin >> first;
    for (int i = 0; i < first; i++) {
        string name;
        cin >> name;
        setters[name] = 1;
    }
    for (int i = 1; i < n; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            string name;
            cin >> name;
            if (setters.find(name) != setters.end()) {
                setters[name]++;
            }
        }
    }
    vector<string>fossil;
    for (auto & setter : setters) {
        if (setter.second == n) {
            fossil.push_back((string)setter.first);
        }
    }
    printf("%d\n", fossil.size());
    for (const auto & it : fossil) {
        printf("%s\n", it.c_str());
    }
    return 0;
}
