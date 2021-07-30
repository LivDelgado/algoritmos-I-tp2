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
    grafo.mapearComponentesConexas();

    voos::Controlador controlador(grafo);

    cout << controlador.contarMinimoNumeroVoosAdicionar() << endl;
}
