/*@ <authors>
 *
 * MARP11 José Antonio Carmona Alfonsel
 *
 *@ </authors> */


 /*@ <COSTE>
  *
  * El coste es O(A log V)
  *
  *@ </COSTE> */
#include <limits>
#include <iostream>
#include <fstream>
#include "DigrafoValorado.h"
#include "IndexPQ.h"
#include <queue>
using namespace std;

template <typename Valor>
class Dijkstra {
    using Camino = std::deque<Valor>;
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
        dist(g.V(), INF), ways(g.V(), 0), ulti(g.V()), pq(g.V()) {
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }
    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor distancia(int v) const { return dist[v]; }
    Valor caminos(int v) const { return ways[v]; }
    //Camino camino(int v) const {
    //    Camino cam;
    //    // recuperamos el camino retrocediendo
    //    AristaDirigida<Valor> a;
    //    for (a = ulti[v]; a.desde() != origen; a = ulti[a.desde()])
    //        cam.push_front(a);
    //    cam.push_front(a);
    //    return cam;
    //}
private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    std::vector<Valor> ways;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        Valor max_esfuerzo = std::max(dist[v], a.valor());

        if (max_esfuerzo < dist[w]) {
            dist[w] = max_esfuerzo; ulti[w] = a;
            pq.update(w, dist[w]);
        }
    }
};

bool resuelveCaso() {

    // leemos la entrada
    int N, M;
    cin >> N >> M;
    if (!cin) return false;

    DigrafoValorado<int> grafo = DigrafoValorado<int>(N);

    for (int i = 0; i < M; i++) {
        int p1, p2, coste;
        cin >> p1 >> p2 >> coste;

        AristaDirigida<int> arista = AristaDirigida<int>(p1 - 1, p2 - 1, coste);
        AristaDirigida<int> arista2 = AristaDirigida<int>(p2 - 1, p1 - 1, coste);

        grafo.ponArista(arista);
        grafo.ponArista(arista2);
    }

    int S, D;
    cin >> S >> D;

    Dijkstra<int> caminos = Dijkstra<int>(grafo, S - 1);

    if (caminos.hayCamino(D - 1))
        cout << caminos.distancia(D-1) << endl;
    else
        cout << "IMPOSIBLE" << endl;
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