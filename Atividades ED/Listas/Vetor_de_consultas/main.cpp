#include <vector>
#include <iostream>
#include <string>
using namespace std;
/*Há um vetor de strings de entrada e um vetor de strings de consulta. Para cada sequência de consultas, 
determine quantas vezes ela ocorre na lista de sequências de entrada.*/
void *matchingStrings(vector<string> vetor, vector<string> consult, int *cont, int tam){
    //a funcao era pra retornar um inteiro, mas esqueci como retorna vetor kkkkkkkkkkkkkkkkkkkkkkkk
    //resolvi contabilizar as ocorrencias por referencia, bem mais facil
    for(int i = 0; i < consult.size(); i++){
        for(int j = 0; j < vetor.size(); j++){
            if(consult[i] == vetor[j]){
                cont[i]++;
            }
        }
    }
}

int main(){
    int tam;
    cin >> tam;
    vector<string> v(tam);
    for(int i = 0; i < tam; i++){
        cin >> v[i];
    }
    cin >> tam;
    vector<string> consulta(tam);
    for(int i = 0; i < tam; i++){
        cin >> consulta[i];
    }
    //apartir daqui faco uma  sequencia de gambiarras
    int *cont = new int[consulta.size()]; //eu declarei como int cont[tam]; antes, mas moodle me deu warning, fiz assim e foi rs
    matchingStrings(v, consulta, cont, tam);//chamo a funcao, que nao retorna nada, ja que ele muda por referencia
    for(int i = 0; i < tam; i++){//printo o vetor ate o penultimo valor do vetor, ja que o ultimo printava um espaco no final, e o moodle nao aceitava, queria um \n
        if(tam - i >= 2){
            cout << cont[i] << " ";
        }
    }
    cout << cont[tam-1] << endl;//aqui printo o ultimo valor e o /n que o moodle tanto queria!
    delete [] cont;//free

    return 0;
}
/*conclusoes: Professor reclamava de algoritmos iguais, com todos os problemas que tive aqui,
percebo que talvez eu tenha feito um totalmente original ou anormal ao da maioria, com sacadas minhas
mas que com certeza nao é o menos complexo. fiz muita coisa desnecessaria.
*/