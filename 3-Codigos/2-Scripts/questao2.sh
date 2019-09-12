#!/bin/bash 
for (( i=1; i<=$#; i+=2 ))
 do
  mes=${!i}
  ano=$(($i+1))
  cal $mes ${!ano}
 done


