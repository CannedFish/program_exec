import sys

OLDEST = 200
num = 0
o_day, y_day = [2014, 9, 6], [0]*3
N = int(sys.stdin.next())
for i in xrange(N):
    name, date = sys.stdin.next().split()
    y, m, d = map(int, date.split('/'))
    y_d, m_d, d_d = 2014-y, 9-m, 6-d
    if y_d > OLDEST or\
            (y_d == OLDEST and m_d > 0) or\
            (y_d == OLDEST and m_d == 0 and d_d > 0):
        continue
    elif y > 2014 or\
            (y == 2014 and m < 9) or\
            (y == 2014 and m == 9 and d < 6):
        continue
    else:
        num += 1
        if y < o_day[0] or\
                (y == o_day[0] and m < o_day[1]) or\
                (y == o_day[0] and m == o_day[1] and d < o_day[2]):
            o_day[0] = y
            o_day[1] = m
            o_day[2] = d
            o_name = name
        if y > y_day[0] or\
                (y == o_day[0] and m < o_day[1]) or\
                (y == o_day[0] and m == o_day[1] and d < o_day[2]):
            y_day[0] = y
            y_day[1] = m
            y_day[2] = d
            y_name = name
print "%d %s %s" % (num, o_name, y_name)

