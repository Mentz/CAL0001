#!/usr/bin/env python2
from sys import argv
import csv

vetins = [0.0000000]*5
vetfnd = [0.0000000]*5
vettot = [0.0000000]*5
avlins = [0.0000000]*5
avlfnd = [0.0000000]*5
avltot = [0.0000000]*5
hstins = [0.0000000]*5
hstfnd = [0.0000000]*5
hsttot = [0.0000000]*5
htrins = [0.0000000]*5
htrfnd = [0.0000000]*5
htrtot = [0.0000000]*5

if len(argv)>1:
	m = int(argv[1])
else:
	m = 10

for i in range(1, m+1):
	c = 0
	with open("Tempos/raw/run%d.csv" % i, "r") as csvfile:
		run = csv.DictReader(csvfile)
		for row in run:
			vetins[c] += float(row['vet-ins'])
			vetfnd[c] += float(row['vet-fnd'])
			vettot[c] += vetins[c] + vetfnd[c]
			avlins[c] += float(row['avl-ins'])
			avlfnd[c] += float(row['avl-fnd'])
			avltot[c] += avlins[c] + avlfnd[c]
			hstins[c] += float(row['hst-ins'])
			hstfnd[c] += float(row['hst-fnd'])
			hsttot[c] += hstins[c] + hstfnd[c]
			htrins[c] += float(row['htr-ins'])
			htrfnd[c] += float(row['htr-fnd'])
			htrtot[c] += htrins[c] + htrfnd[c]
			c = c + 1

for i in range(0, 5):
	vetins[i] /= m
	vetfnd[i] /= m
	vettot[i] /= m
	avlins[i] /= m
	avlfnd[i] /= m
	avltot[i] /= m
	hstins[i] /= m
	hstfnd[i] /= m
	hsttot[i] /= m
	htrins[i] /= m
	htrfnd[i] /= m
	htrtot[i] /= m


# Impressao para stdout dos valores de saida
print("teste vet-ins vet-fnd vet-tot avl-ins avl-fnd avl-tot hst-ins hst-fnd hst-tot htr-ins htr-fnd htr-tot")
for i in range(0, 5):
	print("%s %s %s %s %s %s %s %s %s %s %s %s %s" % (
		str(i + 1),
		str.format("%1.6f" % vetins[i]),
		str.format("%1.6f" % vetfnd[i]),
		str.format("%1.6f" % vettot[i]),
		str.format("%1.6f" % avlins[i]),
		str.format("%1.6f" % avlfnd[i]),
		str.format("%1.6f" % avltot[i]),
		str.format("%1.6f" % hstins[i]),
		str.format("%1.6f" % hstfnd[i]),
		str.format("%1.6f" % hsttot[i]),
		str.format("%1.6f" % htrins[i]),
		str.format("%1.6f" % htrfnd[i]),
		str.format("%1.6f" % htrtot[i])))
