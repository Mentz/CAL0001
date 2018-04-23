#ifndef _I_AVL_
#define _I_AVL_

#include "structs.hpp"

class AVLD : DataStructure {
private:
	// TODO Mudar para uma AVL de verdade
	std::map<std::pair<std::string, std::string>, int> m;

public:
	AVLD(){};

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
