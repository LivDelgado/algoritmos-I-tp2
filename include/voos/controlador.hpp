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

            int obterMaiorNumeroAeroportos();

            bool componenteTemVertice(kosaraju::ComponenteFortementeConexa componente, int vertice);
            bool componenteTemEntrada(kosaraju::ComponenteFortementeConexa componente);
            bool componenteTemSaida(kosaraju::ComponenteFortementeConexa componente);

        public:
            Controlador(kosaraju::Grafo grafo);

            int contarMinimoNumeroVoosAdicionar();

    };

}

#endif