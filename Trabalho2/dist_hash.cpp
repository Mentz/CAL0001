/****************************
* Código de:                *
*     Felipe Weiss          *
*     Lucas Litter Mentz    *
*****************************
* Todos direitos reservados *
*  F.Weiss, L.Mentz © 2018  *
****************************/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "includes/structs.hpp"
#include "includes/hashset.hpp"

int main(int argc, char ** argv)
{
	int n, m;
	char f_path[150];
	Data d;
	std::vector<Data> wholeFile, buscas;
	std::ifstream file;

	HashSetD hst;
	// Guardar o arquivo no vetor para desconsiderar tempo de
	//  leitura de arquivo nos testes das estruturas
	sprintf(f_path, "Entradas/entrada-%d.txt", 5);
	file = std::ifstream(f_path, std::ifstream::in);
	file >> n;
	wholeFile = std::vector<Data>(n);
	for (int i = 0; i < n; i++)
	{
		file >> d.ordem >> d.nome >> d.sobrenome;
		wholeFile[i] = d;
	}

	file >> m;
	buscas = std::vector<Data>(m);
	d.ordem = 0;
	for (int i = 0; i < m; i++)
	{
		file >> d.nome >> d.sobrenome;
		buscas[i] = d;
	}

	hst = HashSetD();

	// HashSet - Inserção
	for (int i = 0; i < n; i++)
		hst.insert(wholeFile[i]);

	// HashSet - Medição da distribuição do hash
	std::vector<int> ret = hst.get_dist_hash();

	//printf("Maior: %d Menor: %d\n", *std::max_element(ret.begin(), ret.end()), *std::min_element(ret.begin(), ret.end()));

	for(int i = 0; i < ret.size(); i++){
	 	printf("%d, %d\n", i, ret[i]);
	}

	return 0;
}
