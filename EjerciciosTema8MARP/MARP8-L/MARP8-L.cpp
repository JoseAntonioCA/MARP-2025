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
#include "IndexPQ.h"
#include <queue>
using namespace std;

struct Conferencia {
    int indice;
    int inicio;
    int final;

    bool operator<(const Conferencia& other) const {
        return (other.inicio < inicio);
    }
};



bool resuelveCaso() {

    // leemos la entrada
    int N;
    cin >> N;
    if (N == 0) return false;

    // leer el resto del caso y resolverlo

    priority_queue<Conferencia> pq = priority_queue<Conferencia>();

    for (int i = 0; i < N; i++) {
        int ini, fin;
        cin >> ini >> fin;

        Conferencia conferencia = Conferencia();
        conferencia.final = fin;
        conferencia.inicio = ini;
        conferencia.indice = i;

        pq.push(conferencia);
    }

    std::vector<int> soluc = vector<int>(N, 0);

    int nSalas = 1;

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            soluc[i] = 1;
        }
        else {
            auto e = pq.top(); pq.pop();
            if (e.final > pq.top().inicio) {
                nSalas++;
                soluc[i] = soluc[e.indice]+1;
            }
            else {
                soluc[i] = soluc[pq.top().indice];
            }
        }
    }

    for (int i = 0; i < soluc.size(); i++) {
        cout << soluc[i] << " ";
    }
    

    cout << endl;

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