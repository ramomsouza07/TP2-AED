#include <iostream>
#include <string>
// Classes POO do tema (Personagem e Equipamento herdam da classe abstrata Elemento)
#include "headers/Personagem.h"
#include "headers/Equipamento.h"
// Estruturas de Dados
#include "headers/ListaNaoOrdenada.h"
#include "headers/ListaOrdenada.h"
#include "headers/Pilha.h"
#include "headers/Fila.h"
#include "headers/FilaCircular.h"
#include "headers/ListaSimples.h"
#include "headers/ListaDupla.h"
#include "headers/ListaCircular.h"
#include "headers/PilhaEnc.h"
#include "headers/FilaEnc.h"
#include "headers/Deque.h"
#include "headers/Arvore.h"
#include "headers/Grafo.h"

using namespace std;

int main() {
    int opcaoPrincipal = 0;

    // loop do menu principal
    while (opcaoPrincipal != 5) {
        cout << "\n================ MENU ================" << endl;
        cout << "1: Operar em Listas Sequenciais" << endl;
        cout << "2: Operar em Listas de Alocacao Dinamica" << endl;
        cout << "3: Operar Pilhas, Filas e Deques" << endl;
        cout << "4: Operar Arvores e Grafos" << endl;
        cout << "5: Finalizar o sistema" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcaoPrincipal;

        // 1: Listas Sequenciais (alocacao estatica com vetor)
        if (opcaoPrincipal == 1) {
            int opcaoSeq = 0;
            while (opcaoSeq != 3) {
                cout << "\n--- LISTAS SEQUENCIAIS ---" << endl;
                cout << "1: Lista Nao Ordenada" << endl;
                cout << "2: Lista Ordenada" << endl;
                cout << "3: Voltar" << endl;
                cout << "Opcao: ";
                cin >> opcaoSeq;

                // Lista Sequencial Nao Ordenada
                if (opcaoSeq == 1) {
                    // [POO - Encapsulamento]: o vetor interno e privado, acessamos so pelos metodos publicos
                    ListaNaoOrdenada lista(50);
                    int opLista = 0;

                    while (opLista != 9) {
                        cout << "\n[Lista Nao Ordenada]" << endl;
                        cout << "1: Inserir no Inicio" << endl;
                        cout << "2: Inserir no Final" << endl;
                        cout << "3: Remover Primeiro" << endl;
                        cout << "4: Remover Ultimo" << endl;
                        cout << "5: Remover Pelo ID" << endl;
                        cout << "6: Buscar Pelo ID" << endl;
                        cout << "7: Alterar Pelo ID" << endl;
                        cout << "8: Imprimir Lista" << endl;
                        cout << "9: Voltar" << endl;
                        cout << "Opcao: ";
                        cin >> opLista;

                        // insercao no inicio ou no final
                        if (opLista == 1 || opLista == 2) {
                            int tipo;
                            cout << "1: Personagem | 2: Equipamento: ";
                            cin >> tipo;

                            long id;
                            cout << "ID: ";
                            cin >> id;
                            cin.ignore(); // limpa o enter antes do getline

                            // [POO - Abstracao e Polimorfismo]: ponteiro da classe abstrata Elemento*
                            // recebe objetos das classes filhas Personagem ou Equipamento (upcasting)
                            Elemento* e = NULL;
                            if (tipo == 1) {
                                string nome;
                                int nivel;
                                cout << "Nome: ";
                                getline(cin, nome);
                                cout << "Nivel: ";
                                cin >> nivel;
                                e = new Personagem(id, nome, nivel); // [POO - Heranca]: Personagem herda de Elemento
                            } else if (tipo == 2) {
                                string nomeItem;
                                int dano;
                                cout << "Nome: ";
                                getline(cin, nomeItem);
                                cout << "Dano: ";
                                cin >> dano;
                                e = new Equipamento(id, nomeItem, dano); // [POO - Heranca]: Equipamento herda de Elemento
                            } else {
                                cout << "Tipo invalido!" << endl;
                                continue;
                            }

                            int deuCerto = 0;
                            if (opLista == 1) deuCerto = lista.InserirNoInicio(e);
                            else deuCerto = lista.InserirNoFinal(e);

                            if (deuCerto == 1) cout << "Inserido!" << endl;
                            else cout << "Erro: lista cheia." << endl;

                        // remocoes nas pontas e pelo ID
                        } else if (opLista == 3) {
                            if (lista.RemoverPrimeiro() == 1) cout << "Primeiro removido!" << endl;
                            else cout << "Lista vazia." << endl;

                        } else if (opLista == 4) {
                            if (lista.RemoverUltimo() == 1) cout << "Ultimo removido!" << endl;
                            else cout << "Lista vazia." << endl;

                        } else if (opLista == 5) {
                            long id;
                            cout << "ID para remover: ";
                            cin >> id;
                            if (lista.RemoverPeloId(id) == 1) cout << "Removido!" << endl;
                            else cout << "ID nao encontrado." << endl;

                        // busca sequencial pelo ID
                        } else if (opLista == 6) {
                            long id;
                            cout << "ID para buscar: ";
                            cin >> id;
                            Elemento* achou = lista.BuscarPeloId(id);
                            // [POO - Polimorfismo]: chama em tempo de execucao o imprimirInfo() de Personagem ou Equipamento
                            if (achou != NULL) achou->imprimirInfo();
                            else cout << "ID nao encontrado." << endl;

                        // substitui um elemento existente por um novo a partir do ID
                        } else if (opLista == 7) {
                            long idAntigo;
                            cout << "ID do elemento que deseja alterar: ";
                            cin >> idAntigo;

                            int tipo;
                            cout << "Novo elemento - 1: Personagem | 2: Equipamento: ";
                            cin >> tipo;
                            long novoId;
                            cout << "Novo ID: ";
                            cin >> novoId;
                            cin.ignore();

                            Elemento* novo = NULL;
                            if (tipo == 1) {
                                string nome;
                                int nivel;
                                cout << "Nome: ";
                                getline(cin, nome);
                                cout << "Nivel: ";
                                cin >> nivel;
                                novo = new Personagem(novoId, nome, nivel);
                            } else if (tipo == 2) {
                                string nomeItem;
                                int dano;
                                cout << "Nome: ";
                                getline(cin, nomeItem);
                                cout << "Dano: ";
                                cin >> dano;
                                novo = new Equipamento(novoId, nomeItem, dano);
                            } else {
                                cout << "Tipo invalido!" << endl;
                                continue;
                            }

                            if (lista.AlterarPeloId(idAntigo, novo) == 1) cout << "Alterado!" << endl;
                            else cout << "ID nao encontrado." << endl;

                        } else if (opLista == 8) {
                            lista.imprimirTodos();
                        }
                    }
                // Lista Sequencial Ordenada (mantem os IDs em ordem crescente)
                } else if (opcaoSeq == 2) {
                    ListaOrdenada listaOrd(50);
                    int opLista = 0;

                    while (opLista != 8) {
                        cout << "\n[Lista Ordenada]" << endl;
                        cout << "1: Inserir Elemento" << endl;
                        cout << "2: Remover Primeiro" << endl;
                        cout << "3: Remover Ultimo" << endl;
                        cout << "4: Remover Pelo ID" << endl;
                        cout << "5: Buscar Pelo ID" << endl;
                        cout << "6: Alterar Pelo ID" << endl;
                        cout << "7: Imprimir Lista" << endl;
                        cout << "8: Voltar" << endl;
                        cout << "Opcao: ";
                        cin >> opLista;

                        // insere ja na posicao ordenada pelo ID (nao aceita ID repetido)
                        if (opLista == 1) {
                            int tipo;
                            cout << "1: Personagem | 2: Equipamento: ";
                            cin >> tipo;

                            long id;
                            cout << "ID: ";
                            cin >> id;
                            cin.ignore();

                            Elemento* e = NULL;
                            if (tipo == 1) {
                                string nome;
                                int nivel;
                                cout << "Nome: ";
                                getline(cin, nome);
                                cout << "Nivel: ";
                                cin >> nivel;
                                e = new Personagem(id, nome, nivel);
                            } else if (tipo == 2) {
                                string nomeItem;
                                int dano;
                                cout << "Nome: ";
                                getline(cin, nomeItem);
                                cout << "Dano: ";
                                cin >> dano;
                                e = new Equipamento(id, nomeItem, dano);
                            } else {
                                cout << "Tipo invalido!" << endl;
                                continue;
                            }

                            if (listaOrd.Inserir(e) == 1) cout << "Inserido!" << endl;
                            else cout << "Erro: ID ja existe ou lista cheia." << endl;

                        } else if (opLista == 2) {
                            if (listaOrd.RemoverPrimeiro() == 1) cout << "Primeiro removido!" << endl;
                            else cout << "Lista vazia." << endl;

                        } else if (opLista == 3) {
                            if (listaOrd.RemoverUltimo() == 1) cout << "Ultimo removido!" << endl;
                            else cout << "Lista vazia." << endl;

                        } else if (opLista == 4) {
                            long idBusca;
                            cout << "ID para remover: ";
                            cin >> idBusca;
                            if (listaOrd.RemoverPeloId(idBusca) == 1) cout << "Removido!" << endl;
                            else cout << "ID nao encontrado." << endl;

                        // busca pelo ID usando busca binaria O(log n)
                        } else if (opLista == 5) {
                            long idBusca;
                            cout << "ID para buscar: ";
                            cin >> idBusca;
                            Elemento* achou = listaOrd.BuscarPeloId(idBusca);
                            if (achou != NULL) achou->imprimirInfo();
                            else cout << "ID nao encontrado." << endl;

                        // remove o antigo e reinsere o novo mantendo a ordenacao
                        } else if (opLista == 6) {
                            long idAntigo;
                            cout << "ID do elemento que deseja alterar: ";
                            cin >> idAntigo;

                            int tipo;
                            cout << "Novo elemento - 1: Personagem | 2: Equipamento: ";
                            cin >> tipo;
                            long novoId;
                            cout << "Novo ID: ";
                            cin >> novoId;
                            cin.ignore();

                            Elemento* novo = NULL;
                            if (tipo == 1) {
                                string nome;
                                int nivel;
                                cout << "Nome: ";
                                getline(cin, nome);
                                cout << "Nivel: ";
                                cin >> nivel;
                                novo = new Personagem(novoId, nome, nivel);
                            } else if (tipo == 2) {
                                string nomeItem;
                                int dano;
                                cout << "Nome: ";
                                getline(cin, nomeItem);
                                cout << "Dano: ";
                                cin >> dano;
                                novo = new Equipamento(novoId, nomeItem, dano);
                            } else {
                                cout << "Tipo invalido!" << endl;
                                continue;
                            }

                            if (listaOrd.AlterarPeloId(idAntigo, novo) == 1) cout << "Alterado!" << endl;
                            else cout << "Erro ao alterar." << endl;

                        } else if (opLista == 7) {
                            listaOrd.imprimirTodos();
                        }
                    }
                }
            }
        // 2: Listas de Alocacao Dinamica (Simples, Dupla e Circular)
        } else if (opcaoPrincipal == 2) {
            int opDin = 0;
            while (opDin != 4) {
                cout << "\n--- LISTAS ENCADEADAS ---" << endl;
                cout << "1: Simples | 2: Dupla | 3: Circular | 4: Voltar\nOpcao: ";
                cin >> opDin;
                if (opDin < 1 || opDin > 3) break;

                // instancia as tres listas encadeadas
                ListaSimples ls;
                ListaDupla ld;
                ListaCircular lc;

                int op = 0;
                while (op != 6) {
                    cout << "\n1: Inserir Inicio | 2: Inserir Fim | 3: Remover ID | 4: Buscar ID | 5: Imprimir | 6: Voltar\nOpcao: ";
                    cin >> op;

                    // insercao no inicio ou no fim da lista escolhida
                    if (op == 1 || op == 2) {
                        int tipo;
                        cout << "1: Personagem | 2: Equipamento: ";
                        cin >> tipo;
                        long id;
                        cout << "ID: ";
                        cin >> id;
                        cin.ignore();

                        Elemento* e = NULL;
                        if (tipo == 1) {
                            string nome; int nivel;
                            cout << "Nome: "; getline(cin, nome);
                            cout << "Nivel: "; cin >> nivel;
                            e = new Personagem(id, nome, nivel);
                        } else if (tipo == 2) {
                            string nome; int dano;
                            cout << "Nome: "; getline(cin, nome);
                            cout << "Dano: "; cin >> dano;
                            e = new Equipamento(id, nome, dano);
                        } else continue;

                        // direciona para a lista escolhida (1: Simples, 2: Dupla, 3: Circular)
                        if (opDin == 1) {
                            if (op == 1) ls.insereInicio(e);
                            else ls.insereFim(e);
                        } else if (opDin == 2) {
                            if (op == 1) ld.insereInicio(e);
                            else ld.insereFim(e);
                        } else {
                            if (op == 1) lc.insereInicio(e);
                            else lc.insereFim(e);
                        }
                        cout << "Inserido!" << endl;
                        
                    // remocao pelo ID
                    } else if (op == 3) {
                        long id;
                        cout << "ID para remover: ";
                        cin >> id;
                        int ok = 0;
                        if (opDin == 1) ok = ls.remove(id);
                        else if (opDin == 2) ok = ld.remove(id);
                        else ok = lc.remove(id);

                        if (ok) cout << "Removido!" << endl;
                        else cout << "ID nao encontrado." << endl;

                    // busca pelo ID
                    } else if (op == 4) {
                        long id;
                        cout << "ID para buscar: ";
                        cin >> id;
                        Elemento* achou = NULL;
                        if (opDin == 1) achou = ls.busca(id);
                        else if (opDin == 2) achou = ld.busca(id);
                        else achou = lc.busca(id);

                        if (achou != NULL) achou->imprimirInfo();
                        else cout << "ID nao encontrado." << endl;

                    } else if (op == 5) {
                        if (opDin == 1) ls.imprime();
                        else if (opDin == 2) ld.imprime();
                        else lc.imprime();
                    }
                }
            }
        // 3: Pilhas, Filas e Deques ([POO - Composicao]: usam uma lista privada internamente)
        } else if (opcaoPrincipal == 3) {
            int opcaoPFD = 0;
            while (opcaoPFD != 5) {
                cout << "\n--- Pilhas, Filas e Deques ---" << endl;
                cout << "1: Pilha (sequencial)" << endl;
                cout << "2: Fila (sequencial, menos eficiente)" << endl;
                cout << "3: Fila Circular (sequencial, eficiente)" << endl;
                cout << "4: Pilha, Fila e Deque (encadeados)" << endl;
                cout << "5: Voltar" << endl;
                cout << "Opcao: ";
                cin >> opcaoPFD;

                // Pilha Sequencial ([POO - Composicao] com ListaNaoOrdenada | LIFO em O(1))
                if (opcaoPFD == 1) {
                    Pilha pilha(50);
                    int opPilha = 0;
                    while (opPilha != 6) {
                        cout << "\n[Pilha]" << endl;
                        cout << "1: Empilhar" << endl;
                        cout << "2: Desempilhar" << endl;
                        cout << "3: Consultar Topo" << endl;
                        cout << "4: Verificar se esta Cheia" << endl;
                        cout << "5: Verificar se esta Vazia" << endl;
                        cout << "6: Voltar" << endl;
                        cout << "Opcao: ";
                        cin >> opPilha;

                        if (opPilha == 1) {
                            int tipo;
                            cout << "1: Personagem | 2: Equipamento: ";
                            cin >> tipo;

                            long id;
                            cout << "ID: ";
                            cin >> id;
                            cin.ignore();

                            Elemento* e = NULL;
                            if (tipo == 1) {
                                string nome;
                                int nivel;
                                cout << "Nome: ";
                                getline(cin, nome);
                                cout << "Nivel: ";
                                cin >> nivel;
                                e = new Personagem(id, nome, nivel);
                            } else if (tipo == 2) {
                                string nomeItem;
                                int dano;
                                cout << "Nome: ";
                                getline(cin, nomeItem);
                                cout << "Dano: ";
                                cin >> dano;
                                e = new Equipamento(id, nomeItem, dano);
                            } else {
                                cout << "Tipo invalido!" << endl;
                                continue;
                            }

                            if (pilha.empilhar(e)) {
                                cout << "Empilhado!" << endl;
                            } else {
                                cout << "Erro: Pilha cheia." << endl;
                            }
                        } else if (opPilha == 2) {
                            if (pilha.desempilhar()) {
                                cout << "Desempilhado!" << endl;
                            } else {
                                cout << "Pilha vazia." << endl;
                            }
                        } else if (opPilha == 3) {
                            Elemento* topo = pilha.consultarTopo();
                            if (topo != NULL) {
                                topo->imprimirInfo();
                            } else {
                                cout << "Pilha vazia." << endl;
                            }
                        } else if (opPilha == 4) {
                            if (pilha.pilhaCheia()) cout << "A pilha esta cheia." << endl;
                            else cout << "A pilha nao esta cheia." << endl;
                        } else if (opPilha == 5) {
                            if (pilha.pilhaVazia()) cout << "A pilha esta vazia." << endl;
                            else cout << "A pilha nao esta vazia." << endl;
                        }
                    }
                // Fila Sequencial comum (FIFO: desenfileirar desloca o vetor em O(n))
                } else if (opcaoPFD == 2) {
                    Fila fila(50);
                    int opFila = 0;
                    while (opFila != 6) {
                        cout << "\n[Fila]" << endl;
                        cout << "1: Enfileirar" << endl;
                        cout << "2: Desenfileirar" << endl;
                        cout << "3: Consultar Inicio" << endl;
                        cout << "4: Verificar se esta Cheia" << endl;
                        cout << "5: Verificar se esta Vazia" << endl;
                        cout << "6: Voltar" << endl;
                        cout << "Opcao: ";
                        cin >> opFila;

                        if (opFila == 1) {
                            int tipo;
                            cout << "1: Personagem | 2: Equipamento: ";
                            cin >> tipo;

                            long id;
                            cout << "ID: ";
                            cin >> id;
                            cin.ignore();

                            Elemento* e = NULL;
                            if (tipo == 1) {
                                string nome;
                                int nivel;
                                cout << "Nome: ";
                                getline(cin, nome);
                                cout << "Nivel: ";
                                cin >> nivel;
                                e = new Personagem(id, nome, nivel);
                            } else if (tipo == 2) {
                                string nomeItem;
                                int dano;
                                cout << "Nome: ";
                                getline(cin, nomeItem);
                                cout << "Dano: ";
                                cin >> dano;
                                e = new Equipamento(id, nomeItem, dano);
                            } else {
                                cout << "Tipo invalido!" << endl;
                                continue;
                            }

                            if (fila.enfileirar(e)) {
                                cout << "Enfileirado!" << endl;
                            } else {
                                cout << "Erro: Fila cheia." << endl;
                            }
                        } else if (opFila == 2) {
                            if (fila.desenfileirar()) {
                                cout << "Desenfileirado!" << endl;
                            } else {
                                cout << "Fila vazia." << endl;
                            }
                        } else if (opFila == 3) {
                            Elemento* inicio = fila.consultarInicio();
                            if (inicio != NULL) {
                                inicio->imprimirInfo();
                            } else {
                                cout << "Fila vazia." << endl;
                            }
                        } else if (opFila == 4) {
                            if (fila.filaCheia()) cout << "A fila esta cheia." << endl;
                            else cout << "A fila nao esta cheia." << endl;
                        } else if (opFila == 5) {
                            if (fila.filaVazia()) cout << "A fila esta vazia." << endl;
                            else cout << "A fila nao esta vazia." << endl;
                        }
                    }
                // Fila Circular (FIFO eficiente: usa operador % para inserir e remover em O(1))
                } else if (opcaoPFD == 3) {
                    FilaCircular filaCirc(50);
                    int opFilaCirc = 0;
                    while (opFilaCirc != 6) {
                        cout << "\n[Fila Circular]" << endl;
                        cout << "1: Enfileirar" << endl;
                        cout << "2: Desenfileirar" << endl;
                        cout << "3: Consultar Inicio" << endl;
                        cout << "4: Verificar se esta Cheia" << endl;
                        cout << "5: Verificar se esta Vazia" << endl;
                        cout << "6: Voltar" << endl;
                        cout << "Opcao: ";
                        cin >> opFilaCirc;

                        if (opFilaCirc == 1) {
                            int tipo;
                            cout << "1: Personagem | 2: Equipamento: ";
                            cin >> tipo;

                            long id;
                            cout << "ID: ";
                            cin >> id;
                            cin.ignore();

                            Elemento* e = NULL;
                            if (tipo == 1) {
                                string nome;
                                int nivel;
                                cout << "Nome: ";
                                getline(cin, nome);
                                cout << "Nivel: ";
                                cin >> nivel;
                                e = new Personagem(id, nome, nivel);
                            } else if (tipo == 2) {
                                string nomeItem;
                                int dano;
                                cout << "Nome: ";
                                getline(cin, nomeItem);
                                cout << "Dano: ";
                                cin >> dano;
                                e = new Equipamento(id, nomeItem, dano);
                            } else {
                                cout << "Tipo invalido!" << endl;
                                continue;
                            }

                            if (filaCirc.enfileirar(e)) {
                                cout << "Enfileirado!" << endl;
                            } else {
                                cout << "Erro: Fila circular cheia." << endl;
                            }
                        } else if (opFilaCirc == 2) {
                            if (filaCirc.desenfileirar()) {
                                cout << "Desenfileirado!" << endl;
                            } else {
                                cout << "Fila circular vazia." << endl;
                            }
                        } else if (opFilaCirc == 3) {
                            Elemento* inicio = filaCirc.consultarInicio();
                            if (inicio != NULL) {
                                inicio->imprimirInfo();
                            } else {
                                cout << "Fila circular vazia." << endl;
                            }
                        } else if (opFilaCirc == 4) {
                            if (filaCirc.filaCheia()) cout << "A fila circular esta cheia." << endl;
                            else cout << "A fila circular nao esta cheia." << endl;
                        } else if (opFilaCirc == 5) {
                            if (filaCirc.filaVazia()) cout << "A fila circular esta vazia." << endl;
                            else cout << "A fila circular nao esta vazia." << endl;
                        }
                    }
                // Pilha, Fila e Deque Encadeados ([POO - Composicao] com ListaSimples e ListaDupla)
                } else if (opcaoPFD == 4) {
                    PilhaEnc pe;
                    FilaEnc fe;
                    Deque dq;
                    int qual, op = 0;
                    cout << "\nQual estrutura usar? (1: Pilha | 2: Fila | 3: Deque): ";
                    cin >> qual;
                    if (qual < 1 || qual > 3) continue;

                    while (op != 4) {
                        cout << "\n1: Inserir | 2: Remover | 3: Imprimir | 4: Voltar\nOpcao: ";
                        cin >> op;

                        if (op == 1) {
                            int tipo, valor;
                            long id;
                            string nome;
                            cout << "1: Personagem | 2: Equipamento: ";
                            cin >> tipo;
                            if (tipo != 1 && tipo != 2) continue;

                            cout << "ID: "; cin >> id;
                            cin.ignore();
                            cout << "Nome: "; getline(cin, nome);
                            cout << "Nivel/Dano: "; cin >> valor;

                            Elemento* e = NULL;
                            if (tipo == 1) e = new Personagem(id, nome, valor);
                            else e = new Equipamento(id, nome, valor);

                            // no Deque o usuario escolhe em qual ponta inserir
                            if (qual == 1) pe.empilhar(e);
                            else if (qual == 2) fe.enfileirar(e);
                            else {
                                int lado;
                                cout << "1: Inserir no Inicio | 2: Inserir no Fim: ";
                                cin >> lado;
                                if (lado == 1) dq.inserirInicio(e);
                                else dq.inserirFim(e);
                            }
                            cout << "Inserido!" << endl;

                        } else if (op == 2) {
                            Elemento* r = NULL;
                            // no Deque o usuario escolhe de qual ponta remover
                            if (qual == 1) r = pe.desempilhar();
                            else if (qual == 2) r = fe.desenfileirar();
                            else {
                                int lado;
                                cout << "1: Remover do Inicio | 2: Remover do Fim: ";
                                cin >> lado;
                                if (lado == 1) r = dq.removerInicio();
                                else r = dq.removerFim();
                            }

                            if (r != NULL) {
                                cout << "Removido: ";
                                r->imprimirInfo();
                                delete r; // libera o elemento removido da memoria
                            }
                            else cout << "Estrutura vazia." << endl;

                        } else if (op == 3) {
                            if (qual == 1) pe.imprimir();
                            else if (qual == 2) fe.imprimir();
                            else dq.imprimir();
                        }
                    }
                }
            }
        // 4: Estruturas Nao-Lineares (Arvore Binaria de Busca e Grafo)
        } else if (opcaoPrincipal == 4) {
            int opcaoAG = 0;
            Arvore arvore;
            Grafo grafo;

            while (opcaoAG != 3) {
                cout << "\n--- ARVORES E GRAFOS ---" << endl;
                cout << "1: Arvore Binaria de Busca" << endl;
                cout << "2: Grafo" << endl;
                cout << "3: Voltar" << endl;
                cout << "Opcao: ";
                cin >> opcaoAG;

                // Arvore Binaria de Busca (ABB: menores a esquerda, maiores a direita)
                if (opcaoAG == 1) {
                    int opArvore = 0;
                    while (opArvore != 7) {
                        cout << "\n[Arvore]" << endl;
                        cout << "1: Inserir Elemento" << endl;
                        cout << "2: Remover pelo ID" << endl;
                        cout << "3: Buscar pelo ID" << endl;
                        cout << "4: Imprimir Em-Ordem" << endl;
                        cout << "5: Imprimir Pre-Ordem" << endl;
                        cout << "6: Imprimir Pos-Ordem" << endl;
                        cout << "7: Voltar" << endl;
                        cout << "Opcao: ";
                        cin >> opArvore;

                        if (opArvore == 1) {
                            int tipo;
                            cout << "1: Personagem | 2: Equipamento: ";
                            cin >> tipo;

                            long id;
                            cout << "ID: ";
                            cin >> id;
                            cin.ignore();

                            if (tipo == 1) {
                                string nome;
                                int nivel;
                                cout << "Nome: ";
                                getline(cin, nome);
                                cout << "Nivel: ";
                                cin >> nivel;

                                Personagem* p = new Personagem(id, nome, nivel);
                                arvore.insere(p);
                                cout << "Inserido!" << endl;
                            } else if (tipo == 2) {
                                string nomeItem;
                                int dano;
                                cout << "Nome: ";
                                getline(cin, nomeItem);
                                cout << "Dano: ";
                                cin >> dano;

                                Equipamento* eq = new Equipamento(id, nomeItem, dano);
                                arvore.insere(eq);
                                cout << "Inserido!" << endl;
                            } else {
                                cout << "Tipo invalido!" << endl;
                            }
                        } else if (opArvore == 2) {
                            long id;
                            cout << "ID para remover: ";
                            cin >> id;
                            if (arvore.remove(id)) cout << "Removido!" << endl;
                            else cout << "ID nao encontrado." << endl;

                        } else if (opArvore == 3) {
                            long id;
                            cout << "ID para buscar: ";
                            cin >> id;
                            Elemento* achou = arvore.busca(id);
                            if (achou != NULL) achou->imprimirInfo();
                            else cout << "ID nao encontrado." << endl;

                        // percursos classicos da Arvore Binaria
                        } else if (opArvore == 4) {
                            arvore.imprimeEmOrdem(); // imprime os IDs em ordem crescente
                        } else if (opArvore == 5) {
                            arvore.imprimePreOrdem();
                        } else if (opArvore == 6) {
                            arvore.imprimePosOrdem();
                        }
                    }
                // Grafo Ponderado com Dupla Representacao (Lista de Adjacencia + Matriz de Adjacencia)
                } else if (opcaoAG == 2) {
                    int opGrafo = 0;
                    while (opGrafo != 11) {
                        cout << "\n[Grafo]" << endl;
                        cout << "1: Inserir Vertice" << endl;
                        cout << "2: Inserir Aresta" << endl;
                        cout << "3: Remover Aresta" << endl;
                        cout << "4: Remover Vertice" << endl;
                        cout << "5: Buscar Vertice" << endl;
                        cout << "6: Verificar se dois Vertices sao Vizinhos" << endl;
                        cout << "7: Obter Grau de um Vertice" << endl;
                        cout << "8: Imprimir Vizinhos" << endl;
                        cout << "9: Imprimir Grafo (Lista e Matriz de Adjacencia)" << endl;
                        cout << "10: Percorrer Grafo (BFS / DFS)" << endl;
                        cout << "11: Voltar" << endl;
                        cout << "Opcao: ";
                        cin >> opGrafo;

                        // cadastra um novo vertice (Personagem ou Equipamento) no grafo
                        if (opGrafo == 1) {
                            int tipo;
                            cout << "1: Personagem | 2: Equipamento: ";
                            cin >> tipo;

                            long id;
                            cout << "ID: ";
                            cin >> id;
                            cin.ignore();

                            if (tipo == 1) {
                                string nome;
                                int nivel;
                                cout << "Nome: ";
                                getline(cin, nome);
                                cout << "Nivel: ";
                                cin >> nivel;

                                Personagem* p = new Personagem(id, nome, nivel);
                                if (grafo.insereVertice(p)) {
                                    cout << "Vertice inserido!" << endl;
                                } else {
                                    delete p; // Libera memoria para evitar memory leak caso ID ja exista
                                    cout << "Erro: ID ja existe." << endl;
                                }
                            } else if (tipo == 2) {
                                string nomeItem;
                                int dano;
                                cout << "Nome: ";
                                getline(cin, nomeItem);
                                cout << "Dano: ";
                                cin >> dano;

                                Equipamento* eq = new Equipamento(id, nomeItem, dano);
                                if (grafo.insereVertice(eq)) {
                                    cout << "Vertice inserido!" << endl;
                                } else {
                                    delete eq; // Libera memoria para evitar memory leak caso ID ja exista
                                    cout << "Erro: ID ja existe." << endl;
                                }
                            } else {
                                cout << "Tipo invalido!" << endl;
                            }
                        // conecta dois vertices existentes com uma aresta ponderada (peso)
                        } else if (opGrafo == 2) {
                            long idOrig, idDest;
                            int peso;
                            cout << "ID Origem: ";
                            cin >> idOrig;
                            cout << "ID Destino: ";
                            cin >> idDest;
                            cout << "Peso: ";
                            cin >> peso;

                            if (grafo.insereAresta(idOrig, idDest, peso)) cout << "Aresta inserida!" << endl;
                            else cout << "Erro ao inserir aresta." << endl;

                        } else if (opGrafo == 3) {
                            long idOrig, idDest;
                            cout << "ID Origem: ";
                            cin >> idOrig;
                            cout << "ID Destino: ";
                            cin >> idDest;

                            if (grafo.removeAresta(idOrig, idDest)) cout << "Aresta removida!" << endl;
                            else cout << "Erro ao remover aresta." << endl;

                        } else if (opGrafo == 4) {
                            long id;
                            cout << "ID para remover: ";
                            cin >> id;
                            if (grafo.removeVertice(id)) cout << "Vertice removido!" << endl;
                            else cout << "ID nao encontrado." << endl;

                        } else if (opGrafo == 5) {
                            long id;
                            cout << "ID para buscar: ";
                            cin >> id;
                            Elemento* elem = grafo.buscaVertice(id);
                            if (elem != NULL) elem->imprimirInfo();
                            else cout << "ID nao encontrado." << endl;

                        // verifica se dois vertices possuem aresta direta
                        } else if (opGrafo == 6) {
                            long id1, id2;
                            cout << "ID do primeiro vertice: ";
                            cin >> id1;
                            cout << "ID do segundo vertice: ";
                            cin >> id2;
                            if (grafo.saoVizinhos(id1, id2)) {
                                cout << "Os vertices " << id1 << " e " << id2 << " SAO vizinhos (possuem aresta entre si)!" << endl;
                            } else {
                                cout << "Os vertices " << id1 << " e " << id2 << " NAO sao vizinhos (ou algum deles nao existe)." << endl;
                            }

                        // calcula e exibe o grau do vertice
                        } else if (opGrafo == 7) {
                            long id;
                            cout << "ID do vertice: ";
                            cin >> id;
                            int grau = grafo.obterGrau(id);
                            if (grau != -1) {
                                cout << "O grau do vertice " << id << " e: " << grau << endl;
                            } else {
                                cout << "Erro: Vertice com ID " << id << " nao encontrado no grafo." << endl;
                            }

                        } else if (opGrafo == 8) {
                            long id;
                            cout << "ID do vertice: ";
                            cin >> id;
                            grafo.imprimeVizinhos(id);

                        // imprime tanto a lista de adjacencia quanto a matriz de adjacencia
                        } else if (opGrafo == 9) {
                            grafo.imprimeGrafo();

                        // percursos em Largura (BFS com fila) e Profundidade (DFS recursivo)
                        } else if (opGrafo == 10) {
                            long idInicio;
                            int tipoBusca;
                            cout << "ID inicial: ";
                            cin >> idInicio;
                            cout << "1: Largura (BFS) | 2: Profundidade (DFS): ";
                            cin >> tipoBusca;

                            if (tipoBusca == 1) grafo.buscaEmLargura(idInicio);
                            else if (tipoBusca == 2) grafo.buscaEmProfundidade(idInicio);
                            else cout << "Opcao invalida." << endl;
                        }
                    }
                }
            }
        } else if (opcaoPrincipal == 5) {
            cout << "Encerrando..." << endl;
        } else {
            cout << "Opcao invalida." << endl;
        }
    }
    return 0;
}