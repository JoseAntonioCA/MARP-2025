

//template <class T>
//int nodos(bintree<T> const& tree) {
//    ...
//}
//
//...


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

/*@ <authors>
 *
 * José Antonio Carmona Alfonsel - MARP11.
 *
 *@ </authors> */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase
#include "bintree.h"
#include <algorithm>

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

template <class T>
struct Info {
    bool esAVL;
    int altura;
    T min;
    T max;
    bool nodoVacio;
};

template <class T>
Info <T> comprobarSiAVL(BinTree<T> const& tree) {

    if (tree.empty())
        return { true, 0, T(), T(), true};

    T elem = tree.root();

    auto izq = comprobarSiAVL(tree.left());
    auto der = comprobarSiAVL(tree.right());

    Info<T> datos;
    datos.altura = max(izq.altura, der.altura) + 1;

    bool equilibrado = std::abs(izq.altura - der.altura) <= 1;
    bool binarioOrdenado = (izq.nodoVacio || izq.max < elem) && (der.nodoVacio || elem < der.min);

    datos.esAVL = izq.esAVL && der.esAVL && equilibrado && binarioOrdenado;

    if (izq.nodoVacio) datos.min = elem;
    else datos.min = izq.min;

    if (der.nodoVacio) datos.max = elem;
    else datos.max = der.max;

    datos.nodoVacio = false;

    return datos;
}

template <class T>
bool esAVL(BinTree<T> const& tree) {
    return comprobarSiAVL(tree).esAVL;
}

bool resuelveCaso() {
    // leer los datos de la entrada

    char tipo;
    cin >> tipo;
    if (!cin)
        return false;

    if (tipo == 'N') {
        BinTree<int> tree = read_tree<int>(cin);
        if (esAVL(tree))
            cout << "SI" << "\n";
        else
            cout << "NO" << "\n";
    }
    else if (tipo == 'P') {
        BinTree<string> tree = read_tree<string>(cin);
        if (esAVL(tree))
            cout << "SI" << "\n";
        else
            cout << "NO" << "\n";
    }

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    if (!in.is_open())
        std::cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    std::cout << "Pulsa Intro para salir..." << std::flush;
    std::cin.get();
#endif
    return 0;
}
