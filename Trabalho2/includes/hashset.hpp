#ifndef _I_HASHSET_
#define _I_HASHSET_

#include "structs.hpp"

class HashSetD : DataStructure {
private:
	std::vector<std::vector<Data>> hv;
	static const int hashSize = 65536;
	int rndSeed;

	int hash(Data d)
	{
		int n, i, j, hash = d.nome.size();
		n = hash;
		for (i = 0; i < n; i++)
			hash = (hash * (d.nome[i] - 65 + i)) % hashSize;

		n = d.sobrenome.size();
		for (j = 0; i < n; i++)
			hash = (hash * (d.nome[i] - 65 + i + j)) % hashSize;

		return hash;
	}

public:
	HashSetD()
	{
		srand(time(NULL));
		rndSeed = hashSize + (rand() % hashSize);
		hv = std::vector<std::vector<Data>>(hashSize, std::vector<Data>(0));
	}

	void insert(Data d)
	{
		int h = hash(d);
		hv[h].push_back(d);
	}
	
	int find(Data d)
	{
		int i, h = hash(d);
		for (i = 0; i < hv[h].size(); i++)
			if (d == hv[h][i])
				return i;

		return -1;
	}
};

#endif
