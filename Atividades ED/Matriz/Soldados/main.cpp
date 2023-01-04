#include <iostream>
using namespace std;

/*
    verificar quantos soldados com numero menor esta atras de um soldado
    com numero maior, em uma matriz de 3x3.

*/
int main(){
    //criando uma matriz e a lendo.
    int matriz[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
             cin >> matriz[i][j];
        }
    }
    //criando o metodo de verificacao.
    int cont = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            if(matriz[i][j] > matriz[i+1][j]){
                cont++;
            }
        }
    }
    //printando esse resultado.
    cout << cont;
    return 0;
}