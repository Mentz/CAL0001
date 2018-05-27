#!/usr/bin/python3

moedas = [1, 3, 4]

def coinChange(n):
	T = [0]
	for i in range(1, n+1):
		mm = 4294967296
		for m in moedas:
			if i-m >= 0:
				mm = min(mm, 1 + T[i-m])
		T.append(mm)
	return T[n]

if __name__ == "__main__":
	n = input("Quantos cents de troco?")
	print("Troco: " + str(coinChange(n)))
