#include <string>
#include <iostream>
using namespace std;

/*
    questao pede que para retirar tabulaçao ou espaços duplicados da frase.
*/

int main() {

    //criando e lendo string

    string line;
    getline(std::cin, line);

    //verificando se ha espaços duplicados ou tabs, e printando se tive OK!

    for (int i = 0; i < line.size(); i++){
        
        if((line[i] == ' ' && line[i+1] == ' ') || (line[i] == '\t')){



        }else{

            //printando

            cout << line[i];

        }

    }
        

    return 0;
}
