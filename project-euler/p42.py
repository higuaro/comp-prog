#!/usr/bin/env python

t = dict()
sum = 0
for n in xrange(1, 500):
    sum += n
    t[sum] = True

f = open("words2.txt")
triangular = 0
for word in f:
    sum = 0;
    for c in word:
        v = ord(c) - 64
        if v > 0:
            sum += v  
    if sum in t:
        print word, "has sum", sum, "is in t"   
        triangular += 1
print triangular
