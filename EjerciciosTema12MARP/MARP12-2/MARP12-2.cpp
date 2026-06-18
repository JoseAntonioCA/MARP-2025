#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pelicula {
    int inicio;
    int fin;
    int duracion;
    bool operator< (const Pelicula& other) const {
        return (inicio < other.inicio);
    }
    Pelicula(int ini, int dur) {
        inicio = ini;
        duracion = dur;
        fin = ini + dur + 10; // Ya incluye los 10 min de descanso
    }
};

// Tu función modificada: SIN búsqueda binaria, usando el vector 1D y el parámetro J (hora libre)
int solucion(const vector<Pelicula>& pelis, vector<int>& sol, int N, int i, int J) {
    // Caso base: ya no quedan películas por evaluar
    if (i == N)
        return 0;

    // 1. Si la película actual NO se puede meter porque empieza antes de que termine la anterior (J)
    if (pelis[i].inicio < J) {
        // Simplemente pasamos a la siguiente película dejando J igual (no tocamos sol[i])
        return solucion(pelis, sol, N, i + 1, J);
    }

    // 2. Si sí se puede meter, J ya no es una restricción limitante para el resto del vector.
    // El estado depende solo de 'i', así que podemos usar tu vector 1D de memoización.
    if (sol[i] != -1)
        return sol[i];

    // OPCIÓN A: Descartar la película actual por elección
    int aux2 = solucion(pelis, sol, N, i + 1, J);

    // OPCIÓN B: Coger la película actual
    int aux = pelis[i].duracion + solucion(pelis, sol, N, i + 1, pelis[i].fin);

    // Guardamos el máximo de las dos decisiones
    sol[i] = max(aux, aux2);
    return sol[i];
}

bool resuelveCaso() {
    int N;
    cin >> N;
    if (N == 0)
        return false;

    int d, m, h, dur;
    char aux;
    vector<Pelicula> pelis;

    for (int i = 0; i < N; i++) {
        cin >> d >> h >> aux >> m >> dur;
        pelis.push_back(Pelicula(d * 24 * 60 + h * 60 + m, dur));
    }

    // Ordenamos por hora de inicio
    sort(pelis.begin(), pelis.end());

    vector<int> sol(N, -1);

    cout << solucion(pelis, sol, N, 0, 0) << endl;

    return true;
}

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
