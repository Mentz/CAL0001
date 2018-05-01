#!/usr/bin/env python2
from sys import argv
import csv

vetins = [0.0000000]*5
vetfnd = [0.0000000]*5
vettot = [0.0000000]*5
btrins = [0.0000000]*5
btrfnd = [0.0000000]*5
btrtot = [0.0000000]*5
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
			btrins[c] += float(row['btr-ins'])
			btrfnd[c] += float(row['btr-fnd'])
			hstins[c] += float(row['hst-ins'])
			hstfnd[c] += float(row['hst-fnd'])
			htrins[c] += float(row['htr-ins'])
			htrfnd[c] += float(row['htr-fnd'])
			c = c + 1
	for j in range(0, 5):
		vettot[j] += vetins[j] + vetfnd[j]
		btrtot[j] += btrins[j] + btrfnd[j]
		hsttot[j] += hstins[j] + hstfnd[j]
		htrtot[j] += htrins[j] + htrfnd[j]

for i in range(0, 5):
	vetins[i] /= m
	vetfnd[i] /= m
	vettot[i] /= m
	btrins[i] /= m
	btrfnd[i] /= m
	btrtot[i] /= m
	hstins[i] /= m
	hstfnd[i] /= m
	hsttot[i] /= m
	htrins[i] /= m
	htrfnd[i] /= m
	htrtot[i] /= m


# Impressao para stdout dos valores de saida
#print("teste vet-ins vet-fnd vet-tot btr-ins btr-fnd btr-tot hst-ins hst-fnd hst-tot htr-ins htr-fnd htr-tot")
print("teste vet-ins vet-fnd btr-ins btr-fnd hst-ins hst-fnd htr-ins htr-fnd")
for i in range(0, 5):
	#print("%s %s %s %s %s %s %s %s %s %s %s %s %s" % (
	print("%s %s %s %s %s %s %s %s %s" % (
		str(i + 1),
		str.format("%1.6f" % vetins[i]),
		str.format("%1.6f" % vetfnd[i]),
		#str.format("%1.6f" % vettot[i]),
		str.format("%1.6f" % btrins[i]),
		str.format("%1.6f" % btrfnd[i]),
		#str.format("%1.6f" % btrtot[i]),
		str.format("%1.6f" % hstins[i]),
		str.format("%1.6f" % hstfnd[i]),
		#str.format("%1.6f" % hsttot[i]),
		str.format("%1.6f" % htrins[i]),
		str.format("%1.6f" % htrfnd[i]),
		#str.format("%1.6f" % htrtot[i])
		))
