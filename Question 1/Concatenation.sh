#!/bin/bash

#Concatenation of two strings

echo "Enter the strings to concatenate "
read string1
read string2

res=$string1""$string2

echo "The concatinated string is $res"

