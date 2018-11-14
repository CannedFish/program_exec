import sys

broken = sys.stdin.next()
broken += broken.lower()
for c in sys.stdin.next():
    if c in broken or \
            (c >= 'A' and c <= 'Z' and '+' in broken):
        continue
    sys.stdout.write(c)
sys.stdout.write('\n')
