#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    int vetor[n];

    for(int i=0;i<n;i++){

        cin >> vetor[i]; 

    }

    bool check = false;

    for(int i=0;i<n-1;i++){

        if(vetor[i]<= vetor[i+1]){

            check = true;

        }else {

            check = false;
            break;

        }

    }

    if(check==true){

        cout << "ok" << endl;

    }else{

        cout << "precisa de ajuste" << endl;

    }

}