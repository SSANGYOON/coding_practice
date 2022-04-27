import sys

n, d, k, c = map(int, sys.stdin.readline().rsplit())
l = [int(sys.stdin.readline().rstrip()) for _ in range(n)]
ans = 0
s = set()
for i in range(n):
    t = 1
    s = set()
    for j in range(k):
        if l[(i+j) % n] == c:
            t = 0
        s.add(l[(i+j) % n])
    ans = max(len(s)+t,ans)
print(ans)
        
    