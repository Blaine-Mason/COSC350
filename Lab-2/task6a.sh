#!/bin/bash

# Blaine Mason
# Lab-2 Task 6
echo "Enter the length of the base (Must be odd and > 3): "
read num

if [ `expr $num % 2` -eq 0 ]; then 
  echo "Input for base must be odd" 
  exit 1 
fi
if [ $num -lt 4 ]; then 
    echo “Input must be greater than 3.” 
    exit 2 
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

star=`expr $star - 4`

temp=1
count=`expr $num / 2`
for i in $(seq 1 $count);
do 
  for j in $(seq 1 $temp);
  do
    echo -n " "
  done 
  for k in $(seq 1 $star);
  do
    echo -n "*"
  done
  star=`expr $star - 2`
  temp=`expr $temp + 1` 
  echo
done
exit 0
