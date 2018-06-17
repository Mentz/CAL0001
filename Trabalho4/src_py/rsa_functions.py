#!/usr/bin/env python3

import math

'''
erastostenes(max)
retorna o maior primo menor que max
'''
def erastostenes(max):
	crivo = [True]*(max+1)
	sqmax = int(math.sqrt(max))
	for i in range(2, sqmax + 1):
		for j in range(2*i, max + 1, i):
			crivo[j] = False

	if max % 2 == 0: max -= 1
	for i in range(max+1, 0, -1):
		if crivo[i] == True:
			return i
	return 1


'''
millerrabin(candidato)
retorna True se candidato é possível primo ou
False se candidato é não-primo
'''



'''
modexp(base, exp, mod)
Realiza exponenciação modular
retorna (base^exp) % mod
'''
def modexp(base, exp, mod):
	m = mod
	pot = base
	e = exp
	res = 1
	while e > 0:
		if (e%2) == 1:
			res = (res * pot) % m
		pot = (pot * pot) % m
		e = e // 2

	return res
