#!/bin/bash

if [ $# -ne 2 ]; then
	echo "Error --- usage: $0 <writefile> <writestr>"
	exit 1
fi

mkdir -p $(dirname $1) && echo $2 > $1
if [ $? -ne 0 ]; then
	echo "Error --- can not create $1"
	exit 1
fi

exit 0

