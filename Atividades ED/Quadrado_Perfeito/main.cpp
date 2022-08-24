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

    for(int i=0; i<3; i++) {

        //diagonal principal

        if((matriz[i][i]+matriz[i][i]+matriz[i][i])!=check) {

            perfeita = false;
        }
    }

    for(int i=0; i<3; i++) {

        //diagonal secundaria

        for(int j=3; j>=0; j--) {

            if((matriz[i][j]+matriz[i][j]+matriz[i][j])!=check) {

                perfeita = false;
            }
        }
    }

    //verificaçao para printar.

    if(perfeita) {

        cout << "sim";

    }else {

        cout << "nao";

    }

    return 0;
}
