#include <cstdio>
#include <string>
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
	Estado davez;
	string novo;
	int pos;
	queue<Estado> fila;
	fila.emplace(Estado(inicial, 0));
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
			fila.emplace(Estado(novo, davez.movs + 1));
		}
		if (pos + 3 <= 8) { // Baixo
			novo = string(davez.jogo);
			novo[pos] = novo[pos + 3];
			novo[pos + 3] = '0';
			fila.emplace(Estado(novo, davez.movs + 1));
		}
		if (pos - 1 > 0) { // Esquerda
			novo = string(davez.jogo);
			novo[pos] = novo[pos - 1];
			novo[pos - 1] = '0';
			fila.emplace(Estado(novo, davez.movs + 1));
		}
		if (pos + 1 <= 8) { // Direita
			novo = string(davez.jogo);
			novo[pos] = novo[pos + 1];
			novo[pos + 1] = '0';
			fila.emplace(Estado(novo, davez.movs + 1));
		}
	}
	return davez.movs;
}

int main(int argc, char ** argv)
{
	string s = "103425786";
	string f = "123456780";

	printf("Movimentos necessários: %d\n", solveBFS(s, f));

	return 0;
}