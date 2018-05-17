# coding: utf8

def calculaBairrosRicos(matriz, p):
	viz = []
	i = 0
	# O(v)
	for line in matriz:
		soma = 0.0
		conta = 0
		# O(v)
		for aresta in line:
			soma += aresta
			if aresta != 0:
				conta += 1
		media = soma / float(conta)
		# O(1) -- usa lista
		viz.append((i, media))
		i += 1
	# O(v*log(v)) -- ordenação estável
	viz.sort(key=lambda v: v[1], reverse=True)
	nviz = []
	# O(p) -- p <= v, sempre
	for i in xrange(0, p):
		nviz.append(viz[i])
	return nviz
# Complexidade total: O(v*v + (v*log v) + p)
#	= O(v²)

if __name__ == "__main__":
	p = 2
	mat = [[0,  2,  0,  5,  0],
		   [2,  0, 14,  5,  4],
		   [0, 14,  0,  0, 34],
		   [5,  5,  0,  0, 58],
		   [0,  4, 34, 58,  0]]
	viz = calculaBairrosRicos(mat, p)
	print(p),
	print("vizinhancas mais ricas:")
	print(viz)
