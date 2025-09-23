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


// Coste: N log N

struct Paciente {
	string nombre; // Nombre del paciente
	int gravedad; // Gravedad del paciente
	int t_espera; // Cuento tiempo lleva esperando el paciente
};

bool operator < (Paciente const& a, Paciente const& b) {
	return a.gravedad < b.gravedad || (a.gravedad == b.gravedad && a.t_espera < b.t_espera);
}

bool resuelveCaso() {

	int n;
	cin >> n;

	if (n == 0) {
		return false;
	}
	priority_queue<Paciente> pacientes;

	for (int i = n; i > 0; i--) {
		char tipo;
		cin >> tipo;

		if (tipo == 'I') {
			string nombre;
			int gravedad;
			cin >> nombre >> gravedad;

			pacientes.push({ nombre, gravedad, i });
		}

		if (tipo == 'A') {
			cout << pacientes.top().nombre << endl;
			pacientes.pop();
		}
	}

	cout << "---" << endl;

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
