/*@ <authors>
 *
 * MARP11 José Antonio Carmona Alfonsel
 *
 *@ </authors> */


 /*@ <COSTE>
  * 
  * O (N log N) por el uso de colas de prioridad normales y variables
  *
  *@ </COSTE> */

#include <iostream>
#include <fstream>
#include "IndexPQ.h"
#include <queue>
using namespace std;

struct Conferencia {
    int inicio;
    int final;
    int index;

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

    IndexPQ<int, less<int>> SalasEventos(N);


    priority_queue<Conferencia> pq = priority_queue<Conferencia>();

    for (int i = 0; i < N; i++) {
        int ini, fin;
        cin >> ini >> fin;
        
        pq.push({ ini, fin, i });
    }

    int nSalas = 1;
    vector<int> soluc = vector<int>(N, 0);

    for (int i = 0; i < N; i++) {
        auto e = pq.top();
        pq.pop();

        if (SalasEventos.empty()) {
            soluc[e.index] = nSalas;
            SalasEventos.push(nSalas - 1, e.final);
        }
        else {
            if (e.inicio >= SalasEventos.top().prioridad) {
                soluc[e.index] = SalasEventos.top().elem+1;
                SalasEventos.update(SalasEventos.top().elem, e.final);
            }
            else {
                nSalas++;
                soluc[e.index] = nSalas;
                SalasEventos.push(nSalas - 1, e.final);
            }
        }
    }

    cout << nSalas << endl;
    for (int i = 0; i < N; i++) {
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