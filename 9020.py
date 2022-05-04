import math
t = int(input())
l = [False,False,True,True]
for i in range(4,10000):
    ans = True
    for j in range(2,int(math.sqrt(i))+1):
        if i % j == 0 :
            ans = False
    l.append(ans)
for i in range(t):
    n = int(input())
    b = n//2
    for j in range(b):
        if l[b-j] and l[b+j]:
            print(b-j,b+j)
            break
