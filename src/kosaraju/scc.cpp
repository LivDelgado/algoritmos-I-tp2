#include "kosaraju/scc.hpp"

#include <iostream>

using namespace kosaraju;

ComponenteFortementeConexa::ComponenteFortementeConexa()
{
    this->vertices = std::vector<int>();
}

void ComponenteFortementeConexa::adicionarVertice(int vertice)
{
    this->vertices.push_back(vertice);
}
