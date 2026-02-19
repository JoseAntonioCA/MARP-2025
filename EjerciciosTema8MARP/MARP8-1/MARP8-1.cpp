/*@ <authors>
 *
 * MARP11 José Antonio Carmona Alfonsel
 *
 *@ </authors> */


 /*@ <COSTE>
  *
  *
  *@ </COSTE> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int numero_parches(vector<int> const& S, int L) {
    int nParches = 0;
    int longParche = L;
    vector<bool> agujeroParcheado(S.size(), false);
    for (int i = 0; i < S.size(); ++i) {
        if (!agujeroParcheado[i])
            nParches++;
        if (i != S.size() - 1) {
            int dif = S[i + 1] - S[i];
            if (dif <= longParche) {
                agujeroParcheado[i + 1] = true;
                longParche -= dif;
            }
            else
                longParche = L;
        }
    }
    return nParches;
}

bool resuelveCaso() {

    // leemos la entrada
    int N, L;
    cin >> N;
    if (!cin) return false;
    vector<int> agujeros = vector<int>();

    cin >> L;

    for (int i = 0; i < N; ++i) {
        int e;
        cin >> e;
        agujeros.push_back(e);
    }

    cout << numero_parches(agujeros, L) << endl;
    

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