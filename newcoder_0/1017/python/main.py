import sys

n, c = sys.stdin.next().split()
n = int(n)
b = (n+1) % 2
n = (n+1) / 2
ns = []
num = 0
while n > 0:
    ns.append(2*num+1)
    n -= ns[num]
    num += 1
if n < 0:
    num -= 1
for i in range(num)[::-1]:
    sys.stdout.write(" " * ((ns[num-1]-ns[i])/2)\
            + ("%c" % c) * ns[i]\
            + "\n")
for i in range(1, num):
    sys.stdout.write(" " * ((ns[num-1]-ns[i])/2)\
            + ("%c" % c) * ns[i]\
            + "\n")
print "%d" % (2*(n+ns[num]) + b) if n < 0 else "%d" % b

