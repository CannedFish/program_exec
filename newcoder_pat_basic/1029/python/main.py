import sys

s = [0]*128
s1, s2 = 0, 0
for x in sys.stdin.next():
    s[ord(x)] += 1
for x in sys.stdin.next():
    s[ord(x)] -= 1
for i in xrange(128):
    if s[i] < 0:
        s1 += s[i]
    else:
        s2 += s[i]
print "Yes %d" % s2 if s1 == 0 else "No %d" % -s1
