#include <iostream>
int fa[5010];

int lead(int a) {
    if (fa[a] == a) return a;
    return fa[a] = lead(fa[a]);
}

void merge(int a, int b) {
    int a_lead = lead(a);
    int b_lead = lead(b);
    fa[a_lead] = b_lead;
}

int main() {
    int n, m, p;
    std::cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int temp1, temp2;
        std::cin >> temp1 >> temp2;
        merge(temp1, temp2);
    }
    for (int i = 0; i < p; i++) {
        int temp1, temp2;
        std::cin >> temp1 >> temp2;
        if (lead(temp1) == lead(temp2)) std::cout << "Yes" << std::endl;
        else std::cout << "No" << std::endl;
    }
    return 0;
}
