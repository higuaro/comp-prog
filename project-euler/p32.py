#!/usr/bin/env python3

from itertools import permutations

digits = list('123456789')

products = {}
total = 0
for p in permutations(digits):
    # move the operator 
    for i in range(1, 6):
        # move the equal
        for j in range(i + 2, 8):
            prod = list(p)
            (multiplicand, multiplier, product) = (int("".join(prod[:i])), int("".join(prod[i:j])), int("".join(prod[j:])))
            if multiplicand * multiplier == product and not product in products:
                products[product] = True
                total += product

print(total)
