#include <iostream>
#include <vector>
using namespace std;


/*
Desenvolva um algoritmo para inserir um elemento em um vetor ordenado contendo
n elementos, de tal modo que ap´os a inser¸c˜ao ele continue ordenado. Suponha que
o vetor tenha capacidade infinita, ou seja, o tamanho do vetor seja m >>> n, ou
seja, ele nunca ficar´a cheio, sempre ter´a um espa¸co no vetor para adicionar um novo
elemento. Desconsidere o caso do vetor est´a vazio (n = 0). Depois determine a
complexidade desse seu algoritmo em rela¸c˜ao ao melhor e pior caso, se houver
*/
void inclui(vector<int>& v, int k){
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i] > k){
            int aux = v[i];
            v[i] = k;
            for(int j = i+1; j < v.size(); j++){
                int aux2 = v[j];
                v[j] = aux;
                aux = aux2;
            }
            return;
        }
    }
    v[v.size()-1] = k;
}

int main(){
    vector<int> v;
    int x; 
    cin >> x;
    v.resize(x+1);
    int y;
    for(int i = 0; i < x; i++){
        cin >> y;
        v[i] = y;
    }
    int k;
    cin >> k;
    inclui(v,k);

    for(int i = 0; i<v.size();i++)
        cout << v[i] << " ";
}
