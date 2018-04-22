#include <cstdio>
#include <ctime>
#include <vector>

using namespace std;

unsigned long long fib_ruim(int n)
{
	if (n <= 1)
		return 1;
	return fib_ruim(n - 1) + fib_ruim(n - 2);
} // Complexidade (aproximado em aula): O(2^n)

vector<unsigned long long> v(1001);

unsigned long long fib_bom(int n)
{
	if (n < 2) //------------------------------------ + O(1)
		return 1; //--------------------------------- + O(1)
	if (v[n] != 0) //-------------------------------- + O(1)
		return v[n]; //------------------------------ + O(1)
	return v[n] = fib_bom(n - 1) + fib_bom(n - 2); // + O(1)
}


int main(int argc, char ** argv)
{
	int n, nmax = 60;
	unsigned long long f;
	double tdiff;
	clock_t start, end;

	for (int n = 25; n <= nmax; n++)
	{
		start = clock();
		f = fib_ruim(n);
		end = clock();
		tdiff = double(end - start)/CLOCKS_PER_SEC;
		printf("%d;%llu;%f\n", n, f, tdiff);
	} printf("----------------------------------------\n");

	for (int n = 25; n <= nmax; n++)
	{
		start = clock();
		f = fib_bom(n);
		end = clock();
		tdiff = double(end - start)/CLOCKS_PER_SEC;
		printf("%d;%llu;%f\n", n, f, tdiff);
	}

	return 0;
}