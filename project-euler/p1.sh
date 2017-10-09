#!/bin/bash
perl -le '$L=1e3;for(;$i<$L;$i+=3,$j+=5){ $t+=$j if $j<$L; $t+=$i if $i%5 }; print $t'
