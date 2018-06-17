#!/usr/bin/env python3
#! coding=UTF-8 !

import math
import random

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
	for i in range(max, 0, -1):
		if crivo[i] == True:
			return i
	return 1


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


'''
fermat(candidato, tentativas)
retorna True se candidato é possível primo ou
False se candidato eh nao-primo
'''
def fermat(candidato, tentativas):
	tentativas = min(candidato, tentativas)
	for i in range(0, tentativas):
		if not witness(candidato):
			return False
	return True


'''
witness(a, p)
retorna True se (a^p-1)%p = 1, para qualquer a em [1, p[
se não, retorna False
'''
def witness(p):
	if (p <= 3): return True
	a = random.randint(2, p-1)
	left = modexp(a, p-1, p)
	right = 1 # eh 1, mas pra garantir :D
	if left != right:
		print("falso com a = {}".format(a))
	return left == right
