#!/bin/bash
perl -le 'for($j=999;$j>99;--$j){for($i=999;$i>99;--$i){$v=$j*$i;if(substr($v,0,3)==reverse(substr($v,3,3))){print \"$v=$i*$j\"}}}'|sort -rn
