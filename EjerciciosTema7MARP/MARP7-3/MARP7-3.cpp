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
        ways[origen] = 1;
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
        int distancia = dist[v] + a.valor();
        if (dist[w] > distancia) {
            dist[w] = distancia;
            ways[w] = ways[v];
            ulti[w] = a;
            pq.update(w, dist[w]);
        }
        else if (dist[w] == distancia) {
            ways[w] += ways[v];
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

        AristaDirigida<int> arista1 = AristaDirigida<int>(p1 - 1, p2 - 1, coste);
        AristaDirigida<int> arista2 = AristaDirigida<int>(p2 - 1, p1 - 1, coste);

        grafo.ponArista(arista1);
        grafo.ponArista(arista2);
    }

    Dijkstra<int> caminos = Dijkstra<int>(grafo, 0);
    cout << caminos.caminos(N - 1) << endl;
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