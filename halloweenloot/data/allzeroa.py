import random
print(100)
x = [random.randint(1, 100) for _ in range(100)]
print(' '.join(str(0) for y in x))
print(' '.join(str(y) for y in x))
