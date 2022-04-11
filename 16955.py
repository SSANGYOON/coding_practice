dx = (-1, 1, 0, 0, -1, 1, -1, 1)
dy = (0, 0, -1, 1, -1, 1, 1, -1)

def win():
    for y in range(10):
        for x in range(10):
            if field[y][x] == '.':
                if isO(y, x):
                    return 1
    return 0

def isO(y, x):
    if trav(y, x, [0, 1]): return True
    if trav(y, x, [2, 3]): return True
    if trav(y, x, [4, 5]): return True
    if trav(y, x, [6, 7]): return True
    return False

def trav(y, x, dir):
    t_cnt = 1
    for d in dir:
        cnt = 0
        ny, nx = y+dy[d], x+dx[d]
        for _ in range(5):
            if not(0 <= ny < 10 and 0 <= nx <10):
                t_cnt += cnt
                break
            if field[ny][nx] == 'X':
                cnt += 1
                ny, nx = ny+dy[d], nx+dx[d]
            else:
                t_cnt += cnt
                break
    return True if t_cnt >= 5 else False
field = [list(input()) for _ in range(10)]
print(win())