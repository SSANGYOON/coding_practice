n = int(input())
for _ in range(n):
    sounds = input().split()
    voice = set()
    t = input()
    while t != 'what does the fox say?':
        voice.add(t.split()[-1])
        t = input()
    ans = []
    for s in sounds:
        if s not in voice:
            ans.append(s)
    print(' '.join(ans))

