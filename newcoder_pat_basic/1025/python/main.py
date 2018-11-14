import sys

def insert(a, n, idx):
    t = a[idx+n]
    for i in xrange(idx, idx+n+1):
        if t < a[i]:
            break
    for j in range(i+1, idx+n+1)[::-1]:
        a[j] = a[j-1]
    a[i] = t

def merge(a, N, n):
    _n = 2 * n
    i = 0
    while i < N:
        j = i + n
        while j < i+_n and j < N:
            insert(a, j-i, i)
            j += 1
        i += _n

def is_merge(b, N, n):
    if n > N/2:
        sys.stdout.write("Insertion Sort\n")
        return False
    i = n
    while i < N:
        j = i+1
        while j < i+n and j < N:
            if b[j] < b[j-1]:
                sys.stdout.write("Insertion Sort\n")
                return False
            j += 1
        i += n
    sys.stdout.write("Merge Sort\n")
    return True

N = int(sys.stdin.next())
a = map(int, sys.stdin.next().split())
b = map(int, sys.stdin.next().split())

num_sorted = 1
for num_sorted in xrange(1, N):
    if b[num_sorted] < b[num_sorted-1]:
        break
if is_merge(b, N, num_sorted):
    merge(b, N, num_sorted)
else:
    insert(b, num_sorted, 0)
for i in xrange(N-1):
    sys.stdout.write("%d " % b[i])
sys.stdout.write("%d\n" % b[N-1])

