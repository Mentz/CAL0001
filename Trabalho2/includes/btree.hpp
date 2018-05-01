#ifndef _I_BTREE_
#define _I_BTREE_

#include "structs.hpp"

class BTreeD : DataStructure {
private:
	// std::map usa internamente uma Árvore Rubro-Negra
	std::map<std::pair<std::string, std::string>, int> m;

public:
	BTreeD(){};

	void insert(Data d)
	{
		m[make_pair(d.nome, d.sobrenome)] = d.ordem;
	}

	int find(Data d)
	{
		if (m.find(make_pair(d.nome, d.sobrenome)) != m.end())
			return m[make_pair(d.nome, d.sobrenome)];
		return -1;
	}
};

#endif
