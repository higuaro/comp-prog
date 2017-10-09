#!/usr/bin/env python
def isDigitsPermutation(u, v):
    su = str(u)
    sv = str(v)

    # I'm assuming that the digits could be repeated, something like
    # 12994587 (2x = 25989174)
    if len(su) == len(sv):
        digitsU = {chr(i + 48):0 for i in xrange(10)}
        digitsV = {chr(i + 48):0 for i in xrange(10)}
        for i in xrange(len(su)):
            digitsU[su[i]] += 1
            digitsV[sv[i]] += 1

        for k in digitsU.keys():
            if digitsU[k] != digitsV[k]: return False 

        return True
    else:
        return False
    
found = False
n = 0
while not found:
    n += 1

    found = True
    for k in xrange(2, 7):
        if not isDigitsPermutation(n, n * k):
            found = False
            break
    if found: print n
