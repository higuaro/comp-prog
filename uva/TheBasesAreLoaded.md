Description
==========

Write a program to convert a whole number specified in any base (2..16) to a whole number in any other base (2..16). ``Digits" above 9 are represented by single capital letters; e.g. 10 by A, 15 by F, etc.

Input
=====

Each input line will consist of three values. The first value will be a positive integer indicating the base of the number. The second value is a positive integer indicating the base we wish to convert to. The third value is the actual number (in the first base) that we wish to convert. This number will have letters representing any digits higher than 9 and may contain invalid ``digits". It will not exceed 10 characters. Each of the input values on a single line will be separated by at least one space.

Output
======

Program output consists of the original number followed by the string ``base", followed by the original base number, followed by the string ``=" followed by the converted number followed by the string ``base" followed by the new base. If the original number is invalid, output the statement

```text
original Value is an illegal base original Base number
```

where original Value is replaced by the value to be converted and original Base is replaced by the original base value.

Sample input
========

```text
2 10 10101
5 3 126
15 11 A4C
```

Sample output
======

```text
10101 base 2 = 21 base 10 
126 is an illegal base 5 number 
A4C base 15 = 1821 base 11
```

Solution: Use a routine to convert from base 10 to n-base and viceversa, another routine to evaluate an n-base number in base 10, I toke care of negative numbers just in case, although the problem statement suggest nothing about it.
