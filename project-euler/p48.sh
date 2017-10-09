#/bin/bash

# one-liner version
#>n;for i in {1..1000}; do echo "$i^$i + " >> n; done; tr -d '\n' < n | sed -e 's/ + $/\n/g' | bc

>n
for i in {1..1000}; do 
    echo "$i^$i + " >> n
done

tr -d '\n' < n | sed -e 's/ + $/\n/g' | bc
