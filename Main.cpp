#include <iostream>
#include <string>
#include <limits>
#include "headers/Personagem.h"
#include "headers/Equipamento.h"
#include "headers/ListaNaoOrdenada.h"
#include "headers/ListaOrdenada.h"

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
            case 3:
                cout << "\n----------------------------------------------------------------------" << endl;
                cout << "--- PILHAS, FILAS E DEQUES (inserir depois!!)---" << endl;
                cout << "----------------------------------------------------------------------" << endl;
                break;
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