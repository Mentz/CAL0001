/****************************
* Código de:                *
*     Felipe Weiss          *
*     Lucas Litter Mentz    *
*****************************
* Todos direitos reservados *
*  F.Weiss, L.Mentz © 2018  *
****************************/

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include "includes/structs.hpp"
#include "includes/vector.hpp"
#include "includes/avl.hpp"
#include "includes/hashset.hpp"
#include "includes/hashtree.hpp"

int main(int argc, char ** argv)
{
	int n, m;
	char f_path[150];
	Data d;
	std::vector<Data> wholeFile, buscas;
	std::ifstream file;
	clock_t t0, t1;
	double times[12] = {0};

	VectorD vec;
	AVLD avl;
	HashSetD hset;
	HashTreeD htree;
	
	for (int q = 1; q < 6; q++)
	{
		// Guardar o arquivo no vetor para desconsiderar tempo de
		//  leitura de arquivo nos testes das estruturas
		sprintf(f_path, "Entradas/entrada-%d.txt", q);
		printf("Measuring %s now.\n", f_path);
		file = std::ifstream(f_path, std::ifstream::in);
		file >> n;
		printf("There are %d registries there\n", n);
		wholeFile = std::vector<Data>(n);
		for (int i = 0; i < n; i++)
		{
			file >> d.ordem >> d.nome >> d.sobrenome;
			wholeFile[i] = d;
		}
		
		file >> m;
		printf("There are %d queries there\n", m);
		buscas = std::vector<Data>(m);
		d.ordem = 0;
		for (int i = 0; i < m; i++)
		{
			file >> d.nome >> d.sobrenome;
			buscas[i] = d;
		}

		// TODO Embelezar esse código repetido
		// Vector - Medição da inserção
		t0 = clock();
		for (int i = 0; i < n; i++)
			vec.insert(wholeFile[i]);
		t1 = clock();
		times[0] = getSeconds(t0, t1);

		// Vector - Medição da busca
		t0 = clock();
		for (int i = 0; i < n; i++)
			vec.find(buscas[i]);
		t1 = clock();
		times[1] = getSeconds(t0, t1);

		times[2] = times[0] + times[1];

		// AVL - Medição da inserção
		t0 = clock();
		for (int i = 0; i < n; i++)
			avl.insert(wholeFile[i]);
		t1 = clock();
		times[3] = getSeconds(t0, t1);

		// AVL - Medição da busca
		t0 = clock();
		for (int i = 0; i < n; i++)
			avl.find(buscas[i]);
		t1 = clock();
		times[4] = getSeconds(t0, t1);

		times[5] = times[3] + times[4];

		// HashSet - Medição da inserção
		t0 = clock();
		for (int i = 0; i < n; i++)
			hset.insert(wholeFile[i]);
		t1 = clock();
		times[6] = getSeconds(t0, t1);

		// HashSet - Medição da busca
		t0 = clock();
		for (int i = 0; i < n; i++)
			hset.find(buscas[i]);
		t1 = clock();
		times[7] = getSeconds(t0, t1);

		times[8] = times[6] + times[7];

		// HashTree - Medição da inserção
		t0 = clock();
		for (int i = 0; i < n; i++)
			htree.insert(wholeFile[i]);
		t1 = clock();
		times[9] = getSeconds(t0, t1);

		// HashTree - Medição da busca
		t0 = clock();
		for (int i = 0; i < n; i++)
			htree.find(buscas[i]);
		t1 = clock();
		times[10] = getSeconds(t0, t1);

		times[11] = times[9] + times[10];

		// TODO Melhorar impressão dos tempos
		// Imprimir tempos
		std::cout << "Tempos: \n";
		for (int i = 0; i < 12; i++)
			std::cout << times[i] << "s" << ((i % 3) == 0 ? "\n":"    ");
	}

	return 0;
}
