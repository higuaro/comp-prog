#!/bin/bash
tr -d '"' < names.txt | tr ',' '\n' | sort | perl -lne '@b=unpack("C*",$_);$s=0;foreach(@b){$s+=$_-64};print "*".$s."+"' | nl
while read l; do 
	echo "($l" | tr '+' ')' | xargs -i echo "{}+" >> f; 
done < r
tr -d '\t' < f | tr -d '\n' > f2

