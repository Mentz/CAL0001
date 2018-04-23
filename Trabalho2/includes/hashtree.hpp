#ifndef _I_HASHTREE_
#define _I_HASHTREE_

#include "structs.hpp"

class HashTreeD : DataStructure {
private:
	std::vector<std::map<std::pair<std::string, std::string>, int> > ht;
	static const int hashSize = 65536;
	int rndSeed;

	int hash(Data d)
	{
		int n, i, j;
		long long hash = d.nome.size();
		n = hash;
		for (i = 0; i < n; i++){
			hash = (rndSeed * hash * (d.nome[i] + i)) % hashSize;
			if(hash < 0) hash *= -1;
		}

		n = d.sobrenome.size();
		for (j = 0; i < n; i++){
			hash = (rndSeed * hash * (d.nome[i] + i + j)) % hashSize;
			if(hash < 0) hash *= -1;
		}

		return hash;
	}

public:
	HashTreeD()
	{
		srand(time(NULL));
		rndSeed = hashSize + (rand() % hashSize);
		ht = std::vector<std::map<std::pair<std::string, std::string>, int> >
				(hashSize, std::map<std::pair<std::string, std::string>, int>());
	}

	void insert(Data d)
	{
		int h = hash(d);
		ht[h][make_pair(d.nome, d.sobrenome)] = d.ordem;
	}

	int find(Data d)
	{
		int h = hash(d);
		if (ht[h].find(make_pair(d.nome, d.sobrenome)) != ht[h].end())
			return ht[h][make_pair(d.nome, d.sobrenome)];

		return -1;
	}
};

#endif
