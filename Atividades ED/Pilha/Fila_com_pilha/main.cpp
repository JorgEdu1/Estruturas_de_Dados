#include <iostream>
#include <string>
#include <sstream>
#include "Stack.h"
using namespace std;

int main(){
    Stack<int> deposito, prateleira;
    int n, op, aux;
    stringstream ss;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> op;
        if(op == 1){
            cin >> aux;
        }
        if(op == 1){
            deposito.push(aux);
        }
        else if(op == 2){
            if(prateleira.empty()){
                while(!deposito.empty()){
                    prateleira.push(deposito.top());
                    deposito.pop();
                }
            }
            prateleira.pop();
        }
        else if(op == 3){
            if(prateleira.empty()){
                while(!deposito.empty()){
                    prateleira.push(deposito.top());
                    deposito.pop();
                }
            }
            ss << prateleira.top() << "\n";
        }
    }

    cout << ss.str() << endl;
    return 0;
}
