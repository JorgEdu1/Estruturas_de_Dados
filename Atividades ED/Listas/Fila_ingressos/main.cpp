#include <iostream>
#include <vector>
using namespace std;
/*
Com a proximidade da Copa do Mundo, o fluxo de pessoas nas filas para compra de ingressos
aumentou consideravelmente. Como as filas estão cada vez maiores, pessoas menos pacientes
tendem a desistir da compra de ingressos e acabam deixando as filas, liberando assim vaga
para outras pessoas. Quando uma pessoa deixa a fila, todas as pessoas que estavam atrás dela
dão um passo a frente, sendo assim nunca existe um espaço vago entre duas pessoas. A fila inicialmente
contém N pessoas, cada uma com um identificador diferente.
*/
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
int* remove(int *vec, int *size, int value) {
    *size -= 1;
    int *aux = new int[*size];
    int temp;
    for (int i = 0; i < *size; i++) {
        if (vec[i] == value){
            temp = i;
        }
    }
    int teste = 0;
    for (int i = 0; i < *size; i++) {
        if(i == temp){
            aux[i] = vec[teste+1];
            teste++;
        }else{
            aux[i] = vec[teste];
        }
        teste++;
    }

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
    for (int i = 0; i < vezes_remove; i++) {
        cin >> aux;
        for(int j = 0; j < cont; j++){
            if(aux == vec[j]){
                vec = remove(vec, &cont, aux);
            }
        }
    }
    for (int i = 0; i < cont; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}