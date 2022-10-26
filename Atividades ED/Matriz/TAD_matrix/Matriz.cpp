// Arquivo de Implementacao do TAD Matriz
#include <iostream>
#include <iomanip>
#include "Matriz.h"
using namespace std;

// Aloca espaco dinamicamente para matriz com m linhas e n colunas
Matriz::Matriz(int m, int n) {
    lin = m;
    col = n;
    mat = new int*[lin];
    for(int i = 0; i < lin; i++) {
        mat[i] = new int[col];
    }
}   

// Destrutor: Libera a memoria que foi alocada dinamicamente no construtor
Matriz::~Matriz() {
    for (int i = 0; i < this->lin; i++){
        delete [] mat[i];
    }
    delete [] mat;
    cout << "matriz liberada" << endl;    
}   

// Retorna o numero de linhas da matriz
int Matriz::linhas() {
    return this->lin;
} 

// Retorna o numero de colunas da matriz
int Matriz::colunas() { 
    return this->col;
}

// Retorna o valor da celula [i][j] da matriz
int Matriz::getValor(int i, int j) {
    return this->mat[i][j];
} 

// Atribui valor a celula [i][j] da matriz
void Matriz::setValor(int valor, int i, int j) {
    this->mat[i][j] = valor;
}

// Imprimir a matriz 
void Matriz::print() {
    for(int i = 0; i < lin; ++i) {
		for(int j = 0; j < col; ++j) {
			cout << setw(7) << mat[i][j];
		}
		cout << "\n";
	}
} 

// Soma matrizes
Matriz *Matriz::soma(Matriz& B) {
    if(B.lin != this->lin){
        return nullptr;
    }else{
        Matriz *aux = new Matriz(this->lin, this->col);
        for(int i = 0; i < this->lin; i++){
            for (int j = 0; j < col; j++){
                aux->setValor(B.getValor(i,j)+this->getValor(i,j),i,j);
            }
        }
        return aux;
    }
}

// Multiplica matrizes
Matriz *Matriz::multiplica(Matriz& B) {
    int somaMatrix = 0;
    int auxInt;
    if(B.lin != this->col){
        return nullptr;
    }else{
        Matriz *aux = new Matriz(this->lin,B.col);
        for(int i=0;i<this->lin;i++){
            for (int j = 0; j < B.col; j++){
                for(int k = 0; k < B.lin; k++){
                    aux->setValor(aux->getValor(i,j)+(this->getValor(i,k)*B.getValor(k,j)),i,j);
            }
            
        }
        return aux;
    }
}
}