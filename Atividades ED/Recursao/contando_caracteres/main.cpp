#include <iostream>
#include <string>

using namespace std;

// Retorna o números de ocorrências do caractere 'c' na string 'str' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
int contaCaracteres(string str, int n, char c){

        n--;
        if(n < 0){

            return 0;

        }else{

            if(str[n] == c){

                return contaCaracteres(str,n,c)+1;

            }else{

                return contaCaracteres(str,n,c);

            }

        }
}

int main() {
    
    string line; 
    char caracter;
    getline(cin, line);
    cin >> caracter;
    int tam = line.size();

    int quant = contaCaracteres(line, tam, caracter);

    cout << quant;
    

    return 0;
}