#!/bin/bash
new_array=(apple banana carrot dice eagle fine globe hair invoice knie lemon)
for i in $(seq 0 $((${#new_array[@]} - 1)))
do
	echo ${new_array[$i]}
done
