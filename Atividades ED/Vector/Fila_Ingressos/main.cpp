#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int* insert(int *vec, int *size, int value){
    *size += 1;
    int *aux = new int[*size];
    if(vec != 0){
        for(int i = 0; i < *size; i++){
            aux[i] = vec[i];
        }

        delete vec;
        vec = nullptr;
    }
    aux[*size-1] = value;
    return aux;
}
int* remove(int *vec, int *size, int *value, int* tam_v) {
    for (int j = 0; j < *tam_v; j++){
        for (int i = 0; i < *size; i++) {
            if (vec[i] == value[j]){
                vec[i] = INT_MAX;
            }
        }
    }
    int cont = 0;
    int *aux = new int[*size - *tam_v];
    for(int i = 0; i < *size-*tam_v; i++){
        if(vec[cont] == INT_MAX){
            cont++;
            aux[i] = vec[cont];
        }else{
            aux[i] = vec[cont];
        }
        cont++;
    }
    *size -= *tam_v;
    delete vec;
    vec = nullptr;
    return aux;
}

int main(){
    int n;
    cin >> n;
    int *vec = 0;
    int aux, cont = 0;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        vec = insert(vec, &cont, aux);
    }
    int vezes_remove;
    cin >> vezes_remove;
    int remover[vezes_remove];
    for (int i = 0; i < vezes_remove; i++) {
        cin >> remover[i];
    }
    vec = remove(vec, &cont, remover, &vezes_remove);
    for (int i = 0; i < cont; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}