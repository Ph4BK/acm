#include <iostream>
#include <cmath>
using namespace std;
int x[1000], y[1000], weight[1000];
double ans_x, ans_y;
constexpr double down = .9;
constexpr double eps = 1e-6;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x[i], &y[i], &weight[i]);
        ans_x += x[i];
        ans_y += y[i];
    }
    ans_x /= n;
    ans_y /= n;
    double temperature = 5e4;
    while (temperature > eps) {
        temperature *= down;
        double dx = 0., dy = 0.;
        for (int i = 0; i < n; i++) {
            double dist = sqrt(pow(x[i] - ans_x, 2) + pow(y[i] - ans_y, 2));
            if (dist == 0.) continue;
            dx += (x[i] - ans_x) * weight[i] / dist;
            dy += (y[i] - ans_y) * weight[i] / dist;
        }
        double dist = sqrt(pow(dx, 2) + pow(dy, 2));
        if (dist == 0.) break;
        ans_x += dx / dist * temperature;
        ans_y += dy / dist * temperature;
    }
    printf("%.3lf %.3lf", ans_x, ans_y);
    return 0;
}
