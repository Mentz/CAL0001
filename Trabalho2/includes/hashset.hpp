#ifndef _I_HASHSET_
#define _I_HASHSET_

#include "structs.hpp"

class HashSetD : DataStructure {
private:
	std::vector<std::vector<Data> > hv;
	static const int hashSize = 521;

	unsigned int hash(Data d)
	{
		int n, i, j;
		unsigned int hash = d.nome.size();
		n = hash;
		for (i = 0; i < n; i++) {
			hash = (hash * (d.nome[i] + i) ^ 843273) % hashSize;
			if (hash < 0) hash = -hash;
		}

		n = d.sobrenome.size();
		for (j = 0; j < n; j++) {
			hash = (hash * (d.sobrenome[j] + i + j) ^ 321757) % hashSize;
			if (hash < 0) hash = -hash;
		}

		return hash;
	}

public:
	HashSetD()
	{
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
