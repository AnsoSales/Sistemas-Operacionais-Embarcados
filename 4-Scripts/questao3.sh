#!/bin/bash
for ((i = 2019; i>= 2009; i--))
   do
	mes=$1
	dia=$2
	ncal $mes $i | grep -w $dia
	
   done
