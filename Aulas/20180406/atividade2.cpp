#include <vector>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <iostream>

#define MAX(a,b) ((a>b)?a:b)

using namespace std;

typedef vector<vector<int> > vvi;

void expo(int a, int b){
	clock_t begin = clock();
	// Cálculo começa aqui;
	// Sim, o valor resultante pode estourar o tipo, mas o tempo
	// nessa operação não é afetado por isso.
	long long res = 1; // --------------- O(1) +
	for(int i = 0; i < b; i++){	// ------ O(n) *
		res *= a; // ------------------------ O(1)
	}
	// Cálculo termina aqui;
	// Complexidade de tempo: O(1) + O(n) * O(1) = O(MAX(1, n * 1)) = O(n);
	clock_t end = clock();
	double time = double(end - begin) / CLOCKS_PER_SEC;
	printf("Exponenciação: O(n)\nTempo: %.6f segundos\n", time);
}

void matrix_multi(vvi &a, vvi &b){
	clock_t begin = clock();
	// Cálculo começa aqui;
	int na = a.size(); // --------------------- O(1) + 
	int nb = b.size(); // --------------------- O(1) +
	vvi res(na, vector<int> (na)); // --------- O(n) + 
	for(int i = 0; i < na; i++){ // ----------- O(n) *
		for(int j = 0; j < na; j++){ // ----------- O(n) *
			int temp = 0; // -------------------------- O(1) +
			for(int k = 0; k < na; k++){ // ----------- O(n) *
				temp += a[i][k] * b[k][j]; // ------------- O(1)
			}
			res[i][j] = temp; // ---------------------- O(1) +
		}
	}
	// Cálculo termina aqui;
	// Complexidade de tempo: O(1) + O(1) + O(n) + O(n) * O(n) * (O(1) + O(n) * O(1) + O(1) =
	//  = O(MAX(1,1,n,(n*n*(MAX(1,n,1))))) = O(MAX(1,1,n,n^3)) = O(n^3);
	clock_t end = clock();
	double time = double(end - begin) / CLOCKS_PER_SEC;
	printf("Produto Matricial: O(n³)\nTempo: %.6f segundos\n", time);
}

int main(){
	srand(time(NULL));
	int a = 2, n;

	cout << "Forneça um inteiro para n:\n";
	cin >> n;

	expo(a, n);
	vvi res(n, vector<int>(n));
	vvi res2(n, vector<int>(n));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			res[i][j] = rand() % 6;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			res2[i][j] = rand() % 6;
		}
	}

	matrix_multi(res, res2);
	
	return 0;
}