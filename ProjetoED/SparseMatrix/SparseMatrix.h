#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include "Node.h"
class SparseMatrix{
private:
    Node *m_head{nullptr};
    int m_rows{0};
    int m_cols{0};
public:
    SparseMatrix() = default;//construtor padrao.
    SparseMatrix(int rows, int cols);//construtor com parametros linhas e colunas.
    double get(int row, int col);//retorna o valor de um nó, se nao existir, retorna 0.
    void insert(int row, int col, double value);//insere um nó na matriz.
    void print();//printa a matriz.
    int rows();//um getRows.
    int cols();//getCols.
    //~SparseMatrix();//destrutor.
};
#endif