/*@ <authors>
 *
 * MARP11 José Antonio Carmona Alfonsel
 *
 *@ </authors> */


 /*@ <COSTE>
  *
  * O (N log N)
  *
  *@ </COSTE> */

#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;

void resuelveCaso() {

    // leemos la entrada
    int N, V;
    cin >> N >> V;
    vector<int> pilas = vector<int>();

    for (int i = 0; i < N; ++i) {
        int e;
        cin >> e;
        pilas.push_back(e);
    }

    sort(pilas.begin(), pilas.end(), greater<int>());

    int i = 0;
    int nCoches = 0;
    int j = N - 1;

    while (i < j) {
        int voltaje = pilas[i] + pilas[j];
        if (voltaje >= V) {
            nCoches++;
            i++;
            j--;
        }
        else {
            j--;
        }
    }

    cout << nCoches << endl;
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
    int nCasos;
    cin >> nCasos;
    for (int i = 0; i < nCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
#endif
    return 0;
}