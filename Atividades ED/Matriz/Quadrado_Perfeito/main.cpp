#include <iostream>
using namespace std;

/*
    Questao pediu apenas para verificar se a matriz era um quadrado perfeito, ou seja,
     se as somas de linhas, colunas e diagonais eram iguais
*/

int main() {
    //criando a matriz e a lendo
    int matriz[3][3];
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cin >> matriz[i][j];
        }
    }
     //criando um metodo para verificar seu quadrado perfeito
    int check = matriz[0][0] + matriz[0][1] + matriz[0][2];
    bool perfeita = true;
    for(int i=0; i<3; i++) {
        //verificando linhas
        if((matriz[0][i]+matriz[1][i]+matriz[2][i])!=check) {
            perfeita = false;
        }
    }
    for(int i=0; i<3; i++) {
        //verificando colunas
        if((matriz[i][0]+matriz[i][1]+matriz[i][2])!=check) {
            perfeita = false;
        }
    }
    //diagonal principal
    int soma_diag_principal = 0;
    for(int i=0; i<3; i++) {
        soma_diag_principal += matriz[i][i];
    }   
    if(soma_diag_principal!=check){
        perfeita = false;
    }
    //diagonal secundaria
    int cont = 2, soma_diag_secundaria = 0;
    for(int i=0; i<3; i++) {
        soma_diag_secundaria += matriz[cont][i];
        cont--;
    }
    if(soma_diag_secundaria!=check){
        perfeita = false;
    }
    //verificaçao para printar.
    if(perfeita) {
        cout << "sim";
    }else {
        cout << "nao";
    }
    return 0;
}
