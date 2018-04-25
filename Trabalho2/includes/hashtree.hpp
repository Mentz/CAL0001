#ifndef _I_HASHTREE_
#define _I_HASHTREE_

#include "structs.hpp"

class HashTreeD : DataStructure {
private:
	std::vector<std::map<std::pair<std::string, std::string>, int> > ht;
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

	std::vector<int> get_dist_hash(){
		std::vector<int> ret(hashSize);
		int cnt = 0;
		for(auto &a : ht){
			ret[cnt++] = a.size();
		}
		return ret;
	}
};

#endif
