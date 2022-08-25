#include <iostream>
using namespace std;

/*
    teste
*/

int main(){

    int matriz[3][3];

    for(int i = 0; i < 3; i++){

        for(int j = 0; j < 3; j++){

             cin >> matriz[i][j];

        }

    }

    int cont = 0;

    for(int i = 0; i < 2; i++){

        for(int j = 0; j < 3; j++){

            if(matriz[i][j] > matriz[i+1][j]){

                cont++;

            }

        }

    }

    cout << cont;

    return 0;
}