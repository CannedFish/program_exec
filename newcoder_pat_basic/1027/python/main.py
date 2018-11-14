import sys

p, a = map(lambda x: map(int, x.split('.')), sys.stdin.next().split())
r = [0]*3
sign = 0
if p[0] > a[0] \
        or (p[0] == a[0] and p[1] > a[1]) \
        or (p[0] == a[0] and p[1] == a[1] and p[2] > a[2]):
    sign = 1
if sign == 1:
    p, a = a, p
    sys.stdout.write("-")
r[2] = a[2]+29-p[2]
r[1] = a[1]+17-1-p[1]+r[2]/29
r[0] = a[0]-1-p[0]+r[1]/17
sys.stdout.write("%d.%d.%d\n" % (r[0], r[1]%17, r[2]%29))

