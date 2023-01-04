#include <iostream>
using namespace std;
/*
*/
int triangulo(int* v,int n){
    if(n < 1){       
        return v[0];     
    }else {   
        int aux[n-1];  
        for(int i = 0; i < n-1; i++) {            
            aux[i] = v[i] + v[i+1];       
        }     
        triangulo(aux,n-1);
        cout << "[";  
        for(int i = 0; i < n; i++){          
            if(i+1 < n){          
                cout << v[i] << " ";       
            }else{       
                cout << v[i];              
            }
        }     
        cout << "]" << endl;   
    } 
}

int main(){
    
    int n;
    cin >> n;
    int v[n];
    
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    triangulo(v,n);
    
    return 0;
}