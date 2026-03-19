/*@ <authors>
 *
 * MARP11 Jose Antonio Carmona Alfonsel
 *
 *@ </authors> */


 /*@ <COSTE>
   *
   * O (N*T)
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

struct Objeto { int p; double valor; };

double mochila_rec(vector<Objeto> const& obj, int i, int j,
    Matriz<double>& mochila) {
    if (mochila[i][j] != -1) // subproblema ya resuelto
        return mochila[i][j];
    if (i == 0 || j == 0) mochila[i][j] = 0;
    else if ((obj[i - 1].p * 3) > j)
        mochila[i][j] = mochila_rec(obj, i - 1, j, mochila);
    else
        mochila[i][j] = max(mochila_rec(obj, i - 1, j, mochila),
            mochila_rec(obj, i - 1, j - (obj[i - 1].p * 3), mochila)
            + obj[i - 1].valor);
    return mochila[i][j];
}

double mochila(vector<Objeto> const& objetos, int M, vector<bool>& sol) {
    int n = objetos.size();
    Matriz<double> mochila(n + 1, M + 1, -1);
    double valor = mochila_rec(objetos, n, M, mochila);
    // cálculo de los objetos
    int i = n, j = M;
    sol = vector<bool>(n, false);

    int nObjetosRecogidos = 0;

    while (i > 0 && j > 0) {
        if (mochila[i][j] != mochila[i - 1][j]) {
            sol[i - 1] = true; j = j - objetos[i - 1].p * 3;
            nObjetosRecogidos++;
        }
        --i;
    }

    cout << valor << endl;
    cout << nObjetosRecogidos << endl;
    if (nObjetosRecogidos > 0) {
        for (int i = 0; i < sol.size(); i++) {
            if (sol[i])
                cout << objetos[i].p << " " << objetos[i].valor << endl;
        }
    }
    cout << "---" << endl;


    return valor;
}

bool resuelveCaso() {
    // leer el resto del caso y resolverlo

    int T, N;
    cin >> T >> N;

    if (!cin)
        return false;

    vector<Objeto> objetos = vector<Objeto>();

    for (int i = 0; i < N; i++) {
        int p;
        double valor;
        cin >> p >> valor;
        objetos.push_back({p, valor});
    }

    vector<bool> sol;
    mochila(objetos, T, sol);

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
