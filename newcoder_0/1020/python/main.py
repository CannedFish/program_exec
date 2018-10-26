import sys

N, p = map(int, sys.stdin.next().split())
if N <= 0:
    print 0
    sys.exit(0)
nums = map(int, sys.stdin.next().split())
nums.sort(lambda x,y: x-y)
Max, l, i, Min = 0, 1, 0, nums[0]
for x in nums[1:]:
    if x > Min*p:
        if l > Max:
            Max = l
        while x > Min*p:
            i += 1
            Min = nums[i]
            l -= 1
    l += 1
print "%d" % (l if l > Max else Max)
