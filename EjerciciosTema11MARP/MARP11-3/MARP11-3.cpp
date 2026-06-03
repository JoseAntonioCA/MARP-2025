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

struct Evento { int grupos; double dinero; };

double mochila_rec(vector<Evento> const& obj, int i, int j,
    Matriz<double>& mochila) {
    if (mochila[i][j] != -1) // subproblema ya resuelto
        return mochila[i][j];
    if (i == 0 || j == 0) mochila[i][j] = 0;
    else if ((obj[i - 1].dinero) > j)
        mochila[i][j] = mochila_rec(obj, i - 1, j, mochila);
    else
        mochila[i][j] = max(mochila_rec(obj, i - 1, j, mochila),
            mochila_rec(obj, i - 1, j - (obj[i - 1].dinero), mochila)
            + obj[i - 1].grupos);
    return mochila[i][j];
}

double mochila(vector<Evento> const& objetos, int P) {
    int n = objetos.size();
    Matriz<double> mochila(n + 1, P + 1, -1);
    double valor = mochila_rec(objetos, n, P, mochila);
    cout << valor << endl;


    return valor;
}

bool resuelveCaso() {
    // leer el resto del caso y resolverlo

    int P, N;
    cin >> P >> N;

    if (!cin)
        return false;

    vector<Evento> eventos = vector<Evento>();

    for (int i = 0; i < N; i++) {
        int p;
        double valor;
        cin >> p >> valor;
        eventos.push_back({ p, valor });
    }
    mochila(eventos, P);

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
