import sys

_in = sys.stdin.next()
_out = sys.stdin.next()
i = 0
show = [0] * 128
for c in _in:
    if i < len(_out) and _out[i] == c:
        i += 1
    else:
        cur = ord(c) - 32 if c >= 'a' and c <= 'z' else ord(c)
        if show[cur] == 0:
            show[cur] = 1
            sys.stdout.write("%c" % cur)
sys.stdout.write("\n")
