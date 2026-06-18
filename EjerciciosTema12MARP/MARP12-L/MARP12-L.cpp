/*@ <authors>
 *
 * MARP11 Jose Antonio Carmona Alfonsel
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
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
int corta_tablon(vector<int> const& D/*, Matriz<int>& P*/) {
    int n = D.size() - 1;
    Matriz<int> matrices(n + 1, n + 1, 0);
    //P = Matriz<int>(n + 1, n + 1, 0);
    for (int d = 1; d <= n - 1; ++d) // recorre diagonales
        for (int i = 1; i <= n - d; ++i) { // recorre elementos de diagonal
            int j = i + d;
            matrices[i][j] = INF;
            for (int k = i; k <= j - 1; ++k) {
                int temp = matrices[i][k] + matrices[k + 1][j] + (D[j] - D[i - 1]);
                if (temp < matrices[i][j]) { // es mejor partir por k
                    matrices[i][j] = temp;
                    //P[i][j] = k;
                }
            }
        }
    return matrices[1][n];
}

bool resuelveCaso() {

    int N;
    cin >> N;

    if (N == 0)
        return false;

    vector<int> puntosCorte = vector<int>();
    puntosCorte.push_back(0);
    int num = 0;
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;

        num += e;
        puntosCorte.push_back(num);
    }

    cout << corta_tablon(puntosCorte) << endl;



    // leer el resto del caso y resolverlo




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
