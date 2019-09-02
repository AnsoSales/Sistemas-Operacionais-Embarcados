#!/bin/bash
source up.sh
n=$1
caminho=$PWD
cd $caminho
echo $n
echo $caminho
for ((i=1; i<=n; i++))
do
cd ..
done

