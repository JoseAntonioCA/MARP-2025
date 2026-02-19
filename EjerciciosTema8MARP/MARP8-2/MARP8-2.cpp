/*@ <authors>
 *
 * MARP11 José Antonio Carmona Alfonsel
 *
 *@ </authors> */


 /*@ <COSTE>
  *
  *
  *@ </COSTE> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;

//Coste: O(N log N) por la ordenacion

bool resuelveCaso() {

    // leemos la entrada
    int N;
    cin >> N;
    if (!cin) return false;
    vector<int> enemigos = vector<int>();
    vector<int> aliados = vector<int>();

    for (int i = 0; i < N; ++i) {
        int e;
        cin >> e;
        enemigos.push_back(e);
    }
    for (int i = 0; i < N; ++i) {
        int e;
        cin >> e;
        aliados.push_back(e);
    }

    sort(enemigos.begin(), enemigos.end(), greater<int>());
    sort(aliados.begin(), aliados.end(), greater<int>());

    int nExitos = 0;

    int i = 0;
    int j = 0;

    while (i < N && j < N) {
        if (aliados[i] >= enemigos[j]) {
            nExitos++;
            i++; j++;
        }
        else
            j++;

    }

    cout << nExitos << endl;

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