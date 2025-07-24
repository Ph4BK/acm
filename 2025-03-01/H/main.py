def solve():
    n, m = input().split()
    n = int(n)
    m = int(m)
    n2 = n
    digit = 0
    ans = 0
    tmp = 1
    while n2:
        digit += 1
        n2 >>= 1
        tmp <<= 1
    for _ in range(digit):
        tmp >>= 1
        if m * (tmp - 1) < n:
            ans += tmp
            n -= min(m, n // tmp) * tmp
    return ans


t = int(input())
for _ in range(t):
    ans = solve()
    print(ans)
