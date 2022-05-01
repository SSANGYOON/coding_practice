n, p = map(int, input().split())
g = [[],[],[],[],[],[],[]]
ans = 0
for i in range(n):
    l,pn = map(int, input().split())
    while len(g[l]) > 0 and g[l][-1] > pn:
        g[l].pop()
        ans += 1
    if len(g[l]) == 0 or g[l][-1] < pn:
        g[l].append(pn)
        ans += 1
print(ans)