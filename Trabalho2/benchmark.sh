#!/bin/bash

# Roda 1000 execuções e tira a média deles

for i in `seq 1 10`; do
	./main > Tempos/raw/run$i.csv
done

python avg_results.py
