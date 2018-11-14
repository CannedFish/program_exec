import sys

pn = an = total = 0
a = []
t = []
for c in sys.stdin.next():
    if c == 'P':
        pn += 1
    elif c == 'A':
        an += 1
        a.append(pn)
    elif c == 'T':
        t.append(an)
    else:
        continue
for i in xrange(1, len(a)):
    a[i] += a[i-1]
for i in xrange(len(t)):
    if t[i] > 0:
        total += a[t[i]-1]
print "%d" % (total % 1000000007)
