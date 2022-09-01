#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

    /*
        questao pedia que fosse feito uma solucao para distinguir o tipo priimitica de cada elemento
        digitado pelo usuario.
    */

   //funcao que verifica se e decimal ou hexadecimal ponto flutuante.

bool flutuante(string teste){

    int check = 0;

    for (int i = 0; i < teste.size(); i++){
        
        if((teste[i-1] >= '0' && teste[i-1] <= '9') && (teste[i+1] >= '0' && teste[i+1] <= '9') && (teste[i] == '.')){

            check++;

        }else if((teste[i-1] >= 'a' && teste[i-1] <= 'f') && (teste[i+1] >= 'a' && teste[i+1] <= 'f') && (teste[i] == '.')){

            check++;

        }

    }
    
    if(check == 1) {

        return true;

    }else {

        return false;

    }

}

    //funcao que verifica se tem letra no elemento.

bool temLetra(string teste){

    int check = 0;

    for (int i = 0; i < teste.size(); i++){
        
        if((teste[i] >= 'a' && teste[i] <= 'z') || (teste[i] >= 'a' && teste[i] <= 'z')){

            check++;

        }

    }

    if(check >= 1) {

        return true;

    }else {

        return false;

    }

}

int main () {

    //criando stringstream para que possamos quebrar palavra por palavra da frase digitada.

    stringstream ss ; 
    string str ;
    string value;

    getline ( cin , str ) ;
    ss << str ;

    //loop que quebra essa stringstream e chama as funcoes dentro dos if's

    while ( ss >> value ) {
            
        if(flutuante(value)) {

            cout << "float ";

        }else if(temLetra(value)){

            cout << "str ";

        }else {

            cout << "int ";

        }

    }

    return 0;
 }