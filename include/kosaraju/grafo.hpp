#ifndef GRAFO
#define GRAFO

#include <list>
#include <stack>
#include <vector>

#include "kosaraju/scc.hpp"

namespace kosaraju {
    class Grafo
    {
        private:
            int numeroDeVertices;
            std::list<int> *listaDeSaida;
            std::list<int> *listaDeEntrada;
            bool *verticesVisitados;

            std::vector<ComponenteFortementeConexa> *componentesConexas;

            void percorrerOrdemGrafo(int origem, bool verticesVisitados[], std::stack<int> &pilhaVerticesConectadosAVerticesJaExplorados);
            void DFS(int origem, bool verticesVisitados[], ComponenteFortementeConexa &componente);

            void zerarVerticesVisitados();

        public:
            Grafo(int numeroDeVertices);

            void adicionarAresta(int origem, int destino);
            void mapearComponentesConexas();
            void imprimirComponentes();

            Grafo obterGrafoTransposto();
    };

}

#endif