import random
C = 10000
P = 100
print(C, P)
def shuffled(X):
    X = list(X)
    random.shuffle(X)
    return X
for _ in range(P):
    print(random.randint(1, 1000000), *shuffled(range(1, C+1)))
