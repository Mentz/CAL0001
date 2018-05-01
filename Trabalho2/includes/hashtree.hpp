#ifndef _I_HASHTREE_
#define _I_HASHTREE_

#include "structs.hpp"
#include "hash.hpp"

class HashTreeD : DataStructure {
private:
	std::vector<std::map<std::pair<std::string, std::string>, int> > ht;
	static const int hashSize = MAX_HASH;

public:
	HashTreeD()
	{
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
