import sys

a, b = map(int, sys.stdin.next().split())
tick = round((b-a)/100.0)
t = map(lambda x: (tick/(60**x))%60, range(3))
print "%02d:%02d:%02d" % (t[2], t[1], t[0])
