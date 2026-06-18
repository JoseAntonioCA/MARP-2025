#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include"Matriz.h"
using namespace std;

struct Objeto { int peso; double valor; int chorizoNecesario; int panNecesario; };


//Coste (N * M)
double mochila_rec(vector<Objeto> const& obj, int i, int j,
    Matriz<double>& mochila) {
    if (i == 0 || j <= 0)
        return 0;
    if (mochila[i][j] != -1) // subproblema ya resuelto
        return mochila[i][j];
    else if (obj[i-1].panNecesario > j)
        mochila[i][j] = mochila_rec(obj, i - 1, j, mochila);
    else
    {
        int mini = min((obj[i-1].peso / obj[i-1].chorizoNecesario), j / obj[i-1].panNecesario);
        for (int k = 0; k <= mini; k++) {
            mochila[i][j] = max(mochila_rec(obj, i - 1, j - obj[i-1].panNecesario * k, mochila) + obj[i-1].valor * k,
                mochila[i][j]);
        }
    }
    return mochila[i][j];
}


bool resuelveCaso() {

    // leer los datos de la entrada
    int N, masa;
    cin >> N >> masa;
    if (!std::cin)  // fin de la entrada
        return false;
    int peso, gchorizo, mPan;
    double valor;
    vector<Objeto> bollos;
    for (int i = 0; i < N; i++)
    {
        cin >> peso >> gchorizo >> mPan >> valor;
        bollos.push_back({ peso,valor,gchorizo,mPan });
    }

    Matriz<double> mochila(N + 1, masa + 1, -1);
    cout << mochila_rec(bollos, N, masa, mochila) << endl;
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