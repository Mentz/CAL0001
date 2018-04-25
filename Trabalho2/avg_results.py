#!/usr/bin/env python2
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

m = 1

for i in range(1, m+1):
	c = 0
	with open("Tempos/raw/run%d.csv" % i, "r") as csvfile:
		run = csv.DictReader(csvfile)
		for row in run:
			vetins[c] += row['vet-ins']
			vetfnd[c] += row['vet-fnd']
			vettot[c] += vetins[c] + vetfnd[c]
			avlins[c] += row['avl-ins']
			avlfnd[c] += row['avl-fnd']
			avltot[c] += avlins[c] + avlfnd[c]
			hstins[c] += row['hst-ins']
			hstfnd[c] += row['hst-fnd']
			hsttot[c] += hstins[c] + hstfnd[c]
			htrins[c] += row['htr-ins']
			htrfnd[c] += row['htr-fnd']
			htrtot[c] += htrins[c] + htrfnd[c]
			c = c + 1

for i in range(1, 6):
	vetins[c] /= m
	vetfnd[c] /= m
	vettot[c] /= m
	avlins[c] /= m
	avlfnd[c] /= m
	avltot[c] /= m
	hstins[c] /= m
	hstfnd[c] /= m
	hsttot[c] /= m
	htrins[c] /= m
	htrfnd[c] /= m
	htrtot[c] /= m

with open("Tempos/media.csv", "w") as outfile:
	fieldnames = ['teste','vet-ins','vet-fnd','vet-tot','avl-ins','avl-fnd','avl-tot','hst-ins','hst-fnd','hst-tot','htr-ins','htr-fnd','htr-tot']
	outcsv = csv.DictWriter(outfile, fieldnames=fieldnames)
	outcsv.writeheader()
	for i in range(1, 6):
		outcsv.writerow({str(i), vetins[i], vetfnd[i], vettot[i], avlins[i], avlfnd[i], avltot[i], hstins[i], hstfnd[i], hsttot[i], htrins[i], htrfnd[i], htrtot[i]})
