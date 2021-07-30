#ifndef CONTROLADOR
#define CONTROLADOR

#include <list>
#include <stack>
#include <vector>

#include "kosaraju/grafo.hpp"

namespace voos
{
    class Controlador
    {
        private:
            int numeroNovosVoosAdicionados;

            kosaraju::Grafo grafo;

            void inserirArestasParaFormarDAG();

            kosaraju::ComponenteFortementeConexa obterComponenteQueTemVertice(int vertice);

            int contarAeroportoQueNaoEhOrigem();
            int contarAeroportoQueNaoEhDestino();

            int obterMaiorNumeroAeroportos();

            bool todosOsVerticesEstaoNaComponente(std::list<int> vertices, kosaraju::ComponenteFortementeConexa componente);
            
            bool componenteTemVertice(kosaraju::ComponenteFortementeConexa componente, int vertice);
            bool componenteTemEntrada(kosaraju::ComponenteFortementeConexa componente);
            bool componenteTemSaida(kosaraju::ComponenteFortementeConexa componente);

        public:
            Controlador(kosaraju::Grafo grafo);

            int contarMinimoNumeroVoosAdicionar();

    };

}

#endif