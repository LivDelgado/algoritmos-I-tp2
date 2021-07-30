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
    leitura::GeradorGrafo geradorGrafo = leitura::GeradorGrafo();
    kosaraju::Grafo grafo = geradorGrafo.gerarGrafo();

    cout << "Strongly Connected Components:\n";
    grafo.mapearComponentesConexas();
    grafo.imprimirComponentes();

    voos::Controlador controlador(grafo);

    cout << "Mínimo de arestas" << endl;
    cout << controlador.contarMinimoNumeroVoosAdicionar() << endl;
}