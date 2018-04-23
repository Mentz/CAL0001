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
		v.emplace_back(d);
	}

	int find(Data d){
		for (int i = 0; i < v.size(); i++)
			if (d == v[i])
				return i;

		return -1;
	}
};

#endif
