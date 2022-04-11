
n,m = map(int,input().split())
l = [0]
l.extend(list(map(int,input().split())))
def bf(cur,t,pos):
    if pos >=len(l) or t>m:
        return cur
    return max(bf(cur+l[pos],t+1,pos+1),bf((cur+l[pos])//2,t+1,pos+2))
print(bf(1,0,0))