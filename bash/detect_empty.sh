#!/bin/bash
X=""
#if [ -n $X]; then	# This gives the wrong answer
#if [ -n "$X"]; then	# This also gives the wrong answer
#if [ -n "$X" ]
if test -n "$X" 
then	# -n tests to see if the argument is non empty
	echo "The variable X is not the empty string"
else
	echo "The variable X IS the empty string"
fi
