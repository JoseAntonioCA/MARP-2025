/*@ <authors>
 *
 * MARP11 Jose Antonio Carmona Alfonsel
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Matriz.h"
#include "EnterosInf.h"
using namespace std;

/*@ <answer>

 Sustituye este párrafo por un comentario general sobre la solución,
 explicando cómo se resuelve el problema y cuál es el coste de la solución,
 en función del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

pair<int, int> devolver_cambio(vector<int> const& M, int C) {
    int n = M.size();
    EntInf infinito = EntInf();
    Matriz<int> monedas(n + 1, C + 1, infinito._intInf);
    monedas[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        monedas[i][0] = 0;
        for (int j = 1; j <= C; ++j)
            if (M[i - 1] > j)
                monedas[i][j] = monedas[i - 1][j];
            else if (M[i - 1] > j && monedas[i - 1][j] != infinito._intInf && (i > 1 && ((monedas[i - 1][j]) * M[i - 2] >= M[i - 1]))) {
                monedas[i][j] = monedas[i][j-1];
            }
            else
                monedas[i][j] = min(monedas[i - 1][j], monedas[i][j - M[i - 1]] + 1);
    }

    pair<int, int> sol;
    int pagado = 0;
    int nMonedas = 0;
    if (monedas[n][C] != infinito._intInf) {
        int i = n, j = C;
        while (j > 0) { // no se ha pagado todo
            if (M[i - 1] <= j && monedas[i][j] != monedas[i - 1][j]) {
                // tomamos una moneda de tipo i
                ; j = j - M[i - 1];


            }
            else // no tomamos más monedas de tipo i
                --i;
        }
    }
    return sol;
}

bool resuelveCaso() {

    int precio, n;
    cin >> precio >> n;

    if (!cin)
        return false;

    vector<int> valoresMonedas = vector<int>();

    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        valoresMonedas.push_back(e);
    }

    pair<int, int> sol = devolver_cambio(valoresMonedas, n);


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
