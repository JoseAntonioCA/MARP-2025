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

void devolver_cambio(vector<int> const& M, int C, int precio) {
    int n = M.size();
    vector<EntInf> monedas(C + 1, Infinito);
    monedas[0] = 0;
    // calcular la matriz sobre el propio vector
    for (int i = 1; i <= n; ++i) {
        for (int j = C; j >= M[i - 1]; j--) {
            monedas[j] = min(monedas[j], monedas[j - M[i - 1]] + 1);
        }
    }

    int i = precio;
    while (monedas[i] == Infinito)
        i++;

    cout << i << " " << monedas[i] << endl;
}

bool resuelveCaso() {
    // leer el resto del caso y resolverlo

    int precio, n;
    cin >> precio >> n;

    if (!cin)
        return false;

    vector<int> valoresMonedas = vector<int>();

    int mayor = precio;

    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        mayor += e;
        valoresMonedas.push_back(e);
    }

    devolver_cambio(valoresMonedas, mayor, precio);

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
