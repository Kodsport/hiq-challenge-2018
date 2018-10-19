import random
print(100)
x = [random.randint(-100, 100) for _ in range(100)]
print(' '.join(str(y) for y in x))
print(' '.join(str(-y) for y in x))
