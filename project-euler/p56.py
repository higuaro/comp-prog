#!/bin/env python

maxSum = 0
for a in range(0, 100):
    for b in range(0, 100):
        res = a ** b
        sRes = str(res)
        
        maxSum = max(maxSum, sum([ord(c) - 48 for c in sRes]))
        
print(maxSum)
