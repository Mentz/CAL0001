#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

class Estado {
public:
	string jogo;
	int movs;

	Estado()
	{
		jogo = "123456780";
		movs = 0;
	}

	Estado(string j, int c)
	{
		jogo = j;
		movs = c;
	}
};

int solveBFS(string inicial, string final)
{
	map<string, bool> vis;
	Estado davez;
	string novo;
	int pos;
	queue<Estado> fila;
	fila.push(Estado(inicial, 0));
	while (!fila.empty())
	{
		davez = fila.front(); fila.pop();
		//printf("DaVez: %s\n", davez.jogo.data());
		if (davez.jogo == final)
			break;
		pos = davez.jogo.find('0');
		if (pos - 3 > 0) { // Cima
			novo = string(davez.jogo);
			novo[pos] = novo[pos - 3];
			novo[pos - 3] = '0';
			if (vis.find(novo) == vis.end())
			{
				vis[novo] = true;
				fila.push(Estado(novo, davez.movs + 1));
			}
		}
		if (pos + 3 <= 8) { // Baixo
			novo = string(davez.jogo);
			novo[pos] = novo[pos + 3];
			novo[pos + 3] = '0';
			if (vis.find(novo) == vis.end())
			{
				vis[novo] = true;
				fila.push(Estado(novo, davez.movs + 1));
			}
		}
		if (pos - 1 > 0 && pos != 3 && pos != 6) { // Esquerda
			novo = string(davez.jogo);
			novo[pos] = novo[pos - 1];
			novo[pos - 1] = '0';
			if (vis.find(novo) == vis.end())
			{
				vis[novo] = true;
				fila.push(Estado(novo, davez.movs + 1));
			}
		}
		if (pos + 1 <= 8 && pos != 2 && pos != 5) { // Direita
			novo = string(davez.jogo);
			novo[pos] = novo[pos + 1];
			novo[pos + 1] = '0';
			if (vis.find(novo) == vis.end())
			{
				vis[novo] = true;
				fila.push(Estado(novo, davez.movs + 1));
			}
		}
	}
	return davez.movs;
}

int main(int argc, char ** argv)
{
	string s = "103425786";
	cin >> s;
	string f = "123456780";

	printf("Movimentos necessários: %d\n", solveBFS(s, f));

	return 0;
}
