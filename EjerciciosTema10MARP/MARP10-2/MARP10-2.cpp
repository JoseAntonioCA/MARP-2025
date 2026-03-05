/*@ <authors>
 *
 * MARP11 Jose Antonio Carmona Alfonsel
 *
 *@ </authors> */

 /*@ <COSTE>
   *
   * O (N*N)
   *
   *@ </COSTE> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

/*@ <answer>

 Sustituye este párrafo por un comentario general sobre la solución,
 explicando cómo se resuelve el problema y cuál es el coste de la solución,
 en función del tamaño del problema.

 @ </answer> */



bool resuelveCaso() {

    int V, S;
    cin >> V >> S;

    if (!cin)
        return false;

    vector<long long> puntuacion = vector<long long>(S);

    for (int i = 0; i < S; i++) {
        cin >> puntuacion[i];
    }

    vector<long long> dp = vector<long long>(V + 1, LLONG_MAX);

    dp[0] = 0;

    for (int i = 1; i <= S; ++i) {
        for (int p = puntuacion[i-1]; p <= V; p++) {
            if (dp[p - puntuacion[i-1]] != LLONG_MAX)
                dp[p] = min(dp[p], dp[p - puntuacion[i-1]] + 1);
        }
    }

    vector<long long> sol;

    if (dp[V] != LLONG_MAX) {
        int i = S, j = V;
        while (j > 0 && i > 0) { // no se ha pagado todo
            if (puntuacion[i-1] <= j && dp[j] == dp[j - puntuacion[i - 1]] + 1) {
                // tomamos una moneda de tipo i
                sol.push_back(puntuacion[i - 1]);
                j = j - puntuacion[i - 1];
            }
            else // no tomamos más monedas de tipo i
                --i;
        }


        cout << dp[V]<< ": ";
        for (int i = 0; i < sol.size(); i++) {

            cout << sol[i] << " ";
        }
        cout << endl;

    }
    else
        cout << "Imposible" << endl;



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
