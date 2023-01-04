#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

    /*
        questao pedia que verificassemos se a frase esta em ordem lexicografica ou nao.
    */

int main () {
    //criei uma stringstream para poder quebrar a string que irei ler em palavras separadas.
    stringstream ss ; 
    string str ;
    string value ;
    string ant_word = "zzz";
    bool check = true;
    getline ( cin , str ) ;
    ss << str ;
    //todo momento em que eu leio uma palavra da stringstream, isso da um retorno verdadeiro, permitindo
    //o while funcionar.
    while ( ss >> value ) { 
        //verificando se a frase e lexicografica mesmo.
        if(ant_word == "zzz"){
        }else if(ant_word >= value){
            check = false;
        }
        ant_word = value;
    }
    //checko pela variavel booleana se esta true ou false e printo.
    if(check){
        cout << "sim" << endl;
    }else{
        cout << "nao" << endl;
    }
    return 0;
 }