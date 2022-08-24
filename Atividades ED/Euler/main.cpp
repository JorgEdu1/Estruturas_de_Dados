#include <iostream>
#include <iomanip>
using namespace std;

double fatorial(double numero){

    double num_fat = numero, result = 1;

    for(int i = 2; i <= numero; i++){
        
        result = result * i;

    }

    return result;

}

double euler(double numero){

    double euler = 1, num = numero;

    for(int i = numero; i > 0; i--){

        euler = (1/fatorial(i)) + euler;

    }
  
    return euler;

}

int main(){

    double numero;

    cin >> numero;
    
    cout << fixed;
    cout << setprecision(6);
    cout << "Fatorial: " << euler(numero);

}