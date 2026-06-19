#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const long long int INF = 1e18; // Usamos un infinito lo bastante grande


//Coste (O N*N + N)
bool resuelveCaso() {
    int N, PMax, PMin;
    cin >> N >> PMax >> PMin;
    if (!cin) // Fin de la entrada
        return false;

    vector<int> potencias(N);
    for (int i = 0; i < N; i++) {
        cin >> potencias[i];
    }

    vector<int> costes(N);
    for (int i = 0; i < N; i++) {
        cin >> costes[i];
    }

    // dp[p] será el coste mínimo para conseguir exactamente la potencia p
    vector<long long int> dp(PMax + 1, INF);
    dp[0] = 0; // Conseguir potencia 0 cuesta 0

    // Rellenamos la tabla de programación dinámica
    for (int i = 0; i < N; i++) {
        for (int p = potencias[i]; p <= PMax; p++) {
            if (dp[p - potencias[i]] != INF) { //Si se ha podido pagar la potencia anterior, se coge lo que ha costado pagarla mas el coste de la bombilla y asi llegar a la potenca actual
                dp[p] = min(dp[p], dp[p - potencias[i]] + costes[i]);
            }
        }
    }

    // Buscamos el mínimo coste en el rango [PMin, PMax]
    long long int min_coste = INF;
    int mejor_potencia = -1;

    for (int p = PMin; p <= PMax; p++) {
        if (dp[p] < min_coste) {
            min_coste = dp[p];
            mejor_potencia = p;
        }
    }

    if (min_coste == INF) {
        cout << "IMPOSIBLE" << endl;
    }
    else {
        cout << min_coste << " " << mejor_potencia << endl;
    }

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