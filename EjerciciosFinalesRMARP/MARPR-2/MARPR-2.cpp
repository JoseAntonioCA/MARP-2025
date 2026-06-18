/*@ <authors>
 *
 * MARP11 José Antonio Carmona Alfonsel
 *
 *@ </authors> */


 /*@ <COSTE>
  *
  * El coste es O(V + A)
  *
  *@ </COSTE> */
#include <limits>
#include <iostream>
#include <fstream>
#include "Grafo.h"
#include <queue>
#include <deque>
using namespace std;
class CaminoMasCorto {
public:
    CaminoMasCorto(Grafo const& g) : visit(g.V(), false), color(g.V(), ' '),
        ant(g.V()), dist(g.V()), bipartito(true) {

        for (int i = 0; i < g.V(); ++i) {
            // Si el amigo 'i' no ha sido visitado aún en otro grupo, lanzamos BFS
            if (!visit[i]) {
                bfs(g, i);
            }
        }
    }
    // ¿hay camino del origen a v?
    bool hayCamino(int v) const {
        return visit[v];
    }

    bool esBipartito() const {
        return bipartito;
    }
    // número de aristas entre s y v
    int distancia(int v) const {
        return dist[v];
    }
private:
    std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    std::vector<char> color; // color del vertice, si rojo o azul
    std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
    std::vector<int> dist; // dist[v] = aristas en el camino s-v más corto
    bool bipartito;

    void bfs(Grafo const& g, int origen) {
        std::queue<int> q;
        dist[origen] = 0; visit[origen] = true;
        color[origen] = 'r';
        q.push(origen);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : g.ady(v)) {
                if (!visit[w]) {
                    ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
                    color[w] = (color[v] == 'r') ? 'b' : 'r';
                    q.push(w);
                }
                else if (color[v] == color[w]) {
                    bipartito = false;
                }
            }
        }
    }
};

bool resuelveCaso() {

    // leemos la entrada
    int A, R;
    cin >> A >> R;
    if (!cin) return false;

    Grafo grafo = Grafo(A);

    for (int i = 0; i < R; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        grafo.ponArista(p1-1, p2-1);
    }
    CaminoMasCorto caminos = CaminoMasCorto(grafo);
    //Dijkstra<int> caminos = Dijkstra<int>(grafo, S - 1);

    if (caminos.esBipartito())
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
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