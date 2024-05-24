#!/bin/bash

echo "Enter strings to compare " 
read str1
read str2

if [ $str1 == $str2 ]; then
    echo "Strings are equal "
elif [ $str1 -gt $str2 ]; then
    echo "String 1 is greater than string 2"
else echo "String 1 is lesser than string 2"
fi