/*@ <authors>
 *
 * MARP11 José Antonio Carmona Alfonsel
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
#include <vector>
using namespace std;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

struct Grupo {
    int musicos;
    int nPartituras;
    int grupoMasGrande;

    bool operator<(const Grupo& other) const {
        return grupoMasGrande < other.grupoMasGrande;
    }
};

bool resuelveCaso() {
    int P, N;
    if (!(cin >> P >> N))
        return false;

    priority_queue<Grupo, vector<Grupo>, less<Grupo>> grupos;

    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        grupos.push({ e, 1, e });
    }

    for (int i = N; i < P; i++) {
        auto e = grupos.top();
        if (e.grupoMasGrande == 1) {
            break;
        }
        grupos.pop();
        e.nPartituras++;
        e.grupoMasGrande = (e.musicos + e.nPartituras - 1) / e.nPartituras;
        grupos.push(e);
    }

    cout << grupos.top().grupoMasGrande << endl;
    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    if (!in.is_open())
        cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
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
