#!/bin/bash

echo "Enter the length of the base (Must be odd and > 3): "
read num
if [ `expr $num % 2` -eq 0 ]; then
    if [ $num -le 3 ]; then
        echo "Input must be greater than 3."
        exit 2
    fi
  echo "Input for base must be odd"
  exit 1
fi
temp=`expr $num / 2`
star=1
for i in $(seq 0 $temp);
do
  for j in $(seq 1 $temp);
  do
    echo -n " "
  done
  for k in $(seq 1 $star);
  do
    echo -n "*"
  done
  star=`expr $star + 2`
  temp=`expr $temp - 1`
  echo 
done