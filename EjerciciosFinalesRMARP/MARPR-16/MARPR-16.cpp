#include <iostream>
#include <fstream>
#include "Matriz.h"
using namespace std;

int numDiasConMismaFruta(vector<int> const& bizcocho, int i, int j, Matriz<int>& patin) {
    int& res = patin[i][j];
    if (res == -1) {
        if (i > j) res = 0;
        else if (i == j - 1) //Solo quedan 2 trozos
        {
            if (bizcocho[i] == bizcocho[j] && bizcocho[i] != 0)
                res = 1;
            else
                res = 0;
        }
        //Vemos si coger de un lado u otro
        else if (bizcocho[i] == bizcocho[j] && bizcocho[i] != 0)
            res = numDiasConMismaFruta(bizcocho, i + 1, j - 1, patin) + 1;
        else if (bizcocho[i] == bizcocho[i + 1] && bizcocho[i] != 0)
            res = numDiasConMismaFruta(bizcocho, i + 2, j, patin) + 1;
        else if (bizcocho[j] == bizcocho[j - 1] && bizcocho[j] != 0)
            res = numDiasConMismaFruta(bizcocho, i, j - 2, patin) + 1;
        //No hay trozos iguales, comprobamos el resto
        else
            res = max(max(numDiasConMismaFruta(bizcocho, i + 2, j, patin),
                numDiasConMismaFruta(bizcocho, i, j - 2, patin)), numDiasConMismaFruta(bizcocho, i + 1, j - 1, patin));
    }
    return res;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (!cin)
        return false;

    vector<int>bizcocho(N);

    for (int i = 0; i < N; i++)
        cin >> bizcocho[i];

    Matriz<int> patindromo(N, N, -1);

    cout << numDiasConMismaFruta(bizcocho, 0, N - 1, patindromo) << endl;

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