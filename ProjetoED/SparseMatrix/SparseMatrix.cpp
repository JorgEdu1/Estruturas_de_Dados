#include "SparseMatrix.h"
#include <iostream>

SparseMatrix::SparseMatrix(int rows, int cols) {
    m_rows = rows;
    m_cols = cols;
    m_head = new Node(nullptr, nullptr, -1, -1, 0);//criu o sentinela raiz, tipo esse M:
    /*
    M  0  0  0
    0 
    0
    0
    */
    m_head->right = m_head;
    m_head->down = m_head;//aqui eu faco sua ligacao com ele mesmo. Circular.
    for(int i = 0; i < m_rows; i++){
        if(rows > 0){
            Node *aux = m_head;
            while(aux->down != m_head){
                aux = aux->down;//andando pelas linhas ate achar a ultima linha.
            }
            Node *ajuda = new Node(nullptr, m_head, i, -1, 0);//declaro um nó, que na direita ele aposta para si mesmo, pois esta limpo, e abaixo ele aposta para head, CIRCULAR.
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
            Node *ajuda = new Node(m_head, nullptr, -1, i, 0);//declaro um no, que na direita ele aposta para head, pois é ciruclar, e na down ele aposta para si mesmo, pois esta limpo
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
    Node *auxRow = m_head;
    for(int i = 0; i <= row; i++){
       auxRow = auxRow->down;
    }
    Node *auxCol = m_head;//sou o sentinela de coluna - DOWN
    for(int i = 0; i <= col; i++){
        auxCol = auxCol->right;
    }
    if(auxRow->right == auxRow && auxCol->down == auxCol){//caso 1.
        Node *ajuda = new Node(auxRow, auxCol, row, col, value);
        auxRow->right = ajuda;
        auxCol->down = ajuda;
    } 
    else if(auxRow->right == auxRow && auxCol->down != auxCol){//caso 2
        Node *MoovableCol = auxCol;        // SERVE PARA MARCAR O ULTIMO ELEMENTO DA COLUNA
        while(MoovableCol->down != auxCol){
            MoovableCol = MoovableCol->down;
        }
        if(row == MoovableCol->row){
            MoovableCol->value = value;
        }
        if(row < MoovableCol->row){
            Node *novo = new Node(auxRow, auxCol->down, row, col, value);
            auxRow->right = novo;
            auxCol->down = novo;
        }
        else if(row > MoovableCol->row){
            Node *novo = new Node(auxRow, auxCol, row, col, value);
            MoovableCol->down = novo;
            auxRow->right = novo;
        }
    }else if(auxRow->right != auxRow && auxCol->down == auxCol){//caso 3
        Node *MoovableRow = auxRow;         // SERVE PARA MARCAR O ULTIMO ELEMENTO DA LINHA
        while(MoovableRow->right != auxRow){
            MoovableRow = MoovableRow->right;
        }
        if(col == MoovableRow->col){
            MoovableRow->value = value;
        }
        if(col < MoovableRow->col){
            Node *novo = new Node(auxRow->right, auxCol, row, col, value);
            auxRow->right = novo;
            auxCol->down = novo;
        }
        else if(col > MoovableRow->col){
            Node *novo = new Node(auxRow, auxCol, row, col, value);
            MoovableRow->right = novo;
            auxCol->down = novo;
        }
    }
    else {//caso 4
        Node *MoovableRow = auxRow;         // SERVE PARA MARCAR O ULTIMO ELEMENTO DA LINHA
        while(MoovableRow->right != auxRow){
            MoovableRow = MoovableRow->right;
        }
        Node *MoovableCol = auxCol;         // SERVE PARA MARCAR O ULTIMO ELEMENTO DA COLUNA
        while(MoovableCol->down != auxCol){
            MoovableCol = MoovableCol->down;
        }
        if(col == MoovableRow->col && row == MoovableCol->row){
            MoovableRow->value = value;
        }
        if(col < MoovableRow->col && row < MoovableCol->row){
            Node *novo = new Node(auxRow->right, auxCol->down, row, col, value);
            auxRow->right = novo;
            auxCol->down = novo;
        }
        else if(col > MoovableRow->col && row > MoovableCol->row){
            Node *novo = new Node(auxRow, auxCol, row, col, value);
            MoovableRow->right = novo;
            MoovableCol->down = novo;
        }
        else if(col < MoovableRow->col && row > MoovableCol->row){
            Node *novo = new Node(auxRow->right, auxCol, row, col, value);
            auxRow->right = novo;
            MoovableCol->down = novo;
        }
        else if(col > MoovableRow->col && row < MoovableCol->row){
            Node *novo = new Node(auxRow, auxCol->down, row, col, value);
            MoovableRow->right = novo;
            auxCol->down = novo;
        }
        if(auxCol->down->col == col && auxRow->right->row == row && auxCol->down != auxCol && auxRow->right != auxRow){//caso 1
            Node *MovRow = auxCol; 
            while(MovRow->down->row != row){
                MovRow = MovRow->down;
            }
            MovRow = MovRow->down;
            MovRow->value = value;
        }
    }
}

double SparseMatrix::get(int row, int col){
    //metodo get: faco o auxRow ir ate a linha do referido nó, apos isso, crio um MoovableRow, que ira percorrer a linha, ate achar o nó que eu quero.
    Node *auxRow = m_head->down;
    while(auxRow->row != row){
        auxRow = auxRow->down;
    }
    Node *MoovableRow = auxRow;
    while(MoovableRow->col != col){
        MoovableRow = MoovableRow->right;
        if(MoovableRow->col == -1){
            return 0;
        }
    }
    if(MoovableRow->col == col){
        return MoovableRow->value;
    }//se nao achar o nó, retorna 0.
    return 0;
}

void SparseMatrix::print() {
    //um simples for dentro de for para printar uma matriz, diferenca é que chamamos o get de cada posicao da matriz.
    for(int i = 0; i < m_rows; i++){
        for(int j = 0; j < m_cols; j++){
            std::cout << this->get(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

int SparseMatrix::rows(){
    //um simples metodo getRows para ter a quantidade de linhas da matriz.
    return m_rows;
}

int SparseMatrix::cols(){
    //um simples metodo getCols para ter a quantidade de colunas da matriz.
    return m_cols;
}
/*SparseMatrix::~SparseMatrix(){
    Node *auxRow = m_head->down;
    Node *auxCol = m_head->right;
    while(auxRow != m_head){
        //dentro deste while eu vou percorrendo os possiveis nós da matriz, e deletando eles.
        Node *MoovableRow = auxRow->right;
        while(MoovableRow != auxRow){
            Node *aux = MoovableRow->right;
            delete MoovableRow;
            MoovableRow = aux;
        }
        auxRow = auxRow->down;
    }
    while(auxCol != m_head){
        //dentro deste while eu vou percorrendo os sentinelas de colunas e vou deletando eles.
        Node *aux = auxCol->right;
        delete auxCol;
        auxCol = aux;
    }
    while(auxRow != m_head){
        //dentro deste while eu vou percorrendo os sentinelas de linhas e deletando eles.
        Node *aux = auxRow->down;
        delete auxRow;
        auxRow = aux;
    }
    delete m_head;//por fim, deletamos o head.
    std::cout << "Matriz deletada!" << std::endl; 
}*/