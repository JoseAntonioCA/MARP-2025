/*@ <authors>
 *
 * MARP11 Jose Antonio Carmona Alfonsel
 *
 *@ </authors> */

 /*@ <COSTE>
   *
   * O (N*M)
   *
   *@ </COSTE> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Matriz.h"
using namespace std;

/*@ <answer>

 Sustituye este párrafo por un comentario general sobre la solución,
 explicando cómo se resuelve el problema y cuál es el coste de la solución,
 en función del tamaño del problema.

 @ </answer> */

int num_combi(int i, int j, Matriz<int>& C, const Matriz<char>& intersecciones) {
    if (j < 0 || i < 0) return 0;
    else if (j == 0 && i == 0) return 1;
    else if (intersecciones[i][j] == 'X') return 0;
    else if (C[i][j] != -1) return C[i][j];
    else {
        C[i][j] = num_combi(i - 1, j, C, intersecciones) + num_combi(i, j - 1, C, intersecciones);
        return C[i][j];
    }
}


bool resuelveCaso() {

    int N, M;
    cin >> N >> M;

    if (!cin)
        return false;

    Matriz<char> intersecciones(N, M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> intersecciones[i][j];
        }
    }

    Matriz<int> C(N, M, -1);

    cout << num_combi(N - 1, M - 1, C, intersecciones) << endl;



    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    if (!in.is_open())
        cout << "Error: no se ha podido abrir el archivo de entrada." << endl;
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
#endif
    return 0;
}
