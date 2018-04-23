#ifndef _I_HASHSET_
#define _I_HASHSET_

#include "structs.hpp"

class HashSetD : DataStructure {
private:
	std::vector<std::vector<Data> > hv;
	static const int hashSize = 65536;
	int rndSeed;

	int hash(Data d)
	{
		int n, i, j;
		long long hash = d.nome.size();
		n = hash;
		for (i = 0; i < n; i++){
			hash = (hash * (d.nome[i] - 'a' + i)) % hashSize;
			if(hash < 0) hash *= -1;
		}

		n = d.sobrenome.size();
		for (j = 0; j < n; j++){
			hash = (hash * (d.nome[i] - 'a' + i + j)) % hashSize;
			if(hash < 0) hash *= -1;
		}

		return hash % hashSize;
	}

public:
	HashSetD()
	{
		srand(time(NULL));
		rndSeed = hashSize + (rand() % hashSize);
		hv = std::vector<std::vector<Data>>(hashSize, std::vector<Data>());
	}

	void insert(Data d)
	{
		int h = hash(d);
		hv[h].emplace_back(d);
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
