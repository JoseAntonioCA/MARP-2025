#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

struct Bateria
{
    int turno;
    long long int tiempo;
    long long int restanteTotal;

};
bool operator< (Bateria a, Bateria b)
{
    return (a.restanteTotal > b.restanteTotal) || (a.restanteTotal == b.restanteTotal && a.turno > b.turno);
}

//COste O (N log N + M log M)
bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    priority_queue<Bateria>bats;
    int t;
    for (int i = 0; i < N; i++)
    {
        cin >> t;
        bats.push({i + 1, t, t});
    }
    int M;
    cin >> M;
    queue<Bateria> repuestos;
    for (int i = N; i < N+M; i++)
    {
        cin >> t;
        repuestos.push({i + 1, t, t});
    }
    int Z, T;
    cin >> Z >> T;

    while (!bats.empty() && bats.top().restanteTotal <= T)
    {
        Bateria aux = bats.top();
        bats.pop();
        aux.tiempo -= Z;
        if (aux.tiempo > 0)
        {
            aux.restanteTotal += aux.tiempo;
            bats.push(aux);
        }
        else if (!repuestos.empty())
        {
            Bateria aux2 = repuestos.front();
            repuestos.pop();
            aux2.restanteTotal += aux.restanteTotal;
            bats.push(aux2);
        }
    }
    if (bats.empty())
    {
        cout << "ABANDONEN INMEDIATAMENTE LA BASE" << endl;
    }
    else
    {
        if (bats.size() != N)
        {
            cout << "FALLO EN EL SISTEMA" << endl;
        }
        else
        {
            cout << "CORRECTO" << endl;
        }
        while (!bats.empty())
        {
            cout << bats.top().turno << " " << bats.top().restanteTotal << endl;
            bats.pop();
        }
    }
    cout << "---" << endl;
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