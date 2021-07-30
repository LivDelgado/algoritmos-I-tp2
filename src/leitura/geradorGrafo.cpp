#include "leitura/geradorGrafo.hpp"

using namespace leitura;

GeradorGrafo::GeradorGrafo() {}

kosaraju::Grafo GeradorGrafo::gerarGrafo()
{
    int numeroAeroportos, numeroRotas;
    std::cin >> numeroAeroportos >> numeroRotas;

    kosaraju::Grafo grafo(numeroAeroportos);

    int origem, destino;

    for (int i = 0; i < numeroRotas; i++)
    {
        std::cin >> origem >> destino;
        grafo.adicionarAresta(origem-1, destino-1);
    }

    return grafo;
}
