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
#include <climits>


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>




struct Elem {
	int id;
	int pila;
	int pos;

	bool operator>(const Elem& other) const {
		return id > other.id;
	}
};

bool resuelveCaso() {

	int n;
	cin >> n;

	if (!cin) {
		return false;
	}

	vector<vector<int>> pilas(n);
	
	int mejor = INT_MAX;

	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		pilas[i].resize(k);

		for (int j = 0; j < k; j++) {
			cin >> pilas[i][j];
			mejor = min(mejor, pilas[i][j]);
		}
	}

	priority_queue<Elem, vector<Elem>, greater<Elem>> comics;

	for (int i = 0; i < n; i++) {
		int pos = pilas[i].size() - 1;
		comics.push({ pilas[i][pos], i, pos });
	}

	bool encontrado = false;
	int turno = 1;
	while (!encontrado) {
		Elem elem = comics.top();
		comics.pop();

		if (elem.id == mejor) {
			cout << turno << endl;
			encontrado = true;
		}
		else {
			if (elem.pos > 0) {
				comics.push({ pilas[elem.pila][elem.pos - 1], elem.pila, elem.pos - 1 });
			}
		}

		turno++;
	}

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
