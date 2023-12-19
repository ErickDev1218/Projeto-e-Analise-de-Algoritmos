/*Desenvolva um algoritmo para determinar se uma vetor de tamanho n esta ordenado.
Depois faca a analise de complexidade desse seu algoritmo em relacao ao melhor e
pior caso, se houver.*/

#include <iostream>
#include <vector>
using namespace std;

bool testa(vector<int> v){
    if(v.size() == 1){
        return true;
    }
    for(int i = 1; i < v.size(); i++){
        if(v[i-1] > v[i]){
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> v;
    int x = 0;
    cin >> x;
    int value = 0;
    v.resize(x);
    for(int i = 0; i < x; i++){
        cin >> value;
        v[i] = value;       
    }

    cout << (testa(v) == true ? "True" : "False") << endl;
}