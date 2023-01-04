#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
/*
O código de Arnoldo pega as palavras e todas palavra que tem mais de uma sílaba, repete três vezes a mesma sílaba.
Para uma "falsa" separação silábica Arnaldo definiu que toda vogal seguida de consoante separa sílaba.
>>>>>>>>
Volte cá seu cabra safado
========
VoVoVolte cá seu cacacabra sasasafado
<<<<<<<<
*/
bool eVogal(char c){

    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){

        return true;

    }else {

        return false;

    }

}

int contSilaba(string str){
    
    int contSil = 0;
    
    for(int i = 0; i < str.size(); i++){
        
         if((eVogal(str[i]) == true) && (eVogal(str[i+1]) == false)){
             
             contSil++;
             
         }else if (!(eVogal(str[(int)str.size()-1]))) {

            contSil++;

        }
        
    }
    
    
    return contSil;
}

int main(){

    string line;
    getline(std::cin, line);
    stringstream ss;
    string value;
    string str;
    string completa = "";
    int count;
    int contador = 0;
    int countSil;
    ss << line;
    bool check = false;

    while (ss >> value ) {

        count = value.size();
        countSil = contSilaba(value);
        if(count > 3){
            
            for(int i = 0; i < value.size(); i++) {

                if((countSil > 1) && (eVogal(value[i]) == true) && (eVogal(value[i+1]) == false)){
                
                    contador = i+1;
                    
                    for(int j = 0; j < contador ; j++){
                        
                        str += value[j];
                        
                    }
                    
                    check = true;
                    break;
                    
                }
                
                if((check = false) && (eVogal(value[i]) == true) && (eVogal(value[i+1]) == false)){
                
                    contador = i+1;
                    
                    for(int j = 0; j < contador ; j++){
                        
                        str += value[j];
                        
                    }
                    
                    break;
                }
            }
            completa = completa + str + str + value + " ";
            str = "";

    }else {

        completa = completa + value + " ";

        }
    }

    for(int i = 0; i < completa.size()-1; i++) {

        cout << completa[i];

    }

}
