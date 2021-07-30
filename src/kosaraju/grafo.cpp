#include "kosaraju/grafo.hpp"

#include <iostream>

using namespace kosaraju;


Grafo::Grafo(int numeroDeVertices)
{
    this->numeroDeVertices = numeroDeVertices;
    this->listaDeSaida = new std::list<int>[numeroDeVertices];
    this->listaDeEntrada = new std::list<int>[numeroDeVertices];
    this->verticesVisitados = new bool[numeroDeVertices];
    this->zerarVerticesVisitados();

    this->componentesConexas = new std::vector<ComponenteFortementeConexa>();
}

void Grafo::DFS(int origem, bool verticesVisitados[], ComponenteFortementeConexa &componente)
{
    verticesVisitados[origem] = true;

    componente.adicionarVertice(origem);

    std::list<int>::iterator i;

    for (i = listaDeSaida[origem].begin(); i != listaDeSaida[origem].end(); i++)
    {
        if (!verticesVisitados[*i])
        {
            DFS(*i, verticesVisitados, componente);
        }
    }
}

Grafo Grafo::obterGrafoTransposto()
{
    Grafo grafoTransposto(numeroDeVertices);

    for (int origem = 0; origem < numeroDeVertices; origem++)
    {
        std::list<int>::iterator i;

        for (i = listaDeSaida[origem].begin(); i != listaDeSaida[origem].end(); ++i)
        {
            grafoTransposto.listaDeSaida[*i].push_back(origem);
        }
    }

    return grafoTransposto;
}

void Grafo::adicionarAresta(int origem, int destino)
{
    listaDeSaida[origem].push_back(destino);
    listaDeEntrada[destino].push_back(origem);
}

void Grafo::percorrerOrdemGrafo(int origem, bool verticesVisitados[], std::stack<int> &pilhaVerticesConectadosAVerticesJaExplorados)
{
    verticesVisitados[origem] = true;

    std::list<int>::iterator i;

    for (i = listaDeSaida[origem].begin(); i != listaDeSaida[origem].end(); ++i)
    {
        if (!verticesVisitados[*i])
        {
            percorrerOrdemGrafo(*i, verticesVisitados, pilhaVerticesConectadosAVerticesJaExplorados);
        }
    }

    pilhaVerticesConectadosAVerticesJaExplorados.push(origem);
}

void Grafo::mapearComponentesConexas()
{
    std::stack<int> pilhaVerticesConectadosAVerticesJaExplorados;

    for (int i = 0; i < numeroDeVertices; i++)
    {
        if (verticesVisitados[i] == false)
        {
            percorrerOrdemGrafo(i, verticesVisitados, pilhaVerticesConectadosAVerticesJaExplorados);
        }
    }

    Grafo grafoTransposto = obterGrafoTransposto();

    this->zerarVerticesVisitados();

    while (!pilhaVerticesConectadosAVerticesJaExplorados.empty())
    {
        int origem = pilhaVerticesConectadosAVerticesJaExplorados.top();
        pilhaVerticesConectadosAVerticesJaExplorados.pop();

        if (verticesVisitados[origem] == false)
        {
            ComponenteFortementeConexa *componente = new ComponenteFortementeConexa();
            grafoTransposto.DFS(origem, verticesVisitados, *componente);
            this->componentesConexas->push_back(*componente);
        }
    }
}

void Grafo::zerarVerticesVisitados()
{
    for (int i = 0; i < this->numeroDeVertices; i++) {
        this->verticesVisitados[i] = false;
    }
}

void Grafo::imprimirComponentes()
{
    std::vector<ComponenteFortementeConexa>::iterator i;

    for (i = this->componentesConexas->begin(); i != this->componentesConexas->end(); i++)
    {
        std::vector<int>::iterator j;
        for (j = i->vertices->begin(); j != i->vertices->end(); j++)
        {
            std::cout << (*j) << " ";
        }

        std::cout << std::endl;
    }

}
