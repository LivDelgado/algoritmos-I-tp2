#ifndef GERADOR
#define GERADOR

#include <string>
#include <iostream>

#include "kosaraju/grafo.hpp"

namespace leitura
{
    class GeradorGrafo
    {
        public:
            GeradorGrafo();
            kosaraju::Grafo gerarGrafo();
    };

}

#endif