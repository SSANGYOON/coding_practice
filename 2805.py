n,m = map(int,input().split())
trees = list(map(int,input().split()))
low = 0
hi = max(trees)
while low < hi:
    mid = (low + hi+1) // 2
    woods = 0
    for t in trees:
        woods += max(t-mid,0)
    if woods >= m:
        low = mid
    else:
        hi = mid -1
print(low)
