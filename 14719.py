input()
l = list(map(int,input().split()))
maxh = l.index(max(l))
cur = maxh
ans = 0
while cur> 0:
    t = l[0:cur].index(max(l[0:cur]))
    ans += l[t]*(cur-t)-sum(l[t:cur])
    cur = t
cur = maxh
while cur< len(l)-1:
    t = l[cur+1:].index(max(l[cur+1:]))+cur+1
    ans += l[t]*(t-cur)-sum(l[cur+1:t+1])
    cur = t
print(ans)