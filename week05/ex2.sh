#!/bin/bash

FILE=numbers;
LOCK=numbers.lock;

if [ ! -f $FILE ]; then
  echo "0" >> $FILE;
fi

while true
do
	if [ -f $LOCK ]; then
		exit 6
	fi
	touch $LOCK

	NUMBER=$(tail -n 1 $FILE)
	NEW_NUMBER=$((NUMBER + 1));
	echo $NEW_NUMBER >> $FILE;
	rm -f $LOCK
done
