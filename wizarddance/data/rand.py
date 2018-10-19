import random
import sys

N = int(sys.argv[1])
X = list(range(0, N))
random.shuffle(X)
p = []
for i, v in enumerate(X):
    d = abs(i - v)
    if random.randint(0, 1) == 0:
        d = (N - d) % N
    p.append(d)
print(N)
print(*p)
