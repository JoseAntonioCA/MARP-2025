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

struct Trabajo {
    int c;
    int f;
};
bool operator<(Trabajo a, Trabajo b) {
    return a.c < b.c;
}
// las tareas están ordenadas de mayor a menor beneficio
int resolver(vector<Trabajo> const& trabajos, int C, int F) {
    int N = trabajos.size(); // número de edificios
    int actual = C;
    int nTrabajos = 0;
    int i = 0;

    while (actual < F) {
        int mejorFin = actual;

        while (i < N && trabajos[i].c <= actual) {
            mejorFin = max(mejorFin, trabajos[i].f);
            i++;
        }

        if (mejorFin == actual) {
            return -1;
        }

        actual = mejorFin;
        nTrabajos++;
    }

    
    return nTrabajos;
}

bool resuelveCaso() {

    // leemos la entrada
    int C, F, N;
    cin >> C >> F >> N;
    if (C == 0 && F == 0 && N == 0) return false;
    vector<Trabajo> trabajos = vector<Trabajo>();

    for (int i = 0; i < N; ++i) {
        int c, f;
        cin >> c >> f;
        trabajos.push_back({ c, f});
    }

    sort(trabajos.begin(), trabajos.end());

    int nTrabajos = resolver(trabajos, C, F);

    if (nTrabajos != -1) {
        cout << nTrabajos << endl;
    }
    else {
        cout << "Imposible" << endl;
    }

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