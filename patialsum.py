n = int(input())
num = list(map(int,input().split(' ')))
num.sort()
base = 1
for n in num:
    if n == base:
        base *=2
print(base)
