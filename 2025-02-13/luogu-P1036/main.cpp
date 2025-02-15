#include <iostream>
using namespace std;
int num[10001];
int prime[10000];
int prime_count;
int arr[20];
int n, k;
int ans;

void Euler_sieve() {
    num[1] = 1;
    for (int i = 1; i <= 10000; i++) {
        if (num[i] == 0) {
            prime[prime_count++] = i;
        }
        for (int j = 0; j < prime_count; j++) {
            if (i * prime[j] > 10000) break;
            num[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

bool is_prime(int n) {
    if (n == 1) return false;
    int stat = true;
    for (int i = 0; i < prime_count; i++) {
        if (prime[i] * prime[i] > n) break;
        if (n % prime[i] == 0) {
            stat = false;
            break;
        }
    }
    return stat;
}

void search(int cur, int chosen, int sum) {
    if (chosen == k) {
        if (is_prime(sum)) ans++;
        return;
    }
    if (chosen + n - cur < k) return;
    search(cur + 1, chosen, sum);
    search(cur + 1, chosen + 1, sum + arr[cur]);
}

int main(){
    Euler_sieve();
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    search(0, 0, 0);
    cout << ans << endl;
    return 0;
}
