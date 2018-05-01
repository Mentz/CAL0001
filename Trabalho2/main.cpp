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
#include <fstream>
#include <vector>
#include "includes/structs.hpp"
#include "includes/vector.hpp"
#include "includes/btree.hpp"
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
	double times[8] = {0};

	VectorD vec;
	BTreeD btr;
	HashSetD hst;
	HashTreeD htr;

	printf("%s,%s,%s,%s,%s,%s,%s,%s\n",
			"vet-ins", "vet-fnd", "btr-ins", "btr-fnd",
			"hst-ins", "hst-fnd", "htr-ins", "htr-fnd");
	for (int q = 1; q < 6; q++)
	{
		// Guardar o arquivo no vetor para desconsiderar tempo de
		//  leitura de arquivo nos testes das estruturas
		sprintf(f_path, "Entradas/entrada-%d.txt", q);
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

		vec = VectorD();
		btr = BTreeD();
		hst = HashSetD();
		htr = HashTreeD();

		// TODO Embelezar esse código repetido
		// Vector - Medição da inserção

		t0 = clock();
		for (int i = 0; i < n; i++)
			vec.insert(wholeFile[i]);
		t1 = clock();
		times[0] = getSeconds(t0, t1);

		// Vector - Medição da busca
		t0 = clock();
		for (int i = 0; i < m; i++)
			vec.find(buscas[i]);
		t1 = clock();
		times[1] = getSeconds(t0, t1);

		// AVL - Medição da inserção
		t0 = clock();
		for (int i = 0; i < n; i++)
			btr.insert(wholeFile[i]);
		t1 = clock();
		times[2] = getSeconds(t0, t1);

		// AVL - Medição da busca
		t0 = clock();
		for (int i = 0; i < m; i++)
			btr.find(buscas[i]);
		t1 = clock();
		times[3] = getSeconds(t0, t1);

		// HashSet - Medição da inserção
		t0 = clock();
		for (int i = 0; i < n; i++)
			hst.insert(wholeFile[i]);
		t1 = clock();
		times[4] = getSeconds(t0, t1);

		// HashSet - Medição da busca
		t0 = clock();
		for (int i = 0; i < m; i++)
			hst.find(buscas[i]);
		t1 = clock();
		times[5] = getSeconds(t0, t1);

		// HashTree - Medição da inserção
		t0 = clock();
		for (int i = 0; i < n; i++)
			htr.insert(wholeFile[i]);
		t1 = clock();
		times[6] = getSeconds(t0, t1);

		// HashTree - Medição da busca
		t0 = clock();
		for (int i = 0; i < m; i++)
			htr.find(buscas[i]);
		t1 = clock();
		times[7] = getSeconds(t0, t1);

		// Imprimir tempos em formato CSV
		for (int i = 0; i < 8; i++)
			printf("%s%1.6lf", (i)?",":"", times[i]);
		printf("\n");
	}

	return 0;
}
