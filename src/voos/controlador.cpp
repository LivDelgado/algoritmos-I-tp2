#include "voos/controlador.hpp"

using namespace voos;

Controlador::Controlador(kosaraju::Grafo grafo)
{
    this->grafo = grafo;
    this->numeroNovosVoosAdicionados = 0;
}

bool Controlador::componenteTemVertice(kosaraju::ComponenteFortementeConexa componente, int vertice)
{
    return std::find(componente.vertices.begin(), componente.vertices.end(), vertice) != componente.vertices.end();
}

bool Controlador::componenteTemEntrada(kosaraju::ComponenteFortementeConexa componente)
{
    bool temEntrada = false;
    std::list<int> *listaDeEntrada = this->grafo.obterListaDeEntrada();
    for (int vertice : componente.vertices)
    {
        for (int verticeEntrada : listaDeEntrada[vertice])
        {
            if (!componenteTemVertice(componente, verticeEntrada))
            {
                temEntrada = true;
            }
        }
    }

    return temEntrada;
}

bool Controlador::componenteTemSaida(kosaraju::ComponenteFortementeConexa componente)
{
    bool temSaida = false;

    std::list<int> *listaDeSaida = this->grafo.obterListaDeSaida();
    for (int vertice : componente.vertices)
    {
        for (int verticeSaida : listaDeSaida[vertice])
        {
            if (!componenteTemVertice(componente, verticeSaida))
            {
                temSaida = true;
            }
        }
    }

    return temSaida;
}

int Controlador::obterMaiorNumeroAeroportos()
{
    int naoEhOrigem = 0;
    int naoEhDestino = 0;

    for (kosaraju::ComponenteFortementeConexa componente : *this->grafo.obterComponentesConexas())
    {
        if (!componenteTemEntrada(componente))
            naoEhDestino++;
        if (!componenteTemSaida(componente))
            naoEhOrigem++;
    }

    if (naoEhOrigem > naoEhDestino)
    {
        return naoEhOrigem;
    }

    return naoEhDestino;
}

int Controlador::contarMinimoNumeroVoosAdicionar()
{
    if (this->grafo.obterNumeroVertices() == 1)
    {
        return 0;
    }


    return this->obterMaiorNumeroAeroportos();
}
