#!/bin/bash

for i in `seq 1 5`; do
	for j in `seq 1 4`;	do
		diff -w Saidas/saida-$i.txt Saidas/saida-$i-$j.txt &> /dev/null
		if [ $? -ne 0 ]; then
			printf "Erro no algoritmo %d, teste %d\n" $j $i
		fi
	done
done
