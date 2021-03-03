#!/bin/bash

# Blaine Mason
# Lab-2
# task8.sh

if [ $# -le 1 ]; then
    echo "You must pass two or more arguments"
    exit 1
else
    sum=0
    for arg in $@; do
        temp=`expr $arg % 2` 
        if [ $temp -eq 1 ]; then
            sum=`expr $sum + $arg`
        fi
    done
    echo "The sum of the odd digits = $sum"
fi

exit 0
