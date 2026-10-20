# Segundo Trabalho: Estruturas de Dados com POO (C++)

Este repositório contém a implementação de diversas estruturas de dados clássicas em **C++**, aplicando os pilares da **Programação Orientada a Objetos (POO)**. O projeto foca no uso correto de herança, polimorfismo, encapsulamento e na eficiência das operações.

## Principais Decisões de Design

Para otimizar o funcionamento do sistema e garantir a melhor reutilização de código, tomamos as seguintes decisões de arquitetura:

* **Classes Base (Polimorfismo):** Criamos a classe abstrata `Elemento` (tendo o ID como chave primária) e as classes derivadas concretas `Pessoa` e `Maquina` para realizar os testes no sistema.


* **Pilhas e Filas Estáticas:** Utilizamos a **Lista Não Ordenada** como base (por composição). Optamos por não usar a lista ordenada porque manter a ordenação adicionaria uma complexidade desnecessária e atrapalharia o funcionamento correto das lógicas LIFO (Pilha) e FIFO (Fila).


* **Pilhas e Filas Dinâmicas:** Utilizamos a **Lista Duplamente Encadeada Circular** como base. Essa escolha foi feita porque essa estrutura permite o controle fácil de ambas as pontas, garantindo inserções e remoções com custo temporal de **O(1)** e evitando o tratamento de casos especiais.


* **Encapsulamento Oculto:** Em estruturas como a Árvore Binária de Busca (BST) e as listas encadeadas, a classe dos "nós" foi mantida estritamente privada, invisível para o usuário final.



## Tabela de Complexidade

Abaixo está o resumo da complexidade de tempo computacional das operações implementadas:

| Estrutura | Inserção (Início) | Inserção (Final) | Remoção | Busca |
| --- | --- | --- | --- | --- |
| **Lista Não Ordenada (Estática)** | O(1) | O(1) | O(n) | O(n) |
| **Lista Ordenada (Estática)** | O(n) | O(n) | O(n) | O(log n) * |
| **Lista Encadeada Simples** | O(1) | O(n) | O(n) | O(n) |
| **Lista Duplamente Encadeada** | O(1) | O(1) | O(n) | O(n) |
| **Lista Dupla. Enc. Circular** | O(1) | O(1) | O(n) | O(n) |
| **Pilha (Estática / Dinâmica)** | O(1) | — | O(1) | O(1) ** |
| **Fila (Estática / Dinâmica)** | — | O(1) | O(1) | O(1) ** |
| **Árvore Binária de Busca** | O(log n) *** | — | O(log n) *** | O(log n) *** |

> **Observações:**
> 
> 
> * A busca na Lista Ordenada foi otimizada utilizando Busca Binária.
> ** Referente à busca do Topo (Pilha) e Frente (Fila).
> *** Na BST, essa é a complexidade média (árvore balanceada). No pior caso (árvore degenerada), a complexidade cai para O(n).
> 
> 

## 💻 Tecnologias Utilizadas

* **C++** (Programação Orientada a Objetos)



## 👥 Integrantes do Grupo

* Antônio Neto


* Eduardo Molica


* Matheus Santiago


* Ramom Souza


* Vinícius Melo
