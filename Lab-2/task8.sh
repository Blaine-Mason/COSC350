#!/bin/bash

# Blaine Mason
# Lab-2
# task8.sh

if [ $# -ne 1 ]; then
    echo "You must pass only one argument"
    exit 1
else
    n=$1
    sum=0
    while [ $n -gt 0 ]; 
    do
        remainder=`expr $n % 10`
        sum=`expr $sum + $remainder`
        n=`expr $n / 10`
    done
    echo "The sum of the digits of $1 = $sum"
fi

exit 0
