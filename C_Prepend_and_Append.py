def solve():
    n = int(input())
    s = input().strip()
    l, r = 0, n - 1
    ans = n
    while l <= r and s[l] != s[r] and ans > 0:
        l += 1
        r -= 1
        ans -= 2
    print(ans)

t = int(input())
for _ in range(t):
    solve()