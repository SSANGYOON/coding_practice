dir = [[1,0],[-1,0],[0,1],[0,-1],[1,-1],[-1,1],[1,1],[-1,-1]]

while True:
    groups = 0
    c,r= map(int,input().split())
    if r*c == 0:
        break
    wi = [list(map(int,input().split())) for _ in range(r)]
    visited = [[0]*c for _ in range(r)]
    for i in range(r):
        for j in range(c):
            if visited[i][j] > 0 or wi[i][j] == 0:
                continue
            else:
                groups += 1
                visited[i][j] = groups
                stack = [(i,j)]
                while stack:
                    y,x = stack.pop()
                    for d in dir:
                        ny = y + d[0]
                        nx = x + d[1]
                        if ny >= 0 and ny < r and nx >= 0 and nx < c and visited[ny][nx] == 0 and wi[ny][nx] == 1:
                            visited[ny][nx] = groups
                            stack.append((ny,nx))
    print(groups)
