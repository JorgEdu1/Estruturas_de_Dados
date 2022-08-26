#include <string>
#include <iostream>
using namespace std;

/*
    questao pede que para retirar tabulaçao ou espaços duplicados da frase.
*/

int main() {

    string line;
    getline(std::cin, line);

    for (int i = 0; i < line.size(); i++){
        
        if((line[i] == ' ' && line[i+1] == ' ') || (line[i] == '\t')){



        }else{

            cout << line[i];

        }

    }
        

    return 0;
}
