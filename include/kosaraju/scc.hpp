#ifndef SCC
#define SCC

#include <vector>

namespace kosaraju {
    class ComponenteFortementeConexa
    {
        public:
            std::vector<int> vertices;

            ComponenteFortementeConexa();

            void adicionarVertice(int vertice);
    };

}

#endif