/*@ <authors>
 *
 * MARP11 José Antonio Carmona Alfonsel
 *
 *@ </authors> */


 /*@ <COSTE>
  *
  * El coste es V + 3(V + A)
  *
  *@ </COSTE> */

#include <iostream>
#include <fstream>
#include "Digrafo.h"
#include <queue>
using namespace std;

int adyacente(int v, char i) {
    switch (i) {
    case 'A': return v + 1;
    case 'J': {
        int w;
        cin >> w;
        return w;
    }
    case 'C': {
        int w;
        cin >> w;
        return w;
    }
    }
}

string bfs(int size) {
    string veredicto;
    vector<bool> visitados(size, false);
    int i = 0;
    visitados[i] = true;
    queue<int> cola; cola.push(i);

    bool aVecesLlega = false;
    int w;

    while (!cola.empty()) {


        int v = cola.front(); cola.pop();

        char caso;
        cin >> caso;

        int w = adyacente(i, caso);


        if (caso == 'A') {
            if (w != size)
                visitados[w] = true;
            i++;
        }
        else if (caso == 'J') {
            if (visitados[w]) {
                return "NUNCA";
            }
            visitados[w] = true;
        }
        else if (caso == 'C') {
            if (visitados[w]) {
                aVecesLlega = true;
            }
            visitados[w] = true;
        }

        for (int i = 0; i < 3; ++i) {
            int w = adyacente(v, i);
            if (distancia[w] == INF) {
                distancia[w] = distancia[v] + 1;
                if (w == destino) return distancia[w];
            }
        }
        cola.push(w);
    }
}



bool resuelveCaso() {

    // leemos la entrada
    int L;
    cin >> L;
    if (!cin) return false;

    // leer el resto del caso y resolverlo

    Digrafo grafo = Digrafo(L);

    for (int i = 0; i < L; i++) {
        char caso;
        cin >> caso;

        if (caso == 'A') {
            if (i != L - 1)
                grafo.ponArista(i, i + 1);

        }
        else {
            int dest;
            cin >> dest;
            if (caso == 'J') {
                grafo.ponArista(i, dest - 1);
            }
            else if (caso == 'C') {
                grafo.ponArista(i, dest - 1);
                if (i != L - 1)
                    grafo.ponArista(i, i + 1);
            }
        }
    }


    /*for (int i = 0; i < N; i++) {
        int distTotal;
        distTotal = caminoP1->distancia(i) + caminoP2->distancia(i) + caminoT->distancia(i);
        if (distTotal < distanciaMin)
            distanciaMin = distTotal;
    }

    cout << distanciaMin << endl;*/

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