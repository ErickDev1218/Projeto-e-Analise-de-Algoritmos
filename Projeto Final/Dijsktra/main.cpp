#include "Grafo.hpp"
#include <iostream>
using namespace std;

int main(){
    cout << "Digite quantos vertices há no grafo: ";
    int qtdV;
    cin >> qtdV;
    Grafo * x = new Grafo(qtdV);

    cout << "Digite quantas arestas há no grafo: ";
    int qtdA;
    cin >> qtdA;

    cout << "Digite os arestas seguidas de seus pesos. Ex: A B 5" << endl;
    for(int i = 0 ; i < qtdA; i++){
        char u,v;
        int w;
        cin >> u >> v >> w;
        x->addAresta(u,v,w);
    }

    cout << endl << endl;
    cout << "1 - Ver o grafo" << endl << "2 - Acionar o algoritmo Dijkstra" << endl << "3 - Ver os caminhos para todos os vertices" << endl << "99 - Para encerrar o programa" << endl;

    int dec = 0;
    do{
        cin >> dec;
        if(dec == 1){
            x->verGrafo();
        }else if(dec == 2){
            cout << "Digite o vertice origem para o algoritmo: ";
            char o;
            cin >> o;
            x->dijkstra(o);
        }else if(dec == 3){
            x->verCaminhos();
        }else if(dec == 99){
            for(int i = 0; i < x->grap.size(); i++){
                delete x->grap[i];
                delete x;
            }
            cout << "Ate mais!" << endl;
        }
    }while(dec != 99);

}