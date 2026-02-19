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

/*@ <answer>

 Sustituye este párrafo por un comentario general sobre la solución,
 explicando cómo se resuelve el problema y cuál es el coste de la solución,
 en función del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

int pagoTotal(int n, int totalMonedas, vector<int>& const valoresMonedas, vector<int>& cantidadMonedas{
    int n = l.size();
    vector<int> parrafo(n);
    ultima = vector<int>(n);
    // casos básicos
    int i = n - 1; int suma = l[i];
    while (i >= 0 && ((n - 1) - i) + suma <= L) {
        parrafo[i] = 0;
        ultima[i] = n - 1;
        --i;
        suma += l[i];
    }
    // casos recursivos
    //i es la palabra de inicio de linea, j es la del final
    while (i >= 0) {
        int j = i; suma = l[i]; parrafo[i] = INT_MAX;
        while (j < n - 1 && (j - i) + suma <= L) {
            int pen = L - (j - i) - suma;
            int nuevo = pen * pen * pen + parrafo[j + 1];
            if (nuevo < parrafo[i]) {
                parrafo[i] = nuevo; ultima[i] = j;
            }
            ++j; suma += l[j];
        }
        --i;
    }
    return parrafo[0];
}

bool resuelveCaso() {

    int n, precio;
    cin >> n;

    if (!cin)
        return false;

    vector<int> valoresMonedas = vector<int>();
    vector<int> cantidadMonedas = vector<int>();

    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        valoresMonedas.push_back(e);
    }

    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        cantidadMonedas.push_back(e);
    }



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
