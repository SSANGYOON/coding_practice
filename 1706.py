r,c = map(int,input().split())
v = ['' for _ in range(c)]
h = []
for _ in range(r):
    t = input()
    h.append(t)
    for i in range(c):
        v[i] += t[i]
words = []
for w in h:
    ws = w.split('#')
    for s in ws:
        if len(s) > 1:
            words.append(s)
for w in v:
    ws = w.split('#')
    for s in ws:
        if len(s) > 1:
            words.append(s)
words.sort()
print(words[0])