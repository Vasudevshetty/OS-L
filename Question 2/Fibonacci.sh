#!/bin/bash

echo -n "Enter the number : "
read n

first=0
second=1

echo -n $first $second" "

for ((i=0;i<=n;i++)) do
   third=$(($first+$second)) 
   echo -n $third" "
   first=$second
   second=$third
done

