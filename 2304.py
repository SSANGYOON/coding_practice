n = int(input())
p = dict()
for _ in range(n):
    n, h = map(int,input().split())
    p[n] = h
highest = -1
height = 0
keys = sorted(p.keys())
for i,k in enumerate(sorted(p.keys())):
    if p[k] >height:
        highest =i
        height = p[k]

start = -1
height = 0
area = 0
for i in range(highest):
    if height <p[keys[i]]:
        area += (keys[i]-start)*height
        height = p[keys[i]]
        start = keys[i]
area += height *(keys[highest]-start)
area += p[keys[highest]]

start = 2001
height = 0
for i in range(len(keys)-1,highest-1,-1):
    if height <p[keys[i]]:
        area += (start-keys[i])*height
        height = p[keys[i]]
        start = keys[i]
area += height *(start-keys[highest])
print(area)