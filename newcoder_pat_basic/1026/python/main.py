import sys

N, C = sys.stdin.next().split()
N = int(N)
sys.stdout.write(C * N + '\n' \
        + (C + ' '*(N-2) + C + '\n') * (int(round(N/2.0))-2) \
        + C * N + '\n')
