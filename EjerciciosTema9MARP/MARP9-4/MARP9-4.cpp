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

bool resuelveCaso() {

    // leemos la entrada
    int P, N;
    cin >> P >> N;
    if (!cin) return false;
    vector<int> personas = vector<int>();

    for (int i = 0; i < N; ++i) {
        int e;
        cin >> e;
        personas.push_back(e);
    }

    sort(personas.begin(), personas.end(), greater<int>());

    int i = 0;
    int nSillas = N;
    int j = N - 1;

    while (i < j) {
        int peso = personas[i] + personas[j];
        if (peso <= P) {
            nSillas--;
            i++;
            j--;
        }
        else {
            i++;
        }
    }

    cout << nSillas << endl;

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