#!/bin/bash
filename="sites.txt"

while read -r line 
do
   wget -P /home/anderson/Documentos $line 
done < "sites.txt"
