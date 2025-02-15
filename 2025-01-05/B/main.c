#include <stdio.h>
#include <limits.h>

void Euler(int* primes) {
    int numbers[31622];
    int count = 0;
    for(int i = 0; i < 31622; i++)
        numbers[i] = 1;
    numbers[0] = 0;
    for(int i = 0; i < 31622; i++) {
        if (numbers[i]) {
            primes[count] = i + 1;
            count++;
        }
        for(int j = 0; j < count; j++) {
            int tmp_prime = primes[j];
            if(tmp_prime*(i+1) > 31622)
                break;
            numbers[tmp_prime*(i+1) - 1] = 0;
            if((i+1) % tmp_prime == 0)
                break;
        }
    }
}

int main() {
    int primes[3401];
    Euler(primes);
    int t;
    scanf("%d", &t);
    while (t--) {
        long long p, q;
        scanf("%lld%lld", &p, &q);
        if (p % q) {
            printf("%lld\n", p);
            continue;
        }
        long long min_div = LLONG_MAX;
        long long q_core = q;
        for (int i = 0; primes[i] * primes[i] <= q_core; i++) {
            if (q % primes[i] == 0) {
                while(q_core % primes[i] == 0) q_core /= primes[i];
                long long temp = primes[i];
                while (temp <= p) {
                    if (p % temp) break;
                    if (p / temp % q) {
                        if (temp < min_div) min_div = temp;
                        break;
                    }
                    temp *= primes[i];
                }
            }
        }
        if (q_core != 1) {
            long long temp = q_core;
            while (temp <= p) {
                if (p % temp) break;
                if (p / temp % q) {
                    if (temp < min_div) min_div = temp;
                    break;
                }
                temp *= q_core;
            }
        }
        printf("%lld\n", p / min_div);
    }
    return 0;
}
