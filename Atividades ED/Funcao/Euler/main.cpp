#include <iostream>
#include <iomanip>
using namespace std;

/*
    questao pedia que calculasse o numero de euler com base em um fatorial
*/

double fatorial(double numero){

    //funçao para calcular fatorial

    double num_fat = numero, result = 1;

    for(int i = 2; i <= numero; i++){
        
        result = result * i;

    }

    return result;

}

double euler(double numero){

    //funçao que calcula o fatorial

    double euler = 1, num = numero;

    for(int i = numero; i > 0; i--){

        euler = (1/fatorial(i)) + euler;

    }
  
    return euler;

}

int main(){

    //funçao main que chama a funçao euler e que por sua vez, chama a funçao fatorial

    double numero;

    cin >> numero;
    
    //foi usado o std::fixed e std::setprecision pois o professor pediu

    cout << fixed;
    cout << setprecision(6);
    cout << "Fatorial: " << euler(numero);


    return 0;
}