n = int(input())

ans = [1]*10
ans[0] = 0

for i in range(n-1):
    ans[0] = ans[1]
    ans[9] = ans[8]
    t = [0]*10
    for i in range(1,9):
        t[i] = ans[i-1]+ans[i+1]
    for i in range(1,9):
        ans[i]=t[i]
print(sum(ans)%1000000000)