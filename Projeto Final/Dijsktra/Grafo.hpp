#ifndef GRAFO_HPP
#define GRAFO_HPP
#include "Node.hpp"
#include <iostream>
#include <stack>
#include <queue>

class Grafo{
    public:
        std::vector<Node*> grap;
        int qtdVertices = 0;
        int qtdArestas = 0;


        Grafo(int qtdV){
            qtdVertices = qtdV;

            int letra = 65;
            for(int i = 0; i < qtdVertices;i++){
                Node * aux = new Node(letra);
                letra++;
                grap.push_back(aux);
            }
        }

        void addAresta(char u,char v,int w){
            Node* auxU = nullptr;
            Node* auxV = nullptr;
            for(int i = 0; i < qtdVertices; i++){
                if(grap[i]->name == u){
                    auxU = grap[i];
                }
                if(grap[i]->name == v){
                    auxV = grap[i];
                }
            }

            if(auxU == nullptr){
                std::cout << "Impossivel adicionar aresta em " << u << " pois ele nao esta no grafo." << std::endl;
                return;
            }else{
                if(auxV == nullptr){
                    std::cout << "Impossivel adicionar aresta de " << u << " para " << v << " pois " << v << " nao esta no grafo." << std::endl;
                    return;
                }else{
                    auxU->adj.push_back(std::make_pair(auxV,w));
                    std::cout << "Aresta adicionada com sucesso!" << std::endl;
                    qtdArestas++;
                }
            }
        }

        void dijkstra(char u){
            Node *origem = nullptr;
            for(int i = 0; i<qtdVertices;i++){
                if(grap[i]->name == u){
                    origem = grap[i];
                }
            }

            if(origem == nullptr){
                std::cout << "Vertice origem nao esta no grafo!" << std::endl;
                return;
            }

            std::priority_queue<std::pair<Node*,int>, std::vector<std::pair<Node*, int>>, std::greater<std::pair<Node*, int>>> hm;

            origem->camMin = 0; //Vertice origem com caminho 0 para ele mesmo
            origem->pai = nullptr; //Simboliza que ele é a origem

            hm.push(std::make_pair(origem,origem->camMin));
            while(!hm.empty()){
                Node* u = hm.top().first;
                int distU = hm.top().second;
                hm.pop();

                for(std::pair k : u->adj){
                    Node* v = k.first;
                    int w = k.second;

                    //Relaxamento
                    if(distU + w < v->camMin){
                        v->camMin = distU + w;
                        v->pai = u;
                        hm.push(std::make_pair(v,v->camMin));
                    }
                }
            }
        }

        void verGrafo(){
            for(int i = 0; i < grap.size(); i++){
                Node * aux = grap[i];
                for(std::pair k : aux->adj){
                    std::cout << "(" << aux->name << "," << k.first->name << ") peso: " << k.second << std::endl;
                }
            }
        }

        void verCaminhos(){
            for(int i = 0; i < grap.size();i++){
                std::stack<Node*> pil;
                Node * aux = grap[i];
                pil.push(aux);
                
                while(!pil.empty() && aux->pai != nullptr){
                    pil.push(aux->pai);
                    aux = aux->pai;
                }

                while(!pil.empty()){
                    std::cout << pil.top()->name << " -> ";
                    pil.pop();
                }
                std::cout << "#" << std::endl;

            }
        }

};
#endif