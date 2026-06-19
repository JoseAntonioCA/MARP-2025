
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool resuelveCaso() {
    int N, S;
    cin >> N >> S;
    if (!cin)
        return false;

    vector<int> P(N);
    for (int& p : P) {
        cin >> p;
    }
    vector<int> E(N);
    for (int& e : E) {
        cin >> e;
    }

    vector<int> benef(N + 1);
    benef[N] = 0;

    // sig[i] = menor índice j (> i) tal que P[j] - P[i] >= K
    // será N si no hay ninguno
    vector<int> sig(N, N);

    int j = N; // restaurante más cercano a i separado al menos K
    for (int i = N - 1; i >= 0; --i) {
        // ajustamos j
        while (P[j - 1] - P[i] >= S) //Mientras la distancia entre el actual y el "siguiente" sea menor o igual a la brecha, se puede ir restando
            --j;
        sig[i] = j;
        benef[i] = max(benef[i + 1], E[i] + benef[j]);
    }

    // reconstrucción de una solución óptima (en orden creciente)
    vector<int> elegidas;
    int i = 0;
    while (i < N) {
        if (benef[i] == E[i] + benef[sig[i]]) {
            // tomamos i
            elegidas.push_back(P[i]);
            i = sig[i]; // saltamos al siguiente, puede ser N
        }
        else {
            ++i;
        }
    }

    //salida del beneficio óptimo
    cout << benef[0] << ": ";
    // imprimir posiciones (segunda línea)
    for (int t = 0; t < elegidas.size(); ++t) {
        cout << elegidas[t] << " ";
    }
    cout << endl;

    return true;
}

int main() {
    // Ajustes para leer ficheros locales si no estamos en el juez
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}