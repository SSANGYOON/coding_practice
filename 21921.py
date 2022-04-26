n,x = map(int,input().split())
view = list(map(int,input().split()))
v = sum(view[:x])
max_v = v
max_d = 1
for i in range(n-x):
    v = v-view[i]+view[i+x]
    if v > max_v:
        max_v =v
        max_d = 1
    elif v == max_v:
        max_d += 1
if max_v:
    print(max_v)
    print(max_d)
else:
    print('SAD')