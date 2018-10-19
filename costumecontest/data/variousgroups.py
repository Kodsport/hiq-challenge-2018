import random
import string

print(1000)
for i in range(100):
    cat = ''.join(random.choice(string.ascii_lowercase) for _ in range(20))
    for j in range(10):
        print(cat)
