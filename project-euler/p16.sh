#!/bin/bash
echo \"2^1000\" | bc | tr -d '\\n\\\\'| perl -nle 'foreach(unpack(\"w*\")){$s+=$_-48}print $s'
