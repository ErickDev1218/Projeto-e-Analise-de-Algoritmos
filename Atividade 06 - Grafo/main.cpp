#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<list<int>> unique(vector<list<int>> g,vector<vector<bool>> M){
    vector<list<int>> a;
    a.resize(g.size());

    for(int i = 0; i < g.size(); i++){
        for(auto k : g[i]){
            if(k != i && M[i][k]){
                a[i].push_back(k);
                M[i][k] = false;
            }
        }
    }
    return a;
}

int main(){
    vector <list <int>> G;
    int vertices;
    cin >> vertices;
    G.resize(vertices+1);
    vector<vector<bool>> M(vertices+1,vector<bool>(vertices+1,false)); 

    int qtdArestas;
    cin >> qtdArestas;

    for(int i = 1; i <= qtdArestas; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        M[u][v] = true;
        M[v][u] = true;
    }

    cout << "Multigrafo: " << endl;
    for(int i = 0; i <= vertices; i++){
        for(auto k : G[i]){
            cout << "(" << i << "," << k << ")" << endl;
        }
    }
    cout << endl << "Grafo equivalente:" << endl;
    vector<list<int>> A = unique(G,M);
    
    for(int i = 0; i <= vertices; i++){
        for(auto k : A[i]){
            cout << "(" << i << "," << k << ")" << endl;
        }
    }
}