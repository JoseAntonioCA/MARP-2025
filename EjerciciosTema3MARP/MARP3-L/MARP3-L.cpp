/*@ <authors>
 *
 * MARP11 José Antonio Carmona Alfonsel
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
#include "IndexPQ.h"
#include <unordered_map>
using namespace std;


/*@ <answer>

 Sustituye este párrafo por un comentario general sobre la solución,
 explicando cómo se resuelve el problema y cuál es el coste de la solución,
 en función del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

struct Canal {
    int id;
    int minutos;

    bool operator<(const Canal& other) const {
        return (minutos < other.minutos || (minutos == other.minutos && id < other.id));
    }
};

bool resuelveCaso() {

    // leemos la entrada
    int D, C, N;
    cin >> D >> C >> N;
    if (!cin) return false;

    // leer el resto del caso y resolverlo

    IndexPQ<int, int, greater<int>> canales;
    unordered_map<int, int> tiempoCanales;

    for (int i = 1; i <= C; i++) {
        int televidentes;
        cin >> televidentes;
        canales.push(i, televidentes);
    }

    int iniPeriodo = 0;
    int finalPeriodo = 0;

    for (int i = 0; i < N; i++) {
        auto e = canales.top();

        cin >> finalPeriodo;

        tiempoCanales[e.elem] += (finalPeriodo - iniPeriodo);
        
        int canal = 0;
        int audiencia = 0;
        cin >> canal;

        while (canal != -1) {
            cin >> audiencia;
            canales.update(canal, audiencia);
            cin >> canal;
        }

        iniPeriodo = finalPeriodo;
    }

    tiempoCanales[canales.top().elem] += (D - iniPeriodo);

    priority_queue<Canal, vector<Canal>, less<Canal>> canalesOrdenados;

    int size = 0;

    for (auto it = tiempoCanales.begin(); it != tiempoCanales.end(); it++) {
        canalesOrdenados.push({ it->first, it->second });
        size++;
    }

    for (int i = 0; i < size; i++) {
        cout << canalesOrdenados.top().id << " " << canalesOrdenados.top().minutos << endl;
        canalesOrdenados.pop();
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
