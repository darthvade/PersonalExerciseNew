#!/bin/bash
counter=1
while [ $counter -lt 10000 ]
do 
	counter=`expr $counter + 1`
	echo $RANDOM >> ./initfile
done
