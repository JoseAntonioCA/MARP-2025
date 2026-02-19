/*@ <authors>
 *
 * MARP11 José Antonio Carmona Alfonsel
 *
 *@ </authors> */


 /*@ <COSTE>
  * 
  * O(N log N) por la ordenacion
  *
  *@ </COSTE> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;


bool resuelveCaso() {

    // leemos la entrada
    int N, M;
    cin >> N;
    if (!cin) return false;
    cin >> M;
    vector<int> Tjugadores = vector<int>();
    vector<int> Tprendas = vector<int>();

    for (int i = 0; i < N; ++i) {
        int e;
        cin >> e;
        Tjugadores.push_back(e);
    }
    for (int i = 0; i < M; ++i) {
        int e;
        cin >> e;
        Tprendas.push_back(e);
    }

    sort(Tjugadores.begin(), Tjugadores.end(), less<int>());
    sort(Tprendas.begin(), Tprendas.end(), less<int>());

    int nExitos = 0;

    int i = 0;
    int j = 0;

    while (i < N && j < M) {

        if (Tprendas[j] < Tjugadores[i]) {
            // prenda demasiado pequeña
            j++;
        }
        else if (Tprendas[j] > Tjugadores[i] + 1) {
            // prenda demasiado grande
            i++;
        }
        else {
            // válida
            i++;
            j++;
        }
    }


    cout << N - i << endl;

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