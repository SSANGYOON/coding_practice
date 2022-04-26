n,r,c = map(int,input().split())

t = n -1
ans = 0
while t >= 0:
    if r >= 2 ** t:
        ans += 2 * 2 ** t
        r -= 2 ** t
    if c >= 2 ** t:
        ans += 2 ** t
        c -= 2 ** t
    t -= 1
print(ans)