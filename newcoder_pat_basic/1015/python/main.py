import sys

H, N, K = map(int, sys.stdin.next().split())

D = [None] * 100000
for i in xrange(N):
    v = map(int, sys.stdin.next().split())
    D[int(v[0])] = v

O = []
for i in xrange(N/K):
    h = i*K
    for j in xrange(K):
        O.insert(h, D[H])
        H = D[H][2]

while H != -1:
    O.append(D[H])
    H = D[H][2]

for i in xrange(len(O)-1):
    O[i][2] = O[i+1][0]
    print "%05d %d %05d" % (O[i][0], O[i][1], O[i][2])
print "%05d %d -1" % (O[-1][0], O[-1][1])

