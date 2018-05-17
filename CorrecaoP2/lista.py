# coding: utf8

def calculaBairrosRicos(matriz, p):
	viz = []
	i = 0
	# O(v)
	for line in matriz:
		soma = 0.0
		conta = 0
		# O(e) -- no total faz 2*e, não é v*e
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
# Complexidade total: O(v + e + (v*log v) + p)
#	= O(e + v*log v)

if __name__ == "__main__":
	p = 2
	mat = [[2,  5],
		   [2, 14, 5, 4],
		   [14, 34],
		   [5, 5, 58],
		   [4, 34, 58]]
	viz = calculaBairrosRicos(mat, p)
	print(p),
	print("vizinhancas mais ricas:")
	print(viz)
