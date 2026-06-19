
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include "Matriz.h"
using namespace std;

const long long int INF = 1e9;


//Coste O (N^3)

int rec(Matriz<int>& C, vector<vector<int>>& pueblos, int i, int j)
{
    if (i >= pueblos.size())
    {
        return 0;
    }
    if (C[i][j] != INF)
    {
        return C[i][j];
    }
    else
    {
        int aux = pueblos[i][j];
        for (int k = i+1; k < j ;k++)
        {
            aux = min(aux, pueblos[i][k] + rec(C, pueblos, k, j));
        }
        C[i][j] = aux;
        return C[i][j];
    }
}

void resultado(vector<vector<int>>& pueblos)
{
    Matriz<int> C(pueblos.size(), pueblos.size(), INF);
    for (int i = 0; i < pueblos.size(); i++)
    {
        for (int j = i+1; j < pueblos.size(); j++)
        {
            cout << rec(C, pueblos, i, j) << " ";
        }
        cout << endl;
    }
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<vector<int>> pueblos(N, vector<int>(N, 0));

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            cin >> pueblos[i][j];
        }
    }
    resultado(pueblos);
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