/*@ <authors>
 *
 * MARP11 José Antonio Carmona Alfonsel
 *
 *@ </authors> */

 /*@ <COSTE>
  *
  * O(N log N) por el sort
  *
  *@ </COSTE> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Horas.h"

using namespace std;

struct Pelicula {
    long long inicioTotal; // minutos absolutos desde día 0
    long long finTotal;    // minutos absolutos desde día 0
};

bool resuelveCaso() {
    int N;
    cin >> N;
    if (N == 0) return false;

    vector<Pelicula> peliculas;

    for (int i = 0; i < N; i++) {
        int dia, duracion;
        Horas ini;
        cin >> dia >> ini >> duracion;

        long long inicioTotal = (long long)(dia - 1) * 24 * 60 + ini.hora * 60 + ini.minuto;
        long long finTotal = inicioTotal + duracion;

        Pelicula p;
        p.inicioTotal = inicioTotal;
        p.finTotal = finTotal;

        peliculas.push_back(p);
    }

    // Ordenar por hora de finalización creciente
    sort(peliculas.begin(), peliculas.end(),
        [](const Pelicula& a, const Pelicula& b) {
            return a.finTotal < b.finTotal;
        });

    long long ultimoFin = -10;
    int nPelis = 0;

    for (auto& p : peliculas) {
        if (p.inicioTotal >= ultimoFin + 10) {
            nPelis++;
            ultimoFin = p.finTotal;
        }
    }

    cout << nPelis << "\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
#endif
    return 0;
}
