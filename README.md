# Descrição do Problema
## Objetivo

A companhia deseja saber qual o número mínimo de rotas que deverá adicionar a sua rede aérea para fazer com que um dado aeroporto de origem possa atingir qualquer aeroporto de destino

A rede aérea contém um conjunto de aeroportos A = \{1, 2..., n\} operados pela companhia e um conjunto de rotas direcionadas R = \{r1, r2, . . . , rm\}, tal que ri = (u, v) ∈ A × A. 

Cada item de R é composto de um aeroporto de origem _u_ e um aeroporto de destino _v_. **Seu trabalho será encontrar o menor número de rotas adicionais \{rm+1 . . . \} que a companhia deve prover para que seus passageiros possam alcançar qualquer outro aeroporto.** Note que poderá ser necessário para os passageiros fazer várias escalas até chegar no seu destino final.

## Entrada

Primeira linha: *<número de aeroportos (n)> <número de rotas (m)>*

As m linhas seguintes: *<origem (u)> <destino (v)>*

# Descrição da Solução
## Estratégia
1. Utilizar um algoritmo para encontrar as componentes fortemente conexas do grafo. Nesse caso, eu utilizei o algoritmo de Kosaraju.
2.  Então, consideramos cada Componente como um vértice, e buscamos aqueles que **não tem** aresta de entrada e/ou de saída.   
3.  O resultado será o número máximo entre o número de vértices sem aresta de entrada e o número de vértices sem aresta de saída.
    Considerando aqui os vértices do grafo condensado!

_Caso especial: se o grafo só tiver um vértice, o resultado final é 0._

### Como o passo 2 é implementado?
Verificamos que uma componente tem entrada se algum dos seus vértices tem uma aresta de entrada cujo outro vértice for **_externo à componente_**. O mesmo vale pra saída.
