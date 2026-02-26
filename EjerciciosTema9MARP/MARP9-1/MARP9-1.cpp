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
#include "ConjuntosDisjuntos.h"
using namespace std;

struct Edificio {
    int pW;
    int pE;
    int id;
};
bool operator<(Edificio a, Edificio b) {
    return a.pE < b.pE;
}
// las tareas están ordenadas de mayor a menor beneficio
int resolver(vector<Edificio> const& edificios) {
    int N = edificios.size(); // número de edificios
    int ultimoPE = -1;
    int nEdificios = 0;
    
    // recorrer las tareas de mayor a menor beneficio
    for (int i = 0; i < N; ++i) {
        if (edificios[i].pW >= ultimoPE) {
            nEdificios++;
            ultimoPE = edificios[i].pE;
        }
    }
    return nEdificios;
}

bool resuelveCaso() {

    // leemos la entrada
    int N;
    cin >> N;
    if (N == 0) return false;
    vector<Edificio> edificios = vector<Edificio>();

    int longE = 0;

    for (int i = 0; i < N; ++i) {
        int pW, pE;
        cin >> pW >> pE;
        longE = pE;
        edificios.push_back({pW, pE, i});
    }

    sort(edificios.begin(), edificios.end());


    cout << resolver(edificios) << endl;


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