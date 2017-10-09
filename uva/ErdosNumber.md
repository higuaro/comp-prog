Description
===========

The Hungarian Paul Erdös (1913-1996, speak as "Ar-dish") not only was one of the strangest mathematicians of the 20th century, he was also one of the most famous. He kept on publishing widely circulated papers up to a very high age and every mathematician having the honor of being a co-author to Erdös is well respected.
Not everybody got the chance to co-author a paper with Erdös, so many people were content if they managed to publish a paper with somebody who had published a scientific paper with Erdös. This gave rise to the so-called Erdös numbers. An author who has jointly published with Erdös had Erdös number 1. An author who had not published with Erdös but with somebody with Erdös number 1 obtained Erdös number 2, and so on.

Problem 

Today, nearly everybody wants to know which Erdös number he or she has. Your task is to write a program which computes Erdös numbers for a given set of scientists.

Input
===== 

The first line of the input contains the number of scenarios.
The input for each scenario consists of a paper database and a list of names. It begins with the line

```text
P N
```

where `P` and `N` are natural numbers. Following this line are P lines containing descriptions of papers (this is the paper database). A paper appears on a line by itself and is specified in the following way:

```text
Smith, M.N., Martin, G., Erdos, P.: Newtonian forms of prime factors matrices
```

Note that umlauts like 'ö' are simply written as 'o'. After the P papers follow N lines with names. Such a name line has the following format:

```text
Martin, G.
```

Output 
=====

For every scenario you are to print a line containing a string `Scenario i` (where i is the number of the scenario) and the author names together with their Erdös number of all authors in the list of names. The authors should appear in the same order as they appear in the list of names. The Erdös number is based on the papers in the paper database of this scenario. Authors which do not have any relation to Erdös via the papers in the database have Erdös number `infinity`.

Sample Input
======

```text
1
4 3
Smith, M.N., Martin, G., Erdos, P.: Newtonian forms of prime factor matrices 
Erdos, P., Reisig, W.: Stuttering in petri nets
Smith, M.N., Chen, X.: First oder derivates in structured programming
Jablonski, T., Hsueh, Z.: Selfstabilizing data structures
Smith, M.N.
Hsueh, Z.
Chen, X.
```

Sample Ouput
======

```text
Scenario 1
Smith, M.N. 1
Hsueh, Z. infinity
Chen, X. 2
```

**Solution:** Used BFS for this, grab the authors of every paper using a split, then make every author to be child the other authors in the same line (take care of not making the author child of him/herself), after reading all the papers and forming the graph, set Erdos number of 0 to "Erdos, P" and then run the BFS from this node. 

There is a LOT of noise in the uva forums regarding the input format of this problem, my advise, don't stress to much with that, focus on solving the problem with the bfs, I got a lot of WA believing that there was a catch in the input format while there was not.

