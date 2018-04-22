#include <cstdio>
#include <ctime>

#define abs(a) ((a>=0)?a:-a)

using namespace std;

double raiz(double rad, double chute, double intervalo)
{
	double erro = (chute * chute) - rad; //---------------------- O(1)
	if (abs(erro) <= 0.00001) //------------------------------- + O(1)
		return chute; //--------------------------------------- + O(1)
	if (erro > 0) //------------------------------------------ OU O(1)
		return raiz(rad, (chute - intervalo), intervalo/2); //- + T(n/2) + O(1)
	else //--------------------------------------------------- OU O(1)
		return raiz(rad, (chute + intervalo), intervalo/2);//-- + T(n/2) + O(1)
} // Recorrência: T(n) = T(n/2) + O(1); T(1) = O(1).
  // Complexidade: O(log n)

int main(int argc, char ** argv)
{
	double rad;
	printf("Insira o radicando: ");
	scanf("%lf", &rad);
	printf("\n%f\n", raiz(rad, rad, rad/2));

	return 0;
}