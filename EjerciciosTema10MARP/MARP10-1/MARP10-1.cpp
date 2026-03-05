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

    int N, L;
    cin >> N >> L;

    if (!cin)
        return false;

    vector<long long> longitud = vector<long long>(N);
    vector<long long> coste = vector<long long>(N);

    for (int i = 0; i < N; i++) {
        cin >> longitud[i] >> coste[i];
    }

    vector<long long> formas = vector<long long>(L+1, 0);
    vector<long long> minCuerdas = vector<long long>(L+1, LLONG_MAX);
    vector<long long> minCoste = vector<long long>(L+1, LLONG_MAX);

    formas[0] = 1;
    minCuerdas[0] = 0;
    minCoste[0] = 0;

    for (int i = 0; i < N; ++i) {
        vector<long long> formas_prev = formas;
        vector<long long> minCuerdas_prev = minCuerdas;
        vector<long long> minCoste_prev = minCoste;

        for (int l = longitud[i]; l <= L; l++) {

            if (formas_prev[l - longitud[i]] > 0) {

                formas[l] += formas_prev[l - longitud[i]];

                minCuerdas[l] = min(minCuerdas[l],
                    minCuerdas_prev[l - longitud[i]] + 1);

                minCoste[l] = min(minCoste[l],
                    minCoste_prev[l - longitud[i]] + coste[i]);
            }
        }
    }

    if (formas[L] == 0)
        cout << "NO" << endl;
    else
        cout << "SI " << formas[L] << " "
        << minCuerdas[L] << " "
        << minCoste[L] << "\n";



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
