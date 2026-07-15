#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


// Coste O (N*N + N)
int DuracionMaxima(const vector<int>& duracionEvento, int total)
{
    vector<int> aula(total + 1, -1); //Si una de las aulas tiene "d" duración total de eventos, la sala con más tiempo de eventos tendrá una duración de "d" o total - d, puede ser la misma sala u otra diferente
    for (int d = 0; d <= total; d++)
        aula[d] = max(d, total - d);

    for (int i = 0; i < duracionEvento.size(); i++)
    {
        for (int d = 0; d <= total - duracionEvento[i]; d++)
        {
            aula[d] = min(aula[d], aula[d + duracionEvento[i]]);
        }
    }
    return aula[0];
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> duracion;
    int total = 0;
    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        total += n;
        duracion.push_back(n);
    }
    cout << DuracionMaxima(duracion, total) << endl;

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