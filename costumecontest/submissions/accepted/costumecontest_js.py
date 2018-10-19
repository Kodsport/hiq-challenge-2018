#!/usr/bin/env python3
import collections

N = int(input())
m = collections.defaultdict(int)
for i in range(N):
    m[input()] += 1

best = min(m.values())
for cat in sorted(x for x in m.keys() if m[x] == best):
    print(cat)
