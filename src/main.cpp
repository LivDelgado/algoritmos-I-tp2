// Kosaraju'origem algorithm to find strongly connected components in C++

#include <iostream>
#include <list>
#include <stack>

#include "kosaraju/grafo.hpp"

using namespace std;


int main()
{
    kosaraju::Grafo grafo(8);
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(1, 2);
    grafo.adicionarAresta(2, 3);
    grafo.adicionarAresta(2, 4);
    grafo.adicionarAresta(3, 0);
    grafo.adicionarAresta(4, 5);
    grafo.adicionarAresta(5, 6);
    grafo.adicionarAresta(6, 4);
    grafo.adicionarAresta(6, 7);


    cout << "Strongly Connected Components:\n";
    grafo.mapearComponentesConexas();
    grafo.imprimirComponentes();
}