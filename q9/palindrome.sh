#!/bin/bash

read -p "Enter a string: " str

# Reverse the string
reverse_str=$(echo "$str" | rev)

# Check if the string is equal to its reverse
if [ "$str" == "$reverse_str" ]; then
    echo "$str is a palindrome."
else
    echo "$str is not a palindrome."
fi
