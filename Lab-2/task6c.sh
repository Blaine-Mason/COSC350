#!/bin/bash

# Blaine Mason
# Lab-2 Task 6

echo "Enter the length of the tail: "
read tail_
echo "Enter the length of the base (Must be odd): "
read base

if [ `expr $base % 2` -eq 0 ]; then
  echo "Input for base must be odd"
  exit 1
fi
total=`expr $base + $tail_`
star=1
while [ "$star" -le "$base" ];
do 
  if [ $star -eq $base ]; then
    for k in $(seq 1 $total);
    do
      echo -n "*"
    done
    star=`expr $star + 2`
    echo
  else
    for i in $(seq 1 $tail_);
    do
      echo -n " "
    done
    for j in $(seq 1 $star)
    do 
      echo -n "*"
    done
    star=`expr $star + 2`
    echo
  fi
done

star=`expr $star - 4`

while [ $star -ge 0 ];
do 
  for i in $(seq 1 $tail_);
  do
    echo -n " "
  done
  for j in $(seq 1 $star)
  do 
    echo -n "*"
  done
  star=`expr $star - 2`
  echo
done
exit 0