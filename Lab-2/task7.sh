#!/bin/bash

# Blaine Mason
# Lab-2
# task7.sh

echo "Enter a number to calculate factorial: "
read n 

fact=1

while [ $n -lt 0 ];
do
    echo "INVALID ENTRY! MUST BE POSITIVE"
    read n
done

n_=$n
while [ $n_ -gt 0 ];
do
    fact=`expr $fact \* $n_`
    n_=`expr $n_ - 1`
done

echo "$n! = $fact"
exit 0