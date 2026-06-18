#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
//Coste O(N * logN)

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)  // fin de la entrada
        return false;
    vector<pair<int,int>>horasConferencias;

    int ini, fin;

    for (int i = 0; i < N; i++)
    {
        cin >> ini >> fin;
        horasConferencias.push_back({ ini,fin });
    }

    sort(horasConferencias.begin(), horasConferencias.end());
    priority_queue<int, vector<int>, greater<int>> ultConferenciaHora;

    ultConferenciaHora.push(horasConferencias[0].second);
    int amigos = 0;
    for (int i = 1; i < N; i++)
    {
        if (horasConferencias[i].first < ultConferenciaHora.top())
        {
            amigos++;
            ultConferenciaHora.push(horasConferencias[i].second);
        }
        else
        {
            ultConferenciaHora.pop();
            ultConferenciaHora.push(horasConferencias[i].second);
        }
    }
    cout << amigos << endl;

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}