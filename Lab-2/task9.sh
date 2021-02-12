#!/bin/bash

# Blaine Mason
# Lab-2
# task9.sh

echo "Enter the directory you want to search:"
read dir
if [ ${dir:0:1} == '~' ]; then
    dir="${HOME}/${dir:2:}"
fi

if [ ! -d $dir ]; then
    echo "Invalid Directory!"
    exit 1
fi

attempt=0

while [ $attempt -lt 3 ];
do  
    echo "Enter the name of the file to search for"
    read search
    echo "$dir$search"
    if [ -e "$dir$search" ]; then
        break
    else
        attempt=`expr $attempt + 1`
    fi
done
if [ $attempt -eq 3 ];
then 
    exit 2
fi

if ! [ -r "$dir/$search" ];
then 
    exit 3
fi

echo "Enter the word you would like to search for:"
read word

if [ -z "$(grep $word "$dir/$search")" ];
then 
    echo "$word NOT FOUND!"
    exit 4
else
    echo "$word FOUND!"
    exit 0
fi