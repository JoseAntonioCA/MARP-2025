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
#include "Grafo.h"
#include <queue>
using namespace std;

class CaminoMasCorto {
private:
    std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
    std::vector<int> dist; // dist[v] = aristas en el camino s-v más corto
    int s;
public:
    CaminoMasCorto(Grafo const& g, int s) : visit(g.V(), false),
        ant(g.V()), dist(g.V()), s(s) {
        bfs(g);
    }
    // ¿hay camino del origen a v?
    bool hayCamino(int v) const {
        return visit[v];
    }

    void bfs(Grafo const& g) {
        std::queue<int> q;
        dist[s] = 0; visit[s] = true;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : g.ady(v)) {
                if (!visit[w]) {
                    ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
                    q.push(w);
                }
            }
        }
    }

    // número de aristas entre s y v
    int distancia(int v) const {
        return dist[v];
    }



};

bool resuelveCaso() {

    // leemos la entrada
    int N, C, P1, P2, T;
    cin >> N >> C >> P1 >> P2 >> T;
    if (!cin) return false;

    // leer el resto del caso y resolverlo

    Grafo grafo = Grafo(N);

    for (int i = 0; i < C; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        grafo.ponArista(v1-1, v2-1);
    }
    
    int distanciaMin = 20001;

    CaminoMasCorto* caminoP1 = new CaminoMasCorto(grafo, P1-1);
    CaminoMasCorto* caminoP2 = new CaminoMasCorto(grafo, P2-1);
    CaminoMasCorto* caminoT = new CaminoMasCorto(grafo, T-1);

    for (int i = 0; i < N; i++) {
        int distTotal;
        distTotal = caminoP1->distancia(i) + caminoP2->distancia(i) + caminoT->distancia(i);
        if (distTotal < distanciaMin)
            distanciaMin = distTotal;
    }

    cout << distanciaMin << endl;

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