#ifndef _I_HASHSET_
#define _I_HASHSET_

#include "structs.hpp"

class HashSetD : DataStructure {
private:
	std::vector<std::vector<Data> > hv;
	static const int hashSize = 8193;
	int rndSeed;

	unsigned int hash(Data d)
	{
		int n, i, j;
		unsigned int hash = d.nome.size();
		n = hash;
		for (i = 0; i < n; i++) {
			hash = (hash * (d.nome[i] + i) ^ 54059) % hashSize;
		}

		n = d.sobrenome.size();
		for (j = 0; j < n; j++) {
			hash = (hash * (d.sobrenome[j] + i + j) ^ 76963) % hashSize;
		}

		return hash;
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
		hv[h].emplace_back(d.ordem, d.nome, d.sobrenome);
	}

	int find(Data d)
	{
		int i, h = hash(d);
		for (i = 0; i < hv[h].size(); i++)
			if (d == hv[h][i])
				return hv[h][i].ordem;

		return -1;
	}

	std::vector<int> get_dist_hash(){
		std::vector<int> ret(hashSize);
		int cnt = 0;
		for(auto &a : hv){
			ret[cnt++] = a.size();
		}
		return ret;
	}
};

#endif
