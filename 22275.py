from math import ceil
n, d= map(int,input().split())
tasks = []

for _ in range(n):
    tasks.append(tuple(map(int,input().split())))
tasks.sort()
conflict = -1
ans = -1
for s in range(0,481):
    con = 0
    for t in tasks:
        if t[0]<=s:
            start = s
        else:
            start = s + ceil((t[0]-s)/d)*d
        if t[0] +t[1] >= start:
            con += (t[0]+t[1]-start)//d + 1
    if con <conflict or conflict == -1:
        ans = s
        conflict = con
print(ans,conflict)
