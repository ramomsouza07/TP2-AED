#include <iostream>
#include <string>
#include <limits>
#include "headers/Personagem.h"
#include "headers/Equipamento.h"
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

void limparBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    int opcaoPrincipal = -1;

    while (opcaoPrincipal != 5) {
        cout << "================ MENU ================" << endl;
        cout << "1: Operar em Listas Sequenciais" << endl;
        cout << "2: Operar em Listas de Alocacao Dinamica" << endl;
        cout << "3: Operar Pilhas, Filas e Deques" << endl;
        cout << "4: Operar Arvores e Grafos" << endl;
        cout << "5: Finalizar o sistema" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcaoPrincipal;

        switch (opcaoPrincipal) {
            case 1: { 
                int opcaoSeq = -1;
                while (opcaoSeq != 3) {
                    cout << "\n--- LISTAS SEQUENCIAIS ---" << endl;
                    cout << "1: Lista Nao Ordenada" << endl;
                    cout << "2: Lista Ordenada" << endl;
                    cout << "3: Voltar" << endl;
                    cout << "Opcao: ";
                    cin >> opcaoSeq;

                    if (opcaoSeq == 1) { 
                        ListaNaoOrdenada lista(50);
                        int opLista = -1;
                        
                        while (opLista != 6) {
                            cout << "\n[Lista Nao Ordenada] Operacoes:" << endl;
                            cout << "1: Inserir no Inicio" << endl;
                            cout << "2: Inserir no Final" << endl;
                            cout << "3: Remover Primeiro" << endl;
                            cout << "4: Remover Ultimo" << endl;
                            cout << "5: Imprimir Lista" << endl;
                            cout << "6: Voltar" << endl;
                            cout << "Opcao: ";
                            cin >> opLista;

                            switch (opLista) {
                                case 1:
                                case 2: {
                                    int tipo;
                                    cout << "\n1: Personagem | 2: Equipamento -> Escolha: ";
                                    cin >> tipo;

                                    long id;
                                    cout << "Digite o ID unico: ";
                                    cin >> id;
                                    limparBuffer(); 

                                    if (tipo == 1) {
                                        string nome;
                                        int nivel;
                                        cout << "Nome do Personagem: ";
                                        getline(cin, nome);
                                        cout << "Nivel: ";
                                        cin >> nivel;
                                        
                                        Personagem* p = new Personagem(id, nome, nivel);
                                        if (opLista == 1) lista.InserirNoInicio(p);
                                        else lista.InserirNoFinal(p);
                                        cout << "Personagem inserido!" << endl;
                                        
                                    } else if (tipo == 2) {
                                        string nomeItem;
                                        int dano;
                                        cout << "Nome do Equipamento: ";
                                        getline(cin, nomeItem);
                                        cout << "Dano Base: ";
                                        cin >> dano;
                                        
                                        Equipamento* eq = new Equipamento(id, nomeItem, dano);
                                        if (opLista == 1) lista.InserirNoInicio(eq);
                                        else lista.InserirNoFinal(eq);
                                        cout << "Equipamento inserido!" << endl;
                                    } else {
                                        cout << "Tipo invalido!" << endl;
                                    }
                                    break;
                                }
                                case 3:
                                    if (lista.RemoverPrimeiro()) cout << "Primeiro removido!" << endl;
                                    else cout << "Lista vazia." << endl;
                                    break;
                                case 4:
                                    if (lista.RemoverUltimo()) cout << "Ultimo removido!" << endl;
                                    else cout << "Lista vazia." << endl;
                                    break;
                                case 5:
                                    cout << "\n--- CONTEUDO DA LISTA ---" << endl;
                                    lista.imprimirTodos();
                                    cout << "-------------------------" << endl;
                                    break;
                                case 6:
                                    break;
                                default:
                                    cout << "Opcao invalida." << endl;
                            }
                        }
                    } else if (opcaoSeq == 2) { 
                        ListaOrdenada listaOrd(50);
                        int opLista = -1;
                        
                        while (opLista != 6) {
                            cout << "\n[Lista Ordenada] Operacoes:" << endl;
                            cout << "1: Inserir Elemento" << endl;
                            cout << "2: Remover Primeiro" << endl;
                            cout << "3: Remover Ultimo" << endl;
                            cout << "4: Remover Pelo ID" << endl;
                            cout << "5: Imprimir Lista" << endl;
                            cout << "6: Voltar" << endl;
                            cout << "Opcao: ";
                            cin >> opLista;

                            switch (opLista) {
                                case 1: {
                                    int tipo;
                                    cout << "\n1: Personagem | 2: Equipamento -> Escolha: ";
                                    cin >> tipo;

                                    long id;
                                    cout << "Digite o ID unico: ";
                                    cin >> id;
                                    limparBuffer(); 

                                    if (tipo == 1) {
                                        string nome;
                                        int nivel;
                                        cout << "Nome do Personagem: ";
                                        getline(cin, nome);
                                        cout << "Nivel: ";
                                        cin >> nivel;
                                        
                                        Personagem* p = new Personagem(id, nome, nivel);
                                        if(listaOrd.Inserir(p)) cout << "Personagem inserido na posicao correta!" << endl;
                                        else cout << "Erro: ID ja existe ou lista cheia." << endl;
                                        
                                    } else if (tipo == 2) {
                                        string nomeItem;
                                        int dano;
                                        cout << "Nome do Equipamento: ";
                                        getline(cin, nomeItem);
                                        cout << "Dano Base: ";
                                        cin >> dano;
                                        
                                        Equipamento* eq = new Equipamento(id, nomeItem, dano);
                                        if(listaOrd.Inserir(eq)) cout << "Equipamento inserido na posicao correta!" << endl;
                                        else cout << "Erro: ID ja existe ou lista cheia." << endl;
                                    } else {
                                        cout << "Tipo invalido!" << endl;
                                    }
                                    break;
                                }
                                case 2:
                                    if (listaOrd.RemoverPrimeiro()) cout << "Primeiro removido!" << endl;
                                    else cout << "Lista vazia." << endl;
                                    break;
                                case 3:
                                    if (listaOrd.RemoverUltimo()) cout << "Ultimo removido!" << endl;
                                    else cout << "Lista vazia." << endl;
                                    break;
                                case 4: {
                                    long idBusca;
                                    cout << "Digite o ID a ser removido: ";
                                    cin >> idBusca;
                                    if (listaOrd.RemoverPeloId(idBusca)) cout << "Elemento removido via Busca Binaria!" << endl;
                                    else cout << "ID nao encontrado." << endl;
                                    break;
                                }
                                case 5:
                                    cout << "\n--- CONTEUDO DA LISTA ORDENADA ---" << endl;
                                    listaOrd.imprimirTodos();
                                    cout << "----------------------------------" << endl;
                                    break;
                                case 6:
                                    break;
                                default:
                                    cout << "Opcao invalida." << endl;
                            }
                        }
                    }
                }
                break;
            }
            case 2: {
                int opDin = 0;
                while (opDin != 4) {
                    cout << "\n--- LISTAS ENCADEADAS ---" << endl;
                    cout << "1: Simples | 2: Dupla | 3: Circular | 4: Voltar\nOpcao: ";
                    cin >> opDin;
                    if (opDin < 1 || opDin > 3) break;

                    ListaSimples ls;
                    ListaDupla ld;
                    ListaCircular lc;

                    int op = 0;
                    while (op != 6) {
                        cout << "\n1: Inserir Inicio | 2: Inserir Fim | 3: Remover ID | 4: Buscar ID | 5: Imprimir | 6: Voltar\nOpcao: ";
                        cin >> op;

                        if (op == 1 || op == 2) {
                            int tipo;
                            cout << "1: Personagem | 2: Equipamento: ";
                            cin >> tipo;
                            long id;
                            cout << "ID: ";
                            cin >> id;
                            limparBuffer();

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

                            if (opDin == 1) {
                                if (op == 1) ls.insereInicio(e);
                                else ls.insereFim(e);
                            } else if (opDin == 2) {
                                if (op == 1) ld.insereInicio(e);
                                else ld.insereFim(e);
                            } else {
                                lc.insere(e);
                            }
                            cout << "Inserido!" << endl;

                        } else if (op == 3) {
                            long id;
                            cout << "ID para remover: ";
                            cin >> id;
                            bool ok = false;
                            if (opDin == 1) ok = ls.remove(id);
                            else if (opDin == 2) ok = ld.remove(id);
                            else ok = lc.remove(id);

                            if (ok) cout << "Removido!" << endl;
                            else cout << "ID nao encontrado." << endl;

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
                break;
            }
            case 3: {
                int opcaoPFD = -1;
                while (opcaoPFD != 5) {
                    cout << "\n--- Pilhas, Filas e Deques ---" << endl;
                    cout << "1: Pilha (sequencial)" << endl;
                    cout << "2: Fila (sequencial, menos eficiente)" << endl;
                    cout << "3: Fila Circular (sequencial, eficiente)" << endl;
                    cout << "4: Pilha, Fila e Deque (encadeados)  " << endl;
                    cout << "5: Voltar" << endl;
                    cout << "Opcao: ";
                    cin >> opcaoPFD;

                    if (opcaoPFD == 1) {
                        Pilha pilha(50);
                        int opPilha = -1;
                        while (opPilha != 6) {
                            cout << "\n[Pilha] Operacoes:" << endl;
                            cout << "1: Empilhar (Inserir)" << endl;
                            cout << "2: Desempilhar (Remover)" << endl;
                            cout << "3: Consultar Topo" << endl;
                            cout << "4: Verificar se esta Cheia" << endl;
                            cout << "5: Verificar se esta Vazia" << endl;
                            cout << "6: Voltar" << endl;
                            cout << "Opcao: ";
                            cin >> opPilha;

                            if (opPilha == 1) {
                                int tipo;
                                cout << "\n1: Personagem | 2: Equipamento -> Escolha: ";
                                cin >> tipo;

                                long id;
                                cout << "Digite o ID unico: ";
                                cin >> id;
                                limparBuffer();

                                Elemento* e = nullptr;
                                if (tipo == 1) {
                                    string nome;
                                    int nivel;
                                    cout << "Nome do Personagem: ";
                                    getline(cin, nome);
                                    cout << "Nivel: ";
                                    cin >> nivel;
                                    e = new Personagem(id, nome, nivel);
                                } else if (tipo == 2) {
                                    string nomeItem;
                                    int dano;
                                    cout << "Nome do Equipamento: ";
                                    getline(cin, nomeItem);
                                    cout << "Dano Base: ";
                                    cin >> dano;
                                    e = new Equipamento(id, nomeItem, dano);
                                } else {
                                    cout << "Tipo invalido!" << endl;
                                    continue;
                                }

                                if (pilha.empilhar(e)) {
                                    cout << "Elemento empilhado com sucesso!" << endl;
                                } else {
                                    cout << "Erro: Pilha cheia ou elemento nulo." << endl;
                                    delete e; // Evita vazamento caso falhe
                                }
                            } else if (opPilha == 2) {
                                if (pilha.desempilhar()) {
                                    cout << "Elemento desempilhado com sucesso!" << endl;
                                } else {
                                    cout << "Erro: Pilha vazia." << endl;
                                }
                            } else if (opPilha == 3) {
                                Elemento* topo = pilha.consultarTopo();
                                if (topo != nullptr) {
                                    cout << "\n--- Topo da Pilha ---" << endl;
                                    topo->imprimirInfo();
                                    cout << "---------------------" << endl;
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
                    } 
                    else if (opcaoPFD == 2) {
                        Fila fila(50);
                        int opFila = -1;
                        while (opFila != 6) {
                            cout << "\n[Fila] Operacoes:" << endl;
                            cout << "1: Enfileirar (Inserir)" << endl;
                            cout << "2: Desenfileirar (Remover)" << endl;
                            cout << "3: Consultar Inicio" << endl;
                            cout << "4: Verificar se esta Cheia" << endl;
                            cout << "5: Verificar se esta Vazia" << endl;
                            cout << "6: Voltar" << endl;
                            cout << "Opcao: ";
                            cin >> opFila;

                            if (opFila == 1) {
                                int tipo;
                                cout << "\n1: Personagem | 2: Equipamento -> Escolha: ";
                                cin >> tipo;

                                long id;
                                cout << "Digite o ID unico: ";
                                cin >> id;
                                limparBuffer();

                                Elemento* e = nullptr;
                                if (tipo == 1) {
                                    string nome;
                                    int nivel;
                                    cout << "Nome do Personagem: ";
                                    getline(cin, nome);
                                    cout << "Nivel: ";
                                    cin >> nivel;
                                    e = new Personagem(id, nome, nivel);
                                } else if (tipo == 2) {
                                    string nomeItem;
                                    int dano;
                                    cout << "Nome do Equipamento: ";
                                    getline(cin, nomeItem);
                                    cout << "Dano Base: ";
                                    cin >> dano;
                                    e = new Equipamento(id, nomeItem, dano);
                                } else {
                                    cout << "Tipo invalido!" << endl;
                                    continue;
                                }

                                if (fila.enfileirar(e)) {
                                    cout << "Elemento enfileirado com sucesso!" << endl;
                                } else {
                                    cout << "Erro: Fila cheia ou elemento nulo." << endl;
                                    delete e;
                                }
                            } else if (opFila == 2) {
                                if (fila.desenfileirar()) {
                                    cout << "Elemento desenfileirado com sucesso!" << endl;
                                } else {
                                    cout << "Erro: Fila vazia." << endl;
                                }
                            } else if (opFila == 3) {
                                Elemento* inicio = fila.consultarInicio();
                                if (inicio != nullptr) {
                                    cout << "\n--- Inicio da Fila ---" << endl;
                                    inicio->imprimirInfo();
                                    cout << "----------------------" << endl;
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
                    } 
                    else if (opcaoPFD == 3) {
                        FilaCircular filaCirc(50);
                        int opFilaCirc = -1;
                        while (opFilaCirc != 6) {
                            cout << "\n[Fila Circular] Operacoes:" << endl;
                            cout << "1: Enfileirar (Inserir)" << endl;
                            cout << "2: Desenfileirar (Remover)" << endl;
                            cout << "3: Consultar Inicio" << endl;
                            cout << "4: Verificar se esta Cheia" << endl;
                            cout << "5: Verificar se esta Vazia" << endl;
                            cout << "6: Voltar" << endl;
                            cout << "Opcao: ";
                            cin >> opFilaCirc;

                            if (opFilaCirc == 1) {
                                int tipo;
                                cout << "\n1: Personagem | 2: Equipamento -> Escolha: ";
                                cin >> tipo;

                                long id;
                                cout << "Digite o ID unico: ";
                                cin >> id;
                                limparBuffer();

                                Elemento* e = nullptr;
                                if (tipo == 1) {
                                    string nome;
                                    int nivel;
                                    cout << "Nome do Personagem: ";
                                    getline(cin, nome);
                                    cout << "Nivel: ";
                                    cin >> nivel;
                                    e = new Personagem(id, nome, nivel);
                                } else if (tipo == 2) {
                                    string nomeItem;
                                    int dano;
                                    cout << "Nome do Equipamento: ";
                                    getline(cin, nomeItem);
                                    cout << "Dano Base: ";
                                    cin >> dano;
                                    e = new Equipamento(id, nomeItem, dano);
                                } else {
                                    cout << "Tipo invalido!" << endl;
                                    continue;
                                }

                                if (filaCirc.enfileirar(e)) {
                                    cout << "Elemento enfileirado na fila circular!" << endl;
                                } else {
                                    cout << "Erro: Fila circular cheia ou elemento nulo." << endl;
                                    delete e;
                                }
                            } else if (opFilaCirc == 2) {
                                if (filaCirc.desenfileirar()) {
                                    cout << "Elemento desenfileirado da fila circular!" << endl;
                                } else {
                                    cout << "Erro: Fila circular vazia." << endl;
                                }
                            } else if (opFilaCirc == 3) {
                                Elemento* inicio = filaCirc.consultarInicio();
                                if (inicio != nullptr) {
                                    cout << "\n--- Inicio da Fila Circular ---" << endl;
                                    inicio->imprimirInfo();
                                    cout << "-------------------------------" << endl;
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
                    }
                    else if (opcaoPFD == 4) {
                        PilhaEnc pe;
                        FilaEnc fe;
                        Deque dq;
                        int qual, op = 0;
                        cout << "\nQual estrutura usar? (1: Pilha | 2: Fila | 3: Deque): ";
                        cin >> qual;

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
                                limparBuffer();
                                cout << "Nome: "; getline(cin, nome);
                                cout << "Nivel/Dano: "; cin >> valor;

                                Elemento* e = NULL;
                                if (tipo == 1) e = new Personagem(id, nome, valor);
                                else e = new Equipamento(id, nome, valor);

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
                                if (qual == 1) r = pe.desempilhar();
                                else if (qual == 2) r = fe.desenfileirar();
                                else {
                                    int lado;
                                    cout << "1: Remover do Inicio | 2: Remover do Fim: ";
                                    cin >> lado;
                                    if (lado == 1) r = dq.removerInicio();
                                    else r = dq.removerFim();
                                }

                                if (r != NULL) cout << "Removido!" << endl;
                                else cout << "Estrutura vazia." << endl;

                            } else if (op == 3) {
                                if (qual == 1) pe.imprimir();
                                else if (qual == 2) fe.imprimir();
                                else dq.imprimir();
                            }
                        }
                    }
                }
                break;
            }

            case 4: {
                int opcaoAG = -1;
                Arvore arvore;
                Grafo grafo;

                while (opcaoAG != 3) {
                    cout << "\n--- ARVORES E GRAFOS ---" << endl;
                    cout << "1: Arvore Binaria de Busca (BST)" << endl;
                    cout << "2: Grafo (Lista de Adjacencia)" << endl;
                    cout << "3: Voltar" << endl;
                    cout << "Opcao: ";
                    cin >> opcaoAG;

                    switch (opcaoAG) {
                        case 1: {
                            int opArvore = -1;
                            while (opArvore != 7) {
                                cout << "\n[Arvore Binaria de Busca] Operacoes:" << endl;
                                cout << "1: Inserir Elemento" << endl;
                                cout << "2: Remover Elemento pelo ID" << endl;
                                cout << "3: Buscar Elemento pelo ID" << endl;
                                cout << "4: Imprimir Em-Ordem" << endl;
                                cout << "5: Imprimir Pre-Ordem" << endl;
                                cout << "6: Imprimir Pos-Ordem" << endl;
                                cout << "7: Voltar" << endl;
                                cout << "Opcao: ";
                                cin >> opArvore;

                                switch (opArvore) {
                                    case 1: {
                                        int tipo;
                                        cout << "\n1: Personagem | 2: Equipamento -> Escolha: ";
                                        cin >> tipo;

                                        long id;
                                        cout << "Digite o ID unico: ";
                                        cin >> id;
                                        limparBuffer();

                                        if (tipo == 1) {
                                            string nome;
                                            int nivel;
                                            cout << "Nome do Personagem: ";
                                            getline(cin, nome);
                                            cout << "Nivel: ";
                                            cin >> nivel;

                                            Personagem* p = new Personagem(id, nome, nivel);
                                            arvore.insere(p);
                                            cout << "Personagem inserido na Arvore!" << endl;
                                        } else if (tipo == 2) {
                                            string nomeItem;
                                            int dano;
                                            cout << "Nome do Equipamento: ";
                                            getline(cin, nomeItem);
                                            cout << "Dano Base: ";
                                            cin >> dano;

                                            Equipamento* eq = new Equipamento(id, nomeItem, dano);
                                            arvore.insere(eq);
                                            cout << "Equipamento inserido na Arvore!" << endl;
                                        } else {
                                            cout << "Tipo invalido!" << endl;
                                        }
                                        break;
                                    }
                                    case 2: {
                                        long id;
                                        cout << "Digite o ID a ser removido: ";
                                        cin >> id;
                                        if (arvore.remove(id)) {
                                            cout << "Elemento removido da Arvore!" << endl;
                                        } else {
                                            cout << "ID nao encontrado na Arvore." << endl;
                                        }
                                        break;
                                    }
                                    case 3: {
                                        long id;
                                        cout << "Digite o ID para buscar: ";
                                        cin >> id;
                                        Elemento* achou = arvore.busca(id);
                                        if (achou != NULL) {
                                            cout << "\n--- Elemento Encontrado ---" << endl;
                                            achou->imprimirInfo();
                                            cout << "---------------------------" << endl;
                                        } else {
                                            cout << "ID nao encontrado na Arvore." << endl;
                                        }
                                        break;
                                    }
                                    case 4:
                                        cout << "\n--- CONTEUDO DA ARVORE (EM-ORDEM) ---" << endl;
                                        arvore.imprimeEmOrdem();
                                        cout << "-------------------------------------" << endl;
                                        break;
                                    case 5:
                                        cout << "\n--- CONTEUDO DA ARVORE (PRE-ORDEM) ---" << endl;
                                        arvore.imprimePreOrdem();
                                        cout << "--------------------------------------" << endl;
                                        break;
                                    case 6:
                                        cout << "\n--- CONTEUDO DA ARVORE (POS-ORDEM) ---" << endl;
                                        arvore.imprimePosOrdem();
                                        cout << "--------------------------------------" << endl;
                                        break;
                                    case 7:
                                        break;
                                    default:
                                        cout << "Opcao invalida." << endl;
                                }
                            }
                            break;
                        }
                        case 2: {
                            int opGrafo = -1;
                            while (opGrafo != 9) {
                                cout << "\n[Grafo - Rede de Elementos] Operacoes:" << endl;
                                cout << "1: Inserir Vertice (Personagem ou Equipamento)" << endl;
                                cout << "2: Inserir Aresta / Conexao entre dois IDs" << endl;
                                cout << "3: Remover Aresta / Conexao" << endl;
                                cout << "4: Remover Vertice pelo ID" << endl;
                                cout << "5: Buscar Vertice pelo ID" << endl;
                                cout << "6: Listar Vizinhos de um Vertice" << endl;
                                cout << "7: Imprimir Grafo Completo" << endl;
                                cout << "8: Percorrer Grafo (BFS - Largura / DFS - Profundidade)" << endl;
                                cout << "9: Voltar" << endl;
                                cout << "Opcao: ";
                                cin >> opGrafo;

                                switch (opGrafo) {
                                    case 1: {
                                        int tipo;
                                        cout << "\n1: Personagem | 2: Equipamento -> Escolha: ";
                                        cin >> tipo;

                                        long id;
                                        cout << "Digite o ID unico: ";
                                        cin >> id;
                                        limparBuffer();

                                        if (tipo == 1) {
                                            string nome;
                                            int nivel;
                                            cout << "Nome do Personagem: ";
                                            getline(cin, nome);
                                            cout << "Nivel: ";
                                            cin >> nivel;

                                            Personagem* p = new Personagem(id, nome, nivel);
                                            if (grafo.insereVertice(p)) {
                                                cout << "Personagem inserido como vertice no Grafo!" << endl;
                                            } else {
                                                cout << "Erro: Vertice com ID " << id << " ja existe." << endl;
                                                delete p;
                                            }
                                        } else if (tipo == 2) {
                                            string nomeItem;
                                            int dano;
                                            cout << "Nome do Equipamento: ";
                                            getline(cin, nomeItem);
                                            cout << "Dano Base: ";
                                            cin >> dano;

                                            Equipamento* eq = new Equipamento(id, nomeItem, dano);
                                            if (grafo.insereVertice(eq)) {
                                                cout << "Equipamento inserido como vertice no Grafo!" << endl;
                                            } else {
                                                cout << "Erro: Vertice com ID " << id << " ja existe." << endl;
                                                delete eq;
                                            }
                                        } else {
                                            cout << "Tipo invalido!" << endl;
                                        }
                                        break;
                                    }
                                    case 2: {
                                        long idOrig, idDest;
                                        int peso;
                                        cout << "Digite o ID de Origem: ";
                                        cin >> idOrig;
                                        cout << "Digite o ID de Destino: ";
                                        cin >> idDest;
                                        cout << "Digite o Peso/Afinidade da conexao: ";
                                        cin >> peso;

                                        if (grafo.insereAresta(idOrig, idDest, peso)) {
                                            cout << "Conexao criada com sucesso entre " << idOrig << " e " << idDest << "!" << endl;
                                        } else {
                                            cout << "Erro ao inserir aresta. Verifique se ambos os IDs existem ou se a conexao ja existe." << endl;
                                        }
                                        break;
                                    }
                                    case 3: {
                                        long idOrig, idDest;
                                        cout << "Digite o ID de Origem: ";
                                        cin >> idOrig;
                                        cout << "Digite o ID de Destino: ";
                                        cin >> idDest;

                                        if (grafo.removeAresta(idOrig, idDest)) {
                                            cout << "Conexao removida com sucesso!" << endl;
                                        } else {
                                            cout << "Erro: conexao ou IDs nao encontrados." << endl;
                                        }
                                        break;
                                    }
                                    case 4: {
                                        long id;
                                        cout << "Digite o ID do vertice a remover: ";
                                        cin >> id;
                                        if (grafo.removeVertice(id)) {
                                            cout << "Vertice e todas as suas conexoes foram removidos com sucesso!" << endl;
                                        } else {
                                            cout << "Vertice com ID " << id << " nao encontrado no Grafo." << endl;
                                        }
                                        break;
                                    }
                                    case 5: {
                                        long id;
                                        cout << "Digite o ID para buscar: ";
                                        cin >> id;
                                        Elemento* elem = grafo.buscaVertice(id);
                                        if (elem != NULL) {
                                            cout << "\n--- Vertice Encontrado ---" << endl;
                                            elem->imprimirInfo();
                                            cout << "--------------------------" << endl;
                                        } else {
                                            cout << "Vertice com ID " << id << " nao encontrado no Grafo." << endl;
                                        }
                                        break;
                                    }
                                    case 6: {
                                        long id;
                                        cout << "Digite o ID do vertice para ver seus vizinhos: ";
                                        cin >> id;
                                        grafo.imprimeVizinhos(id);
                                        break;
                                    }
                                    case 7:
                                        grafo.imprimeGrafo();
                                        break;
                                    case 8: {
                                        long idInicio;
                                        int tipoBusca;
                                        cout << "Digite o ID inicial para o percurso: ";
                                        cin >> idInicio;
                                        cout << "1: Busca em Largura (BFS) | 2: Busca em Profundidade (DFS) -> Escolha: ";
                                        cin >> tipoBusca;

                                        if (tipoBusca == 1) {
                                            grafo.buscaEmLargura(idInicio);
                                        } else if (tipoBusca == 2) {
                                            grafo.buscaEmProfundidade(idInicio);
                                        } else {
                                            cout << "Opcao de busca invalida." << endl;
                                        }
                                        break;
                                    }
                                    case 9:
                                        break;
                                    default:
                                        cout << "Opcao invalida." << endl;
                                }
                            }
                            break;
                        }
                        case 3:
                            break;
                        default:
                            cout << "Opcao invalida." << endl;
                    }
                }
                break;
            }
            
            case 5:
                cout << "\nEncerrando o programa..." << endl;
                break;
            default:
                cout << "\nOpcao invalida. Tente novamente." << endl;
        }
    }
    return 0;
}