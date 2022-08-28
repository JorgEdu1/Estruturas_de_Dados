#include <iostream>
using namespace std;

/* 
    Questao pedia que uma soluçao para verificar se uma sequencia de caracteres estava em ordem crescente,
    se sim, print "ok", se nao, "precisa de reparo"
*/

int main(){

    //lendo a sequencia e armazenando em um vetor
    int n;
    cin >> n;

    int vetor[n];

    for(int i=0;i<n;i++){

        cin >> vetor[i]; 

    }

    //checkando se esta em ordem crescente com ajuda de uma variavel booleana

    bool check = false;

    for(int i=0;i<n-1;i++){

        if(vetor[i]<= vetor[i+1]){

            check = true;

        }else {

            check = false;
            break;

        }

    }

    //checkando a situaçao da variavel booleana, se true, esta crescente, se false, nao esta crescente

    if(check==true){

        cout << "ok" << endl;

    }else{

        cout << "precisa de ajuste" << endl;

    }

    return 0;
}