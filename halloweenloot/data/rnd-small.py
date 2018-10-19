import random
N = random.randint(1, 30)
MX = random.randint(1, 30)
print(N)
x = [random.randint(-MX, MX) for _ in range(N)]
z = [random.randint(-MX, MX) for _ in range(N)]
print(' '.join(str(y) for y in x))
print(' '.join(str(y) for y in z))
