#ifndef _I_HASH_
#define _I_HASH_

#include "structs.hpp"

#define MAX_HASH 521

unsigned int hash(Data d)
{
	int n, i, j;
	unsigned int hash = d.nome.size();
	n = hash;
	for (i = 0; i < n; i++) {
		hash = (hash * (d.nome[i] + i) ^ 843273) % MAX_HASH;
		if (hash < 0) hash = -hash;
	}

	n = d.sobrenome.size();
	for (j = 0; j < n; j++) {
		hash = (hash * (d.sobrenome[j] + i + j) ^ 321757) % MAX_HASH;
		if (hash < 0) hash = -hash;
	}

	return hash;
}

#endif
