/*@ <authors>
 *
 * José Antonio Carmona Alfonsel - MARP11.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
 //#include <...>

using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


bool resuelveCaso() {

	int n;
	cin >> n;

	if (n == 0) {
		return false;
	}
	priority_queue<int64_t, vector<int64_t>, greater<int64_t >> sumados;

	for (int i = 0; i < n; i++) {
		int64_t sum; cin >> sum;
		sumados.push(sum);
	}

	int64_t total = 0;

	while (sumados.size() > 1) {
		auto a = sumados.top(); sumados.pop();
		auto b = sumados.top(); sumados.pop();
		int64_t suma = a + b;
		total += suma;
		sumados.push(suma);
	}

	cout << total << endl;

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	if (!in.is_open())
		std::cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio y parar antes de salir
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	std::cout << "Pulsa Intro para salir..." << std::flush;
	std::cin.get();
#endif

	return 0;
}
