#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (!cin)
        return false;

    priority_queue<int>libros;
    
    int e;
    for (int i = 0; i < N; i++) {
        cin >> e;
        libros.push(e);
    }

    int countLibros = 0;
    int descuentoTotal = 0;

    while (!libros.empty()) {
        countLibros++;
        if (countLibros == 3) {
            descuentoTotal += libros.top();
            countLibros = 0;
        }
        libros.pop();
    }

    cout << descuentoTotal << endl;

    return true;
}

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