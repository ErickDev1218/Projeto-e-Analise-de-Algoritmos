#ifndef NODE_HPP
#define NODE_HPP
#include <vector>
#include <string>
#include <utility>
#include <climits>

class Node{
    public:
        char name = ' '; //Nome iniciando nulo
        Node* pai = nullptr; //Pai começando com nullptr
        int camMin = INT_MAX; //Caminho minimo começando com o infinito
        std::vector<std::pair<Node*,int>> adj;


        Node(char n){
            name = n;
        }
};
















#endif