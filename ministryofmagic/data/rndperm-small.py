import random
C = 100
P = 100
print(C, P)
def shuffled(X):
    X = list(X)
    random.shuffle(X)
    return X
for _ in range(P):
    print(random.randint(1000, 1010), *shuffled(range(1, C+1)))
