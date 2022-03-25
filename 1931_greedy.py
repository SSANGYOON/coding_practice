n =int(input())
l = []
for i in range(n):
    start, end = input().split(' ')
    start = int(start)
    end = int(end)
    l.append((end,start))
ans = 0
now = 0
l.sort(reverse= True)
while len(l):
    end, start = l.pop()
    if start >= now:
        ans += 1
        now = end
print(ans)