import random
print(10)
x = [random.randint(-100, 100) for _ in range(10)]
print(' '.join(str(y if y%2 == 0 else 0) for y in x))
print(' '.join(str(0 if y%2 == 0 else -y) for y in x))
