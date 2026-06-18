#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"
using namespace std;


//Coste (A log A)
template <typename Valor>
class ARM_Kruskal {
private:
    std::vector<Arista<Valor>> _ARM;
    Valor coste;
    Valor aristaMasGrande;
    int nConjuntos;
public:
    Valor costeARM() const {
        return coste;
    }

    Valor laAristaMasGrande() const {
        return aristaMasGrande;
    }
    int numeroConjuntos() const {
        return nConjuntos;
    }
    std::vector<Arista<Valor>> const& ARM() const {
        return _ARM;
    }
    ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0), aristaMasGrande(0) {
        PriorityQueue<Arista<Valor>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                _ARM.push_back(a); coste += a.valor();
                aristaMasGrande = a.valor();
                if (_ARM.size() == g.V() - 1) break;
            }
        }
        nConjuntos = cjtos.num_cjtos();
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, M;
    cin >> N >> M;

    GrafoValorado<int> grafo = GrafoValorado<int>(N);

    for (int i = 0; i < M; i++)
    {
        int p1, p2, coste;
        cin >> p1 >> p2 >> coste;

        Arista<int> arista = Arista<int>(p1 - 1, p2 - 1, coste);
        grafo.ponArista({p1-1, p2-1, coste});
    }

    ARM_Kruskal<int> arm = ARM_Kruskal<int>(grafo);
    if (arm.numeroConjuntos() == 1) {
        cout << arm.laAristaMasGrande() << endl;
    }
    else if (N == 1) {
        cout << "0" << endl;
    }
    else
        cout << "Imposible" << endl;

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}