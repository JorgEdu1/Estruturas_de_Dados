#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

    /*
        questao pedia que recebesse uma frase e fizesse uma operacao que o usuario dogitasse, M para tudo maiuscula, m para tudo
        minuscula, p para toda palavra comecar maiuscula, i para inverter a case.
    */

int main(){

    //lendo os valores e armazenando a frase dentro de um stringstream.

    string line;
    char format;

    getline(std::cin, line);
    cin>>format;
    stringstream ss(line);
    string value;
    string str;
    
    //verificacoes de cada caso.

    if (format == 'M'){
        
        while ( ss >> value ) {

            for (int i = 0; i < (int)value.size(); i++){
                
                if(value[i] >= 'a' && value[i] <= 'z') {

                    value[i] -= 32;

                }

            }
            
            str += value + " ";

        }
        
    }else if (format == 'm'){
        
        while ( ss >> value ) {

            for (int i = 0; i < (int)value.size(); i++){
                
                if(value[i] >= 'A' && value[i] <= 'Z') {

                    value[i] += 32;

                }

            }
            
            str += value + " ";

        }
    }else if (format == 'p'){

        while ( ss >> value ) {

            if(value.size() > 1){

                if(value[0] >= 'a' && value[0] <= 'z'){

                    value[0] -= 32;

                    }

                }else {

                    if(value[0] >= 'A' && value[0] <= 'Z'){

                    value[0] += 32;

                }

            }
            
            str += value + " ";

        }

    }else if (format == 'i'){
        
        while ( ss >> value ) {

            for (int i = 0; i < (int)value.size(); i++){
                
                if(value[i] >= 'A' && value[i] <= 'Z') {

                    value[i] += 32;

                }else if(value[i] >= 'a' && value[i] <= 'z') {

                    value[i] -= 32;

                }

            }
            
            str += value + " ";

        }

    }

    /*
    o corretor da questao estava pegando um espaco no final da frase, tive que fazer 
    isso para passar nos testes.
    */

    for (int i = 0; i < str.size() - 1; i++){
    
        cout << str[i];

    }
    

}
