#include <iostream>
using namespace std;

int primo(int num1, int num2) {

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

int a, b;

cin >> a;
cin >> b;

primo(a, b);

}