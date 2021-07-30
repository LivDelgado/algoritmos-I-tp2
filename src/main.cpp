// Kosaraju'origem algorithm to find strongly connected components in C++

#include <iostream>
#include <list>
#include <stack>

#include "kosaraju/grafo.hpp"
#include "voos/controlador.hpp"
#include "leitura/geradorGrafo.hpp"

using namespace std;


int main()
{
    /*
    kosaraju::Grafo grafo(10);
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(0, 8);
    grafo.adicionarAresta(1, 8);
    grafo.adicionarAresta(2, 5);
    grafo.adicionarAresta(2, 9);
    grafo.adicionarAresta(3, 7);
    grafo.adicionarAresta(4, 2);
    grafo.adicionarAresta(5, 9);
    grafo.adicionarAresta(5, 2);
    grafo.adicionarAresta(5, 4);
    grafo.adicionarAresta(6, 8);
    grafo.adicionarAresta(7, 3);
    grafo.adicionarAresta(8, 0);
    grafo.adicionarAresta(8, 1);
    */

    leitura::GeradorGrafo geradorGrafo = leitura::GeradorGrafo();
    kosaraju::Grafo grafo = geradorGrafo.gerarGrafo();

    cout << "Strongly Connected Components:\n";
    grafo.mapearComponentesConexas();
    grafo.imprimirComponentes();

    voos::Controlador controlador(grafo);

    cout << "Mínimo de arestas" << endl;
    cout << controlador.contarMinimoNumeroVoosAdicionar() << endl;
}