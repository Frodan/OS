#!/bin/bash

while true
do
	LOCK=numbers.lock;
	if [ -f $LOCK ]; then
		exit 6
	fi
	touch $LOCK
	NUMBER=$(tail -n 1 numbers)
	NEW_NUMBER=$((NUMBER + 1));
	echo $NEW_NUMBER >> numbers;
	rm -f $LOCK
done
