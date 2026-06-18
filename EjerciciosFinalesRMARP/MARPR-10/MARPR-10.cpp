#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

bool resuelveCaso() {

    // leer los datos de la entrada
    long long int N;
    cin >> N;
    if (N == 0)
        return false;

    priority_queue<long long int, vector<long long int>, greater<long long int >> aficionados;

    long long int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        aficionados.push(n);
    }

    long long int totalGorras = 0;
    long long int a, b;
    while (!aficionados.empty())
    {
        a = aficionados.top();
        aficionados.pop();
        if (!aficionados.empty())
        {
            b = aficionados.top();
            aficionados.pop();
            totalGorras += (a + b);
            aficionados.push(a + b);
        }
    }
    cout << totalGorras << '\n';
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

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