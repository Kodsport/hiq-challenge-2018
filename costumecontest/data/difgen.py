import random
import string
print(1000)
for i in range(1000):
    print(''.join(random.choice(string.ascii_lowercase) for _ in range(20)))
