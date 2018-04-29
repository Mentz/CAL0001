#!/bin/bash

# Roda 1000 execuções e tira a média deles

M=1000

for i in `seq 1 $M`; do
	./main > Tempos/raw/run$i.csv
done

python avg_results.py $M > Tempos/average.dat

gnuplot -c "Scripts/tempos.gnu"
