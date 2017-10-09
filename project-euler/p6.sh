#!/bin/bash
perl -le '$L=100;for(;$i<=$L;++$i) {$t1+=$i*$i; $t2+=$i;} print (($t2*$t2)-$t1)' # prob 6 de projecteuler.net
