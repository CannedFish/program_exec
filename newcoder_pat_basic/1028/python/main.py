import sys

sc = [0] * 101
def inc(x):
    sc[int(x)] += 1

sys.stdin.next()
map(inc, sys.stdin.next().split())
k = map(int, sys.stdin.next().split())
map(lambda x: sys.stdout.write("%d " % sc[x]), k[1:-1])
sys.stdout.write("%d\n" % sc[k[-1]])
