#include <iostream>
#include <vector>
#include <chrono>
#define MAX 10000

using namespace std;

int main()
{
	int valor = 0;
	//Vector A
	vector<vector<double>> A(MAX);
	for (auto & fila : A) {
		fila.resize(MAX, valor);
		valor++;
	}
	
	//Vector x, Vector y
	vector<double> x(MAX, 0), y(MAX, 0);

	//Primera prueba
	auto t0 = chrono::high_resolution_clock::now();
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			y[i] += A[i][j] * x[j];
		}
	}
	auto t1 = chrono::high_resolution_clock::now();

	double tiempo = chrono::duration<double, milli>(t1 - t0).count();
	cout << "Primera prueba: " << tiempo << "\n";

	//Segunda prueba
	t0 = chrono::high_resolution_clock::now();
	for (int j = 0; j < MAX; ++j) {
		for (int i = 0; i < MAX; ++i) {
			y[i] += A[i][j] * x[j];
		}
	}
	t1 = chrono::high_resolution_clock::now();

	tiempo = chrono::duration<double, milli>(t1 - t0).count();
	cout << "Segunda prueba: " << tiempo << "\n";

}