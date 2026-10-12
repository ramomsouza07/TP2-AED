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
            case 2:
                cout << "\n----------------------------------------------------------------------" << endl;
                cout << "--- ALOCACAO DINAMICA (inserir depois!!)---" << endl;
                cout << "----------------------------------------------------------------------" << endl;
                break;
            case 3: {
                int opcaoPFD = -1;
                while (opcaoPFD != 5) {
                    cout << "\n--- Pilhas, Filas e Deques ---" << endl;
                    cout << "1: Pilha (sequencial)" << endl;
                    cout << "2: Fila (sequencial, menos eficiente)" << endl;
                    cout << "3: Fila Circular (sequencial, eficiente)" << endl;
                    cout << "4: Pilha, Fila e Deque (encadeados)  [inserir depois]" << endl;
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
                }
                break;
            }
            case 4:
                cout << "\n----------------------------------------------------------------------" << endl;
                cout << "--- ARVORES E GRAFOS (inserir depois!!) ---" << endl;
                cout << "----------------------------------------------------------------------" << endl;
                break;
            case 5:
                cout << "\nEncerrando o programa..." << endl;
                break;
            default:
                cout << "\nOpcao invalida. Tente novamente." << endl;
        }
    }
    return 0;
}