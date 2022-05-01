n = int(input())
d = []
c = []
for i in range(n):
    dur, cost = map(int,input().split())
    d.append(dur)
    c.append(cost)

def surf(p,n,pay):
    if p<n:
        if d[p] + p <=n:
            return max(surf(p + d[p],n,pay+c[p]),surf(p+1,n,pay))
        else:
            return surf(p+1,n,pay)
    else:
        return pay
print(surf(0,n,0))