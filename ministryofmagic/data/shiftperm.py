import random
C = 10000
P = 100

def shift(P):
    return P[1:] + P[:1]

print(C, P)
V = list(range(1, C+1))
for _ in range(P):
    print(random.randint(1, 1000000), *V)
    V = shift(V)
