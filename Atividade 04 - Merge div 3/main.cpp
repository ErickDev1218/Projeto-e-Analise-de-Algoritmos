#include <iostream>
#include <vector>
using namespace std;

void Intercala(vector<int>& v, int ini, int mid1, int mid2, int fim){
    //Calculando o tamanho dos 3 subvetores
    int tam1 = mid1 - ini + 1; 
    int tam2 = mid2 - mid1;
    int tam3 = fim - mid2;

    vector<int> left (tam1);
    vector<int> medium (tam2);
    vector<int> right (tam3);

    for(int i = 0; i < tam1; i++){
        left[i] = v[i+ini];
    }
    for(int i = 0; i < tam2; i++){
        medium[i] = v[i + mid1 +1];
    }
    for(int i = 0; i < tam3; i++){
        right[i] = v[i + mid2 + 1];
    }
    //Agora eu tenho 3 subvetores e preciso organiza-los em de forma crescente no vetor original

    int i = 0; //Para subvetor left
    int j = 0; //Para o subvetor medium
    int k = 0; //Para o subvetor right
    int l = ini; //Para o vetor original

    while(i < tam1 && j < tam2 && k < tam3){
        if(left[i] <= medium[j] && left[i] <= right[k]){
            v[l] = left[i];
            i++;
        }else if(medium[j] <= left[i] && medium[j] <= right[k]){
            v[l] = medium[j];
            j++;
        }else{
            v[l] = right[k];
            k++;
        }
        l++;
    }

    if(i == tam1 && (j != tam2 || k != tam3)){
        while(j < tam2 && k < tam3){
            if(medium[j] <= right[k]){
                v[l] = medium[j];
                j++;
            }else{
                v[l] = right[k];
                k++;
            }
            l++;
        }
    }else if(j == tam2 && (i != tam1 || k != tam3)){
        while(i < tam1 && k < tam3){
            if(left[i] <= right[k]){
                v[l] = left[i];
                i++;
            }else{
                v[l] = right[k];
                k++;
            }
            l++;
        }
    }else if(k == tam3 && (i != tam1 || j != tam2)){
        while(i < tam1 && j < tam2){
            if(left[i] <= medium[j]){
                v[l] = left[i];
                i++;
            }else{
                v[l] = medium[j];
                j++;
            }
            l++;
        }
    }

    while(i < tam1){
        v[l] = left[i];
        i++;
        l++;
    }
    while(j < tam2){
        v[l] = medium[j];
        j++;
        l++;
    }
    while(k < tam3){
        v[l] = right[k];
        k++;
        l++;
    }
    
}


void TripleMerge(vector<int>& v, int ini, int fim){
    if(ini < fim){
        int n = fim - ini + 1; //calcula o tamanho do vetor
        int razao = n / 3; //calcula o tamanho que cada subvetor terá

        int mid1 = ini + razao - 1;
        int mid2 = ini + 2 * razao - 1;

        TripleMerge(v,ini,mid1); //Chamada recursiva para o primeiro subvetor
        TripleMerge(v,mid1+1,mid2);//Chamada recursiva para o segundo subvetor
        TripleMerge(v,mid2+1,fim);//Chamada recursiva para o terceiro subvetor
        
        Intercala(v,ini,mid1,mid2,fim); //Intercalando 3 subvetores em um vetor ordenado

    }
}


int main(){
    
    vector<int> vetor(9);
    for(int i = vetor.size()-1; i >= 0; i--){
        vetor[i] = i;
        cout << i << " ";
    }

    TripleMerge(vetor,0,vetor.size()-1);

    for(int i = 0; i < vetor.size(); i++)
        cout << vetor[i] << " ";
}