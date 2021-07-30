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

bool Controlador::componenteTemVertice(kosaraju::ComponenteFortementeConexa componente, int vertice)
{
    return std::find(componente.vertices.begin(), componente.vertices.end(), vertice) != componente.vertices.end();
}

kosaraju::ComponenteFortementeConexa Controlador::obterComponenteQueTemVertice(int vertice)
{
    for (kosaraju::ComponenteFortementeConexa componente : *this->grafo.obterComponentesConexas())
    {
        if (componenteTemVertice(componente, vertice))
        {
            return componente;
        }
    }

    return kosaraju::ComponenteFortementeConexa();
}

bool Controlador::todosOsVerticesEstaoNaComponente(std::list<int> vertices, kosaraju::ComponenteFortementeConexa componente)
{
    for (int vertice : vertices)
    {
        if (!componenteTemVertice(componente, vertice))
        {
            return false;
        }
    }

    return true;
}

int Controlador::contarAeroportoQueNaoEhDestino()
{
    std::list<int> *listaDeEntrada = this->grafo.obterListaDeEntrada();

    int numeroAeroportos = 0;

    for (int origem = 0; origem < this->grafo.obterNumeroVertices(); origem++)
    {
        // se não tiver destino ou se tiver e fizer parte de componente

        // obter componente que tem vertice
        // verificar se tem algum que não é parte da componente -> se sim, não incrementa
        kosaraju::ComponenteFortementeConexa componenteQueTemVertice = obterComponenteQueTemVertice(origem);
        if (listaDeEntrada[origem].size() == 0 || 
           !todosOsVerticesEstaoNaComponente(listaDeEntrada[origem], componenteQueTemVertice))
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
        // se não tiver destino ou se tiver e fizer parte de componente

        // obter componente que tem vertice
        // verificar se tem algum que não é parte da componente -> se sim, não incrementa
        kosaraju::ComponenteFortementeConexa componenteQueTemVertice = obterComponenteQueTemVertice(origem);
        if (listaDeSaida[origem].size() == 0 || 
           !todosOsVerticesEstaoNaComponente(listaDeSaida[origem], componenteQueTemVertice))
        {
            numeroAeroportos++;
        }
    }

    return numeroAeroportos;
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
