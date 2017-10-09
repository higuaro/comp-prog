#!/bin/bash
perl -le '$L=4e6;$f0=1;$f=1;for(;$f<$L;){$m=$f; $f+=$f0; $t+=$f if $f<$L && !($f%2); $f0=$m} print $t
