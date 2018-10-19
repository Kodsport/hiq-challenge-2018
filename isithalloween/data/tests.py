import itertools

months = ["JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"]
daysub = [31, 25, 13, 2, 5]

days = list(range(1, 32))
monthssub= ["JAN", "OCT", "DEC"]

tc = 1
for m, d in list(set(list(itertools.product(months, daysub)) + list(itertools.product(monthssub, days)))):
    f = open("secret/{:02d}-{}-{}.in".format(tc, m, d), "w")
    f.write("{} {}\n".format(m, d))
    f.close()
    tc += 1
