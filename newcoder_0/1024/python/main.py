def gcd(a, b):
    a = abs(a)
    b = abs(b)
    while b != 0:
        a, b = b, a%b
    return a

class Rational:
    def __init__(self, t=0, b=1):
        self._bottom = b
        self._top1 = t
        self._top2 = 0
        self._z = 0
        self._gcd = 0
        self._norm()

    def __str__(self):
        s = ""
        if self._z != 0:
            s += "(%d" % self._z if self._z < 0 else "%d" % self._z
            if self._top2 < 0:
                self._top2 = -self._top2
            if self._bottom < 0:
                self._bottom = -self._bottom
            if self._top2 != 0:
                s += " %d/%d" % (self._top2, self._bottom)
            if self._z < 0:
                s += ")"
        else:
            if (self._top2 < 0 and self._bottom < 0) or \
                    (self._top2 > 0 and self._bottom < 0):
                self._top2 = -self._top2
                self._bottom = -self._bottom
            if self._top2 < 0:
                s += "("
            s += "%d/%d" % (self._top2, self._bottom) if self._top2 != 0 else "0"
            if self._top2 < 0:
                s += ")"
        return s

    def _norm(self):
        if self._bottom < 0:
            self._top1 = -self._top1
            self._bottom = -self._bottom
        self._gcd = gcd(self._top1, self._bottom)
        self._top1 = self._top1/self._gcd if self._top1 >= 0 \
                else -(abs(self._top1)/self._gcd)
        self._bottom /= self._gcd
        self._z = self._top1/self._bottom if self._top1 >= 0 \
                else -(abs(self._top1)/self._bottom)
        self._top2 = -(abs(self._top1)%self._bottom) if self._top1 < 0 \
                else self._top1%self._bottom

import sys

def calc(a, b, c, op):
    sys.stdout.write(str(a))
    sys.stdout.write(" %c " % op)
    sys.stdout.write(str(b))
    c._bottom = a._bottom * b._bottom
    if op == '+':
        c._top1 = a._top1*b._bottom + b._top1*a._bottom
    elif op == '-':
        c._top1 = a._top1*b._bottom - b._top1*a._bottom
    elif op == '*':
        c._top1 = a._top1 * b._top1
    else:
        if b._top1 == 0:
            sys.stdout.write(" = Inf\n")
            return
        else:
            c._top1 = a._top1 * b._bottom
            c._bottom = a._bottom * b._top1
    c._norm()
    sys.stdout.write(" = %s\n" % c)

x, y = sys.stdin.next().split()
x = map(int, x.split('/'))
y = map(int, y.split('/'))
a = Rational(x[0], x[1])
b = Rational(y[0], y[1])
c = Rational()
calc(a, b, c, '+')
calc(a, b, c, '-')
calc(a, b, c, '*')
calc(a, b, c, '/')

