#ifndef GRAFO
#define GRAFO

#include <list>
#include <stack>
#include <vector>
#include <algorithm>

#include "kosaraju/scc.hpp"

namespace kosaraju 
{
    class Grafo
    {
        private:
            int numeroDeVertices;

            // esses vetores contém <numeroDeVertices> posições, em que cada posição é uma lista de vértices
            std::list<int> *listaDeSaida; // aqui ele sai do índice e vai pros vértices da lista
            std::list<int> *listaDeEntrada; // aqui ele sai dos vértices da lista e vai pro index

            bool *verticesVisitados;

            std::vector<ComponenteFortementeConexa> componentesConexas;

            void percorrerOrdemGrafo(int origem, bool verticesVisitados[], std::stack<int> &pilhaVerticesConectadosAVerticesJaExplorados);
            void DFS(int origem, bool verticesVisitados[], ComponenteFortementeConexa &componente);

            void zerarVerticesVisitados();

        public:
            Grafo(int numeroDeVertices);
            Grafo();

            bool adicionarAresta(int origem, int destino);
            void mapearComponentesConexas();
            void imprimirComponentes();

            Grafo obterGrafoTransposto();
            int obterNumeroVertices();
            std::list<int> *obterListaDeSaida();
            std::list<int> *obterListaDeEntrada();
            std::vector<ComponenteFortementeConexa>* obterComponentesConexas();
    };

}

#endif