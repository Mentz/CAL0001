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
#include "includes/avl.hpp"
#include "includes/hashset.hpp"
#include "includes/hashtree.hpp"

int main(int argc, char ** argv)
{
	int n, m;
	char f_path[150], s_path1[150], s_path2[150], s_path3[150], s_path4[150];
	Data d;
	std::vector<Data> wholeFile, buscas;
	std::ifstream file;
	std::ofstream saida1, saida2, saida3, saida4;

	VectorD vec;
	AVLD avl;
	HashSetD hset;
	HashTreeD htree;

	for (int q = 1; q < 6; q++)
	{
		// Guardar o arquivo no vetor para desconsiderar tempo de
		//  leitura de arquivo nos testes das estruturas
		sprintf(f_path, "Entradas/entrada-%d.txt", q);
		printf("Rodando %s\n", f_path);
		file = std::ifstream(f_path, std::ifstream::in);
		file >> n;
		sprintf(s_path1, "Saidas/saida-%d-1.txt", q);
		sprintf(s_path2, "Saidas/saida-%d-2.txt", q);
		sprintf(s_path3, "Saidas/saida-%d-3.txt", q);
		sprintf(s_path4, "Saidas/saida-%d-4.txt", q);
		saida1 = std::ofstream(s_path1, std::ofstream::out);
		saida2 = std::ofstream(s_path2, std::ofstream::out);
		saida3 = std::ofstream(s_path3, std::ofstream::out);
		saida4 = std::ofstream(s_path4, std::ofstream::out);
		printf("%d registros\n", n);
		wholeFile = std::vector<Data>(n);
		for (int i = 0; i < n; i++)
		{
			file >> d.ordem >> d.nome >> d.sobrenome;
			wholeFile[i] = d;
		}

		file >> m;
		printf("%d buscas\n", m);
		buscas = std::vector<Data>(m);
		d.ordem = 0;
		for (int i = 0; i < m; i++)
		{
			file >> d.nome >> d.sobrenome;
			buscas[i] = d;
		}

		vec = VectorD();
		avl = AVLD();
		hset = HashSetD();
		htree = HashTreeD();

		// TODO Embelezar esse código repetido
		// Vector - inserção
		for (int i = 0; i < n; i++)
			vec.insert(wholeFile[i]);

		// Vector - busca
		for (int i = 0; i < m; i++)
			saida1 << vec.find(buscas[i]) << "\n";

		// AVL - inserção
		for (int i = 0; i < n; i++)
			avl.insert(wholeFile[i]);

		// AVL - busca
		for (int i = 0; i < m; i++)
			saida2 << avl.find(buscas[i]) << "\n";

		// HashSet - inserção
		for (int i = 0; i < n; i++)
			hset.insert(wholeFile[i]);

		// HashSet - busca
		for (int i = 0; i < m; i++)
			saida3 << hset.find(buscas[i]) << "\n";

		// HashTree - inserção
		for (int i = 0; i < n; i++)
			htree.insert(wholeFile[i]);

		// HashTree - busca
		for (int i = 0; i < m; i++)
			saida4 << htree.find(buscas[i]) << "\n";
	}

	return 0;
}
