import sys

N = int(sys.stdin.next())
_max, m_i = 0, 0
ss = {}
for _ in xrange(N):
    no, score = map(int, sys.stdin.next().split())
    if not ss.has_key(no):
        ss[no] = 0
    ss[no] += score
    if ss[no] > _max:
        _max = ss[no]
        m_i = no
print m_i, _max
