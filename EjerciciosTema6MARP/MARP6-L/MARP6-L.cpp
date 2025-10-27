/*@ <authors>
 *
 * MARP11 José Antonio Carmona Alfonsel
 *
 *@ </authors> */


 /*@ <COSTE>
  *
  * El coste es O(A log A)
  *
  *@ </COSTE> */

#include <iostream>
#include <fstream>
#include "ConjuntosDisjuntos.h"
#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include <queue>
using namespace std;

template <typename Valor>
class ARM_Kruskal {
private:
    std::vector<Arista<Valor>> _ARM;
    Valor coste;
    int nGrupos;
public:
    Valor costeARM() const {
        return coste;
    }
    int nGruposARM() const {
        return nGrupos;
    }
    std::vector<Arista<Valor>> const& ARM() const {
        return _ARM;
    }

    ARM_Kruskal(GrafoValorado<Valor> const& g, int A) : coste(0) {
        PriorityQueue<Arista<Valor>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());

        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                if (a.valor() < A) {
                    cjtos.unir(v, w);
                    _ARM.push_back(a); coste += a.valor();
                    if (_ARM.size() == g.V() - 1) break;
                }
            }
        }
        nGrupos = cjtos.num_cjtos();
    }
};

bool resuelveCaso() {

    // leemos la entrada
    int N, M, A;
    cin >> N >> M >> A;
    if (!cin) return false;

    // leer el resto del caso y resolverlo

    GrafoValorado<int> grafo = GrafoValorado<int>(N);

    for (int i = 0; i < M; i++) {
        int p1, p2, coste;
        cin >> p1 >> p2 >> coste;

        Arista<int> arista = Arista<int>(p1-1, p2-1, coste);

        grafo.ponArista(arista);
    }

    ARM_Kruskal<int> arm = ARM_Kruskal<int>(grafo, A);

    int nAeropuertos = arm.nGruposARM();
    int costeARM = arm.costeARM();

    int costeTotal = (A * nAeropuertos) + costeARM;

    cout << costeTotal << " " << nAeropuertos << endl;

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