#include "voos/controlador.hpp"

using namespace voos;

Controlador::Controlador(kosaraju::Grafo grafo)
{
    this->grafo = grafo;
    this->numeroNovosVoosAdicionados = 0;
}

void Controlador::inserirArestasParaFormarDAG()
{
    // percorrer as componentes conexas
    // começar da primeira, conectar à segunda
    //    último vértice da primeira com o primeiro da segunda
    // até terminar (não conectar o último componente com o primeiro)

    std::vector<kosaraju::ComponenteFortementeConexa>::iterator i;
    std::vector<kosaraju::ComponenteFortementeConexa>* componentesConexas = this->grafo.obterComponentesConexas();

    int origem = -1;
    int destino = -1;

    for (i = componentesConexas->begin(); i != componentesConexas->end(); i++)
    {
        if (origem == -1)
        {
            origem = i->vertices.back();
        }
        else
        {
            destino = i->vertices.front();
        }
        
        if (origem != -1 && destino != -1)
        {
            bool adicionou = this->grafo.adicionarAresta(origem, destino);
            if (adicionou)
                numeroNovosVoosAdicionados++;
            origem = destino = -1;
        }
    }
}

int Controlador::contarAeroportoQueNaoEhDestino()
{
    std::list<int> *listaDeEntrada = this->grafo.obterListaDeEntrada();

    int numeroAeroportos = 0;

    for (int origem = 0; origem < this->grafo.obterNumeroVertices(); origem++)
    {
        if (listaDeEntrada[origem].size() == 0)
        {
            numeroAeroportos++;
        }
    }

    return numeroAeroportos;
}

int Controlador::contarAeroportoQueNaoEhOrigem()
{
    std::list<int> *listaDeSaida = this->grafo.obterListaDeSaida();

    int numeroAeroportos = 0;

    for (int origem = 0; origem < this->grafo.obterNumeroVertices(); origem++)
    {
        if (listaDeSaida[origem].size() == 0)
        {
            numeroAeroportos++;
        }
    }

    return numeroAeroportos;
}

int Controlador::obterMaiorNumeroAeroportos()
{
    int naoEhOrigem = this->contarAeroportoQueNaoEhOrigem();
    int naoEhDestino = this->contarAeroportoQueNaoEhDestino();

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

    this->inserirArestasParaFormarDAG();


    return this->obterMaiorNumeroAeroportos() + this->numeroNovosVoosAdicionados;
}
