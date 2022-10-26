#include "SparseMatrix.h"
#include <iostream>

SparseMatrix::SparseMatrix(int rows, int cols) {
    m_rows = rows;
    m_cols = cols;
    m_head = new Node(nullptr, nullptr, 0, 0, 0);//criu o sentinela raiz, tipo esse M:
    /*
    M  0  0  0
    0
    0
    0
    */
    m_head->right = m_head;
    m_head->down = m_head;//aqui eu faco sua ligacao com ele mesmo. Circular e duplamente encadeada.
    for(int i = 0; i < m_rows; i++){
        if(rows > 0){
            Node *aux = m_head;
            while(aux->down != m_head){
                aux = aux->down;//andando pelas linhas ate achar a ultima linha.
            }
            Node *ajuda = new Node(nullptr, m_head, i+1, 0, 0);//declaro um nó, que na direita ele aposta para si mesmo, pois esta limpo, e abaixo ele aposta para head, CIRCULAR.
            ajuda->right = ajuda;
            aux->down = ajuda;//com ajuda do ponteiro aux, eu faço o ultimo sentinela apontar para o no que declarei agora.
        }
    }
    for(int i = 0; i < m_cols; i++){
        if(cols > 0){
            Node *aux = m_head;
            while(aux->right != m_head){
                aux = aux->right;//andando pelas colunas ate achar a ultima coluna.
            }
            Node *ajuda = new Node(m_head, nullptr, 0, i+1, 0);//declaro um no, que na direita ele aposta para head, pois é ciruclar, e na down ele aposta para si mesmo, pois esta limpo
            ajuda->down = ajuda;
            aux->right = ajuda;//com ajuda do ponteiro aux, eu faço o ultimo sentinela apontar para o no que declarei agora.
        }
    }
}
void SparseMatrix::insert(int row, int col, double value){ 
    /*logica antes de fazer o insert, temos que analizar o seguinte, temos que pegar o sentinela de coluna e analizar se o down dele
    aponta para ele mesmo, pois se sim, quer dizer que aquela coluna esta clear, se nao, quer dizer que ha algum no naquela coluna, 
    a mesma coisa se aplica as linhas, com algumas diferenças, creio eu que ha 4 casos: caso 1: linha livre e coluna livre, 
    caso 2: linha com no e coluna livre, caso 3: linha livre e coluna com no, caso 4: linha com no e coluna com no.*/
    
    Node *auxRow = m_head;//sou o sentinela de linha - RIGHT
    for(int i = 1; i <= row; i++){
       auxRow = auxRow->down;
    }
    Node *auxCol = m_head;//sou o sentinela de coluna - DOWN
    for(int i = 1; i <= col; i++){
        auxCol = auxCol->right;
    }
    
    if(auxRow->right == auxRow && auxCol->down == auxCol){//caso 1.
        Node *ajuda = new Node(auxRow, auxCol, row, col, value);
        auxRow->right = ajuda;
        auxCol->down = ajuda;
    }else if(auxRow->right != auxRow  && auxCol->down == auxCol){//caso 2.
        while(auxRow->right != m_head){
            auxRow = auxRow->right;
        }
        Node *ajuda = new Node(m_head, auxCol, row, col, value);
        auxRow->right = ajuda;
        auxCol->down = ajuda;
    }else if(auxRow->right == auxRow && auxCol->down != auxCol){//caso 3.
        while(auxCol->down != m_head){
            auxCol = auxCol->down;
        }
        Node *ajuda = new Node(auxRow, m_head, row, col, value);
        auxRow->right = ajuda;
        auxCol->down = ajuda;
    }else if(auxRow->right != auxRow && auxCol->down != auxCol){//caso 4.
        while(auxCol->down != m_head){
            auxCol = auxCol->down;
        }
        while(auxRow->right != m_head){
            auxRow = auxRow->right;
        }
        Node *ajuda = new Node(m_head, m_head, row, col, value);
        auxRow->right = ajuda;
        auxCol->down = ajuda;        
    }
}
void SparseMatrix::print() {
    Node *auxRow = m_head->down;
    Node *auxCol = m_head->right;
    for(int i = 0; i < auxRow->mrows; i++) {
        for(int j = 0; j < auxCol->mcols; j++) {
            Node *temp = auxRow;//terminar aqui!
            if(auxRow->right == auxRow){
                std::cout << "0 ";
            }else {
                std::cout << auxRow->right->value << " ";
                auxRow = auxRow->right;
            }
        }
        std::cout << std::endl;
        auxRow->
        auxRow = auxRow->down;
    }
    /*for(int i = 1; i <= m_rows; i++){
        for(int j = 1; j <= m_cols; j++){
            if(auxRow->right->col == i){
                std::cout << auxRow->right->value << " ";
                auxRow = auxRow->down;
            }else{
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
        auxRow = auxRow->down;
    }*/
}
/*

  m  0  0  0
  0
  0
  0
*/