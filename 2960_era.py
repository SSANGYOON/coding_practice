n,k = map(int,input().split())

l = list(range(2,n+1))

res = k
while res>0:
    p = l[0]
    next = []
    dele = []
    for n in l:
        if n % p == 0:
            dele.append(n)
        else:
            next.append(n)
    if len(dele)< res:
        l = next
        res -=len(dele)
    else:
        print(dele[res-1])
        break