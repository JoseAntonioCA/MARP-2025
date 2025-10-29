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
        dist(g.V(), INF), calles(g.V(), INF), posibleMenosCalles(g.V(), false), ulti(g.V()), pq(g.V()) {
        dist[origen] = 0;
        calles[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }
    bool hayCamino(int v) const { return dist[v] != INF; }
    bool posibleMenosCallesHastaPunto(int v) const { return posibleMenosCalles[v]; }
    Valor distancia(int v) const { return dist[v]; }
    Valor nCalles(int v) const { return calles[v]; }
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
    std::vector<Valor> calles;
    std::vector<Valor> dist;
    std::vector<bool> posibleMenosCalles;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        int distancia = dist[v] + a.valor();
        int nCalles = calles[v] + 1;
        if (dist[w] > distancia) {
            if (nCalles <= calles[w])
                posibleMenosCalles[w] = true;
            else
                posibleMenosCalles[w] = false;

            dist[w] = distancia;
            calles[w] = nCalles;
            ulti[w] = a;
            pq.update(w, dist[w]);
        }
        else if (dist[w] == distancia) {
            if (nCalles < calles[w]) {
                calles[w] = nCalles; // actualizamos mínimo de calles
                posibleMenosCalles[w] = true; // ahora sí es posible
            }
            else if (nCalles == calles[w]) {
                posibleMenosCalles[w] = true; // sigue siendo posible
            }
            else {
                // nCalles > calles[w], la distancia es mínima pero tiene más calles
                //posibleMenosCalles[w] = false;
            }
        }
    }
};

bool resuelveCaso() {

    // leemos la entrada
    int N, C, K;
    cin >> N >> C;
    if (!cin) return false;

    DigrafoValorado<int> grafo = DigrafoValorado<int>(N);

    for (int i = 0; i < C; i++) {
        int p1, p2, coste;
        cin >> p1 >> p2 >> coste;

        AristaDirigida<int> arista1 = AristaDirigida<int>(p1 - 1, p2 - 1, coste);
        AristaDirigida<int> arista2 = AristaDirigida<int>(p2 - 1, p1 - 1, coste);

        grafo.ponArista(arista1);
        grafo.ponArista(arista2);
    }

    cin >> K;

    for (int i = 0; i < K; i++) {
        int p1, p2;
        cin >> p1 >> p2;

        Dijkstra<int> caminos = Dijkstra<int>(grafo, p1-1);

        if (!caminos.hayCamino(p2 - 1)) {
            cout << "SIN CAMINO" << endl;
        }
        else {
            cout << caminos.distancia(p2-1) << " ";

            if (caminos.posibleMenosCallesHastaPunto(p2-1))
                cout << "SI" << endl;
            else
                cout << "NO" << endl;
        }
    }

    cout << "---" << endl;
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