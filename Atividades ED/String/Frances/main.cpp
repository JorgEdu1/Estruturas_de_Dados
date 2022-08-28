#include <iostream>
#include <string>
using namespace std;

    /* 
        tem frases que juntamos ao falar, "se eu" fica "seu", ao falarmos, questao quer que identificamos esses espacos
        entre vogais e quer que tire.
    */

int main() {

    //criando a string

    string vetor;
    getline(std::cin, vetor);
    int tam = vetor.size();

    //rodando o verificador de espacos enre vogais iguais.

    for (int i = 0; i < tam; i++) {

        if((vetor[i] == ' ') && (vetor[i-1] == vetor[i+1])){

            vetor[i] = '+';

        }

    }

    //retira e printa esses espacos, tbm retira a vogal duplicada.

    for (int i = 0; i < tam; i++) {

        if (vetor[i] == '+'){
            
            i++;
        
        }else if(((vetor[i] >= 97) && (vetor[i] <= 122)) || (vetor[i] = ' ')){

            cout << vetor[i];

        }

    }

    return 0;
}