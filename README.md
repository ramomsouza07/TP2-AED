# Segundo Trabalho: Estruturas de Dados com POO (C++) — Sistema de RPG

Este repositório contém a implementação de 11 estruturas de dados clássicas em **C++**, aplicando os pilares da **Programação Orientada a Objetos (POO)** em um sistema interativo com temática de **RPG**. O projeto permite armazenar e manipular **Personagens** e **Equipamentos** de forma polimórfica em listas sequenciais, listas encadeadas, pilhas, filas, deque, árvore binária de busca e grafo.

## Principais Decisões de Design

Para otimizar o funcionamento do sistema e garantir a melhor reutilização de código, tomamos as seguintes decisões de arquitetura:

* **Classes Base e Tema (Polimorfismo):** Criamos a classe base abstrata `Elemento` (contendo o `ID` como chave primária e o método virtual puro `imprimirInfo()`) e as classes derivadas concretas `Personagem` (com `ID`, `nome` e `nivel`) e `Equipamento` (com `ID`, `nomeItem` e `danoBase`). Todas as estruturas armazenam ponteiros `Elemento*`, permitindo guardar personagens e equipamentos juntos sem perda de dados (*object slicing*).

* **Pilhas e Filas Sequenciais (Estáticas):** Nas classes `Pilha` e `Fila`, utilizamos a **Lista Não Ordenada** (`ListaNaoOrdenada`) como base por **composição** (evitando expor métodos indevidos que quebrariam as regras LIFO/FIFO). Além disso, implementamos a **Fila Circular** (`FilaCircular`) utilizando aritmética modular (`%`) para garantir enfileiramento e desenfileiramento em **O(1)** sem deslocamento de elementos no vetor.

* **Pilhas, Filas e Deque Dinâmicos (Encadeados):**
  * Nas classes `PilhaEnc` e `FilaEnc`, utilizamos a **Lista Simplesmente Encadeada** (`ListaSimples`) por composição. Como a `ListaSimples` mantém ponteiros para o início (`prim`) e o fim (`ult`), as operações de topo da pilha (no início) e de fila (inserção no fim e remoção no início) ocorrem em **O(1)**.
  * Na classe `Deque` (fila de duas pontas), utilizamos a **Lista Duplamente Encadeada** (`ListaDupla`) por composição, pois o ponteiro anterior (`ant`) permite remover também do final em **O(1)**.

* **Encapsulamento Oculto:** Em estruturas dinâmicas como as Listas Encadeadas (`ListaSimples`, `ListaDupla`, `ListaCircular`), a Árvore Binária de Busca (`Arvore`) e o Grafo Ponderado (`Grafo`), as estruturas internas de nós (`No`, `Vertice`, `Aresta`) foram mantidas estritamente privadas, invisíveis para o usuário final.

## Tabela de Complexidade

Abaixo está o resumo da complexidade de tempo computacional das operações implementadas no projeto:

| Estrutura | Inserção (Início) | Inserção (Final) | Remoção | Busca |
| --- | --- | --- | --- | --- |
| **Lista Não Ordenada (`ListaNaoOrdenada`)** | O(n) | O(1) | Fim: O(1) / Início ou ID: O(n) * | O(n) |
| **Lista Ordenada (`ListaOrdenada`)** | O(n) | O(n) | O(n) | O(log n) ** |
| **Lista Encadeada Simples (`ListaSimples`)** | O(1) | O(1) | Início: O(1) / ID: O(n) | O(n) |
| **Lista Duplamente Encadeada (`ListaDupla`)** | O(1) | O(1) | Início e Fim: O(1) / ID: O(n) | O(n) |
| **Lista Dupla. Enc. Circular (`ListaCircular`)** | O(1) | O(1) | ID: O(n) | O(n) |
| **Pilha (`Pilha` / `PilhaEnc`)** | O(1) (Topo) | — | O(1) (Topo) | O(1) *** |
| **Fila Sequencial (`Fila`)** | — | O(1) | O(n) (desloca vetor) | O(1) *** |
| **Fila Circular / Encadeada (`FilaCircular` / `FilaEnc`)** | — | O(1) | O(1) | O(1) *** |
| **Deque (`Deque`)** | O(1) | O(1) | Início e Fim: O(1) | — |
| **Árvore Binária de Busca (`Arvore`)** | O(log n) **** | — | O(log n) **** | O(log n) **** |
| **Grafo Lista de Adjacência (`Grafo`)** | Vértice: O(V) / Aresta: O(V + A) | — | Vértice / Aresta: O(V + A) | O(V) (BFS/DFS: O(V + A)) |

> **Observações:**
> * \* Na `ListaNaoOrdenada`, a remoção por ID localiza o item em O(n) e substitui pelo último elemento do vetor em O(1), evitando deslocamentos.
> * \*\* A busca na `ListaOrdenada` foi otimizada utilizando **Busca Binária**.
> * \*\*\* Referente à consulta do Topo (`Pilha`) e Frente (`Fila`).
> * \*\*\*\* Na Árvore Binária de Busca (`Arvore`), O(log n) é o caso médio (árvore balanceada). No pior caso (inserção ordenada / árvore degenerada), a complexidade cai para O(n).

## 💻 Tecnologias Utilizadas

* **C++** (Programação Orientada a Objetos)

## 👥 Integrantes do Grupo

* Antônio Neto
* Eduardo Molica
* Matheus Santiago
* Ramom Souza
* Vinícius Melo
