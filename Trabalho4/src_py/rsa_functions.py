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
euclid(a, b)
retorna o máximo divisor comum (mdc) entre a e b
'''
def euclid(a, b):
	if a < b:
		return euclid(b, a)
	if b == 0:
		return a
	return euclid(b, a-b)


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


'''
gerapublickey(p, q)
retorna uma chave pública composta de um natural (e)
e o produto de (p*q = n)
'''
def gerapublickey(p, q):
	n = (p-1)*(q-1)
	while True:
		e = random.random(2, min(p, q)) # se ficar lento, fixe e=65537
		if euclid(e, n) == 1:
			return (e, n)

