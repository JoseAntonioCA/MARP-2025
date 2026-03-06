/*@ <authors>
 *
 * MARP11 Jose Antonio Carmona Alfonsel
 *
 *@ </authors> */

 /*@ <COSTE>
   *
   * O (N*N)
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

int suma_casillas(int i, int j, Matriz<int>& C, const Matriz<int>& tablero) {
    if (j < 0 || i < 0 || tablero.numcols() <= j || tablero.numfils() <= i) return 0;
    else if (i == 0) return tablero[i][j];
    else if (C[i][j] != -1) return C[i][j];
    else {

        int izquierda = suma_casillas(i - 1, j - 1, C, tablero);
        int arriba = suma_casillas(i - 1, j, C, tablero);
        int derecha = suma_casillas(i - 1, j + 1, C, tablero);

        int val1 = max(izquierda, derecha);
        int val2 = max(val1, arriba);

        C[i][j] = tablero[i][j] + val2;
        return C[i][j];
    }
}


bool resuelveCaso() {

    int N;
    cin >> N;

    if (!cin)
        return false;

    Matriz<int> tablero(N, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> tablero[i][j];
        }
    }

    Matriz<int> C(N, N, -1);

    int mayorValor = 0;
    int col = 0;

    for (int j = 0; j < N; j++) {
        int valor = suma_casillas(N - 1, j, C, tablero);
        if (valor > mayorValor) {
            mayorValor = valor;
            col = j+1;
        }
    }

    cout << mayorValor << " " << col << endl;



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
