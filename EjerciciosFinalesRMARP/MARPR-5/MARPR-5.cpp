
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "Matriz.h"
using namespace std;

//Coste O(K*S)

int rec(Matriz<int>& C, int i, int j, const int& dado)
{
    if (i > dado || j < 0)
        return 0;
    if (C[i][j] != -1)
        return C[i][j];
    if (j == 0)
    {
        return 1;
    }
    else
    {
        C[i][j] = rec(C, i, j - i, dado) + rec(C, i + 1, j, dado);
    }
    return C[i][j];
}
void resuelveCaso() {
    int K, S;

    cin >> K >> S;
    // leer los datos de la entrada

    Matriz<int>C(K + 1, S + 1, -1);
    cout << rec(C, 1, S, K) << endl;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}