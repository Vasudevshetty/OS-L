#!/bin/bash

echo "Enter three numbers to find the largest "
read num1 num2 num3

if [ $num1 -gt $num2 ]; then
    if [ $num1 -gt $num3 ]; then
        echo "$num1 is greater"
    else echo "$num3 is greater"
    fi
elif [ $num2 -gt $num3 ]; then
    echo "$num2 is greater"
else echo "$num3 is greater"
fi