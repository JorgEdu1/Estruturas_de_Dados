#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <limits.h>
using namespace std;

void vect(vector<int> vetor, int ind){

    if(ind == vetor.size()){

        return;

    }
    
    cout << vetor[ind] << " ";
    ind++;
    vect(vetor, ind);

}

void rvet(vector<int> vetor, int n){
    
    n--;
    if(n == 0){

        cout << vetor[n] << " ";
        return;

    }
    
    cout << vetor[n] << " ";
    rvet(vetor, n);

}

int sum(vector<int> vetor, int n){

    n--;
    if (n==0) {

        return vetor[n];

    }else{

        return sum(vetor, n) + vetor[n];

    }
    
}
int mult(vector<int> vetor, int n){

    n--;
    if (n==0) {

        return vetor[n];

    }else{

        return mult(vetor, n) * vetor[n];

    }
    
}

void min(vector<int> vetor, int n, int minimo){

    n--;
    if(n == 0){

        if(vetor[n] <= minimo){

            minimo = vetor[n];
            //cout << " novo minimo: " << minimo << endl;

        }

            cout << minimo;
    
    
    }else if(n == vetor.size()-1){

        minimo = vetor[n];
        //cout << " novo minimo: " << minimo << endl;
        min(vetor, n, minimo);

    }else {

        if(vetor[n] <= minimo){

            minimo = vetor[n];
            //cout << " novo minimo: " << minimo << endl;
            min(vetor, n, minimo);

        }else {

            min(vetor, n, minimo);

        }

    }

}

int main(){

    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> vet;
    int value;
    while(ss >> value){
     
        vet.push_back(value);   

    } 

    int tam = vet.size(); 
    int minimo = INT_MAX;

    cout << "vet : [ "; vect(vet, 0); cout << "]" << endl;
    cout << "rvet: [ "; rvet(vet, tam); cout << "]" << endl;
    cout << "sum : " << sum(vet, tam) << endl;
    cout << "mult: " << mult(vet, tam) << endl;
    cout << "min : "; min(vet, tam, minimo); cout << endl;
    cout << "inv : [ "; rvet(vet, tam); cout << "]" << endl;

    return 0;
}