#!/bin/bash

sum=0
for ARG in $@; do
  sum=`expr $sum + $ARG`
done

echo "Sum of Arguments is $sum"
exit 0
