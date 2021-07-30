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

            int contarAeroportoQueNaoEhOrigem();
            int contarAeroportoQueNaoEhDestino();

            int obterMaiorNumeroAeroportos();

        public:
            Controlador(kosaraju::Grafo grafo);

            int contarMinimoNumeroVoosAdicionar();

    };

}

#endif