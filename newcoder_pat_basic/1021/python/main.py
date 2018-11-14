import sys

N = int(sys.stdin.next())
w = [7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2]
M = ['1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2']
n = False
for _ in xrange(N):
    s = sys.stdin.next()[:-1]
    _sum = 0
    _n = False
    for j in xrange(17):
        if s[j] < '0' or s[j] > '9':
            _n = True
            break
        _sum += w[j]*(ord(s[j])-ord('0'))
    if _n or s[17] != M[_sum % 11]:
        print s
        n = True
if not n:
    print "All passed"
