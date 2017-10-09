#!/usr/bin/env python
def t(n): 
    return (n * (n + 1)) / 2

def p(n): 
    return (n * (3 * n - 1)) / 2

def h(n): 
    return n * (2 * n - 1)

Hs = {}
Ts = {}
Ps = {}
offset = 1
ti = 285 + offset;
pi = 165 + offset;
for hi in xrange(143 + offset, 100000):
    Hs[h(hi)] = True
    Ps[p(pi)] = True
    Ts[t(ti)] = True
    pi += 1
    ti += 1

# print Hs

for p in Ps:
    if p in Hs and p in Ts:
        print p
        break 
