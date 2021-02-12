#!/bin/bash

#Blaine Mason
#Lab-2
echo "Enter the length of the tail: "
read tail_
echo "Enter the length of the base (Must be odd): "
read base

space=`expr $base - 1`
star=1
if [ `expr $base % 2` -eq 0 ]; then
  echo "Input for base must be odd"
  exit 1
fi
while [ "$star" -le "$base" ];
do
  for i in $(seq 1 $space);
  do 
    echo -n " "
  done
  for j in $(seq 1 $star);
  do 
    echo -n "*"
  done
  if [ "$star" -eq "$base" ]; then
    for k in $(seq 1 $tail_);
    do
      echo -n "*"
    done
    echo
  else
    echo
  fi
  space=`expr $space - 2`
  star=`expr $star + 2`
done


space=2
star=`expr $base - 2`
while [ "$space" -le "$base" ];
do
  for i in $(seq 1 $space);
  do 
    echo -n " "
  done
  for j in $(seq 1 $star);
  do 
    echo -n "*"
  done
  space=`expr $space + 2`
  star=`expr $star - 2`
  echo
done
exit 0
