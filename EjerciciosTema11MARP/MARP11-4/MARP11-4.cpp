/*@ <authors>
 *
 * MARP11 Jose Antonio Carmona Alfonsel
 *
 *@ </authors> */


 /*@ <COSTE>
   *
   * O (N)
   *
   *@ </COSTE> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Matriz.h"
using namespace std;

/*@ <answer>

 Sustituye este párrafo por un comentario general sobre la solución,
 explicando cómo se resuelve el problema y cuál es el coste de la solución,
 en función del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

int patin_rec(vector<int> const& cubos, int i, int j, Matriz<int>& DP, Matriz<int>& DPdev, bool turno) {
    
    bool nuevoTurno = !turno;

    if (i > j) return 0;  // CASO BASE: no quedan cubos
    if (i == j) return turno ? cubos[i] : 0; // solo queda un cubo

    if (turno) {
        int& res = DP[i][j];
        if (res == -1) {
            res = max(
                cubos[i] + patin_rec(cubos, i + 1, j, DP, DPdev, nuevoTurno),
                cubos[j] + patin_rec(cubos, i, j - 1, DP, DPdev, nuevoTurno)
            );
        }
        return res;
    }
    else {
        int& res = DPdev[i][j];
        if (res == -1) {
            if (cubos[i] > cubos[j])
                res = patin_rec(cubos, i + 1, j, DP, DPdev, nuevoTurno);
            else
                res = patin_rec(cubos, i, j - 1, DP, DPdev, nuevoTurno);
        }
        return res;
    }

}


bool resuelveCaso() {
    int N;
    cin >> N;

    if (N == 0)
        return false;

    vector<int> cubos = vector<int>();

    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        cubos.push_back(e);
    }

    Matriz<int> DP(N, N, -1);
    Matriz<int> DPdev(N, N, -1);

    int num = patin_rec(cubos, 0, N - 1, DP, DPdev, true);
    cout << num << endl;

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
