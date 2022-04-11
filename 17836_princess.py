import sys
from collections import deque
dir =((0,1),(0,-1),(1,0),(-1,0))
input = sys.stdin.readline
r,c,t = map(int,input().rstrip().split())

maze = [list(map(int,input().rstrip().split())) for i in range(r)]

time = [[0]*c for i in range(r)]
time[0][0] = 1
deq = deque()
deq.append((0,0))
answer = t+1
gram = t+1
while deq:
    ro,co = deq.popleft()
    if maze[ro][co] == 2:
        gram = time[ro][co] -1 +abs(ro-(r-1))+abs(co-(c-1))
    elif ro == r-1 and co == c-1:
        answer = min(gram,time[ro][co]-1)
        break
    for d in dir: 
        rn = d[0]+ro
        cn = d[1]+co
        if (rn < r) and (rn >=0) and (cn < c) and (cn >=0):
            if time[rn][cn] == 0:
                if not maze[rn][cn] == 1:
                    time[rn][cn] = time[ro][co] +1
                    deq.append((rn,cn))
answer = min(answer,gram)
if answer <=t:
    print(answer)
else:
    print('Fail')
