import random
C = 10000
P = 100
print(C, P)
for _ in range(P):
    print(random.randint(1, 1000000), *range(1, C+1))
