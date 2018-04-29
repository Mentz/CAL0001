#ifndef _I_VECTOR_
#define _I_VECTOR_

#include "structs.hpp"

class VectorD : DataStructure {
private:
	std::vector<Data> v;

public:
	VectorD(){};

	void insert(Data d)
	{
		v.emplace_back(d.ordem, d.nome, d.sobrenome);
	}

	int find(Data d){
		for (int i = 0; i < v.size(); i++)
			if (d == v[i])
				return v[i].ordem;

		return -1;
	}
};

#endif
