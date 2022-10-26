#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include "Node.h"
class SparseMatrix{
private:
    Node *m_head{nullptr};
    int m_rows{0};
    int m_cols{0};
public:
    SparseMatrix() = default;
    SparseMatrix(int rows, int cols);
    void insert(int row, int col, double value);
    void print();
    //~SparseMatrix();
};
#endif