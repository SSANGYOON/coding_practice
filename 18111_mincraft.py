import sys
input = sys.stdin.readline
h,w,b = map(int,input().split())
blocks = dict()
bs = b
for i in range(h):
    for j in map(int,input().split()):
        if j in blocks:
            blocks[j] +=1
        else:
            blocks[j] = 1
        bs += j
heights = sorted(blocks.keys(),reverse=True)
mint = 100000000000000
mini = -1
for i in range(heights[0],heights[-1]-1,-1):
    t = 0
    for j in heights:
        if j<i:
            t += (i-j)*blocks[j]
        elif j>i:
            t += (j-i)*blocks[j]*2
    if i*h*w <=bs:
        if t<mint:
            mint = t
            mini = i
print(mint,mini)