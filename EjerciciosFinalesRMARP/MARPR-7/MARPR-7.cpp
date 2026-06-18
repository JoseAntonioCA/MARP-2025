
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

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
//Coste O(N*M(
int rec(Matriz<int>& C, int i, int j, Matriz<int>& tab)
{
    if (i >= tab.numfils() || j >= tab.numcols())
        return 0;
    if (C[i][j] != -1)
        return C[i][j];
    if (i == tab.numfils() - 1 && j == tab.numcols() - 1)
    {
        return 1;
    }
    else
    {
        C[i][j] = rec(C, i + tab[i][j], j, tab) + rec(C, i, j + tab[i][j], tab);
    }
    return C[i][j];
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int n, m;
    cin >> n >> m;
    if (!std::cin)  // fin de la entrada
        return false;
    Matriz<int>tab(n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tab[i][j];
        }
    }
    Matriz<int>C(n, m, -1);
    cout << rec(C, 0, 0, tab) << endl;
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}