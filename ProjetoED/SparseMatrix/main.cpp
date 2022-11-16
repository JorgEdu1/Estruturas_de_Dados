#include <iostream>
#include <sstream>
#include <fstream>
#include "SparseMatrix.h"
using namespace std;

SparseMatrix le_indice(){
    //Essa função lê o input do usuario, e retorna um objeto da nossa estrutura de dados.
    int linha, coluna;
    cout << "Numero de linhas: ";
    cin >> linha;
    cout << "Numero de colunas: ";
    cin >> coluna;
    SparseMatrix temp(linha, coluna);
    int n;
    cout << "Quer adicionar quantos elementos na sua matrix: ";
    cin >> n;
    if(n > linha*coluna){
        throw "ERRO: Numero de elementos maior que o numero de linhas e colunas";
    }
    for(int i = 0; i < n; i++){
        int l, c;
        double v;
        cout << "Linha: ";
        cin >> l;
        cout << "Coluna: ";
        cin >> c;
        cout << "Valor: ";
        cin >> v;
        temp.insert(l, c, v);
    }
    system("cls||clear");
    return temp;
}   

SparseMatrix* insere_indice(SparseMatrix* v, int *n, SparseMatrix temp){
    /*Apos ler um objeto com a funcao le_indice(), esse objeto é passado por parametro para essa 
    funcao junto com o vetor de objetos e o tamanho do vetor.*/
    *n+=1;
    SparseMatrix *aux;
    aux = new SparseMatrix[*n];
    if(*n != 0){
        for(int i = 0; i < *n-1; i++){
            aux[i] = v[i];
        }
        delete v;
        v = nullptr;
    }
    aux[*n-1] = temp;
    cout << "matrix alocada!" << endl;
    return aux;
}

SparseMatrix *sum(SparseMatrix* A, SparseMatrix* B){
    //funcão que o professor pede, simplesmente faz a soma de Duas matrizes e retorna um matriz resultante.
    //existe a condicao para testar se as duas matrizes sao de tamanhos iguais.(condicao necessaria para a soma)
    if(A->rows() != B->rows() || A->cols() != B->cols()){
        throw "ERRO: Matrizes de tamanhos diferentes!";
    }
    SparseMatrix *C = new SparseMatrix(A->rows(), A->cols());
    for(int i = 0; i < A->rows(); i++){
        for(int j = 0; j < A->cols(); j++){
            double value = A->get(i, j) + B->get(i, j);
            C->insert(i, j, value);
        }
    }
    return C;
}

SparseMatrix *multiply(SparseMatrix *A, SparseMatrix *B){
    //multiplica duas matrizes e retorna uma matriz resultante.
    //existe uma condicao para testar se as colunas de A sao iguais as linhas de B.(condicao necessaria para multiplicacao)) 
    if(A->cols() != B->rows()){
        throw "ERRO: Numero de colunas de A diferente do numero de linhas de B!";
    }
    SparseMatrix *C = new SparseMatrix(A->rows(), B->cols());
    for(int i = 0; i < A->rows(); i++){
        for(int j = 0; j < B->cols(); j++){
            double value = 0;
            for(int k = 0; k < A->cols(); k++){
                value += A->get(i, k) * B->get(k, j);
            }
            C->insert(i, j, value);
        }
    }
    return C;
}

SparseMatrix *readSparseMatrix(){
    //funcao que le um arquivo .txt com uma matriz e retorna um objeto da nossa estrutura de dados.(posteriormente colocado no vetor)
    ifstream archive;
    stringstream line;
    string aux;
    SparseMatrix *temp = 0;
    int l, c;
    double v;
    archive.open("matriz.txt");
    if(archive.is_open()){
        getline(archive, aux);
        line << aux;
        line >> aux;
        l = stoi(aux);
        line >> aux;
        c = stoi(aux);
        temp = new SparseMatrix(l, c);
    }else{
        throw "ERRO: Arquivo Invalido!";
    }
    while(getline(archive, aux)){
        stringstream teste(aux);
        teste >> aux;
        l = stoi(aux);
        teste >> aux;
        c = stoi(aux);
        teste >> aux;
        v = stod(aux);
        temp->insert(l, c, v);
    } 
    archive.close();
    return temp;
}

int main(){
    /*
    Main completamente interativa, com menu para o usuario escolher o que fazer.
    */ 
    
    SparseMatrix *matrizes = 0;
    cout << "Bem vindo ao programa de matrizes esparsas!" << endl;
    cout << "Ao iniciar o programa, ja eh lido a matriz do arquivo matriz.txt" << endl; 
    try{
        //tudo dentro de um try catch para tratar possiveis erros.
        int op, n = 0;
        SparseMatrix *temp = readSparseMatrix();
        matrizes = insere_indice(matrizes, &n, *temp);
        do{
            cout << "============================================================================================================" << endl;
            cout << "1 - Criar Matriz" << endl;
            cout << "2 - Somar Matrizes" << endl;
            cout << "3 - Multiplicar Matrizes" << endl;
            cout << "4 - Printar uma matriz" << endl;
            cout << "5 - Sair" << endl;
            cout << "============================================================================================================" << endl;
            cout << "Opcao: ";
            cin >> op;
            system("cls||clear");
            if(op == 1){
                //aqui o isuario cria uma matriz digitando.
                cout << "Criar Matriz Digitando:" << endl;
                SparseMatrix temp = le_indice();
                matrizes = insere_indice(matrizes, &n, temp);
            }else if(op == 2){
                //aqui o usuario soma 2 matrizes.
                int i1, i2;
                cout << "Matrizes disponiveis: " << endl;
                for(int i = 0; i < n; i++){
                    cout << i << " - " << matrizes[i].rows() << "x" << matrizes[i].cols() << endl;
                }
                cout << "Matriz 1: ";
                cin >> i1;
                cout << "Matriz 2: ";
                cin >> i2;
                SparseMatrix *C = sum(&matrizes[i1], &matrizes[i2]);
                system("cls||clear");
                cout << "Matriz resultante: " << endl;
                C->print();
                delete C;
                C = nullptr;
            }else if(op == 3){
                //aqui o usuario multiplica 2 matrizes.
                int i1, i2;
                cout << "Matrizes disponiveis: " << endl;
                for(int i = 0; i < n; i++){
                    cout << i << " - " << matrizes[i].rows() << "x" << matrizes[i].cols() << endl;
                }
                cout << "Matriz 1: ";
                cin >> i1;
                cout << "Matriz 2: ";
                cin >> i2;
                system("cls||clear");
                SparseMatrix *C = multiply(&matrizes[i1], &matrizes[i2]);
                cout << "Matriz resultante: " << endl;
                C->print();
                delete C;
                C = nullptr;
            }else if(op == 4){
                //aqui e feito o print de uma matriz.
                int i;
                cout << "Matrizes disponiveis: " << endl;
                for(int i = 0; i < n; i++){
                    cout << i << " - " << matrizes[i].rows() << "x" << matrizes[i].cols() << endl;
                }
                cout << "Matriz: ";
                cin >> i;
                matrizes[i].print();
            }
        } while (op != 5);
    }catch(const char* e){
        cout << e << endl;
    }
    delete matrizes;
    return 0;
}
