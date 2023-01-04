#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;

int main(){
    try{
        Queue<string> *fila = new Queue<string>();
        fila->push("A");
        fila->push("B");
        fila->push("C");
        fila->push("D");
        fila->push("E");
        fila->push("F");
        fila->push("G");
        fila->push("H");
        fila->push("I");
        fila->push("J");
        fila->push("K");
        fila->push("L");
        fila->push("M");
        fila->push("N");
        fila->push("O");
        fila->push("P");

        for(int i = 0; i < 15; i++){
            string time1 = fila->front();
            fila->pop();
            string time2 = fila->front();
            fila->pop();
            int gols1, gols2;
            cin >> gols1 >> gols2;
            if(gols1 > gols2){
                fila->push(time1);
            }else if(gols2 > gols1){
                fila->push(time2);
            }else{
                throw "Empate nao eh permitido!";
            }
        }
        cout << fila->front() << endl;
    }
    catch(const char* e){
        cout << "ERRO: " << e << endl;
    }
    

    return 0;
}