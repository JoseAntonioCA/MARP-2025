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

// calcula el mínimo número de letras a añadir
// para convertir patitos[i..j] en palíndromo
int patin_rec(string const& patitos, int i, int j, Matriz<int>& patin) {
    int& res = patin[i][j];

    if (res == -1) {
        if (i >= j)  // vacío o una letra
            res = 0;
        else if (patitos[i] == patitos[j])
            res = patin_rec(patitos, i + 1, j - 1, patin);
        else
            res = 1 + min(patin_rec(patitos, i + 1, j, patin),
                patin_rec(patitos, i, j - 1, patin));
    }

    return res;
}

// reconstruye el palíndromo mínimo en patitos[i..j]
string reconstruir(string const& patitos, Matriz<int> const& patin, int i, int j) {

    if (i > j) return "";
    if (i == j) return string(1, patitos[i]);

    if (patitos[i] == patitos[j])
        return patitos[i] +
        reconstruir(patitos, patin, i + 1, j - 1) +
        patitos[j];

    else if (patin[i][j] == 1 + patin[i + 1][j])
        return patitos[i] +
        reconstruir(patitos, patin, i + 1, j) +
        patitos[i];

    else
        return patitos[j] +
        reconstruir(patitos, patin, i, j - 1) +
        patitos[j];
}

bool resuelveCaso() {
    string patitos;
    cin >> patitos;

    if (!cin)
        return false;

    int n = patitos.length();
    Matriz<int> patindromo(n, n, -1);
    int num = patin_rec(patitos, 0, n - 1, patindromo);
    string palabra = reconstruir(patitos, patindromo, 0, n - 1);
    cout << num << " " << palabra << endl;

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
