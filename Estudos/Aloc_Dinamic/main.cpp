#include <iostream>
using namespace std;

int* insere_indice(int *v, int *n, int novo){

    *n += 1;
    int *aux;
    aux = new int[*n];

    if(v != 0) {

       for (int i = 0; i < *n; i++){
         aux[i] = v[i]; 
       }
        delete[] v; 
        v = nullptr;
    }
    
    aux[*n-1] = novo;

    return aux;

}

int* remove_indice(int *v, int *n, int ind){

    *n -= 1;
    int *aux = new int[*n];

    for(int i = 0; i < *n+1; i++){

        if(i == ind){

            v[i] = v[*n];

        }

    }

    for(int i = 0; i < *n; i++){

        aux[i] = v[i];

    }

    delete[] v;
    v = nullptr;
    return aux;
} 

void fechar(int *v){

    int opa = 1;
    delete[] v;
    system("clear || cls");
    exit(opa);

}

int menu(){

    int op;

    cout << "==========================================================================" << endl;
    cout << "Bem-vindo ao programa que serve de estudo para alocar array dinamicamente." << endl;
    cout << "Digite:" << endl << "1 para alocar um indice do vetor dinamicamente." << endl << "2 para deletar um indice do vetor dinamicamente." 
    << endl << "3 para mostrar informaçoes do array." << endl << "4 para fechar programa e desalocar todos os dados." << endl;
    cout << "==========================================================================" << endl;
    cin >> op;    

    return op;
}

int main(){

    int op, aux, novo = 0, indice = 0;
    int n=0;
    int *vetor = 0;

    do{ 
        
        op = menu();
        
        if(op == 1){

            //alocar dinamicamente um dado
            cout << "Digite o valor que deseja alocar: ";
            cin >> novo;
            vetor = insere_indice(vetor, &n, novo);
            novo = 0;
            system("clear || cls");

        }else if(op == 2){

            //deletar dinamicamente um dado
            cout << "digite o indice que deseja retirar: ";
            cin >> indice;
            vetor = remove_indice(vetor, &n, indice);
            system("clear || cls");

        }else if(op == 3){

            //printar valores
            for (int i = 0; i < n; i++){

                cout << "indice: " << i << " - valor: " << vetor[i] << endl;

            }
            
            cout << "s para continuar e limpar a tela: ";
            char check;
            cin >> check;
            if (check == 's'){

                system("clear || cls");

            }

        }else if(op == 4){

            //fechar programa e desalocar memoria
            fechar(vetor);

        }else {

            cout << "INVALIDA!"; 

        }

    } while (op != 4);
    
    fechar(vetor);
    return 0;
}
