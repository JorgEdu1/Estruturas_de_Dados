#include <iostream>
#include <vector>
using namespace std;

void right_rotation(vector<int>& vet, int nrot){
    if(nrot == 0){//caso nrot for 0: acaba com a sequencua de recursividade.
        return;
    }else{ //caso nrot for > 0: faço o esquema de rotacao e vou descrementando o nrot e usando recursividade.
        int aux = vet[vet.size()-1];//colocando o ultimo valor do vetor dentro de aux.
        for(int i = vet.size()-1; i > 0; i--){//rodando um for que vai do tamanho do vetor -1 ate o indice 1.
            vet[i] = vet[i-1];
        }
        vet[0] = aux;//o ultimo indice do vetor(ou primeiro) recebe aquele valor guardado.
        nrot--;
        if(nrot > 0){//se ainda tiver rotacoes para seguir, chama a funcao novamente passando o vetor e o numero de rotacoes atualizados.
            right_rotation(vet, nrot);
        }
    }
}

void show(vector<int> &vet) {
    cout << "[ ";
    for(int value : vet)
        cout << value << " ";
    cout << "]\n";
}

int main(){
    int size, nrot;
    cin >> size >> nrot;
    vector<int> vet(size);
    for(int i = 0; i < size; i++)
        cin >> vet[i];
    
    right_rotation(vet, nrot);
    show(vet);
}
