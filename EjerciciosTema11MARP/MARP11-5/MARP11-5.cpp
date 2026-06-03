/*@ <authors>
 *
 * MARP11 Jose Antonio Carmona Alfonsel
 *
 *@ </authors> */


 /*@ <COSTE>
   *
   * O (V^3)
   *
   *@ </COSTE> */

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include "Matriz.h"
using namespace std;

const int INF = 1e9;

/*@ <answer>

 Sustituye este párrafo por un comentario general sobre la solución,
 explicando cómo se resuelve el problema y cuál es el coste de la solución,
 en función del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

bool resuelveCaso() {
    int P, R;

    if (!(cin >> P >> R))
        return false;

    unordered_map<string, int> ids;
    int next_id = 0;

    // Inicializar matriz de distancias C directamente
    vector<vector<int>> C(P, vector<int>(P, INF));
    for (int i = 0; i < P; ++i) {
        C[i][i] = 0;
    }


    for (int i = 0; i < R; i++) {
        string p1, p2;
        cin >> p1 >> p2;
        // Si la persona no tiene ID asignado, se lo damos
        if (ids.find(p1) == ids.end()) ids[p1] = next_id++;
        if (ids.find(p2) == ids.end()) ids[p2] = next_id++;
        int v1 = ids[p1];
        int v2 = ids[p2];

        C[v1][v2] = 1;
        C[v2][v1] = 1;
    }

    for (int k = 0; k < P; ++k) {
        for (int i = 0; i < P; ++i) {
            for (int j = 0; j < P; ++j) {
                auto temp = C[i][k] + C[k][j];
                if (temp < C[i][j]) { // es mejor pasar por k
                    C[i][j] = temp;
                }
            }
        }
    }
    int max_grado_conexion = 0;
    bool conectado = true;

    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < P; ++j) {

            if (C[i][j] == INF) {
                conectado = false;
            }
            else {
                max_grado_conexion = max(max_grado_conexion, C[i][j]);
            }
        }
    }
    if (conectado) {
        cout << max_grado_conexion << endl;
    }
    else {
        cout << "DESCONECTADA" << endl;
    }

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
