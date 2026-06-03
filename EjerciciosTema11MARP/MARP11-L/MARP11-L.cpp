/*@ <authors>
 *
 * MARP11 Jose Antonio Carmona Alfonsel
 *
 *@ </authors> */


 /*@ <COSTE>
   *
   * O (N x M)
   *
   *@ </COSTE> */

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <sstream>
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

int lista_rec(vector<string> const& listaM, vector<string> const& listaT,
    int i, int j, vector<vector<int>>& matriz) {

    if (i >= listaM.size() || j >= listaT.size()) return 0;

    int& res = matriz[i][j];
    if (res != -1) return res;

    if (listaM[i] == listaT[j]) {
        // Coinciden, sumamos 1 y avanzamos en ambas
        res = 1 + lista_rec(listaM, listaT, i + 1, j + 1, matriz);
    }
    else {
        // No coinciden, probamos ambas ramas y nos quedamos con el máximo
        res = max(lista_rec(listaM, listaT, i + 1, j, matriz),
            lista_rec(listaM, listaT, i, j + 1, matriz));
    }
    return res;

}

void reconstruir(vector<string> const& listaM, vector<string> const& listaT,
    int i, int j, vector<vector<int>> const& matriz, vector<string>& sol) {

    if (i >= listaM.size() || j >= listaT.size()) return;

    if (listaM[i] == listaT[j]) {
        sol.push_back(listaM[i]);
        reconstruir(listaM, listaT, i + 1, j + 1, matriz, sol);
    }
    else {
        if (matriz[i][j] == matriz[i + 1][j]) {
            reconstruir(listaM, listaT, i + 1, j, matriz, sol); //Recorremos la siguiente cancion de la lista de manana
        }
        else {
            reconstruir(listaM, listaT, i, j + 1, matriz, sol); //Recorremos la siguiente cancion de la lista de tarde
        }
    }
}

bool resuelveCaso() {
    string lineaM, lineaT;

    if (!getline(cin, lineaM)) {
        return false;
    }
    getline(cin, lineaT);

    vector<string> listaM;
    vector<string> listaT;
    int next_id = 0;

    // Inicializar matriz de distancias C directamente
    
    string cancion;

    stringstream ssM(lineaM);
    while (ssM >> cancion)
        listaM.push_back(cancion);

    stringstream ssT(lineaT);
    while (ssT >> cancion)
        listaT.push_back(cancion);

    
    vector<vector<int>> C(listaM.size()+1, vector<int>(listaT.size()+1, -1));
    lista_rec(listaM, listaT, 0, 0, C);

    vector<string> sol;
    reconstruir(listaM, listaT, 0, 0, C, sol);

    for (size_t i = 0; i < sol.size(); ++i) {
        cout << sol[i] << " ";
    }
    cout << endl;

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
