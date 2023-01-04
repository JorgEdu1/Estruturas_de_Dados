#include <iostream>
using namespace std;

    /*
        questao pedia soluçao para verificar quais sao os primos entre o intervalo de numeros digitados
    */

int primo(int num1, int num2) {

    //funçao que verifica os numeros primos
    bool check; 
    for (int i = num1; i <= num2; i++){
        check = false;
        for (int j = 2; j < i; j++){
            if(i % j == 0) {
               check = true;
            }
        }
        if(check == false){
            cout << i << endl;
        }else {
            check = false;
        }
    }
}

int main(){
    //main que chama a funçao primos
    int a, b;
    cin >> a;
    cin >> b;
    primo(a, b);
    return 0;
}